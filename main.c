#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bingo_size 5
#define Bingo_size0 25

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checked[25];
int count = 0;

int initiate_bingo()					//빙고판을 설정할 때 빙고의 사이즈와 빙고판에서 가로축의 크기를 확인하여 바꾸어야 한다. 
{
	int bingo_num;
	int i;
	int BINGO[bingo_size];
	int BINGO0[bingo_size];
 
	printf("Enter the number of random numbers (<=25) : ");		// bingo판의 크기를 설정한다. 
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
		printf("\n");							//빙고판의 가로축에 있는 숫자의 개수를 5로 설정 
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
		printf("\n");							//빙고판의 가로축에 있는 숫자의 개수를 5로 설정 
		printf("%5d", BINGO0[i]);
		}
		printf("\n");
	
	
	return 0;

}


int print_bingo(int bing[5][5])			//빙고판의 현재 상황 출력 
{
	int i,j;
	
	for(i=0;i<bingo_size;i++){
		for(j=0;j<bingo_size;j++){
			if(bing[i][j] != 0){
				printf("%5d", bing[i][j]);
			}
			else{
				printf("error");
			}
		}
	}
	return 0;
}


int get_number(int turn)		//사용자에게 입력을 받는 것과 컴퓨터의 입력을 동시에 받음 
{
	int numb; 
	int i, retry;
	
	do { 
		retry = 0;
	
	if(turn==0){								//사용자에게 받는 입력 = 0
		printf("enter a number: \n"); 
    	scanf("%d", &numb);
    	
			if(numb < 1 || numb >25){
	 			retry=1;
				 };
				 
			for(i=0; i<count; i++){
				if(checked[i] == numb) {
					retry = 1;
					break;
				}
			}
		}
		
		else{							//컴퓨터의 입력 
			numb = rand() %25 +1;
		} 
		}while(retry==1);
	
	checked[numb++] = numb;
	if(turn == 0){
		printf("user choose %d \n", numb);
	}
	else{
		printf("computer choose %d \n", numb);
	}
	return numb;
}

int process_bingo(int bingo_board[5][5]){		//빙고판의 숫자 지우는 함수 

	int i, j, sum;
	
	for
}
int count_bingo()

int main(void)
{
	int numb;
	int user0, com0;
	
	initiate_bingo();
	

	return 0;
}
