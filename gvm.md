# Greenbone Vulnerability Management

gvmバージョン21.04をUbuntu 20.04へのインストール方法。
ソースからのインストール方法だとかなり時間がかかり、気を使わないといけないこともたくさんあって大変です。

ちなみにソースインストールの方法に関しては[こちら](https://www.libellux.com/openvas/#troubleshooting)を参照してください。

aptのパッケージ管理で良いものがないかと探していたら、[こちら](https://launchpad.net/~mrazavi/+archive/ubuntu/gvm)の方が作っていました。

インストール方法と設定方法についてを解説。

## How to Install

- 1 : パッケージ管理の更新

```bash
$ sudo apt update
$ sudo apt upgrade
$ sudo apt dist-upgrade
```

- 2 : PostgreSQLのインストール

GSA(Greenbone Security Assistant)が使用するデータベースを追加

```bash
$ sudo apt install postgresql
```

- 3 : インストール用のリポジトリの追加

今回は[こちら](https://launchpad.net/~mrazavi/+archive/ubuntu/gvm)を使用しました。

```bash
$ sudo add-apt-repository ppa:mrazavi/gvm
$ sudo apt update
```

- 4 : gvmのインストール

とりあえずいろいろ出てきますが、`yes`を押したり、適当にEnterキーを押していれば問題はないです。

```bash
$ sudo apt install gvm
```

上記のコマンドで以下の4つが主にインストールされることになります。

```bash
# gvm
# gsa
# ospd-openvas
# openvas
# gvm-tools
```

- 5 : GSAへのアクセス

WEBインターフェースであるGSAへのアクセスは以下のURLを打ち込めば大丈夫です。

https://127.0.0.1:9392

ユーザー名とパスワードが求められますが、以下が初期ユーザー名とパスワードになります。

```bash
# username : admin
# password : admin
```

- 6 : NVT/SCAP/CERT/GVMD_DATAデータの更新

スキャンのためには、脆弱性方法をダウンロードして更新する必要があります。
ダウンロードするのは以下の4つからです。

```bash
# NVT
# SCAP
# CERT
# GVMD_DATA
```

こちらの更新処理は必ず必要になりますが、時間がかなりかかります。

こちらのパッケージですが非常に困ったことが一つだけあります。`apt install gvm`でインストールすると、postgresql内には`gvmd`というデータベースとその所有者である`gvmduser`というユーザーが作成されます。

しかし、`gvmd`デーモンからpostgresqlのアクセスには`gvm`というユーザーでアクセスしようとします。

そのため、事前に以下のコマンドを打って`gvmduser`でデータベースにアクセスできるようにします。

```bash
$ sudo cat /etc/default/gvmd-pg
GVMD_POSTGRESQL_URI=postgresql://gvmduser:XXxxxxxX11xx@localhost:5432/gvmd?application_name=gvmd

# このコマンドでGVMD_POSTGRESQL_URIが環境変数に登録される
$ export $(sudo cat /etc/default/gvmd-pg)

$ env|grep GVMD_POSTGRESQL_URI
GVMD_POSTGRESQL_URI=postgresql://gvmduser:XXxxxxxX11xx@localhost:5432/gvmd?application_name=gvmd
```

[こちら](https://launchpad.net/~mrazavi/+archive/ubuntu/gvm)の下の方にも書いていますが、今後はgvm系のコマンド(gvmd,gsad,ospd-openvas,openvas)を打つ際は、必ずコマンドの前に`sudo -E -u gvm -g gvm`をつける必要があります。

以下のコマンドで`GVMD_POSTGRESQL_URI`の環境変数を引き継いただまま、`gvm`ユーザーとして更新処理を実行します。

```bash
# NVTの更新
$ sudo -E -u gvm -g gvm greenbone-nvt-sync

# ファイルからRedisに情報を更新する.
$ sudo -E -u gvm -g gvm openvas --update-vt-info

# CERT,SCAP,GVMD_DATAの更新
$ sudo -E -u gvm -g gvm greenbone-feed-sync --type CERT
$ sudo -E -u gvm -g gvm greenbone-feed-sync --type SCAP
$ sudo -E -u gvm -g gvm greenbone-feed-sync --type GVMD_DATA
```

`http://localhost:9392/feedstatus`にアクセスして、更新が成功すると以下の画像のように`Status`部分が全て*Current*になります。(この画像では一部が**2 days old**になっていますが、最新なら全てが*Current*になります。)

![feed_status](./feed_status.png)

更新処理ですが、何度かエラーを吐いて失敗します。
詳細については[こちら(greenbone-feed-sync)](#greenbone-feed-sync)を参照してください。


## Settings

インストール後にも設定が必要になる。

### Create User

初期のデフォルトの管理ユーザー以外にも、新たな管理ユーザーの作成を行う。
`--create-user`と`--password`は自由に入力してください。

```bash
$ sudo -E -u gvm -g gvm gvmd --create-user=gvmadmin --password=gvmadmin
```

```bash
# gsadの再起動
$ sudo systemctl restart gsad
```

### feed-update.lock

`/var/run/ospd/feed-update.lock`が存在し、所有ユーザーとグループが`gvm:gvm`の場合は必要がありません。存在しない場合はこちらの処理を行ってください。

```bash
$ mkdir -p /var/run/ospd/
$ touch /var/run/ospd/feed-update.lock
$ sudo chown gvm:gvm /var/run/ospd/feed-update.lock
```

### chown Update

`/var/run/gvm`配下を全てgvmユーザーの所有者にする。

```bash
$ sudo chown gvm:gvm -R /var/run/gvm
```

### change Schema Owner

こちらの処理も必ずしも必要ではありません。
`gvmd`データベースが作成された際に、3つのスキーマが作成されます。
しかし、`public`スキーマの所有者がまれに`postgres`になっている場合があります。

以下の`alter`コマンドでオーナーを変えてやる必要があります。

```
postgres=# \c gvmd;

gvmd=# \dn
  List of schemas
  Name  |  Owner   
--------+----------
 cert   | gvmduser
 public | postgres
 scap   | gvmduser
(3 rows)

gvmd=# ALTER SCHEMA public OWNER TO gvmduser;
ALTER SCHEMA

gvmd=# \dn
  List of schemas
  Name  |  Owner   
--------+----------
 cert   | gvmduser
 public | gvmduser
 scap   | gvmduser
(3 rows)
```

### gvmd Rebuild

```bash
$ export $(sudo cat /etc/default/gvmd-pg)

# ユーザーのuuidを表示する
$ sudo -E -u gvm -g gvm gvmd --get-users --verbose
admin 322c1bb8-1553-4b4a-9fed-311f522e86a6
gvmadmin a47781a6-d358-4f49-85d8-4a8c2b50da13

# sudo -E -u gvm -g gvm gvmd --modify-setting 78eceaec-3385-11ea-b237-28d24461215b --value a47781a6-d358-4f49-85d8-4a8c2b50da13
$ sudo -E -u gvm -g gvm gvmd --modify-setting 78eceaec-3385-11ea-b237-28d24461215b --value <uuid_of_user>
```

```bash
# 少しだけ時間がかかるが待つ必要がある。
$ sudo -E -u gvm -g gvm gvmd --rebuild
```

## Logs

ログの場所は以下3つになります。

```bash
$ /var/log/gvm/gvmd.log
$ /var/log/gvm/ospd-openvas.log
$ /var/log/gvm/openvas.log
```

scan実行時に`tail -f`でログを見ながら実行すれば、エラーが発生した際などにも原因を把握しやすくもなります。

### Log settings files

```
$ /etc/openvas/openvas_log.conf

$ /etc/gvm/gvmd_log.conf
$ /etc/gvm/ospd-openvas.conf
```

## Check Update & Status

以下で更新を定期的に確認する必要があります。

```bash
# create env
$ export $(sudo cat /etc/default/gvmd-pg)

# update nvt/scap/gvmd_data
$ sudo -E -u gvm -g gvm greenbone-nvt-sync
$ sudo -E -u gvm -g gvm greenbone-feed-sync --type CERT
$ sudo -E -u gvm -g gvm greenbone-feed-sync --type SCAP
$ sudo -E -u gvm -g gvm greenbone-feed-sync --type GVMD_DATA
```

デーモンが起動しているかのステータスの確認方法

```bash
$ sudo systemctl status ospd-openvas
$ sudo systemctl status gvmd
$ sudo systemctl status gsad
```

デーモンの再起動

```bash
$ sudo systemctl daemon-reload

# ReStart
$ sudo systemctl restart ospd-openvas
$ sudo systemctl restart gvmd
$ sudo systemctl restart gsad
```

## greenbone-feed-sync

内部では`rsync`コマンドを使用しています。接続先である`rsync://feed.community.greenbone.net`ですが、何度か接続していると切断されたり、混雑している時には接続が失敗したりします。

サーバーはドイツにあります。ドイツの09:00〜21:00は、17:00〜05:00です。自分が試した時は、アクセスが切断されたりするのは主にこの時間帯です。
日本からなら06:00〜15:00に更新処理をかけてみるとうまくいくかもしれません。

https://mirror.ufs.ac.za/misc/

## Scan

[Targets](http://localhost:9392/targets)にアクセスして、画面左上の☆をクリックすることで、`Target`を追加することができる。

下記の画像の通り、名前(Name)、IPアドレス(Hosts:Manual)を設定します。
**Port list**は*スキャンするポートの種類*を選択する以下3つから指定。

- All IANA assigned TCP : TCPの全てのポートをスキャン
- All IANA assigned TCP and UDP : TCPとUDPの全てのポートをスキャン
- All TCP and Nmap top 100 UDP : TCPの全てのポートとNmapでスキャンする100のUDPポート

**Alive Test**はスキャン方法を選択。

- Scan Config Default
- ICMP Ping
- TCP-ACK Service Ping
- TCP-SYN Service Ping
- ARP Ping
- ICMP & TCP-ACK Service Ping
- ICMP & ARP Ping
- TCP-ACK Service & ARP Ping
- ICMP, TCP-ACK Service & ARP Ping
- Consider Alive : **ping応答なしでも診断を行う**

![scan_target](./scan_target.png)

---

[Tasks](http://localhost:9392/tasks)にアクセスして、画面左上の☆をクリックして、`New Task`をクリックすることで追加することができる。

**Name**でタスク名をつける。

下記画像の通り、`Scan Targets`からプルダウンで*Target*を選択する。

![scan_task](./scan_task.png)

**Scanner**

- OpenVAS Default
- CVE

**Scan Config**

- Base
- Full and fast : 開いているポートに対する標準的な脆弱性の検査。但し被検査機器にダメージを与えない項目のみ
- Full and Fast ultimate : 開いているポートに対する脆弱性の検査。サービス停止やシャットダウンを伴う可能性がある。
- Full and very deep : 開いているポートに対する脆弱性の検査に加え、脆弱性DB（NVT）に掲載されている全ポートに対して脆弱性を検査。但し被検査機器にダメージを与えない項目のみ。
- Full and very deep ultimate : 開いているポートに対する脆弱性の検査に加え、脆弱性DB（NVT）に掲載されている全ポートに対して脆弱性を検査。サービス停止やシャットダウンを伴う可能性がある。

以下の3つはターゲットシステムの発見やターゲットシステムで使用しているOSやミドルウェア、ハードウェアを検出するコンフィグでは脆弱性の検出

- Discovery
- Host Discovery 
- System Discovery

**QoD**は検出結果の信頼度を指す。

`Save`ボタンを押してタスクを作成して、再生ボタンを押すことでスキャンを開始する。

scan実行時には[Logs](#Logs)にも説明したログを参照しながらやってみると、実際にスキャンの様子を見ることができます。

### tcpdump

scan実行の様子を詳細に見るために、tcpdumpコマンドで実際に通信を飛ばしている様子を見ることができます。

```bash
$ tcpdump host [target_ip]
```

### Reports

スキャンが完了したのにレポートがきちんと出力されないことがまれにあるので、以下のコマンドでキャッシュに溜まっているレポートを吐き出せる。

```bash
# create env
$ export $(sudo cat /etc/default/gvmd-pg)

$ sudo -E -u gvm -g gvm gvmd --optimize=rebuild-report-cache
```

<!-- https://www.libellux.com/openvas/#troubleshooting -->
## Link

- https://linuxmeditation.com/greenbone-security-assistant-on-ubuntu-server
- https://launchpad.net/~mrazavi/+archive/ubuntu/gvm
- https://gist.github.com/ffund/f9c06f77569a3865e9ca92b9455bd90c#file-gvm-20-install-and-setup-L6
- https://www.secure-iv.co.jp/blog/587
- https://end0tknr.hateblo.jp/entry/20201126/1606367682
