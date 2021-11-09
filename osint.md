# OSINT

- https://ja.wikipedia.org/wiki/%E3%82%AA%E3%83%BC%E3%83%97%E3%83%B3%E3%83%BB%E3%82%BD%E3%83%BC%E3%82%B9%E3%83%BB%E3%82%A4%E3%83%B3%E3%83%86%E3%83%AA%E3%82%B8%E3%82%A7%E3%83%B3%E3%82%B9

`Tools`

- theharvester

## theharvester

OSINTツールの一つ。
メール、サブドメイン、ホスト、従業員名、オープンポート、バナーなどを検索エンジン、PGPキーサーバー、SHODANコンピュータデータベースなどのさまざまな公開ソースから収集するツール。

以下から探し出すことが可能。

```
baidu, bing, bingapi, certspotter, crtsh, dnsdumpster,
dogpile, duckduckgo, github-code, google, hunter,
intelx, linkedin, linkedin_links, netcraft, otx,
securityTrails, spyse(disabled for now), threatcrowd,
trello, twitter, vhost, virustotal, yahoo
```

### How to Install

- https://github.com/laramies/theHarvester

### Usage

```bash
# Example
$ python theHarvester.py -d hogehoge -b google
```

-d, -domain : 検索する会社名またはドメインを設定
-l, -limit : 検索結果の件数を制限
-S, -start : 結果番号Xで開始、デフォルト=0
-g, -google-dork : Google検索にはGoogle Dorksを使用
-p, -proxies : リクエストにプロキシを使用し、proxies.yamlにプロキシを入力
-s, -shodan : Shodanを使用して、検出されたホストを照会
-screenshot : 解決したドメインのスクリーンショットを撮る、出力ディレクトリを指定
-v, –virtual-host : DNS解決でホスト名を確認し、バーチャルホストを検索
-e, –dns-server : ルックアップに使用するDNSサーバー
-t, –dns-tld : DNSのTLD拡張検出を行う、デフォルトはFalse
-r, –take-over: 買収されていないかチェック
-n, -dns-lookup : DNSサーバーの検索を有効
-c, -dns-brute : ドメインでDNSブルートフォースを行う
-f, -filename : 結果をHTMLやXMLファイルに保存
-b, -source : 収集するためのソースを設定

- https://whitemarkn.com/learning-ethical-hacker/theharvester/
- https://kaworu.jpn.org/security/theharvester