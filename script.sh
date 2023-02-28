#!/bin/bash
i=0
while true
do
numbers=`ruby -e "puts (-500..0).to_a.shuffle.join(' ')"`
output=$(./push_swap $numbers | ./checker $numbers)
((i+=1))
echo $output $i
echo '\n'
echo $numbers
done