#ifndef _PSTAT_H_
#define _PSTAT_H_

struct rusage{
	uint cputime;
};

enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
struct pstat{
	int pid;
	enum procstate state;
	int readytime;
	uint64 size;
	int ppid;
	char name[16];
	int priority;
};

#endif
