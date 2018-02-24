#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("usage: ./bf filename\n");
		return 0;
	}

	// read file
	char *program = (char *) calloc(10, sizeof(char));
	int fi = 0;
	int size = 10;

	FILE *fp;
	fp = fopen(argv[1],"r");

	if (fp == NULL) {
		printf("Cannot open file\n");
		exit(-1);
	}

	FILE *fout;
	fout = fopen(strcat(argv[1], ".c"), "w");

	fprintf(fout, "#include <stdio.h>\n");
	fprintf(fout, "#include <stdlib.h>\n");
	fprintf(fout, "int main() {\n");
	fprintf(fout, "char *data = (char *) calloc(30000, sizeof(char));\n");
	fprintf(fout, "char *p = data;\n");

	char ch;

	while ((ch = fgetc(fp)) != EOF) {
		switch (ch) {
			case '>':
				fprintf(fout, "++p;\n");
				break;
			case '<':
				fprintf(fout, "--p;\n");
				break;
			case '+':
				fprintf(fout, "++*p;\n");
				break;
			case '-':
				fprintf(fout, "--*p;\n");
				break;
			case '.':
				fprintf(fout, "putchar(*p);\n");
				break;
			case ',':
				fprintf(fout, "*p = getchar();\n");
				break;
			case '[':
				fprintf(fout, "while (*p) {\n");
				break;
			case ']':
				fprintf(fout, "}\n");
				break;
			default:
				break;
		}
	}

	fprintf(fout, "}\n");

	fclose(fp);
	fclose(fout);
	free(fp);
	free(fout);
	free(program);

	return 0;
}