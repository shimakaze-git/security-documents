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

### Update

```bash
$ sudo greenbone-nvt-sync
$ sudo greenbone-scapdata-sync
$ sudo greenbone-certdata-sync
```

### gsad

gsad [OPTION?] - グリーンボーン・セキュリティ・アシスタント・デーモン

#### ヘルプオプション
  - -h --help : ヘルプオプションを表示する

### 参考資料

- https://github.com/yu210148/gvm_install/blob/master/install_gvm.sh
- https://gist.github.com/ffund/f9c06f77569a3865e9ca92b9455bd90c
- https://linuxmeditation.com/greenbone-security-assistant-on-ubuntu-server/
