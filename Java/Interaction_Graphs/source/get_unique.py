import os

unique = set()

fil = file("n=3/complete_graph.txt", "r")

for i in fil.readlines():
    inp = i.split()
    l = [int(i) for i in inp]
    # print l
    for i in l:
        unique.add(i)
    # try:
    #   if l[0]==1:
    #       for i in l:
    #           unique.add(i)
    # except :
    #   pass

for i in unique:
    print i
print '\nDistinct functions: ', len(unique)
