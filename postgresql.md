# PostgreSQL

## Extension

拡張機能。
利用可能な拡張は `pg_available_extensions` で確認できる。

```SQL
select * from pg_available_extensions;
```

http://dbnote.web.fc2.com/note_extension.html

## Logs

ログ設定の方法について記述。
監視には「レスポンス問題発生の予測」、「問題発生時の原因特定」という大きな目的がある。

設定ファイルはこのパスにある。
`/etc/postgresql/12/main/postgresql.conf`

```
log_destination=stderr
logging_collector=on
log_directory=log
log_filename='postgresql-%Y%m%d.log' #ファイル名の変更
client_min_messages=notice
log_min_messages=warning
log_min_error_statement=error
log_min_duration_statement=3000 #スロークエリの検知
log_checkpoints=on #チェックポイントの頻度の確認のために有効化
log_connections=on #クライアントからの接続情報をログに書き込む
log_disconnections=on #クライアントからの切断情報をログに書き込む
log_temp_files=1024 #一時ファイル生成時にログに書き込む
log_statement=ddl #DDLの実行をログに書き込む
log_lock_waits=off
log_line_prefix='[%t]%u %d %p[%l] ' #接頭辞のカスタマイズ
log_rotation_age=1d
log_rotation_size=0
log_truncate_on_rotation=on
log_file_mode=0644 #postgresユーザ以外に読取り権限を付与。ログ監視を想定。
```

https://zatoima.github.io/postgresql-about-monitoring-log.html

https://dev.classmethod.jp/articles/rds-postgres-log-settings/
