# pgAdmin

Ubuntu 20.04にpgAdmin4をインストールする方法

## How to Install

- 1 : リポジトリの設定

```bash
$ sudo curl https://www.pgadmin.org/static/packages_pgadmin_org.pub | sudo apt-key add

$ sudo sh -c 'echo "deb https://ftp.postgresql.org/pub/pgadmin/pgadmin4/apt/$(lsb_release -cs) pgadmin4 main" > /etc/apt/sources.list.d/pgadmin4.list && apt update'
```

- 2 : pgAdminのインストール

```bash
# apt update
$ sudo apt update

# apt install
$ sudo apt install pgadmin4
```

- 3 : メールアドレスとパスワードを登録

新規のメールアドレスとパスワードを入力する。

```bash
$ sudo /usr/pgadmin4/bin/setup-web.sh
```

- 4 : 以下のURLからアクセスが可能になる

`http://127.0.0.1/pgadmin4`

