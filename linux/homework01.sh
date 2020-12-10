#!/bin/bash

#daytime：一天内登录次数；monthtime：一月内登录次数
#hour：上次在线时长的小时数；min上次在线时长的分钟数
daytime=$(last -s today | grep `whoami` | wc -l)
monthtime=$(last | grep `whoami` | wc -l)
hour=$(last | grep liuq | head -n 2 | tail -n 1  | cut -d '(' -f 2 | cut -d ')' -f 1 | cut -d ':' -f 1)
min=$(last | grep liuq | head -n 2 | tail -n 1  | cut -d '(' -f 2 | cut -d ')' -f 1 | cut -d ':' -f 2)

#以字符画的形式显示文字“welcome back”，并加上彩虹特效
figlet welcom back | lolcat

#下载和显示当地天气
curl -s wttr.in/beijing\?0 | tail -n 6

#显示用户名和登录信息，并加上彩虹特效
echo -e "\n你好，`whoami`！\n今日登录：${daytime}次\t本月登录：${monthtime}次\t上次在线时长：${hour}时${min}分" | lolcat

#在字符画中显示格言，并加上彩虹特效
#fortune -e people | cowsay -W 60 -f stegosaurus  | lolcat   


