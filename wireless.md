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
	RX: 26039026 bytes (25143 packets)
	TX: 2595283 bytes (15469 packets)
	signal: -38 dBm
	rx bitrate: 58.5 MBit/s MCS 6
	tx bitrate: 72.2 MBit/s MCS 7 short GI

	bss flags:	CTS-protection short-preamble short-slot-time
	dtim period:	1
	beacon int:	100
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
- rx bitrate : 単位時間あたりに受信されるビット数
- tx bitrate : 単位時間あたりに送信されるビット数
  - MCSは802.11nにおけるModulation and Coding Schemeのインデックス値
  - 「⁠short GI」はGuard Intervalに802.11標準の800ナノ秒ではなく、より短い400ナノ秒を使っていることを意味する
- bss flags : BSS（Basic Service Set）、つまりはそのAP配下のネットワークにおける各種設定を記述
  - **short-slot-time**は、配下に802.11bのクライアントがいないことを前提に短い*Slot Time*を使っていることを意味する
  - **short-preamble**、**CTS-protection**などは主に802.11gの設定
- dtim period : APがマルチキャスト/ブロードキャストフレームを送信する間隔
  - dtime period (Delivery Traffic Indication Map) はビーコンが何回毎に、マルチキャスト/ブロードキャストフレームを送るかを指定するための値
  - 1だと「毎回送る（beacon intが100の場合は100m sec毎に送る⁠）⁠」ことになる
  - 2だとビーコンが2回毎になるので、200ミリ秒ごとに送られることになる
- beacon int : APがビーコンを送信する間隔
  - 100の場合は100m sec毎にビーコンを送信する

```bash
$ iw wlp3s0 station dump
Station a4:12:42:xx:xx:xx (on wlp3s0)
	inactive time:	112 ms
	rx bytes:	412270842
	rx packets:	398160
	tx bytes:	29711803
	tx packets:	189887
	tx retries:	0
	tx failed:	0
	beacon loss:	0
	rx drop misc:	707
	signal:  	-38 dBm
	signal avg:	93 dBm
	tx bitrate:	72.2 MBit/s MCS 7 short GI
	tx duration:	0 us
	rx bitrate:	65.0 MBit/s MCS 7
	rx duration:	0 us
	authorized:	yes
	authenticated:	yes
	associated:	yes
	preamble:	long
	WMM/WME:	yes
	MFP:		no
	TDLS peer:	no
	DTIM period:	1
	beacon interval:100
	CTS protection:	yes
	short preamble:	yes
	short slot time:yes
	connected time:	3557 seconds
	associated at [boottime]:	46531.524s
	associated at:	1635237431627 ms
	current time:	1635240988612 ms
```

- tx retries : 再送信した回数
- ⁠tx failed : 再送信したものの結果的に失敗になった回数

## 無線LANデバイスのサポート状況を確認

```bash
$ iw phy

Wiphy phy0
        max # scan SSIDs: 4
        max scan IEs length: 2257 bytes
        max # sched scan SSIDs: 0
        max # match sets: 0
        RTS threshold: 2347
        Retry short limit: 7
        Retry long limit: 4
        Coverage class: 0 (up to 0m)
        Device supports RSN-IBSS.
        Supported Ciphers:
                * WEP40 (00-0f-ac:1)
                * WEP104 (00-0f-ac:5)
                * TKIP (00-0f-ac:2)
                * CCMP-128 (00-0f-ac:4)
                * CCMP-256 (00-0f-ac:10)
                * GCMP-128 (00-0f-ac:8)
                * GCMP-256 (00-0f-ac:9)
                * CMAC (00-0f-ac:6)
                * CMAC-256 (00-0f-ac:13)
                * GMAC-128 (00-0f-ac:11)
                * GMAC-256 (00-0f-ac:12)
        Available Antennas: TX 0 RX 0
        Supported interface modes:
                 * IBSS
                 * managed
                 * AP
                 * AP/VLAN
                 * monitor
                 * mesh point
                 * P2P-client
                 * P2P-GO
        Band 1:
                Capabilities: 0x186e
                        HT20/HT40
                        SM Power Save disabled
                        RX HT20 SGI
                        RX HT40 SGI
                        No RX STBC
                        Max AMSDU length: 7935 bytes
                        DSSS/CCK HT40
                Maximum RX AMPDU length 65535 bytes (exponent: 0x003)
                Minimum RX AMPDU time spacing: 16 usec (0x07)
                HT Max RX data rate: 150 Mbps
                HT TX/RX MCS rate indexes supported: 0-7, 32
                Bitrates (non-HT):
                        * 1.0 Mbps
                        * 2.0 Mbps
                        * 5.5 Mbps
                        * 11.0 Mbps
                        * 6.0 Mbps
                        * 9.0 Mbps
                        * 12.0 Mbps
                        * 18.0 Mbps
                        * 24.0 Mbps
                        * 36.0 Mbps
                        * 48.0 Mbps
                        * 54.0 Mbps
                Frequencies:
                        * 2412 MHz [1] (20.0 dBm)
                        * 2417 MHz [2] (20.0 dBm)
                        * 2422 MHz [3] (20.0 dBm)
```

