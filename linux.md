# 起動時間の高速化

起動時間を短縮して高速化する方法はいくつかある

## GRUBの設定

`systemd-analyze`でブートプロセスを解析する。
起動に1分44秒くらいかかっているのがわかる。

```bash
$ systemd-analyze
Startup finished in 4.785s (kernel) + 1min 44.793s (userspace) = 1min 49.579s 
graphical.target reached after 1min 44.712s in userspace
```

以下のコマンドで起動するのにかかった時間でユニットファイルを並べて一覧表示する。

```bash
$ systemd-analyze blame
1min 13.618s plymouth-quit-wait.service                           
     25.109s snapd.service
     .........
     .........
     .........
```

大概はplymouthと出てくるのが多い。
**Plymouth(プリムス)**は、Ubuntuの起動時や終了時にスプラッシュスクリーンを表示するサービスのこと。

スプラッシュスクリーンを表示する必要はないため、こちらを省略してみる。以下のGRUBの設定で表示を省略することが可能になる。

```bash
$ sudo vim /etc/default/grub
```

`GRUB_CMDLINE_LINUX_DEFAULT=”quiet splash"`となっている部分を、`GRUB_CMDLINE_LINUX_DEFAULT=”quiet nosplash"`に変更する。

```bash
# If you change this file, run 'update-grub' afterwards to update
# /boot/grub/grub.cfg.
# For full documentation of the options in this file, see:
#   info -f grub -n 'Simple configuration'

GRUB_DEFAULT=0
GRUB_TIMEOUT_STYLE=hidden
GRUB_TIMEOUT=0
GRUB_DISTRIBUTOR=`lsb_release -i -s 2> /dev/null || echo Debian`
# GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
GRUB_CMDLINE_LINUX_DEFAULT="quiet nosplash"
GRUB_CMDLINE_LINUX=""
```

変更したら以下のコマンドを実行して、再起動を行う。

```
# GRUBの設定
$ sudo update-grub2

# 再起動
$ sudo reboot
```

再度、`systemd-analyze`を実行してみると、先ほどと比べて起動時間がかなり早くなっているはずです。自分の環境では40秒くらいの短縮になりました。

```bash
$ systemd-analyze

Startup finished in 4.785s (kernel) + 1min 2.393s (userspace) = 1min 49.579s 
graphical.target reached after 1min 2.213s in userspace
```

### GRUB_CMDLINE_LINUX_DEFAULTの設定

設定するとスプラッシュを映すか、プロセスの処理(文字列が流れる)を映すかを設定できる。

```bash
# スプラッシュにする場合
GRUB_CMDLINE_LINUX_DEFAULT=”quiet splash”

# 文字列にする場合
GRUB_CMDLINE_LINUX_DEFAULT=”quiet nosplash”

# スプラッシュイメージを表示しつつ簡易テキストも表示
GRUB_CMDLINE_LINUX_DEFAULT=”splash”
```

## ディスクアクセスを高速化するpreload

`preload`は、バックグラウンドで動作して、ユーザの利用するアプリケーションを学習します。よく使うアプリケーションをメモリにキャッシュします。

Windowsで似たものとしては、`Windows Superfetch`がある。

### How to Install

```bash
$ sudo apt install -y preload
```

### Configure

設定ファイル

```bash
$ vim /etc/default/preload
```

### Logs

```bash
# ログが記録されます
$ /var/log/preload.log

# キャッシュされたファイルや統計情報が記録
$ /var/lib/preload/preload.state
```

### Link

- https://kaworu.jpn.org/ubuntu/Linux%E3%81%AE%E3%83%87%E3%82%A3%E3%82%B9%E3%82%AF%E3%82%A2%E3%82%AF%E3%82%BB%E3%82%B9%E3%82%92%E9%AB%98%E9%80%9F%E5%8C%96%E3%81%99%E3%82%8Bpreload%E3%81%AE%E5%B0%8E%E5%85%A5
