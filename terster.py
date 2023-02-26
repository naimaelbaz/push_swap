#!/usr/local/bin/python3
import os
import sys

if len(sys.argv) == 4:
    for i in range(0,int(sys.argv[1])):
        args = os.popen("ARG=\"`ruby -e \"puts ("+ sys.argv[3] +").to_a.shuffle.join(\' \')\"`\"; echo $ARG").read().split("\n")[0]
        
        res = os.popen("./push_swap  " + args + " | ./checker_Mac " +args).read().split("\n")[0]
        if res == "OK":
            s = os.popen("ARG=\"`ruby -e \"puts ("+ sys.argv[3] +").to_a.shuffle.join(\' \')\"`\"; ./push_swap $ARG | wc -l| tr -d \" \"").read().split("\n")[0]
            if int(s) > int(sys.argv[2]):
                print("[=> \033[92m"+ res +"\033[00m <=] "+"\033[95m"+ s + "\033[00m -> [\033[91mERROR!\033[00m]")
            else:
                print("[=> \033[92m"+ res +"\033[00m <=] "+ s + " -> [\033[92mok\033[00m]")
        else:
            print("[\033[91mERROR!: not sorted \033[00m]\n -> "+ args)

else: print("ERROR")