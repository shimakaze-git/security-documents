# security-documents
security documents


## Greenbone Vulnerability Management (OpenVas)

Install *Greenbone Vulnerability Management*

- [install gvm script](./install_gvm.sh)


### Install

```bash
$ chmod +x install_gvm.sh
$ sudo ./install_gvm.sh 
$ sudo ./install_gvm.sh
```

### gsad

gsad [OPTION?] - グリーンボーン・セキュリティ・アシスタント・デーモン

#### ヘルプオプション
  - -h --help : ヘルプオプションを表示する

### アプリケーションオプション。
  - --drop-privileges : <user> <user>に権限を落とす。
  - -f, --foreground : フォアグラウンドで実行します。
  - --http-only : SSLを使わず、HTTPのみで動作させます。
  - --listen : <address> <address> をリッスンします。
  - --mlisten : <address> マネージャーのアドレスを指定します。
  - -p, --port : <number> ポート番号 <number> を使用します。
  - -m, --mport : <number> マネージャポート番号 <number> を使用します。
  - -r, --rport : <number> このポート番号<number>からHTTPをリダイレクトします。
  - --no-redirect : HTTPをHTTPSにリダイレクトしません。
  - -v, --verbose : 何の効果もありません。 ロギング設定についてはINSTALLを参照してください。
  - -V, --version : バージョンを表示して終了します。
  --vendor-version=<string> インターフェースのバージョンとして <string> を使用します。
  -k, --ssl-private-key=<file> HTTPS用の秘密鍵として<file>を使用します。
  -c, --ssl-certificate=<file> HTTPS用の証明書として<file>を使用します。
  --dh-params=<file> Diffie-Hellmanパラメータファイル
  --do-chroot chrootを行う。
  --secure-cookie セキュアなクッキーを使用します（HTTPS使用時には暗黙の了解）。
  --timeout=<number> セッションが終了するまでのユーザーのアイドル時間を分単位で指定します。デフォルトは15分です。
  --client-watch-interval=<number> <number>秒ごとにクライアント接続が閉じられたかどうかをチェックします。0 を指定すると無効になります。既定値は 1 秒です。
  --debug-tls=<level> TLSのデバッグを<level>で有効にします。
  --gnutls-priorities=<string> GnuTLS の優先順位の文字列を指定します。
  --http-frame-opts=<frame-opts> X-Frame-Options HTTPヘッダを指定します。 デフォルトは "SAMEORIGIN "です。
  --http-csp=<csp> Content-Security-Policy HTTP ヘッダーです。 デフォルトは "default-src 'self' 'unsafe-inline'; img-src 'self' blob:; frame-ancestors 'self'"です。
  --http-sts HTTP Strict-Tranport-Securityヘッダーを有効にします。
  --http-sts-max-age=<max-age> HTTP Strict-Tranport-Securityヘッダーの最大時間を秒単位で指定します。 既定値は "31536000 "です。
  --ignore-x-real-ip クライアントアドレスの決定に X-Real-IP を使用しません。
  --per-ip-connection-limit=<number> 1ipあたりの最大接続数を設定します。無制限の場合は0を使用します。
  --unix-socket=<file> リッスンするunixソケットへのパスです。
  --unix-socket-owner=<string> unix ソケットの所有者
  --unix-socket-group=<string> unix ソケットのグループ
  --unix-socket-mode=<文字列> unix ソケットのファイルモード
  --munix-socket=<file> Manager の unix ソケットへのパス
  --http-cors=<cors> Cross-Origin Resource Sharing (CORS) allow origin http header を設定する。


### 参考資料

- https://github.com/yu210148/gvm_install/blob/master/install_gvm.sh
- https://gist.github.com/ffund/f9c06f77569a3865e9ca92b9455bd90c
