#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bingo_size 25

int main()											//�������� ������ �� ������ ������� �����ǿ��� �������� ũ�⸦ Ȯ���Ͽ� �ٲپ�� �Ѵ�. 
{
	int bingo_num;
	int i;
	int BINGO[bingo_size];
	int BINGO0[bingo_size];
 
	printf("Enter the number of random numbers (<=25) : ");		// bingo���� ũ�⸦ �����Ѵ�. 
	scanf("%d", &bingo_num);
	
	srand( (unsigned) time(NULL) );	
	
	for (i = 0; i < bingo_num; i++)				//user's bingo
		{ 
		BINGO[i] = rand() % 25;	
		}
	
		printf("your bingo is:\n");			
		for (i = 0; i < bingo_num; i++)
		{
		if (i % 5 == 0)
		printf("\n");							//�������� �����࿡ �ִ� ������ ������ 5�� ���� 
		printf("%5d", BINGO[i]);
		}
		printf("\n");
	
	
	for (i = 0; i < bingo_num; i++)				//computer's bingo
		{ 
		BINGO0[i] = rand() % 25;	
		}
	
		printf("computer's bingo is:\n");	
		for (i = 0; i < bingo_num; i++)
		{
		if (i % 5 == 0)
		printf("\n");							//�������� �����࿡ �ִ� ������ ������ 5�� ���� 
		printf("%5d", BINGO0[i]);
		}
		printf("\n");
	
	
	return 0;

}




