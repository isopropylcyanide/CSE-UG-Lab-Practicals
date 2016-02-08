class Solution:
    # @param A : integer
    # @param B : integer
    # @return an integer

    def uniquePaths(self, A, B):
        M = [[0 for i in xrange(B + 2)] for j in xrange(A + 2)]
        M[A][B + 1] = 1

        for r in xrange(A, 0, -1):
            for c in xrange(B, 0, -1):
                M[r][c] = M[r + 1][c] + M[r][c + 1]
        return M[1][1]


def main():
    a = input()
    b = input()
    c = Solution()
    print c.uniquePaths(a, b)

if __name__ == '__main__':
    main()

    #
