"""
Your algorithms have become so good at predicting the market that you now know
what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the
next N days.Each day, you can either buy one share of WOT, sell any number of
 shares of WOT that you own, or not make any transaction at all. What is the
 maximum profit you can obtain with an optimum trading strategy?
"""


def maxStockLin(A, N):
    profit = 0
    currMax = A[-1]
    for i in xrange(len(A) - 1, -1, -1):
        if A[i] >= currMax:
            currMax = A[i]
        profit += currMax - A[i]

    return profit


def maxStockBrute(A, N):
    def maxStockUtil(day, curProf, curStock):
        if day == len(A) - 1:
            # sell baby as price is never negative
            return curProf + curStock * A[day]

        # for all other days, either do nothing, buy or sell
        doNothProfit = maxStockUtil(day + 1, curProf, curStock)
        buyProfit = maxStockUtil(day + 1, curProf - A[day], curStock + 1)
        sellProfit = 0
        if curStock > 0:
            sellProfit = maxStockUtil(day + 1, curProf + curStock * A[day], 0)

        return max(doNothProfit, buyProfit, sellProfit)

    return maxStockUtil(0, 0, 0)

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()O
        A = map(int, raw_input().split())
        print maxStockLin(A, N)
