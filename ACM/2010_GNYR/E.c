#include <stdio.h>
#include <stdlib.h>
#define N 64
#define D 10
#define K 3
#define X 10000

void HighAdd(int x[K], int x1[K], int x2[K]);
void HighPrint(int x[K]);

int main() {
	int p, i;
	scanf("%d", &p);
	for(i = 0; i < p; i++) {
		int x[N + 1][D][K];
		int j,k;
		x[1][0][0] = 1;
		x[1][0][1] = 0;
		x[1][0][2] = 0;

		for(j = 1; j < D; j++) {
			x[1][j][0] = x[1][j - 1][0] + 1;
			x[1][j][1] = 0;
			x[1][j][2] = 0; 
		}
		int num,n;
		scanf("%d%d", &num, &n);
		for(j = 2; j <= n; j++) {
			x[j][0][0] = 1;
			x[j][0][1] = 0;
			x[j][0][2] = 0;
			for(k = 1; k < D; k++) {
				x[j][k][0] = 0;
				HighAdd(x[j][k], x[j][k-1], x[j-1][k]);
			}
		}
		printf("%d ", num);
		HighPrint(x[n][D-1]);
	}
	return 0;
}

void HighAdd(int x[K], int x1[K], int x2[K]) {
	x[0] = x1[0] + x2[0];
	x[1] = x1[1] + x2[1] + x[0] / X;
	x[0] = x[0] % X;
	x[2] = x1[2] + x2[2] + x[1] / X;
	x[1] = x[1] % X;
}

void HighPrint(int x[K]) {
	if(x[2] == 0 && x[1] == 0) {
		printf("%d \n", x[0]);
	} else if(x[2] == 0) {
		printf("%d%04d \n", x[1], x[0]);
	} else {
		printf("%d%04d%04d \n", x[2], x[1], x[0]);
	} 
}