- `Supported Ciphers` : 対応しているセキュリティプロトコル
  - WEP40 (00-0f-ac:1) : 40bit 鍵長のWEP
  - WEP104 (00-0f-ac:5) : 104bit 鍵長のWEP
  - TKIP (00-0f-ac:2) : WPAのころに策定された暗号化プロトコル
  - CCMP-128 (00-0f-ac:4) : 128bit 暗号化アルゴリズムとしてAESを利用しているWPA2標準のプロトコル
  - CCMP-256 (00-0f-ac:10) : 256bit 暗号化アルゴリズムとしてAESを利用しているWPA2標準のプロトコル
  - GCMP-128 (00-0f-ac:8)
  - GCMP-256 (00-0f-ac:9)
  - CMAC (00-0f-ac:6)
  - CMAC-256 (00-0f-ac:13)
  - GMAC-128 (00-0f-ac:11)
  - GMAC-256 (00-0f-ac:12)

- Supported interface modes : インターフェースのモード
  - IBSS : アドホック接続で使われるモード
  - managed : 通常の無線LANクライアントとして利用する場合のモード
  - AP : masterモードとも呼ばれるアクセスポイントとして利用するモード
  - AP/VLAN : VLANを使うモード
  - monitor : ネットワークトラフィックを監視するモード

- Band x : 対応周波数帯域のセット
  - Bitrates : ビットレートの理論値
  - Frequencies : 周波数帯域
  - HT TX/RX MCS rate indexes supproted : 前述のMCSでサポートしているインデックスを列挙

IBSSはアドホック接続で使われるモード，managedは通常の無線LANクライアントとして利用する場合のモード，APはmasterモードとも呼ばれるアクセスポイントとして利用するモードです。AP/VLANはVLANを使うモードで，monitorはネットワークトラフィックを監視するモードになります。

## アクセスポイントリストを表示

アクセスポイントリストを表示したい

```bash
$ sudo iw wlan0 scan
```

# 信号強度

信号強度を表現する最も簡単で最も一貫した方法はdBm(decibels relative to a milliwatt)。
ミリワット(mW)に対するデシベルを表す。

- mW : ミリワット（1 mW = 0 dBm）
- RSSI : Received Signal Strength Indicator（通常0~60 or 0~255）
- dBm : Decibels in relation to a milliwatt（通常は-30 ~ -100）

dBmは、直線的なスケーリングがされているのでなく対数。

- https://www.ibsjapan.co.jp/tech/details/metageek-solution/wifi-signal-strength-basics.html

*理想的な信号強度*

| TH 信号強度 | TH | TH 詳細 | TH 必須 |
| :--- | :---: | :---: | ---: |
| -30 dBm | 素晴らしい | 達成可能な最大信号強度 | N/A |
| -67 dBm | 良好 | 非常に信頼性の高く、データパケットのタイムリーな伝送を必要とするアプリケーションのための最小信号強度 | VoIP/VoWiFi, ストリーミングビデオ |
| -70 dBm | Okay | 信頼できるパケット伝送に必要な最小信号強度 | Email, web |
| -80 dBm | よくない | 基本的なコネクティビティに必要な最小信号強度 | N/A |
| -90 dBm | 使用不可 | ノイズレベルに近いかそれ以下の信号強度。殆ど機能しない | N/A |

## RSSI

**Received Signal Strength Indicator**

- https://www.ibsjapan.co.jp/tech/details/metageek-solution/understanding-rssi.html

APまたはルータからの信号をデバイスがどれくらい受信できるかを測定したもの。
優れたワイヤレスコネクションを得るのに十分な信号であるかどうかを判断するために役立つ値。

Note：RSSI値はクライアントデバイスのWi-Fiカードから取得することから(受信信号強度)、ルータまたはAPからの送信電力とは異なる。

