def main():
	n=int(raw_input())
	M=[[0 for i in range(n)] for j in range(n)]
	min_queen(1,M,n,M)


def min_queen(Q,M,n,GM):
	Q2=fill(Q,0,M,n,GM)
		print 'Found minimum Queen: ',Q
	else:
		print 'Couldnt find '

def fill(Q,count,M,n,GM):
	print '\nInitially Q: ',Q

	if Q==1:
		ini,inj=0,0
	else:
		flag=0
		for i in xrange(n):
			if flag==1:break
			for j in xrange(n):
				if M[i][j]==0:
					print 'First 0 found at : [',i,'][',j,']'
					ini,inj=i,j
					flag=1		
					break
	off=0
	print 'Before Marking ini: ',ini,' inj: ',inj

	for i in xrange(n):
		offj=0		
		for j in xrange(n):
			if (off==ini) or offj==0 or (abs(i-ini)==abs(j-inj)):
				if not GM[i][j]:
					print ' i: ',i,' j: ',j,' marking '
					M[i][j]=1
					count+=1
					GM[i][j]=1
				else:
					print ' i: ',i,' j: ',j,' already marked '
			offj+=1
		off+=1

	print 'Count in Q: ',Q,',count: ',count
	if count==n*n:
		print '\nReturning queen ',queen
		return count
	else:
		if Q!=n:
			Q+=1
			print 'Incr Q: ',Q
			fill(Q,count,M,n,GM)

if __name__=="__main__":
	main()




















