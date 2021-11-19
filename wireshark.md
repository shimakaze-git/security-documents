# wireshark

- https://tryhackme.com/room/wireshark

# Filter

特定のIPアドレスを持つパケットのみを表示する

```
ip.addr == {ip adddress}
```

`特定の送信元のIPアドレス`と`特定の宛先のIPアドレス`でフィルター処理する。

```
ip.src == {src ip adddress} and ip.dst == {dst ip adddress}
```

ポート番号とプロトコル名の両方でフィルタリング

```
tcp.port eq {port #} or {Protocol Name}

udp.port eq {@ort #} or {Protocol Name}
```


```
and - operator: and / &&
or - operator: or / ||
equals - operator: eq / ==
not equal - operator: ne / !=
greater than - operator: gt /  >
less than - operator: lt / <
```

# ARP traffic

## ARP Request

ARP `要求`

Opcode: request (1)

## ARP Request

ARP `応答`

Opcode: reply (2)

# ICMP traffic

## echo request

icmpリクエスト

type : 8

## echo reply

icmp 応答

type: 0

# TCP traffic

tcp

# DNS traffic

## DNS Query

以下の記述がある場合は、`Dst Port: 53`とあるので、送信先のポートが53であることがわかる。またUDPであることもわかる。

```
User Datagram Protocol, Src Port: 51677, Dst Port: 53
```

`8.8.8.8`に対してDNSクエリを投げていることがわかる。

```
Queries
8.8.8.8.in-addr.arpa: type PTR, class IN
```

## DNS Response

Answersとあり、`8.8.8.8`から応答が返ってきていることがわかる。

```
Answers
8.8.8.8.in-addr.arpa: type PTR, class IN, google-public-dns-a.google.com
```

## Zerologon pcapの解析

- 192.168.100.6 : Windowsドメインコントローラー
- 192.168.100.128 : 攻撃者

