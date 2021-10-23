# Network Command

## ss

ネットワーク通信で利用する「ソケット」についての情報などを出力するコマンド。
※従来はnetstatコマンドが使用されていた

[LINK](https://atmarkit.itmedia.co.jp/ait/articles/1710/06/news014.html)

### Options

- -s : 

### Examples

TCPの接続待ち状態と接続待ち状態にないソケットを表示する.

```bash
$ ss -nalt
```

- -n(--numeric) : サービス名の名前解決を行わない（ポート番号を表示）
- -a(--all) : 接続待ち状態（LISTEN）のソケットと接続待ち状態にないソケットの両方を表示する
- -l(--listening) : 接続待ち状態のソケットだけを表示する
- -t(--tcp) : TCPソケットを表示

