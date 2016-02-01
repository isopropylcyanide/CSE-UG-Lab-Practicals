from time import sleep
from collections import defaultdict


fil = file("n=3/pos_cyc.txt")

len_hash = defaultdict(int)
sets_hash = defaultdict(set)

for i in fil.readlines():
    inp = i.split()
    l = [int(i) for i in inp]

    # print l
    len_hash[l[0]] += 1
    # sets_hash[l[0]] = []

    set_functions = set()

    for i in l[1:]:
        sets_hash[l[0]].add(i)

for key, val in len_hash.iteritems():
    print '\nFunctions of length %d : %d\n' % (key, val),

print '\nTotal Functions: ', sum(len_hash.itervalues())

for key, val in sets_hash.iteritems():
    print '\n Length %d : %s\n -> %d' % (key, val, len(val))
