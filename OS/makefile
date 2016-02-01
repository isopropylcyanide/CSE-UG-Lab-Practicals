#Makefile calls all other makefiles in the directory structure
#Prevents hassle of running individual files
TARGETS = all

all:
	@cd "10-12 Memory -Fit" && $(MAKE)
	@cd "10-19 Page Cache" && $(MAKE)
	@cd "11-17 File Allocation" && $(MAKE)
	@cd "11-9 Deadlock Avoidance" && $(MAKE)
	@cd "8-10 Exec" && $(MAKE)
	@cd "8-24 Signals" && $(MAKE)
	@cd "8-3 Forks" && $(MAKE)
	@cd "9-14 RIP-Threads" && $(MAKE)
	@cd "9-26 Mutex" && $(MAKE)
	@cd "9-7 Schedules" && $(MAKE)

clean:
	@cd "10-12 Memory -Fit" && $(MAKE) clean
	@cd "10-19 Page Cache" && $(MAKE) clean
	@cd "11-17 File Allocation" && $(MAKE) clean
	@cd "11-9 Deadlock Avoidance" && $(MAKE) clean
	@cd "8-10 Exec" && $(MAKE) clean
	@cd "8-24 Signals" && $(MAKE) clean
	@cd "8-3 Forks" && $(MAKE) clean
	@cd "9-14 RIP-Threads" && $(MAKE) clean
	@cd "9-26 Mutex" && $(MAKE) clean
	@cd "9-7 Schedules" && $(MAKE) clean
