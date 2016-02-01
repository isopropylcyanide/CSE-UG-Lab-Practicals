import random
import subprocess
from commands import getstatusoutput as getout

max_line=10**2 +1
max_value=50

def set_testcase():
	try:
		fil = open("inp_fib",'w')
		for i in xrange(1,max_line):
			testcase = random.randrange(1,max_value)
			fil.write(str(testcase)+"\n")
	
	except IOError:
		print 'No such file'
	finally:
		fil.close()



def check_student_case():
	try:
		student_file = open("out",'r')
		correct_file = open("sout" ,'r')
		command_diff = str("diff -y --suppress-common-lines "+ \
					   str(student_file.name) + " " +str(correct_file.name) + \
					   " | grep ^ | wc -l")
		status,ans = getout(command_diff)
		ans = int(ans)
		if ans>100:ans = 100
		print 'Fibonacci Score for ',student_file.name + ' is : ', 100 - int(ans)

	except IOError,OSError:
		print 'Error Occured'
		
	finally:
		student_file.close()
		correct_file.close()


def create_student_output():
	try :
		student_code_file = open("student_code.sh")
		exec_string = "./" + student_code_file.name
		getout(exec_string)
		#Generates the student's out file to be compared 
	except :
		print 'Couldn\'t load student code'

	finally:
		student_code_file.close()

		

if __name__ == '__main__':
	# set_testcase()
	create_student_output()
	check_student_case()