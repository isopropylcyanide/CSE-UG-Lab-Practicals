class Solution:
    # @param A : integer
    # @return a strings

    def countAndSay(self, n):
        if n <= 0:
            return None

        A, i = "1", 1
        while i < n:
            count, new = 1, []
            for j in xrange(1, len(A)):
                if A[j] == A[j - 1]:
                    count += 1
                else:
                    new.append(count)
                    new.append(A[j - 1])
                    count = 1

            new.append(count)
            new.append(A[len(A) - 1])
            A = ''.join([str(k) for k in new])
            i += 1

        return A


def main():
    n = input()
    s = Solution()
    print s.countAndSay(n)


if __name__ == '__main__':
    main()
