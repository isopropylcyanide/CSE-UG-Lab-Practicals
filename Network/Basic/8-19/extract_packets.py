#Number of packets successfully received at the receiver.
#Format: Event-0 Time-1 Source-2 Destination-3 cbr-4 packet_size-5
#Plotting a graph

import os

fil=file("trace1.tr")
fout=file("graph.txt","w+")

total_received,inp=0,[]
from_1,from_2=0,0

print 'Specify size of the discrete interval: ',
size=input()
size_s=size

for i in fil.readlines():
	inp=i.split()
	if inp[0]=='r':
		if inp[2]=='0' and inp[3]=='2'  :from_1+=1
		elif inp[2]=='1' and inp[3]=='2':from_2+=1  
	 	elif inp[2]=='2' and inp[3]=='3':total_received+=1

	if inp[1]==str(size):
		new_entry=str(size)+' '+str(total_received)+'\n'
		fout.write(new_entry)
		size+=size_s

	elif inp[1]>str(size):
		size+=size_s
		
print '\n Total Packets at destination 3: ',total_received
print ' Total Packets at dest from 1  : ',from_1
print ' Total Packets at dest from 2  : ',from_2
fil.close()


