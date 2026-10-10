#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[]){
	printf("initial priority: %d\n", getpriority());
	setpriority(20);
	printf("After setpriority(20): %d\n", getpriority());
	exit(0);
}
