#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bingo_size 25

int initiate_bingo()											//빙고판을 설정할 때 빙고의 사이즈와 빙고판에서 가로축의 크기를 확인하여 바꾸어야 한다. 
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


int print_bingo()

int get_number_byMe()
{
	int x[25]; 
	int i, j;
	
	while { 
    printf("enter a number: \n"); 
    scanf("%d", &x[i]); 
    if (i >=0 && i<= 24)
	{ 
	 	for(i=0; i<25; i++) { 
	 		for(j=0;j<i;j++){
    			if(x[i] == x[j]) {
     			printf("It is overlapped number.\n");
    			}
    		}
		}
	}
	if else 
	{ 
      	printf("Wrong number. Enter a number: \n"); 
    } 
	} 
	
	return 0;
}
int get_number_byCom()
int process_bingo()
int count_bingo()




