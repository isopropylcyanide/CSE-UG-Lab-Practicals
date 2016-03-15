import os

unique = set()

fil = file("only_Pos/pos_only_sets.txt", "r")

lis = []
for i in fil.readlines():
    inp = i.split()
    l = [int(i) for i in inp]
    lis.append(l[0])

print lis
