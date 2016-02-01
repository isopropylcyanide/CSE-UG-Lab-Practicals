from math import ceil,sqrt

def coprime(a,b):
	fact_lis=[(i,a/i) for i in xrange(1,int(ceil(sqrt(a)))+1) if a%i ==0 ]
	my_fact=set()
	for i,j in fact_lis:
		my_fact.add(i)
		my_fact.add(j)

	for fact in my_fact:
		if b%fact==0 and fact!=1:
			return False

	return True

def compute_d(e,z,max_elem):
	d,count=1,True

	while count:
		d+=1
		if pow(e,d,z) == 1:
			break
	return d

def encrypt(text,e,n=None):
	enc=pow(text,e,n)
	print '\nEncrypted %d as %d'%(text,enc)
	return enc

def decrypt(text,d,n=None):
	print 'Decrypted %d as %d\n'%(text,pow(text,d,n))

def main():

	a,b = map(int,raw_input("\nEnter two space separated integers: ").split())

	assert coprime(a,b)==True

	n,z ,e = a*b,(a-1)*(b-1), 7
	print 'N: ',n
	print 'Z: ',z
	print 'E: ',e

	d=compute_d(e,z,max(e,z))

	print 'Public Key : (%d,%d)'%(e,n)
	print 'Private Key : (%d,%d)\n'%(d,n)

	while 1:
		text=input("Enter plain text: ");
		enc=encrypt(text,e,n)
		decrypt(enc,d,n)


if __name__ == '__main__':
	main()