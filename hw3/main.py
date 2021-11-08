#!/usr/bin/env python3

import sys
import container


def error_message1():
    print("incorrect command line!\n"
          "  Waited:\n"
          "     command -f infile outfile\n"
          "  Or:\n"
          "     command -n number outfile")


def error_message2():
    print("incorrect qualifier value!\n"
          "  Waited:\n"
          "     command -f infile outfile\n"
          "  Or:\n"
          "     command -n number outfile")


if __name__ == '__main__':
    if len(sys.argv) != 4:
        error_message1()
        exit(1)

    print("Start")
    c = container.Container()

    if sys.argv[1] == '-f':
        infile = open(sys.argv[2], 'r')
        c.input(infile)
        infile.close()
    elif sys.argv[1] == '-n':
        size = int(sys.argv[2])
        if size < 1 or size > 10000:
            print(f"incorrect number of figures = {size}. Set 0 < number <= 10000")
            exit(3)
        c.rnd_input(size)
    else:
        error_message2()
        exit(2)

    outfile = open(sys.argv[3], 'w')
    outfile.write("Filled container:\n")
    c.print(outfile)
    outfile.write("Sorted container:\n")
    c.sort()
    c.print(outfile)
    outfile.close()
    print("Stop")
