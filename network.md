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
