#include <stdio.h>
#define P 1002
#define TCT 8
#define SL 40
int main()
{
	int p;
	char coin[TCT][4] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"}; 
	char seq[SL+1];
	int n[P];
	int res[P][TCT];

	scanf("%d", &p);
	int i, j;
	for(i = 0; i < p; i++) {
		scanf("%d", &n[i]);
		scanf("%s", seq);
		for(j = 0; j < TCT; j++) {
			res[i][j] = 0;
		}
		for(j = 0; j + 2 < SL; j++) {
			if(seq[j] == coin[0][0] && seq[j+1] == coin[0][1] && seq[j+2] == coin[0][2]) {
				res[i][0]++;
			}
			if(seq[j] == coin[1][0] && seq[j+1] == coin[1][1] && seq[j+2] == coin[1][2]) {
				res[i][1]++;
			}
			if(seq[j] == coin[2][0] && seq[j+1] == coin[2][1] && seq[j+2] == coin[2][2]) {
				res[i][2]++;
			}
			if(seq[j] == coin[3][0] && seq[j+1] == coin[3][1] && seq[j+2] == coin[3][2]) {
				res[i][3]++;
			}
			if(seq[j] == coin[4][0] && seq[j+1] == coin[4][1] && seq[j+2] == coin[4][2]) {
				res[i][4]++;
			}
			if(seq[j] == coin[5][0] && seq[j+1] == coin[5][1] && seq[j+2] == coin[5][2]) {
				res[i][5]++;
			}
			if(seq[j] == coin[6][0] && seq[j+1] == coin[6][1] && seq[j+2] == coin[6][2]) {
				res[i][6]++;
			}
			if(seq[j] == coin[7][0] && seq[j+1] == coin[7][1] && seq[j+2] == coin[7][2]) {
				res[i][7]++;
			}
		}
	}

	for(i = 0; i < p; i++) {
		printf("%d ", n[i]);
		for( j = 0; j < TCT; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}