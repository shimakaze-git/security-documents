# Network Command

## ss

ネットワーク通信で利用する「ソケット」についての情報などを出力するコマンド。
※従来はnetstatコマンドが使用されていた

[LINK](https://atmarkit.itmedia.co.jp/ait/articles/1710/06/news014.html)

### Options

- -f (ソケット) --family (ソケット) : 表示するソケットの種類（ファミリー）をunix、inet、inet6、link、netlinkから指定する
- -x --unix : UNIXドメインソケットを表示（-f unix相当）
- -4 --ipv4 : IPv4のソケットだけを表示（-f inet相当）
- -6 --ipv6 : IPv6のソケットだけを表示（-f inet6相当）
- -0 --packet : パケットソケットを表示（-f link相当）
- -t --tcp : TCPソケットを表示
- -u --udp : UDPソケットを表示
- -d --dccp : DCCPソケットを表示
- -w --raw : RAWソケットを表示
- -a --all : 接続待ち状態（LISTEN）のソケットと接続待ち状態にないソケットの両方を表示する
- -l --listening : 接続待ち状態のソケットだけを表示する


- -n --numeric : サービス名の名前解決を行わない（ポート番号を表示）
- -r --resolve : 名前解決を行う
- -e --extended : 詳細情報を表示
- -o --options : タイマー情報も表示する
- -m --memory : 各ソケットのメモリの使用量も表示する
- -p --processes : ソケットを使用しているプロセスも表示する
- -Z --context : -pオプションに加えてセキュリティコンテキストも表示（SELinux）
- -z --contexts : -Zオプションに加えてソケットコンテキストも表示（SELinux）
- -i --info : 内部TCPの情報も表示する
- -s --summary : ソケットの種類ごとに本数を表示する
- -D (ファイル名) --diag=ファイル名 : RAW情報をファイルに出力する（画面には何も出力しない）

### Examples

#### TCPの接続待ち状態と接続待ち状態にないソケットを表示する.

```bash
$ ss -nalt
```

- -n(--numeric) : サービス名の名前解決を行わない（ポート番号を表示）
- -a(--all) : 接続待ち状態（LISTEN）のソケットと接続待ち状態にないソケットの両方を表示する
- -l(--listening) : 接続待ち状態のソケットだけを表示する
- -t(--tcp) : TCPソケットを表示

#### TCPとUDPの接続状態をプロセス付きで表示

```bash
$ ss -npltu
```

- -p --processes : ソケットを使用しているプロセスも表示する
- -u --udp : UDPソケットを表示

## netdiscover

LAN内で利用されているIPアドレスを常時監視して一覧を出力し続ける

```bash
# How to Install netdiscover
$ sudo apt update
$ sudo apt install -y netdiscover
```

- シンプルなARP Scanner
- アクティブとパッシブの両方のモードで動作できる
- 識別されたホストをライブで表示
- 複数のサブネットをスキャンすることが可能
- タイミングオプション

### Usage

事前に以下のコマンドでサブネットマスクなどを把握する

```bash
$ ip addr
$ ip route
```

```bash
$ netdiscover -r {ネットワークアドレス/サブネット}

$ netdiscover -r 192.168.0.0/24
```

問題点としてサブネットマスクは、以下の3つの範囲でないとエラーが表示される

- 0.0.0.0/8
- 0.0.0.0/16
- 0.0.0.0/24

### Option

- -i : 使用するネットワークデバイス
- -r : 自動スキャンではなく、指定した範囲をスキャンする
- -l : 与えられたファイルに含まれる範囲のリストをスキャン
- -p : パッシブモード - 何も送信せず、スニッフィングのみを行う
- -m : 既知のMACとホスト名のリストをスキャン
- -F : pcapのフィルター表現をカスタマイズ (デフォルト:arp)
- -s : 各ARPリクエストの間にスリープする時間
- -c : 各ARPリクエストの送信回数
- -n : スキャンに使われた最後のソースIPオクテット（2～253まで)
- -d : オートスキャンと高速モード用のホーム設定ファイルを無視
- -f : ファストモードスキャンを有効にすると、時間を大幅に節約
- -P : 他のプログラムでの解析に適したフォーマットで結果を表示し、アクティブスキャン後に停止
- -L : `-P`に似ていますが、アクティブなスキャンが完了した後もリスニングを続ける
- -N : ヘッダーを印刷しない。Pまたは-Lが有効な場合のみ有効
- -S : 各リクエスト間のスリープ時間抑制を有効

