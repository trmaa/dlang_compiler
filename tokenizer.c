#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	FILE* fptr = fopen(argv[1], "w");

	char include[256];
	while (scanf("%s", include) != EOF) {
		if (!strcmp(include, "cin")) {
			fprintf(fptr, "%s ", include);
			continue;
		}
		if (strcmp(include, "inc")) {
			fprintf(fptr, "%s\n", include);
			continue;
		}

		scanf(" \"%255[^\"]\"", include);
		FILE* inc = fopen(include, "r");		

		char ch;
		while ((ch = fgetc(inc)) != EOF) {
			fputc(ch, fptr);
		}

		fclose(inc);
	}

	fclose(fptr);
}
