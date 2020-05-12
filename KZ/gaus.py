#!/usr/bin/python3
import math
import sys


def print_usage():
    print("Usage: " + sys.argv[0] + " n s")

def calc(x,y,s):
    return (1/((2 * math.pi * (s**2)))) * math.e**(-(((x**2) + (y**2))/(2*(s**2))))

def print_matrix(n,s):
    y = -n+(math.ceil(n/2))
    while y <= n-(math.ceil(n/2)):
        x = -n+(math.ceil(n/2));
        while x <= n-(math.ceil(n/2)):
            print("%.3f" % calc(x,y,s),"\t", end = '')
            x += 1
        y += 1
        print("\n")

def main(argv):
    if(len(argv) < 2):
        print_usage()
        exit()
    print_matrix(int(argv[0]),float(argv[1]))

if __name__ == "__main__":
   main(sys.argv[1:])