## nmcli command

### デバイス一覧を表示

```bash
$ nmcli device

$ nmcli dev

DEVICE          TYPE      STATE     CONNECTION 
wlp3s0          wifi      接続済み  aterm-10002c-g 
p2p-dev-wlp3s0  wifi-p2p  切断済み  --         
enp0s25         ethernet  利用不可  --         
lo              loopback  管理無し  -- 
```

### 周囲を飛んでいる無線のWi-Fi情報を表示

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
