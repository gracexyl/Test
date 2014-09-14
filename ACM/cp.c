#include <stdio.h>
#include <string.h>
int main() {
	FILE * f1 = fopen("a.out", "r");
	FILE * f2 = fopen("c.out", "r");
	FILE * f3 = fopen("r.out", "w");
	char str1[100], str2[100];
	int i = 1;
	while(fgets(str1 ,100, f1) && fgets(str2, 100, f2)) {
		if(strcmp(str1, str2) != 0) {
			fprintf(f3, "Line : %d:\n%s\n%s\n", i, str1, str2);
		}
		i++;
	}
	fclose(f1);
	fclose(f2);
	return 0;
}