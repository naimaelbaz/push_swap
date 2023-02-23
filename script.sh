#!/bin/bash

GREEN="\033[92m"
RED="\033[91m"

while true
do
	numbers=$(seq -500 0 | sort -R | head -n 100000 | paste -sd" " -)
	output=$(./push_swap $numbers | ./checker $numbers)
	echo $numbers
	# if [ $output="OK" ]
	# then
	# 	echo -e "${GREEN}OK"
	# else
	# 	echo -e "${RED}KO Or ERROR"
	# fi
	# echo "<------------------->"
	sleep 0.1
done