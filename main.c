#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bingo_SIZE	2

void printMatrix(int SIZE[bingo_SIZE][bingo_SIZE])
{	
	int i, j;
	
	for (i=0; i<bingo_SIZE; i++) {
		for(j=0; j<bingo_SIZE; j++) {
			printf("%d", SIZE[i][j]);
		}
		printf("\n");
	}
		return;
}

int	main(void){				//빙고판 만드는 함 수 
	int A,i;	
	int SIZE[bingo_SIZE][bingo_SIZE];
	
	
	A= bingo_SIZE*bingo_SIZE;
	printf("%d 개의 숫자를 입력하시오: ", A);
	
	scanf("%d ", &SIZE[i][i]);
	
	printf("User Bingo Board\n");
	printMatrix(SIZE);
	
	return;
}


