#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ROAD_WIDTH 5
#define ROAD_LENGTH 12

enum status{ALIVE,DEAD};
enum direction{LEFT = 'a',RIGHT = 'd'};

struct character{
	int x;
	int y;
	enum status status;
};

struct character player = {1,ROAD_LENGTH - 1,ALIVE},enemy_car = {3,0,ALIVE};
int level = 1,score = 0;

void* play(void*);
void enemy_play();
void print();

int main(){
	pthread_t t1;
	pthread_create(&t1,0,play,0);

	while(player.status == ALIVE){
		score += 10;
		enemy_play();
		print();
		usleep(5000000 / (10 + level));
	}
	printf("\nGAME OVER\n");

	return 0;
}

void* play(void *ptr){
	char dir;
	while(player.status == ALIVE){
		scanf("%c",&dir);
		switch(dir){
			case LEFT :
				if(player.x > 1)player.x--;
				break;
			case RIGHT :
				if(player.x < ROAD_WIDTH)player.x++;
				break;
		}
		print();
	}
}

void enemy_play(){
	if(enemy_car.x == player.x && enemy_car.y == player.y){
		player.status = DEAD;
	}

	if(enemy_car.y == ROAD_LENGTH - 1){
		enemy_car.y = 0;
		enemy_car.x = rand() % ROAD_WIDTH + 1;
		level++;
	}else{
		enemy_car.y++;
	}
}

void print(){
	printf("\033[H\033[J");
	printf("Score : %d,Level : %d\n",score,level);
	for(int i = 0;i < ROAD_LENGTH;i++){
		for(int j = 0;j < ROAD_WIDTH + 2;j++){
			if(j == 0 || j == ROAD_WIDTH + 1)printf("X");
			else if(j == player.x && i == player.y)printf("o");
			else if(j == enemy_car.x && i == enemy_car.y)printf("o");
			else printf(" ");
		}
		printf("\n");
	}
}

















