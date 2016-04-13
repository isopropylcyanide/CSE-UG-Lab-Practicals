import itertools
import sys

max_node = int(sys.argv[1])
max_comb = 2**(2**max_node)


def all_comb():
    def comb():
        for i in itertools.combinations(xrange(max_comb), max_node):
            yield i

    for i in comb():
        print ' '.join([str(k) for k in i])


def negative():
    def smart_comb():
        if max_node == 2:
            for i in xrange(6, max_comb):
                yield [1] + [i]

        elif max_node == 3:
            for i in xrange(7, max_comb):
                yield [1, 6] + [i]

        elif max_node == 4:
            for i in xrange(9, max_comb):
                yield [1, 6, 7] + [i]

        elif max_node == 5:
            for i in xrange(18, max_comb):
                yield [1, 6, 7, 9] + [i]

    for lis in smart_comb():
        print ' '.join([str(k) for k in lis])


def positive():
    def smart_comb():
        if max_node == 2:
            for i in xrange(6, max_comb):
                yield [1] + [i]

        elif max_node == 3:
            for i in xrange(30, max_comb):
                yield [22, 24] + [i]

        elif max_node == 4:
            for i in xrange(30, 36, max_comb):
                yield [22, 24] + [i]

        elif max_node == 5:
            for i in xrange(18, max_comb):
                yield [1, 6, 7, 9] + [i]

    for lis in smart_comb():
        print ' '.join([str(k) for k in lis])


def only_Pos_matrice_generate():
    fil = file("source/n=3/only_Pos/pos_only_sets.txt", "r")
    lis = []
    if fil is None:
        print 'Couldn\'t open file'
    # lis = [0,128,136,204,170,161,192,224,238,240,168,252,236,248,234,250,200,232,254,255]

    fil.close()
    for i in itertools.combinations(lis, 3):
        print ' '.join([str(i) for i in list(i)])


if __name__ == '__main__':
    # lis = [1, 6, 7, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 36, 37, 38, 39, 40]
    # for i in itertools.combinations(lis, 3):
    #     print ' '.join([str(i) for i in list(i)])
    # print '248 249 254'
    all_comb()  # Generates all combinations (brute force)
    # print '31 89 123'
    # print '80 120 220'
    # negative()			#Generates all smart combinations for positive matches
    # positive()		#Generates all smart combinations for negative matches

    # print '26355 61535 9 60 8'	#Generates a single n=4 match
    # print '22 24 30 36'  # Generates a single n=3 match
    #
