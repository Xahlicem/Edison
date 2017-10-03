#!/bin/bash
for ((i=0;i<400;i++))
do
 vol=`battery-voltage | grep Voltage`
 volA=( $vol )
 lev=`battery-voltage | grep level`
 levA=( $lev )
 s=${volA[1]}${volA[2]}${volA[2]}${volA[2]}${volA[3]}${volA[4]}${levA[1]}${levA[2]}${levA[2]}${levA[2]}${levA[2]}${levA[2]}${levA[2]}${levA[2]}${levA[3]}
 echo $s
 bin/ssd1306 0 $s
 sleep 15
done
