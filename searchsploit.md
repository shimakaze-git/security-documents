# searchsploitの使い方

## インストール

```Bash
$ git clone https://github.com/offensive-security/exploitdb.git /opt/exploit-database

$ ln -sf /opt/exploit-database/searchsploit /usr/local/bin/searchsploit

$ cp -n /opt/exploit-database/.searchsploit_rc ~/
```

## .searchsploit_rcの中身

各セクションは、以下の3つに分割される。

- エクスプロイト(exploits)
- シェルコード(shellcodes)
- ペーパー(papers)

```
・files_array : そのセクションに関連するすべてのデータ(EDB-ID,タイトル,作成者,公開日など)を含むコンマ区切り値ファイル

・path_array : これはすべてのファイルが配置されているディレクトリを指します。**これは多くの場合、変更が必要な唯一の値です**

・name_array : そのセクションのSearchSploitに表示する値の名前

・git_array : ローカルコピーの更新に使用するリモートgitの場所

・package_array : 利用可能なパッケージマネージャー(aptやbrewなど)がある場合に使用するパッケージ名
```

## 使い方

- https://www.exploit-db.com/searchsploit

```Bash
# タイトルで検索をかける
$ searchsploit -t {name}

# リンクを表示する
$ searchsploit {name} -w
```

- https://4siteadvantage.com/linux/how-to-install-exploit-db-searchsploit-on-ubuntu-19/
