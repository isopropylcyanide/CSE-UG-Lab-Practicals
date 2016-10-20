"""
Karl Pearson method:
    Formula: (ai - amean) * (bi - bmean) / (n * varA * varB)
"""


class correlation:

    def __init__(self):
        self.A = []
        self.B = []
        self.n = 0

    def getMean(self, A):
        return sum(A) / self.n

    def getVariance(self, A, mA):
        return sum([pow(i - mA, 2) for i in A]) / self.n

    def calculateCorrelation(self):
        meanA = self.getMean(self.A)
        meanB = self.getMean(self.B)
        varA = self.getVariance(self.A, meanA)
        varB = self.getVariance(self.B, meanB)
        print '\tMean A: ', '{:15.4f}'.format(meanA)
        print '\tMean B: ', '{:15.4f}'.format(meanB)
        print '\tVariance A: ', '{:12.4f}'.format(varA)
        print '\tVariance B: ', '{:12.4f}'.format(varB)

        num = [(i - meanA) * (j - meanB) for i, j in zip(self.A, self.B)]
        return sum(num) / self.n / varA / varB

    def __str__(self):
        s = '\n\t' * 1 + "A" + '\t' * 2 + "B" + '\n'
        s += '*' * 30 + '\n'
        for i, j in zip(self.A, self.B):
            s += '{:12.4f}'.format(i) + '\t' + '{:12.4f}'.format(i) + '\n'
        s += '*' * 30 + '\n'
        return s


def readInput():
    inputFile = "kpInput"
    corel = correlation()
    try:
        f = file(inputFile, "r")
        for i in f.readlines():
            a, b = map(float, i.strip().split())
            corel.A.append(a)
            corel.B.append(b)
            corel.n += 1
    except IOError as e:
        print e.message()
    finally:
        f.close()
    return corel

if __name__ == '__main__':
    # Read user input
    corel = readInput()
    print corel
    corelAB = corel.calculateCorrelation()
    print '\n\tCorrelation: ', '{:1.12f}\n'.format(corelAB)
