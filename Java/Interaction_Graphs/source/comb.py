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

if __name__ == '__main__':
    # all_comb()  # Generates all combinations (brute force)
    # print '1 9'
    # negative()			#Generates all smart combinations for positive matches
    # positive()		#Generates all smart combinations for negative matches

    # print '26355 61535 9 60 8'	#Generates a single n=4 match
    # print '22 24 30 36'  # Generates a single n=3 match
    #
