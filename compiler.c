#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen_c(char* out) {
	FILE* fptr = fopen(out, "w");
	if (fptr == NULL) {
		perror("Error opening file");
		exit(1);
	}

	char token[256]; 
	while (scanf("%s", token) != EOF) {
		//tokens are Dlang keywords
		if (!strcmp(token, "cin")) {
			fprintf(fptr, "#include ");
			continue;
		}
		if (!strcmp(token, "fn")) {
			fprintf(fptr, "void\n");
			continue;
		}
		if (!strcmp(token, "let")) {
			fprintf(fptr, "float\n");
			continue;
		}
		if (!strcmp(token, "us")) {
			fprintf(fptr, "unsigned\n");
			continue;
		}
		if (!strcmp(token, "b8")) {
			fprintf(fptr, "char\n");
			continue;
		}
		if (!strcmp(token, "b32")) {
			fprintf(fptr, "int\n");
			continue;
		}
		if (!strcmp(token, "b32f")) {
			fprintf(fptr, "float\n");
			continue;
		}
		if (!strcmp(token, "b64")) {
			fprintf(fptr, "long\n");
			continue;
		}
		if (!strcmp(token, "b64d")) {
			fprintf(fptr, "double\n");
			continue;
		}
		if (strstr(token, "std:") == token) {
			fprintf(fptr, "%s\n", token + 4);
			continue;
		}

		// tokens are just C keywords
		fprintf(fptr, "%s", token);
		if (token[0] == '#') {
			fprintf(fptr, " ");
			continue;
		}
		fprintf(fptr, "\n");
	}

	fclose(fptr);
}

int main(int argc, char** argv) {
	system("mkdir -p build/ && rm -rf build/*");

	gen_c("build/main.c");

	system("gcc -S -c build/main.c -o build/main.s");

	system("gcc -c build/main.s -o build/main.o");

	char command[256];
	snprintf(command, sizeof(command), "gcc build/main.o -o %s -lm", argv[1]);
	system(command);
}
