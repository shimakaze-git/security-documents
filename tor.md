# Tor

Tor環境をUbuntu 20.04にインストール。
UbuntuのメインリポジトリのTorは常に古いものであるため、公式リポジトリから最新バージョンをインストールする方法を記述。

- DuckDuckGo : Dafault Search Engine

## How to Install

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

## How to Configure of Etc

`/etc/tor/torrc`が設定ファイルになる。

- Torブラウザ : `tor-browser_ja-JP/Browser/TorBrowser/Data/Tor/torrc`
- Tor本体 : `/etc/tor/torrc`

```bash
# ExcludeNodes
# 使用しないサーバのニックネームを指定。複数の場合はカンマで区切って指定。
ExcludeNodes {jp},
```

torproject公式による駄目なノードのリスト

- https://onionoo.torproject.org/summary?flag=badexit

## How to Configure

Browser Settings

### Japanese Language

- 1 : Tor Browserを起動
- 2 : URLに `about:preferences`と入力
- 3 : Generalにある`Language`から、`Search for more languages…`をクリック
- 4 : `Japanese`を探してクリックして、`Add`をクリックする
- 5 : `OK`ボタンをクリック
- 6 : `適用して再起動`をクリックして、再起動を行って設定完了

### Setup Cookie Configure

Cookieなどの閲覧履歴を確実に削除

- 1 : Tor Browserを起動
- 2 : URLに `about:preferences`と入力
- 3 : `プライバシーとセキュリティ`を選択
- 4 : `（Tor Browser に）記憶させる履歴を詳細設定する」`を選択
- 5 : `常にプライベートブラウジングモード`にチェックを入れて再起動

## Over VPN

VPN経由でTorを使用するのが推奨されている。

FireFoxとChromeの拡張機能である「`VPN Free - Betternet VPN Proxy`」を主に使用する。

## VPN Service

`prontovpn`

- https://protonvpn.com

protonvpnをインストールする

https://protonvpn.com/support/linux-ubuntu-vpn-setup/

- 1 : [ProtonVPN DEBパッケージ](https://protonvpn.com/download/protonvpn-stable-release_1.0.1-1_all.deb)をインストールする
- 2 : ダウンロードしたDEBパッケージをダブルクリックしてインストールする
- 3 : apt経由でインストールする

```bash
$ sudo apt update

# install protonvpn
$ sudo apt install protonvpn
```

- 4 : システムトレイアイコンを表示できるようにする

```bash
$ sudo apt install gnome-shell-extension-appindicator gir1.2-appindicator3-0.1
```

上記が完了すれば`Protonvpn`がインストールされる。

### おすすめの無料VPN

[こちら](https://ja.vpnmentor.com/blog/%EF%BC%88%E6%9C%AC%E5%BD%93%E3%81%AB%E7%84%A1%E6%96%99%E3%81%AE%EF%BC%89%E3%83%99%E3%82%B9%E3%83%88vpn%E3%82%B5%E3%83%BC%E3%83%93%E3%82%B9/)を参考にして、無料VPNを選択する。

- [hide.me](https://hide.me/ja)
- [ProtonVpn](https://protonvpn.com/free-vpn)
- [windscribe](https://jpn.windscribe.com)