## arp-scan

LAN内で利用されているIPアドレスを調べる

```bash
$ sudo arp-scan -I スキャンを行うネットワークアダプタ(eth0など) -l
```

## netcat (nc)

コマンドラインからTCPとUDP接続などを利用してデータを送受信するためのツール。
宛先を指定して対象ホストに接続する(クライアント側になる)ことだけでなく、自らサーバーになりコネクションを待ち受けるための受信側になることも可能。(送信側だけならtelnetでもできる)

### Usage

```bash
$ nc {接続先ホスト} {ポート暗号}
```

192.168.0.5というホストのHTTP(WEB)サービス(80/tcp)へ接続する例

```bash
$ nc 192.168.0.5 80
HEAD / HTTP/1.0
```

`nc 192.168.0.5 80`と打った後に、[**HEAD / HTTP/1.0**]と打ち込み、改行を2回行うと、[**HEAD / HTTP/1.0**]という内容が接続先のホストに送信されます。
送信すると下記のようにHTTPのレスポンスヘッダが返ってきます。

```bash
$ nc 192.168.0.5 80
HEAD / HTTP/1.0

HTTP/1.0 200 OK
Date: Wed, 03 Nov 2021 12:28:18 GMT
Server: Apache
Last-Modified: Wed, 03 Nov 2021 12:23:37 GMT
ETag: "xxxzy-01-5187a909b1234"
Accept-Ranges: bytes
Content-Length: 39
Connection: close
Content-type: text/html

```

telnetでも同じことができます。

```bash
$ telnet 192.168.0.5 80
Trying 192.168.0.5...
Connected to 192.168.0.5.
Escape character is '^]'.
HEAD / HTTP/1.0

HTTP/1.0 200 OK
Date: Wed, 03 Nov 2021 12:28:18 GMT
Server: Apache
Last-Modified: Wed, 03 Nov 2021 12:23:37 GMT
ETag: "xxxzy-01-5187a909b1234"
Accept-Ranges: bytes
Content-Length: 39
Connection: close
Content-type: text/html

Connection closed by foreign host.
```

ChromeやSafariといったWEbブラウザなどでWebページを閲覧すると、Webブラウザでは`レスポンスボディ`のみが表示されるようになっていますが、実際には上記のような`レスポンスヘッダ`も付加されてWebサーバから返ってきます。

レスポンスヘッダの中身にはセキュリティ上、サーバの*弱点となるような情報が含まれている*ことがあります。

`netcat`コマンドを利用することで、余計な加工をされずにサーバ接続時の情報をそのまま扱うことが可能です。

### 標準出力を使った応用

```bash
# \n\nを二回入れることで改行を忘れない.
$ echo -e 'HEAD / HTTP/1.0\n\n' > request.txt

$ cat request.txt
HEAD / HTTP/1.0


$ nc 192.168.0.5 80 < request.txt
HTTP/1.0 200 OK
Date: Wed, 03 Nov 2021 12:28:18 GMT
Server: Apache
Last-Modified: Wed, 03 Nov 2021 12:23:37 GMT
ETag: "xxxzy-01-5187a909b1234"
Accept-Ranges: bytes
Content-Length: 39
Connection: close
Content-type: text/html
```

`mail.example.com`というメールサーバーのSMTPサービス(25/tcp)に、`echo`コマンドの出力を送ることで、動作することを確認する。

```bash
$ echo "HELP" | nc mail.example.com 25
220 ubuntu ESMTP Sendmail; Thu, 4 Jun 2015 02:22:39 +0900;
214-2.0.0 This is sendmail version 8.14.4
214-2.0.0 Topics:
214-2.0.0       HELO    EHLO    MAIL    RCPT    DATA
214-2.0.0       RSET    NOOP    QUIT    HELP    VRFY
214-2.0.0       EXPN    VERB    ETRN    DSN     AUTH
214-2.0.0       STARTTLS
214-2.0.0 For more info use "HELP <topic>".
214-2.0.0 To report bugs in the implementation see
214-2.0.0       http://www.sendmail.org/email-addresses.html
214-2.0.0 For local information send email to Postmaster at your site.
214 2.0.0 End of HELP info
```

