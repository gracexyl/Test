#include <stdio.h>
#define Max_char 10000
#define Max_screen 40

long Caculate_len(int read[Max_char + 1], int B);
void PrintDecode(int read[Max_char + 1], int B);
void PrintBite(int x);

int main() {
	int p, i, j;
	scanf("%d", &p);
	for(i = 0; i < p; i++) {
		int n, B;
		int read[Max_char + 1];
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
		printf("%d %ld\n", n, Caculate_len(read, B));
		PrintDecode(read, B);
		printf("\n");
	}
	return 0;
}

long Caculate_len(int read[Max_char + 1], int B) {
	int i = 0, j;
	long sum = 0;
	while (i < B) {
		if (read[2*i] >= 8 ) {
			sum += (read[2*i] - 8) * 16 + read[2*i + 1] + 3;
			i += 2;
			continue;
		}

		j = read[2*i] * 16 + read [2*i + 1] + 1;
		sum += j;
		i += j+1;
	} 
	return sum;
}

void PrintDecode(int read[Max_char + 1], int B) {
	int i = 0, j, k;
	long sum = 0;
	while (i < B) {
		if (read[2*i] >= 8 ) {
			j = (read[2*i] - 8) * 16 + read[2*i + 1] + 3;
			for(k = 0; k < j; k++) {
				if(sum % Max_screen == 0 && sum > 0) {
					printf("\n");
				}
				PrintBite(read[2*i + 2]);
				PrintBite(read[2*i + 3]);
				sum++;
			}
			i += 2;
			continue;
		}

		j = read[2*i] * 16 + read [2*i + 1] + 1;
		for(k = 0; k < j; k++) {
			if(sum % Max_screen == 0 && sum > 0) {
				printf("\n");
			}
			i++;
			sum++;
			PrintBite(read[2*i]);
			PrintBite(read[2*i + 1]);
		}
		i++;
	} 
}

void PrintBite(int x) {
	if (x < 10) {
		printf("%c", '0' + x);
	} else {
		int y = x - 10;
		printf("%c", 'A' + y);
	}
}