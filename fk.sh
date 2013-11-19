#!/bin/bash
# 提取出反馈报文的账户号，出错原因代码，应还款日期。

if [ $# -ne 1 ]
then
    echo "用法：fk.sh [反馈报文文件名]"
    exit 1
fi

echo -n 出错原因代码：
cat $1 | head -n 1 | cut -c96-97

echo -n 出错账户号：
cat $1 | tail -n-1 | cut -c85-124

echo -n 应还款日期：
cat $1 | tail -n-1 | cut -c197-204

i=1

while [ $i -lt 6 ]
do
    echo -n 出错代码$i：
    cat $1 | tail -n-1 | cut -c$((21+i*7))-$((27+i*7))
    i=$(($i+1))
done
