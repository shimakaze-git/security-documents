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

## How to Configure

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
