#!/usr/bin/env python3
import os, filecmp

print("Binarka 1:")
binarka1 = input()
print("Binarka 2:")
binarka2 = input()
print("Generatorka:")
generatorka = input()

idx = 1
while True:
    os.system("./" + generatorka + " > input")
    os.system("./" + binarka1 + " < input > " + binarka1 + ".out")
    os.system("./" + binarka2 + " < input > " + binarka2 + ".out")

    cmp = filecmp.cmp(binarka1 + ".out", binarka2 + ".out")
    if cmp:
        print("ok " + str(idx))
    else:
        print("wrong")
        exit(0)

    idx = idx + 1
