#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pi;
	pi = fork();
	if (pi > 0) {
		sleep(10);
	} else if (pi == 0) {
		printf("Zombie Created...\n");
		exit(0);
	} else {
		printf("Cannot create...\n");
	}
	return 0;
}
