#! /bin/bash
file=numbers.txt
rm $file
touch $file
for i in {1..150}
do
	cat /dev/random | tr -dc '1-9' | head -c4 >>$file
	echo>>$file
done

