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
		if (strstr(include, "(") != NULL) {
			char* paren_pos = strchr(include, '(');
			if (paren_pos != NULL) {
				int func_len = paren_pos - include;
				fprintf(fptr, "%.*s(\n", func_len, include);

				if (strstr(paren_pos+1, "*") == NULL) {
					fprintf(fptr, "%s \n", paren_pos+1);
					continue;
				}
				if (strstr(paren_pos+1, "&") == NULL) {
					fprintf(fptr, "%s \n", paren_pos+1);
					continue;
				}
			}
		}
		if (strstr(include, "*") != NULL) {
			char* paren_pos = strchr(include, '*');
			if (paren_pos != NULL) {
				int func_len = paren_pos - include;
				fprintf(fptr, "%.*s * %s\n", func_len, include, paren_pos + 1);
				continue;
			}
		}
		if (strstr(include, "&") != NULL) {
			char* paren_pos = strchr(include, '&');
			if (paren_pos != NULL) {
				int func_len = paren_pos - include;
				fprintf(fptr, "%.*s & %s\n", func_len, include, paren_pos + 1);
				continue;
			}
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
