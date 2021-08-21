#!/bin/bash

if [[ $# -ne 2 ]];then
    echo "error!"
fi

Start=$1
End=$2

declare -a arr

function prime(){
    end=$1
    arr[1]=1
    for(( i=2; i<= $end; i++ ));do
        for(( j=$[ $i*$i ]; j<=$end; j=$j+$i ));do
            arr[$j]=1
        done
    done

}

prime $End


for (( k=0; k<=$End; k++ ));do
    if [[ -z ${arr[$k]} ]];then
        sum=$[$sum+$k]
    fi
done

echo $sum
