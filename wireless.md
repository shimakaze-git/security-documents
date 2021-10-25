無線技術関連をまとめたもの

# IEEE 802.11

- https://gihyo.jp/admin/serial/01/ubuntu-recipe/0371

IEEE802.11(無線LAN)は、1つのクライアントがこの周波数帯を常に使用するわけではなく，周波数帯を一定間隔で「チャンネル」に細分化する。

チャンネル番号は5MHzずつずらして割り当てられる。チャンネル幅は20MHz/22MHzなので、4チャンネルないし5チャンネルずらさないと干渉する。
例えば2.4GHzにおいて20MHz幅だとch1（中心周波数2.412GHz）は、2.402GHz〜2.422GHzを使用する。
これと干渉しないチャンネルとなると、20MHz（= 5MHz x 4ch）ずれた2.422GHz〜2.442GHzを使用するch5ないしそれ以上離れたチャンネルである必要がある。

## IEEE 802.11の周波数帯

- 2.4 GHz
  - 2400MHz ~ 2500MHz
  - IEEE 802.11b/g/n/ax
- 5 GHz
  - 5100MHz ~ 5800MHz
  - IEEE 802.11a/n/ac/ax

## IEEE 802.11の規格の種類

- IEEE 802.11a
  - 5GHz
  - Max:54Mbps
  - `チャンネル幅: 20MHz`
- IEEE 802.11b
  - 2.4GHz
  - Max:11Mbps
  - `チャンネル幅: 22MHz`
- IEEE 802.11g
  - 2.4GHz
  - Max:54Mbps
  - 互換性:IEEE 802.11b
  - `チャンネル幅: 20MHz`
- IEEE 802.11n
  - 2.4GHz/5GHz
  - Max:600Mbps
  - 機能:MIMO,チャネルボンディング
  - `チャンネル幅: 20MHz`
- IEEE 802.11ac
  - 5GHz
  - Max:1.3Gbps ~ 6.93Gbps
  - 機能:MU-MIMO,チャネルボンディング,ビームフォーミング
  - `チャンネル幅: 20MHz`
- IEEE 802.11ax
  - 2.4GHz/5GHz
  - Max:9.6Gbps
  - 機能:MU-MIMO,チャネルボンディング,ビームフォーミング

## チャンネルボンディング

802.11n/acは、チャンネルボンディングという仕組みで複数のチャンネルを同時に使用することで40MHzや80MHzといったより広帯域なチャンネルを利用できる。

# 電波が干渉する要因

電波は周波数が高くなると直進性が上がり、水分による吸収率が上がる性質を持っている。
`＝直進性`が上がるということは障害物を避けずにまっすぐ進む（回折しづらくなる）と言うことであり、障害物の向こう側に電波が届きにくくなる。

`水分による吸収率が上がる`と言うことは、**空気中の水分**によって減衰しやすくなるため、距離が遠くなるほど信号強度は落ちて行く。

障害物の多い室内では、5GHzよりも2.4GHzの方が電波は届きやすくなる。

# nmcli command

## デバイス一覧を表示

```bash
$ nmcli device

$ nmcli dev

DEVICE          TYPE      STATE     CONNECTION 
wlp3s0          wifi      接続済み  aterm-10002c-g 
p2p-dev-wlp3s0  wifi-p2p  切断済み  --         
enp0s25         ethernet  利用不可  --         
lo              loopback  管理無し  -- 
```

## 周囲を飛んでいる無線のWi-Fi情報を表示

