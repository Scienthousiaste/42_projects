#!/bin/bash

x="x"
for i in {1..200}
do
	./ft_ssl md5 -s $x > res_1
	md5 -s $x > res_2
	res_diff_string=$(diff res_1 res_2)
	len=${#res_diff_string}
	if [ $len -gt 0 ]
	then
		echo "Iteration $i"
		echo "Diff on strings"
		echo $res_diff_string
	fi
	
	echo $x > fileX
	./ft_ssl md5 fileX > res_3
	md5 fileX > res_4
	res_diff_files=$(diff res_3 res_4)
	len_files=${#res_diff_files}
	if [ $len_files -gt 0 ]
	then
		echo "Iteration $i"
		echo "Diff on files"
		echo $res_diff_files
		echo $len_files
	fi

	if [ 0 -eq 1 ]
	then	
		echo $x | ./ft_ssl md5 -p > res_5
		echo $x | md5 -p > res_6
		res_diff_stdin=$(diff res_5 res_6)
		len_stdin=${#res_diff_stdin}
		if [ $len_stdin -gt 0 ]
		then
			echo "diff on stdin"
			echo $res_diff_stdin
		fi
	fi
	x+="X"
done
rm fileX
rm res_*

