#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HP 10
#define TIME_LIMIT 3

enum operator{ADD,SUB,MUL,MOD};

int operand_1,operand_2,score = 0,hp = MAX_HP,difficulty = 1;
enum operator opr;
time_t start,end;

void correct();
void wrong();
void get_question();
void set_answer(int);

int main(){
	int answer;
	srand(time(0));
	while(1){
		get_question();
		start = time(0);
		scanf("%d",&answer);
		end = time(0);
		set_answer(answer);
		difficulty *= 2;
	}
}

void correct(){
	if(hp < MAX_HP)hp++;
	score += 10;
}

void wrong(){
	printf("Wrong\n");
	hp--;
	if(hp == 0){
		printf("GAME OVER\n");
		exit(1);
	}
}

void get_question(){
	operand_1 = rand() % difficulty + 1;
	operand_2 = rand() % difficulty + 1;
	opr = rand() % 4;
	switch(opr){
		case ADD :
			printf("%d + %d = ",operand_1,operand_2);
			break;
		case SUB :
			printf("%d - %d = ",operand_1,operand_2);
			break;
		case MUL :
			printf("%d * %d = ",operand_1,operand_2);
			break;
		case MOD :
			printf("%d %% %d = ",operand_1,operand_2);
			break;
	}
}

void set_answer(int answer){
	if(end - start > TIME_LIMIT){
		printf("Timeout\n");
		wrong();
	}else{
		switch(opr){
			case ADD :
				(operand_1 + operand_2 == answer)? correct() : wrong();
				break;
			case SUB :
				(operand_1 - operand_2 == answer)? correct() : wrong();
				break;
			case MUL :
				(operand_1 * operand_2 == answer)? correct() : wrong();
				break;
			case MOD :
				(operand_1 % operand_2 == answer)? correct() : wrong();
				break;
		}
	}
	printf("Health : %d, Score : %d\n",hp,score);
}





