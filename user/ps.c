#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char **argv){
	struct pstat uproc[NPROC];
	int nprocs;
	int i;
	char *state;
	static char *states[] = {
		[SLEEPING]	"sleeping",
		[RUNNABLE]	"runnable",
		[RUNNING]	"running",
		[ZOMBIE]	"zombie"
	};
	nprocs = getprocs(uproc);
	if (nprocs <0)
		exit(-1);
	int now = uptime();
	printf("pid\tstate\t\tsize\tppid\tpriority\tname\n");
	for(i=0; i<nprocs; i++){
		state = states[uproc[i].state];
		printf("%d\t%s\t%d\t%d\t", uproc[i].pid, state,
			(int)uproc[i].size, uproc[i].ppid);
		if(uproc[i].state == RUNNABLE)
			printf("%d\t", now - uproc[i].readytime);
		else
			printf("-\t");
		printf("%d\t%s\n", uproc[i].priority, uproc[i].name);
	}
	exit(0);
}

