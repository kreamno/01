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

int user_bingo[5][5];
int com_bingo[5][5];

int initiate_bingo(){				//빙고판을 초기화 하는 함수
	srand((unsigned int)time(NULL));
	
	print_random_bingo((int*)user_bingo);
	print_random_bingo((int*)com_bingo);
}

int print_random_bingo(int board[bingo_size][bingo_size]){
	int i, j, k, random;
	int bingo0[Bingo_size0];
	
	srand((unsigned int)time(NULL));
	
	for(i=0;i<Bingo_size0;i++){
		random = rand() %25 +1;
		
		for(j=0;j<Bingo_size0;j++)
		{
			if (bingo0[j]  == random)
			{
				break;
			}
		}
		if(i==j)
		{
			bingo0[i++] = random;	
		}
	}
	
	k=0;
	
	for(i=0;i<bingo_size;i++){
		for(j=0;j<bingo_size;j++){
			board[i][j] = bingo0[k++];
		}
	}
	for(i=0;i<bingo_size;i++){
		for(j=0;j<bingo_size;j++){
			printf("%5d", board[i][j]);
		}
	}	printf("\n\n");
}


void print_bingo(int bing[bingo_size][bingo_size])			//빙고판의 현재 상황 출력 
{
	int i,j;
	
	for(i=0;i<bingo_size;i++){
		for(j=0;j<bingo_size;j++){
			printf("%7d\n", bing[i][j]);
		}
		printf("\n\n");
	}
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
				 }
		}	
	else{							//컴퓨터의 입력 
			numb = rand() %25 +1;
		} 
		
	if(retry==0){		
			for(i=0; i<count; i++){
				if(checked[i] == numb) {
					retry = 1;
					break;
				}
			}
		}
	}while(retry==1);
	
	checked[count++] = numb;
	
	if(turn == 0){
		printf("user choose %d \n", numb);
	}
	else{
		printf("computer choose %d \n", numb);
	}
	return numb;
}

int process_bingo(int bingo_board[5][5], int numb){		//입력받은 수를 원래 수를 지우고  -1로 만드는 함수 
	int i,j;
	
	for(j=0;j<bingo_size;j++){
		for(i=0;i<bingo_size;i++){
			if(bingo_board[j][i] == numb){
				bingo_board[j][i] = -1;
			}
		}
	} 
	
}

int count_bingo(int bingo_board[5][5]){		//빙고 확인 함수 

	int i, j, sum;
	
	for(j=0;j<bingo_size;j++){		// 가로 축에 대한 확인 
		sum = 0;
		
		for(i=0;i<bingo_size;i++) {
		sum += bingo_board[j][i];
		}
		
		if(sum==-5){
			return 1;
		}
	}
	
	for	(i=0;i<bingo_size;i++){		//세로 축에 대한 확인 
		sum = 0;
		
		for(j=0;j<bingo_size;j++){
			sum += bingo_board[j][i];
		}
		if(sum==-5){
			return 1;
		}
	}
	
	sum = 0;
	
	for(i=0;i<bingo_size;i++){		//대각선에 대한 확인 
		sum += bingo_board[i][i];
	}
	if(sum==-5){
		return 1;
	}
	
	sum=0;
	
	for(i=0;i<bingo_size;i++){		//대각선에 대한 확인 
		sum += bingo_board[i][bingo_size - i - 1];
	}
	if(sum==-5){
		return 1;
	}
	return 0;
}
	
	
int main(void)
{
	int numb, win;
	int user_win, com_win;
	
	initiate_bingo();
	
	do{
		print_random_bingo(user_bingo);
		
		numb = get_number(0);			//사용자 숫자 선택 
		process_bingo(user_bingo, numb);
		process_bingo(com_bingo, numb);
		
		numb= get_number(1);			//컴퓨터 숫자 선택 
		process_bingo(user_bingo, numb);
		process_bingo(com_bingo, numb);
		
		user_win = count_bingo(user_bingo);
		com_win = count_bingo(com_bingo);
		
		}while((user_win==0)&&(com_win==0));
		
		printf("사용자 빙고판 \n");
		print_random_bingo(user_bingo);
		
		printf("컴퓨터 빙고판 \n");
		print_random_bingo(com_bingo);
		
				if(user_win = 1){			// 승자 출력 
					printf("user wins\n");
				}
				if(com_win = 1){
					printf("com wins\n");
				}
				else{
				printf("no winner\n");
			}
	

	return 0;
}
