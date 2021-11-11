# ncrack

ハイスピードオンラインパスワードクラッキングツール。
**ssh, telnet, http(s)のBasic認証、SMB, RDP, VNC**などをクラックできる。
ユーザ名の辞書やパスワードの辞書が同梱されています。

## How to Install

```bash
$ sudo apt update
$ sudo apt install ncrack
```

## Usage

```bash
$ ncrack -v --user root localhost:22
 
Starting Ncrack 0.4ALPHA ( http://ncrack.org ) at 2013-01-09 06:57 JST
 
ssh://127.0.0.1:22 finished.
 
 
Ncrack done: 1 service scanned in 38499.81 seconds.
Probes sent: 999 | timed-out: 0 | prematurely-closed: 157
 
Ncrack finished.
```

### 複数のターゲットを指定

```bash
$ ncrack -v --user root 192.168.0.2:22 192.168.0.3:21
```

### HTTPのBasic認証のクラッキング

```bash
$ ncrack -v --user test \
    -P /usr/local/share/ncrack/top50000.pwd \
    http://127.0.0.1 -g path=/basic
```

https://kaworu.jpn.org/security/ncrack

http://n.pentest.ninja/?p=854