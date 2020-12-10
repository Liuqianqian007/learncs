#!/bin/bash

if [[ $# -ne 2  ]];then
    echo "ERROR"
fi

Start=$1
End=$2

sum=0

function init_prime(){
    local end=$1
    local i
    Prime[1]=1
    for ((i=2; i<=${end}; i++));do
        for ((j=$[ $i * $i ]; j<=${end}; j+=i));do
            Prime[$j]=1
        done
    done
}

init_prime $End

for ((i=${Start}; i<=${End}; i++));do
    if [[ ${Prime[$i]}x == x ]];then
        sum=$[ ${sum}+$i ]
    fi
done

echo ${sum}

