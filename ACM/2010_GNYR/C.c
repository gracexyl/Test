#include <stdio.h>
#define Max_char 20000
#define Max_screen 80

int Caculate_len(int read[Max_char + 1], int wt[Max_char + 1], int B);
void PrintEncode(int wt[Max_char + 1], int i, FILE* f);
void PrintBite(int x, FILE* f);

int main() {
	int p, i, j;
	FILE* f = fopen("a.out", "w");

	scanf("%d", &p);
	for(i = 0; i < p; i++) {
		int n, B;
		int read[Max_char + 1], wt[Max_char + 1];
		char temp;
		scanf("%d%d", &n, &B);
		for (j = 0; j < 2 * B; ) {
			scanf("%c", &temp);
			if((temp > '9' && temp < 'A') || (temp < '0') || (temp > 'F')) {
				continue;
			}
			if(temp >= '0' && temp <= '9') {
				read[j] = temp - '0';
				j++;
			} else {
				read[j] = temp - 'A' + 10;
				j++;
			}
		} 
		j = Caculate_len(read, wt, B);

		fprintf(f, "%d %d\n", n, j/2);
		PrintEncode(wt, j, f);
		fprintf(f, "\n");
	}

	fclose(f);
	return 0;
}

int Caculate_len(int read[Max_char + 1], int wt[Max_char + 1], int B) {
	int i = 0, j, f1, f2, f3 = 0, f4 = 0, k = 0, l;
	int sum = 0;
	while (i < B) {
		j = i + 1;
		f1 = 0;
		f2 = 1;
		while(j < B && read[2*i] == read[2*j] && read[2*i + 1] == read[2*j + 1]) {
			f2++;
			if(f2 >= 16) {
				f1++;
				f2 -= 16;
			}
			j++;
			if( (f1*16 + f2) >= 130) {
				break;
			}
		}
		if(f2 > 2 || f1 > 0) {
			if(f4 > 0 || f3 > 0) {
				f4--;
				if(f4 < 0) {
					f4 += 16;
					f3--;
				}
				wt[sum++] = f3;
				wt[sum++] = f4;
			}
			for(l = k; l < i; l++) {
				wt[sum++] = read[2*l];
				wt[sum++] = read[2*l + 1];
			}

			f2 -= 3;
			if(f2 < 0) {
				f2 += 16;
				f1--;
			}
			wt[sum++] = f1 + 8;
			wt[sum++] = f2;
			wt[sum++] = read[2 * i];
			wt[sum++] = read[2 * i + 1];
			i = j;
			f3 = 0;
			f4 = 0;
			k = i; 
			continue;
		}
		f4++;
		if(f4 >= 16) {
			f3++;
			f4 -= 16;
		}
		if(f3 >= 8) {
			f4--;
			if(f4 < 0) {
				f4 += 16;
				f3--;
			}
			wt[sum++] = f3;
			wt[sum++] = f4;
			for(l = k; l <= i; l++) {
				wt[sum++] = read[2*l];
				wt[sum++] = read[2*l + 1];
			}
			i++;
			f3 = 0;
			f4 = 0;
			k = i; 
			continue;
		}
		i++;
	} 
	if(f4 > 0 || f3 > 0) {
		f4--;
		if(f4 < 0) {
			f4 += 16;
			f3--;
		}
		wt[sum++] = f3;
		wt[sum++] = f4;
	}
	for(l = k; l < i; l++) {
		wt[sum++] = read[2*l];
		wt[sum++] = read[2*l + 1];
	}
	return sum;
}

void PrintEncode(int wt[Max_char + 1], int B, FILE * f) {
	int i = 0;
	for (i = 0; i < B; i++) {
		if(i != 0 && i % Max_screen == 0) {
			fprintf(f, "\n");
		}
		PrintBite(wt[i], f);
	}
}

void PrintBite(int x, FILE * f) {
	if (x < 10) {
		fprintf(f, "%c", '0' + x);
	} else {
		int y = x - 10;
		fprintf(f, "%c", 'A' + y);
	}
}

