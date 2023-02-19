import os
import sys

if len(sys.argv) == 4:
    for i in range(0,int(sys.argv[1])):
        s = os.popen("ARG=\"`ruby -e \"puts ("+ sys.argv[3] +").to_a.shuffle.join(\' \')\"`\"; ./push_swap $ARG | wc -l| tr -d \" \"").read().split("\n")[0]
        if int(s) > int(sys.argv[2]):
            print(s + " -> [\033[91mERROR!\033[00m]")
        else:
            print(s+ " -> [\033[92mok\033[00m]")
else: print("ERROR")