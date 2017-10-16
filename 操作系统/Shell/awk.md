┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:42:06)──> cat netstat.txt                                   ──(日, 723)─┘
Proto Recv-Q Send-Q  Local Address          Foreign Address        (state)
tcp4       0      0  192.168.88.103.54370   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54369   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54366   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54365   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54364   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54363   ti-in-f113.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54362   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54359   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54358   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54341   ti-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54340   tg-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54337   tg-in-f138.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54336   ti-in-f101.1e100.https SYN_SENT
tcp6       0      0  liuqidemacbook-p.54333 yorukamidzuki.49464    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54331 yorukamidzuki.49463    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54326 yorukamidzuki.49462    ESTABLISHED
tcp4       0      0  192.168.88.103.54320   tg-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54317   17.188.138.70.5223     ESTABLISHED
tcp4       0      0  192.168.88.103.54088   111.13.101.73.http     LAST_ACK
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53845   115.182.41.49.7080     ESTABLISHED
tcp4       0      0  192.168.88.103.53826   115.182.41.173.http    ESTABLISHED
tcp4       0      0  192.168.88.103.53793   151.101.76.133.https   ESTABLISHED
tcp4       0      0  192.168.88.103.53737   tk-in-f188.1e100.5228  ESTABLISHED
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:42:10)──> awk '{print $1, $4}' netstat.txt                  ──(日, 723)─┘
Proto Local
tcp4 192.168.88.103.54370
tcp4 192.168.88.103.54369
tcp4 192.168.88.103.54366
tcp4 192.168.88.103.54365
tcp4 192.168.88.103.54364
tcp4 192.168.88.103.54363
tcp4 192.168.88.103.54362
tcp4 192.168.88.103.54359
tcp4 192.168.88.103.54358
tcp4 192.168.88.103.54341
tcp4 192.168.88.103.54340
tcp4 192.168.88.103.54337
tcp4 192.168.88.103.54336
tcp6 liuqidemacbook-p.54333
tcp6 liuqidemacbook-p.54331
tcp6 liuqidemacbook-p.54326
tcp4 192.168.88.103.54320
tcp4 192.168.88.103.54317
tcp4 192.168.88.103.54088
tcp4 192.168.88.103.53860
tcp4 192.168.88.103.53859
tcp4 192.168.88.103.53858
tcp4 192.168.88.103.53845
tcp4 192.168.88.103.53826
tcp4 192.168.88.103.53793
tcp4 192.168.88.103.53737
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:42:32)──> awk '$3 == 0 && $6 == "CLOSE_WAIT" ' netstat.txt  ──(日, 723)─┘
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:44:14)──> awk '$3==0 && $6 == "LISTEN" || NR == 1' netstat.txt
Proto Recv-Q Send-Q  Local Address          Foreign Address        (state)
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:45:00)──> awk '$3==0 && $6 == "CLOSE_WAIT" || NR == 1' netstat.txt
Proto Recv-Q Send-Q  Local Address          Foreign Address        (state)
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:45:15)──> awk '$6 ~ /SYN/ || NR == 1 {print NR, $4, $5, $6}' OFS="\t" netstat.txt
1	Local	Address	Foreign
2	192.168.88.103.54370	tsa01s07-in-f13..https	SYN_SENT
3	192.168.88.103.54369	ti-in-f102.1e100.https	SYN_SENT
4	192.168.88.103.54366	ti-in-f102.1e100.https	SYN_SENT
5	192.168.88.103.54365	ti-in-f102.1e100.https	SYN_SENT
6	192.168.88.103.54364	ti-in-f102.1e100.https	SYN_SENT
7	192.168.88.103.54363	ti-in-f113.1e100.https	SYN_SENT
8	192.168.88.103.54362	ti-in-f102.1e100.https	SYN_SENT
9	192.168.88.103.54359	tsa01s07-in-f13..https	SYN_SENT
10	192.168.88.103.54358	tsa01s07-in-f13..https	SYN_SENT
11	192.168.88.103.54341	ti-in-f101.1e100.https	SYN_SENT
12	192.168.88.103.54340	tg-in-f102.1e100.https	SYN_SENT
13	192.168.88.103.54337	tg-in-f138.1e100.https	SYN_SENT
14	192.168.88.103.54336	ti-in-f101.1e100.https	SYN_SENT
18	192.168.88.103.54320	tg-in-f101.1e100.https	SYN_SENT
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:46:44)──> awk '/SYN/' netstat.txt                           ──(日, 723)─┘
tcp4       0      0  192.168.88.103.54370   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54369   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54366   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54365   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54364   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54363   ti-in-f113.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54362   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54359   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54358   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54341   ti-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54340   tg-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54337   tg-in-f138.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54336   ti-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54320   tg-in-f101.1e100.https SYN_SENT
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:47:13)──> awk '!/SYN/' netstat.txt                          ──(日, 723)─┘
Proto Recv-Q Send-Q  Local Address          Foreign Address        (state)
tcp6       0      0  liuqidemacbook-p.54333 yorukamidzuki.49464    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54331 yorukamidzuki.49463    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54326 yorukamidzuki.49462    ESTABLISHED
tcp4       0      0  192.168.88.103.54317   17.188.138.70.5223     ESTABLISHED
tcp4       0      0  192.168.88.103.54088   111.13.101.73.http     LAST_ACK
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53845   115.182.41.49.7080     ESTABLISHED
tcp4       0      0  192.168.88.103.53826   115.182.41.173.http    ESTABLISHED
tcp4       0      0  192.168.88.103.53793   151.101.76.133.https   ESTABLISHED
tcp4       0      0  192.168.88.103.53737   tk-in-f188.1e100.5228  ESTABLISHED
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:47:43)──> awk 'NR!=1{print > $6}' netstat.txt               ──(日, 723)─┘
awk: can't open file SYN_SENT
 input record number 2, file netstat.txt
 source line number 1
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:48:10)──> cat netstat.txt                               2 ↵ ──(日, 723)─┘
Proto Recv-Q Send-Q  Local Address          Foreign Address        (state)
tcp4       0      0  192.168.88.103.54370   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54369   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54366   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54365   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54364   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54363   ti-in-f113.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54362   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54359   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54358   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54341   ti-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54340   tg-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54337   tg-in-f138.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54336   ti-in-f101.1e100.https SYN_SENT
tcp6       0      0  liuqidemacbook-p.54333 yorukamidzuki.49464    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54331 yorukamidzuki.49463    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54326 yorukamidzuki.49462    ESTABLISHED
tcp4       0      0  192.168.88.103.54320   tg-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54317   17.188.138.70.5223     ESTABLISHED
tcp4       0      0  192.168.88.103.54088   111.13.101.73.http     LAST_ACK
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53845   115.182.41.49.7080     ESTABLISHED
tcp4       0      0  192.168.88.103.53826   115.182.41.173.http    ESTABLISHED
tcp4       0      0  192.168.88.103.53793   151.101.76.133.https   ESTABLISHED
tcp4       0      0  192.168.88.103.53737   tk-in-f188.1e100.5228  ESTABLISHED
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:48:33)──> ls                                                ──(日, 723)─┘
netstat.txt
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:48:45)──> awk 'NR!=1{print > $6}' netstat.txt               ──(日, 723)─┘
awk: can't open file SYN_SENT
 input record number 2, file netstat.txt
 source line number 1
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:49:03)──> awk 'NR!=1{print > $5}' netstat.txt           2 ↵ ──(日, 723)─┘
awk: can't open file tsa01s07-in-f13..https
 input record number 2, file netstat.txt
 source line number 1
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:49:16)──> sudo awk 'NR!=1{print > $6}' netstat.txt      2 ↵ ──(日, 723)─┘
Password:
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:49:46)──> ls                                                ──(日, 723)─┘
CLOSE_WAIT  ESTABLISHED LAST_ACK    SYN_SENT    netstat.txt
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:49:49)──> cat ESTABLISHED                                   ──(日, 723)─┘
tcp6       0      0  liuqidemacbook-p.54333 yorukamidzuki.49464    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54331 yorukamidzuki.49463    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54326 yorukamidzuki.49462    ESTABLISHED
tcp4       0      0  192.168.88.103.54317   17.188.138.70.5223     ESTABLISHED
tcp4       0      0  192.168.88.103.53845   115.182.41.49.7080     ESTABLISHED
tcp4       0      0  192.168.88.103.53826   115.182.41.173.http    ESTABLISHED
tcp4       0      0  192.168.88.103.53793   151.101.76.133.https   ESTABLISHED
tcp4       0      0  192.168.88.103.53737   tk-in-f188.1e100.5228  ESTABLISHED
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:50:23)──> awk 'NR!=1{print $4, $5 > $6}' netstat.txt        ──(日, 723)─┘
awk: can't open file SYN_SENT
 input record number 2, file netstat.txt
 source line number 1
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:50:57)──> sudo awk 'NR!=1{print $4, $5 > $6}' netstat.txt
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:51:03)──> ls                                                ──(日, 723)─┘
CLOSE_WAIT  ESTABLISHED LAST_ACK    SYN_SENT    netstat.txt
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:51:04)──> sudo awk 'NR!=1{if($6 ~ /TIME|ESTABLISHED/) print > "1.txt";    else if ($6 ~/LAST_ACK/) print > "2.txt";                                       else print > "3.txt"}' netstat.txt
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:52:57)──> ls                                                ──(日, 723)─┘
1.txt       3.txt       ESTABLISHED SYN_SENT
2.txt       CLOSE_WAIT  LAST_ACK    netstat.txt
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:52:58)──> cat 1.txt                                         ──(日, 723)─┘
tcp6       0      0  liuqidemacbook-p.54333 yorukamidzuki.49464    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54331 yorukamidzuki.49463    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54326 yorukamidzuki.49462    ESTABLISHED
tcp4       0      0  192.168.88.103.54317   17.188.138.70.5223     ESTABLISHED
tcp4       0      0  192.168.88.103.53845   115.182.41.49.7080     ESTABLISHED
tcp4       0      0  192.168.88.103.53826   115.182.41.173.http    ESTABLISHED
tcp4       0      0  192.168.88.103.53793   151.101.76.133.https   ESTABLISHED
tcp4       0      0  192.168.88.103.53737   tk-in-f188.1e100.5228  ESTABLISHED
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:53:06)──> cat 2.txt                                         ──(日, 723)─┘
tcp4       0      0  192.168.88.103.54088   111.13.101.73.http     LAST_ACK
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:53:09)──> cat 3.txt                                         ──(日, 723)─┘
tcp4       0      0  192.168.88.103.54370   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54369   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54366   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54365   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54364   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54363   ti-in-f113.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54362   ti-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54359   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54358   tsa01s07-in-f13..https SYN_SENT
tcp4       0      0  192.168.88.103.54341   ti-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54340   tg-in-f102.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54337   tg-in-f138.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54336   ti-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.54320   tg-in-f101.1e100.https SYN_SENT
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:53:12)──> awk 'NR!=1{a[$6]++;} END {for (i in a) print i ", "a[i];}' netstat.txt
SYN_SENT, 14
LAST_ACK, 1
CLOSE_WAIT, 3
ESTABLISHED, 8
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:54:09)──> ps aux | awk 'NR!=1{a[$1] += $6;} END {for(i in a) print i", "a[i]"KB";}'
root, 387252KB
_usbmuxd, 3440KB
_nsurlstoraged, 2780KB
_locationd, 9728KB
_gamecontrollerd, 3228KB
_www, 308KB
_mdnsresponder, 5416KB
_hidd, 4932KB
_appleevents, 3900KB
_iconservices, 3280KB
_captiveagent, 3732KB
_windowserver, 71980KB
_coreaudiod, 9200KB
kelele67, 4759964KB
_networkd, 7376KB
_distnote, 1788KB
_netbios, 2476KB
_datadetectors, 1324KB
_ctkd, 1868KB
_nsurlsessiond, 5536KB
_softwareupdate, 3640KB

┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:57:38)──> sudo vim score.txt                                ──(日, 723)─┘
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(11:57:59)──> cat score.txt                                     ──(日, 723)─┘
Marry   2143 78 84 77
Jack    2321 66 78 45
Tom     2122 48 77 71
Mike    2537 87 97 95
Bob     2415 40 57 62
┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(12:04:43)──> awk -f cal.awk score.txt                          ──(日, 723)─┘
NAME	NO.    MATH		ENGLISH    COMPUTER    TOTAL
----------------------------------------------------
Marry  2143     78       84       77      239
Jack   2321     66       78       45      189
Tom    2122     48       77       71      196
Mike   2537     87       97       95      279
Bob    2415     40       57       62      159
---------------------------------
  TOTAL:        319      393      350
AVERAGE:      63.80    78.60    70.00

┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(12:12:27)──> awk 'length>75' netstat.txt                       ──(日, 723)─┘
tcp6       0      0  liuqidemacbook-p.54333 yorukamidzuki.49464    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54331 yorukamidzuki.49463    ESTABLISHED
tcp6       0      0  liuqidemacbook-p.54326 yorukamidzuki.49462    ESTABLISHED
tcp4       0      0  192.168.88.103.54317   17.188.138.70.5223     ESTABLISHED
tcp4       0      0  192.168.88.103.53860   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53859   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53858   120.197.89.235.50000   CLOSE_WAIT
tcp4       0      0  192.168.88.103.53845   115.182.41.49.7080     ESTABLISHED
tcp4       0      0  192.168.88.103.53826   115.182.41.173.http    ESTABLISHED
tcp4       0      0  192.168.88.103.53793   151.101.76.133.https   ESTABLISHED
tcp4       0      0  192.168.88.103.53737   tk-in-f188.1e100.5228  ESTABLISHED

┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(12:15:10)──> netstat -ntu | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr
 217 0
   1 sockets
   1 Inode
   1 1c180813f93193ed
   1 1c180813f1ebfa3d
   1 1c180813eff64105
   1 1c180813eff6400d
   1 1c180813eff6308d
   1 1c180813eff62e9d
   1 1c180813efaf8f95
   1 1c180813ee57d3ed
   1 1c180813ec527abd
   1 1c180813eb5db105
   1 1c180813eb5db00d
   1 1c180813eb5dad25
   1 1c180813eb5da65d
   1 1c180813eb5da375
   1 1c180813eb5a627d
   1 1c180813eb58b6d5
   1 1c180813eb58aa3d
   1 1c180813eb56e8c5
   1 1c180813eb56e7cd
   1 1c180813eb5631fd
   1 1c180813eb56300d
   1 1c180813eb562f15
   1 1c180813eb562e1d
   1 1c180813eb562a3d
   1 1c180813eb562755
   1 1c180813eb562375
   1 1c180813eb562185
   1 1c180813eb5532f5
   1 1c180813eb0a0105

┌─(~/Desktop/Shell/AWK)────────────────────(kelele67@liuqideMacBook-Pro:s000)─┐
└─(12:15:28)──> seq 9 | sed 'H;g' | awk -v RS='' '{for(i=1;i<=NF;i++)printf("%dx%d=%d%s", i, NR, i*NR, i==NR?"\n":"\t")}'
1x1=1
1x2=2   2x2=4
1x3=3   2x3=6   3x3=9
1x4=4   2x4=8   3x4=12  4x4=16
1x5=5   2x5=10  3x5=15  4x5=20  5x5=25
1x6=6   2x6=12  3x6=18  4x6=24  5x6=30  6x6=36
1x7=7   2x7=14  3x7=21  4x7=28  5x7=35  6x7=42  7x7=49
1x8=8   2x8=16  3x8=24  4x8=32  5x8=40  6x8=48  7x8=56  8x8=64
1x9=9   2x9=18  3x9=27  4x9=36  5x9=45  6x9=54  7x9=63  8x9=72  9x9=81