```bash
$ nmcli dev wifi

IN-USE  BSSID              SSID                 MODE      CHAN  RATE        SIGNAL  BARS  SECURITY    
        58:52:8A:10:F3:E7  rs500m-10f3e4-1      インフラ  1     405 Mbit/s  100     ▂▄▆█  WPA2        
        5A:52:8A:10:F3:E7  rs500m-10f3e4-2      インフラ  1     405 Mbit/s  100     ▂▄▆█  WPA2        
        02:25:36:FB:0C:62  rs500k-fb0cc2-2      インフラ  6     195 Mbit/s  80      ▂▄▆_  WPA2        
        00:25:36:FB:0C:62  rs500k-fb0cc2-1      インフラ  6     195 Mbit/s  77      ▂▄▆_  WPA2        
        24:DE:C6:C5:0B:24  0001docomo           インフラ  1     130 Mbit/s  74      ▂▄▆_  WPA2 802.1X 
        24:DE:C6:C5:0B:23  0000docomo           インフラ  1     130 Mbit/s  74      ▂▄▆_  WPA2        
        10:66:82:4C:85:02  aterm-72e649-g       インフラ  1     270 Mbit/s  64      ▂▄▆_  WPA1 WPA2   
        04:AB:18:A4:63:9D  elecom-a4639b        インフラ  3     270 Mbit/s  64      ▂▄▆_  WPA2        
        60:14:66:C6:75:2F  801ZTa-C6752F        インフラ  8     135 Mbit/s  64      ▂▄▆_  WPA1 WPA2   
        80:22:A7:1F:88:B6  aterm-6bd356-a       インフラ  6     270 Mbit/s  57      ▂▄▆_  WPA2        
        A4:12:42:45:88:A3  pr500m-9c8303-1      インフラ  6     270 Mbit/s  57      ▂▄▆_  WPA2        
        A6:12:42:45:88:A3  pr500m-9c8303-2      インフラ  6     270 Mbit/s  57      ▂▄▆_  WPA2 
```

- CHAN : 使用しているチャネル
- RATE : 速度
- SIGNAL : 電波強度
- SECURITY : WiFi認証用の暗号化方式

より多くの情報を表示したい場合は以下のように `-f ALL` オプションを使用する

```bash
$ nmcli -f ALL dev wifi
```

- -f : 表示するフィールドを指定するためのオプション。`ALL` を渡すことで全ての情報を表示。

# iw command

無線LANの接続状況を確認するコマンド。

`iw` コマンドには3種類の操作方法がある。

- `iw dev` : ネットワークインターフェースに関する操作
- `iw phy` : 指定したハードウェアの情報、サポートしている機能などを表示
- `iw reg` : 電波法のような規制に関する操作

## インターフェースの情報を表示

```
$ iw dev
phy#0
        Interface wlp3s0
                ifindex 3
                wdev 0x1
                addr 64:80:99:xx:xx:xx
                type managed
                channel 100 (5500 MHz), width: 40 MHz, center1: 5510 MHz
```

詳細を表示するにはlinkサブコマンドを使用する。

```
$ iw dev wlp3s0 link
Connected to a4:12:42:xx:xx:xx (on wlp3s0)
        SSID: aterm-xxxxxx-a
        freq: 5500
        RX: 77090059 bytes (270174 packets)
        TX: 6422159 bytes (34948 packets)
        signal: -49 dBm
        tx bitrate: 300.0 MBit/s MCS 15 40MHz short GI

        bss flags:      short-slot-time
        dtim period:    1
        beacon int:     100
```

`Connected to` は接続先の**BSSID**を指し、APのMACアドレスでもある。
**SSID**は無線LANのAPの識別名を指す。

- SSID : アクセスポイントの識別名
- freq : 周波数 (5500の場合、5500MHzということであり、5GHz帯のch100であることがわかる。)
- RX : 受信バイトの統計情報
- TX : 送信バイトの統計情報
- signal : 受信信号強度と呼ばれるRSSI(Received Signal Strength Indicator)の値。
  - (-49 dBm) 値は1mWの出力を0dBとしたときの対数比。
  - 数字が大きい方が信号強度が強い = ちゃんと受信できている
  - ネットワークインジケーターのアンテナアイコンは、4本の線を使って5段階の強度を表示
  - 4本全ての線が点灯している（強度が強い）時が-52dBm以上
  - 3本の時が-64dBm以上
  - 2本なら-76dBm以上
  - 1本なら-88dBm以上
  - 0本なら-88dBm未満