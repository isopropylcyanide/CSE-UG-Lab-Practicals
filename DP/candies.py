"""
All the children sit in a line ( their
positions are fixed), and each  of them has a rating score according
to his or her performance in the class.  Alice wants to give at
least 1 candy to each child. If two children sit next to each
other, then the one with the higher rating must get more candies.
Alice wants to save money, so she needs to minimize the total
number of candies given to the children.
"""


def distSave(A, N):
    l = [1 for i in xrange(N)]
    r = [1 for i in xrange(N)]
    for i in xrange(N - 2, -1, -1):
        if A[i] > A[i + 1]:
            r[i] = r[i + 1] + 1

    for i in xrange(1, N):
        if A[i] > A[i - 1]:
            l[i] = l[i - 1] + 1
    return sum([max(l[i], r[i]) for i in xrange(N)])

if __name__ == '__main__':
    N = input()
    A = []
    for _ in xrange(N):
        A.append(input())

    print distSave(A, N)
