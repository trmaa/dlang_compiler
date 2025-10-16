#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("\e[1;31mUsage: %s <src> <out>\e[31;0m\n", argv[0]);
		exit(1);
	}

	char cmd[256];
	snprintf(cmd, sizeof(cmd), "dtokenizer temp.d < %s", argv[1]);
	system(cmd);

	snprintf(cmd, sizeof(cmd), "dcompiler %s < temp.d", argv[2]);
	system(cmd);

	system("rm temp.d");

	exit(0);
}
