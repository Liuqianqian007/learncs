#!/bin/bash


function _func_() {
    if [[ -z $2 ]]; then
        echo variable 2 not exist
    else
        echo $1:$2
    fi

    for (( i=$1; i<$2; i++ )); do
        sum=$[$sum+$i]
        echo $sum
    done

    while [[ $sum -lt 66 ]];do
        sum=$[$sum+66]
    done

    echo sum=$sum

    case $sum in
        55)
            echo hi
        ;;
        75)
            echo hello
        ;;
    esac
    
    array=(one two three)

    for(( j=0; j<3; j++ )); do
        array+=($j)
    done
    
    array[8]=end
    unset array[0]

    for a in ${array[*]};do
        echo value=$a
    done

    for a in ${!array[*]};do
        echo index=$a
    done
    
    #set -x
    for (( i=0; i<=8; i++ ));do
        echo ${array[$i]}
    done
    #set +x

    return
}

read v1 v2

_func_ $v1 $v2
