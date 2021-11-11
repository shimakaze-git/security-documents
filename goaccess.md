# GoAccess

GoAccessはリアルタイムにWebログを解析するツール。コマンドからログファイルを呼び込ませることで解析が可能になる。

- Amazon CloudFront (Download Distribution).
- Amazon Simple Storage Service (S3)
- AWS Elastic Load Balancing
- Combined Log Format (XLF/ELF) Apache | Nginx
- Common Log Format (CLF) Apache
- Google Cloud Storage.
- Apache virtual hosts
- Squid Native Format.
- W3C format (IIS).
- Caddy's JSON Structured format.

## How to Install

```Bash
$ sudo apt update
$ sudo apt install goaccess
```

## Usage

```Bash
$ goaccess access.log
```

`tail -f`との組み合わせ

```Bash
$ tail -f access.log | goaccess -
```

### Nginx / Apache access.log

```Bash
$ goaccess access.log --log-format=COMBINED
```

### Generate HTML

```Bash
$ goaccess access.log -a -o report.html
```

### RealTime

```Bash
$ goaccess access.log -a -o report.html --real-time-html
```

https://wonderwall.hatenablog.com/entry/2017/08/27/183000
