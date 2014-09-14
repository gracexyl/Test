#include <stdio.h>
#define MAX_CHAR 20

long Nimsum(long B, long x, long y);
int trans(long B, long x, long fx[MAX_CHAR]);
long vitrans(long B, long xf[MAX_CHAR], int xl);

int main() {
	int p, i;
	scanf("%d", &p);
	for(i = 0; i < p; i++) {
		long n, B, x, y;
		scanf("%ld%ld%ld%ld", &n, &B, &x, &y);
		printf("%ld %ld \n", n, Nimsum(B, x, y));
	}
	return 0;
}

long Nimsum(long B, long x, long y) {
	long xf[MAX_CHAR], yf[MAX_CHAR];
	int xl, yl;
	int i;

	xl = trans(B, x, xf);
	yl = trans(B, y, yf);
	if (xl < yl) {
		xl = yl;
	}

	for (i = 0; i < MAX_CHAR; i++) {
		xf[i] = (xf[i] + yf[i]) % B;
	}
	return vitrans(B, xf, xl);
}

int trans(long B, long x, long xf[MAX_CHAR]) {
	int i, j;
	for (i = 0; i < MAX_CHAR; i++) {
		if(x == 0) {
			break;
		} else {
			xf[i] = x % B;
			x /= B;
		}
	}
	for(j = i; j < MAX_CHAR; j++) {
		xf[j] = 0;
	}
	return i;
}

long vitrans(long B, long xf[MAX_CHAR], int xl) {
	int t = xf[xl], i;
	for (i = xl - 1; i >= 0; i--) {
		t = t * B + xf[i]; 
	}
	return t;
}
