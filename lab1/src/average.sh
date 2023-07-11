#! /bin/bash
sum=0
count=0
average=0
exec 0< "$1" 
while read line
do
	let "sum=sum + $line"
	let "count=count+1"
done
echo "Summa= $sum"
echo "Count=$count"
let "average=sum/$count"
echo "Average=$average"
