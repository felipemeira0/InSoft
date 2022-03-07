#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define QTY 2

int main() {
	int pipeDesc[QTY];
	char messages[QTY][20] = {"Hello world!", "from Pipe!"};
	char readMessage[20];
	int status;
	memset(readMessage, '\0', sizeof(char)*20);

	status = pipe(pipeDesc);

	if (status == -1) {
		printf("Error creating pipe...\n");
		return 1;
	}

	for (int i = 0; i < QTY; i++) {
		printf("Write message from pipe %d, result %s\n",i,messages[i]);
		write(pipeDesc[1], messages[i], sizeof(char) * 20);
		read(pipeDesc[0], readMessage, sizeof(char) * 20);
		printf("Read message from pipe %d, result %s\n",i,readMessage);
	}
}
