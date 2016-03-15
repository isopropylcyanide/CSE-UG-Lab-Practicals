
def waysCoinChange(A, N):
    """ Given N and inf coins of type M. Print ways to find change"""
    T = [[0 for i in xrange(N + 1)] for j in xrange(len(A) + 1)]
    for i in xrange(len(A)):
        T[i][0] = 1

    for i in xrange(1, len(A) + 1):
        for j in xrange(1, N + 1):
            if j >= A[i - 1]:
                T[i][j] = T[i - 1][j] + T[i][j - A[i - 1]]
            else:
                T[i][j] = T[i - 1][j]

    return T[len(A)][N]


def waysCoinChangeEff(A, N):
    """Space efficient"""
    W = [0 for i in xrange(N + 1)]
    W[0] = 1

    for i in xrange(len(A)):
        for j in xrange(1, N + 1):
            if j >= A[i]:
                W[j] += W[j - A[i]]
    return W[N]

if __name__ == '__main__':
    N, M = map(int, raw_input().split())
    A = map(int, raw_input().split())

    if N > 0:
        print waysCoinChangeEff(A, N)
    else:
        print 0