### バナー取得

バナーとは、サービスが出力するメッセージの中で、ソフトウェアの名称やバージョン情報が含まれるものを指す。
外部からバナーが取得可能な場合、そこには攻撃者にとって有益な情報が含まれることがある。

#### Server ヘッダー

```bash
$ nc test.example.com 80
HEAD / HTTP/1.0

HTTP/1.1 200 OK
Date: Thu, 03 Mar 2016 05:50:45 GMT
Server: Apache/2.2.19 (Unix)
Last-Modified: Sat, 20 Nov 2004 20:16:24 GMT
Accept-Ranges: bytes
Content-Length: 44
Connection: close
Content-Type: text/html
```

レスポンスヘッダー内の、Serverヘッダーに注目すると、`Server: Apache/2.2.19 (Unix)`という文字列が表示されており、こちらがバナーになる。
こうしてバナーを取得することで、このホストでは**Apacheのバージョン2.2.19**が**UNIX環境**で動作していることが分かる。

このような情報は攻撃者へのヒントとなるため、バナーが表示されないように設定する必要がある。
Apacheのバナーを隠蔽する方法として、*設定ファイル(httpd.conf)*の*ServerTokensディレクティブ*に、**ProductOnly**という値を指定する。

```bash
# httpd.conf
ServerTokens ProductOnly
```

上記の設定により、*Serverヘッダー*の出力をプロダクト名のみにすることができる。

設定後にApacheを再起動して、以下のように`Server:Apache`というプロダクト名のみの表示となり、バナーが隠蔽できるようになる。

```bash
$ nc test.example.com 80

HTTP/1.1 200 OK
Date: Thu, 03 Mar 2016 05:57:11 GMT
Server: Apache
....(省略)....
```

#### X-Powered-By ヘッダー

Webサーバーで注目されるバナーとしては、先ほどの`Serverヘッダー`以外に**X-Powered-Byヘッダー**が挙げられる。
いくつかのソフトウェアがこのヘッダーを出力するが、主に**PHPのバージョン**情報が取得可能なヘッダーとして知られている。

```bash
$ nc test.example.com 80
HEAD /list.php HTTP/1.0
 
HTTP/1.1 200 OK
Date: Thu, 10 Mar 2016 17:00:23 GMT
Server: Apache
X-Powered-By: PHP/5.3.11
Connection: close
Content-Type: text/html

```

**X-Powered-Byヘッダー**を確認すれば、*PHPのバージョン`5.3.11`*が利用されていることが分かる。
X-Powered-ByヘッダーはPHPファイル(上記の例では/list.php)へのアクセス時にのみ表示され、皆さんが自分の環境を確認する際には、PHPファイルへHEADリクエストを送信する。

PHPのバナーは、設定ファイル(**php.ini**)のexpose_phpディレクティブに、「**Off**」を指定することで隠蔽できる。

この設定を行うと、次のように**X-Powered-Byヘッダー**自体が出力されなくなり、バナーを隠蔽することができる。

```bash
$ nc test.example.com 80
HEAD /list.php HTTP/1.0

HTTP/1.1 200 OK
Date: Thu, 10 Mar 2016 17:03:13 GMT
Server: Apache
Connection: close
Content-Type: text/html
 
$
```

#### バナーの隠蔽

攻撃者には情報を与えないためにも、バナーなどの情報は外部から取得できないようにする必要がある。
しかし、バナーを隠蔽するべきかどうかというのは、一部に賛否両論があり、隠蔽することに意味がないという意見もある。

その理由としては、「バナーを隠して情報を与えなかったとしても、利用しているソフトウェアのバージョンが古い場合、本質的な脆弱性の問題を解決していない」というものがある。

しかし、バナーなどの情報を隠すことは、「攻撃者から攻撃対象として選定されなくなる」というメリットもあり、攻撃対象を選定するなら、バナーが隠蔽されていないよりは、表示される方を攻撃対象として狙いやすい。攻撃機会を少しでも減らすことができるなら、全く無駄とは言えない。

他にも、[SHODAN](https://www.shodan.io/)に代表されるように、特定のバナー情報からインターネット上に存在するホストを検索できるWebサービスに載せられる可能性も無くなる。

- https://www.shodan.io/


