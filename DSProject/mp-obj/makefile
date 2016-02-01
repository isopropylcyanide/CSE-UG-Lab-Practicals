all:	welcome call status exe

welcome:
	@echo -e Welcome to the compilation menu

call:

	@echo -e Please grant permission for the make scripts to work. Only once.
	@echo -e
	@echo -e These 5 scripts put the formed .o files into an obj folder in each folder
	@echo If the folder exists already these scripts ensure that error is caught.
	@echo -e
	@echo -e
	@ sudo chmod +x sort/exists
	@echo -e Permission granted for arrays
	@ sudo chmod +x linked/existl
	@echo -e Permission granted for linked lists
	@ sudo chmod +x stacks/existsta
	@echo -e Permission granted for stacks
	@ sudo chmod +x queues/existq
	@echo -e Permission granted for queues
	@ sudo  chmod +x trees/existbin
	@echo -e Permission granted for trees

	@echo -e
	@echo -e

	@echo -e


	@cd sort && make -f msort
	@echo -e
	@cd linked && make -f mlist
	@echo -e
	@cd stacks && make -f mstack
	@echo -e
	@cd queues && make -f mqueue
	@echo -e
	@cd trees && make -f mbin
	@echo -e
	@echo -e

status:
	@echo -e Compilation of project successful :D
	@echo -e


exe:
	gcc -Wall -L /home/aman/Desktop/mp/ -o  final2 endp.c sort/obj/*.o linked/obj/*.o stacks/obj/*.o  queues/obj/*.o trees/obj/*.o -lncurses

	echo -e
	echo -e The executable final is statically linked and has been created.
	echo -e
	echo -e Exiting the compile process
	echo -e
	echo -e The project is opening in a new terminal.
	echo -e
	@gnome-terminal -e ./final2

clean:
	@find -name "*.o" -exec rm {} \;
