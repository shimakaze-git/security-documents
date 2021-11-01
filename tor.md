# Tor

Tor環境をUbuntu 20.04にインストール。
UbuntuのメインリポジトリのTorは常に古いものであるため、公式リポジトリから最新バージョンをインストールする方法を記述。

# How to Install

```bash
# apt-transport-httpsをインストールする.
$ sudo apt install apt-transport-https
```

```bash
# Torリポジトリを追加
$ sudo sh -c 'echo "deb [arch=amd64] https://deb.torproject.org/torproject.org $(lsb_release -sc) main" > /etc/apt/sources.list.d/tor-project.list'
$ sudo sh -c 'echo "deb-src [arch=amd64] https://deb.torproject.org/torproject.org $(lsb_release -sc) main" >> /etc/apt/sources.list.d/tor-project.list'
```

```bash
# パッケージの署名に使用するgpgキーを追加
$ curl https://deb.torproject.org/torproject.org/A3C4F0F979CAA22CDBA8F512EE8CBC9E886DDD89.asc | sudo apt-key add -
```

```bash
# torのインストール
$ sudo apt update
$ sudo apt install -y tor deb.torproject.org-keyring
```

```bash
# Torのバージョンを確認
$ tor --version

# コマンドを使用して実行されているかどうかを確認
$ systemctl status tor
```

```bash
# Torブラウザのインストール
$ sudo apt install -y torbrowser-launcher
```