RSSIとdBm は共に信号強度を表すが、測定単位が異なる。
RSSIは相対的な指標であり、一方、dBmは電力レベルをmW単位の絶対値で示す。
クライアントの受信信号の**相対的品質**の測定に使用する用語ですが、*絶対値*ではない。

基本的には`0dBmに近いほど優れた信号`。

# wavemon 信号強度の表示

信号強度のリアルタイムグラフを表示するツール**wavemon**。

- https://raspida.com/wifi-wavemon

# horst

複数のチャンネルの信号強度やノード数を表示するツール

## Usage

horstはチャンネルを変更しながら未接続のAPからのパケットなども受信するために、インターフェースをモニターモードにする必要がある

```bash
$ sudo iw wlp3s0 interface add mon0 type monitor
$ sudo horst -i mon0
```

※上記でうまく動かない時は、一度ネットワークを切断し、wlp3s0そのものをモニターモードにする方法もある

```bash
$ sudo ip link set wlp3s0 down
$ sudo iw wlp3s0 set type monitor
$ sudo ip link set wlp3s0 up
```

作成したmon0は次のように削除

```bash
$ sudo iw mon0 del
```

wlp3s0をモニターモードにした場合は次のように戻す

```bash
$ sudo ip link set wlp3s0 down
$ sudo iw wlp3s0 set type managed
$ sudo ip link set wlp3s0 up
```

# kismet

kismet

# iperf3

iperf3

# ipコマンドによるインターフェース制御

**iwconfig**や**ifconfig**は*非推奨*のコマンドとなっているため、`ip`コマンドを使用していくのがインターフェース制御のコマンドとなる。

### インターフェースの停止と起動

インターフェースの*停止(down)*と*起動(up)*

```bash
# <interface> (wlan0) の停止
$ ip link set dev <interface> down

# <interface> (wlan0) の起動
$ ip link set dev <interface> up
```

### 利用可能なインターフェース

現在、利用可能なインターフェースの一覧

```bash
$ ip link
```

## モニター(Monitor) モードに変更する

モニターモードに変更し、用が済んだ場合の通常のManageモードに戻す方法も記載する

### インターフェースをモニターモードに変更

```bash
# <interface> (wlan0) の停止
$ ip link set dev <interface> down

# wpa_supplicantを止める必要もある場合がある
# $ systemctl stop wpa_supplicant.service
# $ systemctl mask wpa_supplicant.service

# <interface>をモニターモードに変更する
$ iw dev <interface> set type monitor

# <interface> (wlan0) の起動
$ ip link set dev <interface> up
```

### インターフェースを管理（通常）モードにする

```bash
# <interface> (wlan0) の停止
$ ip link set dev <interface> down

# wpa_supplicantをunmaskにする.
$ systemctl unmask wpa_supplicant.service

# <interface> を管理モードに戻す.
$ iw dev <interface> set type managed
```

# tcpdump

`tcpdump`は**libpcap**を利用したネットワークトラフィックをキャプチャ・表示するツール

- https://gihyo.jp/admin/serial/01/ubuntu-recipe/0367?page=1


```bash
# 10パケット受信したら終了
$ sudo tcpdump -c 10

# -iでキャプチャするネットワークインターフェースを指定する.
$ sudo tcpdump -c 10 -i wlan0

# inout
$ sudo tcpdump -Q inout
```

- -c : 指定された数のパケットを受信したら終了する
- -i : キャプチャするネットワークインターフェースを指定
- -Q : 受信パケットか送信パケットかを制約する
  - in : 受信パケットのみ
  - out : 送信パケットのみ
  - inout : 送受信両方のパケット
- -X : hdコマンドのように16進とASCIIを並べて表示
- port : フィルターとなるポート
- -n : ホスト名やプロトコルをそれぞれIPアドレス，ポート番号のまま表示
- -N : ドメイン名のうちホスト名部分のみを表示
- -e : Ethernetフレームの情報などデータリンク層のヘッダーも一緒に表示

## 出力のカスタマイズ

80番ポートの通信を監視して、wlan0のネットワークインターフェースを指定する。

```bash
$ sudo tcpdump -i wlan0 -X -c 5 port 80
```

## キャプチャ内容を保存して再生する

tcpdumpは `libpcap形式` のバイナリデータとしてパケットの内容を保存する。
「-w」オプションでパケットの内容を保存できる。

```bash
$ sudo tcpdump -i wlan0 -w yano.pcap
```

一度保存すれば「-r」オプションで当時のトラフィックの様子を再度確認

```bash
$ sudo tcpdump -r yano.pcap port 80
```
