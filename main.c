#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bingo_size 100

int main()
{
	int bingo_num;
	int i;
	int BINGO[bingo_size];
 
	printf("Enter the number of random numbers (<=100) : ");	// bingo���� ũ�⸦ �����Ѵ�. 
	scanf("%d", &bingo_num);
	
	srand( (unsigned) time(NULL) );	
	
	for (i = 0; i < bingo_num; i++)
		{ 
		BINGO[i] = rand() % 100;	
		}

	for (i = 0; i < bingo_num; i++)
	{
	if (i % 5 == 0)				//�������� �����࿡ �ִ� ������ ������ 5�� ���� 
	printf("\n");
	printf("%5d", BINGO[i]);
	
	}
	printf("\n");
	
	return 0;

}




