#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

enum direction{LEFT = 'a',UP = 'w',RIGHT = 'd',DOWN = 's'};

struct character{
	int x;
	int y;
};

struct game{
	struct character player;
	char map[MAP_WIDTH][MAP_HEIGHT];
};

struct game* create_game(int,int);
void move(struct game*,enum direction);
void print_map(struct game*);

int main(){
	char dir;
	struct game *g = create_game(3,3);
	while(1){
		scanf("%c",&dir);
		move(g,dir);
		print_map(g);
	}
}

struct game* create_game(int x,int y){
	struct game *g = malloc(sizeof(struct game));
	g->player.x = x;
	g->player.y = y;
	memset(g->map,' ',MAP_WIDTH * MAP_HEIGHT);
	for(int i = 0;i < MAP_WIDTH;i++){
		for(int j = 0;j < MAP_HEIGHT;j++){
			if(i == 0 || i == MAP_WIDTH - 1 || j == 0 || j == MAP_HEIGHT - 1){
				g->map[i][j] = 'O';
			}
		}
	}
	for(int i = 0;i < 20;i++){
		int r1,r2;
		r1 = rand() % (MAP_WIDTH - 2) + 1;
		r2 = rand() % (MAP_HEIGHT - 2) + 1;
		g->map[r1][r2] = 'X';
	}
	g->map[x][y] = 'o';
	return g;
}

void move(struct game *g,enum direction dir){
	g->map[g->player.x][g->player.y] = ' ';
	switch(dir){
		case LEFT :
			if(g->map[g->player.x - 1][g->player.y] == ' '){
				g->player.x--;
			}else if(g->map[g->player.x - 1][g->player.y] == 'X'){
				if(g->map[g->player.x - 2][g->player.y] == ' '){
					g->player.x--;
					g->map[g->player.x - 1][g->player.y] = 'X';
				}
			}
			break;
		case UP :
			if(g->map[g->player.x][g->player.y - 1] == ' '){
				g->player.y--;
			}else if(g->map[g->player.x][g->player.y - 1] == 'X'){
				if(g->map[g->player.x][g->player.y - 2] == ' '){
					g->player.y--;
					g->map[g->player.x][g->player.y - 1] = 'X';
				}
			}
			break;
		case RIGHT :
			if(g->map[g->player.x + 1][g->player.y] == ' '){
				g->player.x++;
			}else if(g->map[g->player.x + 1][g->player.y] == 'X'){
				if(g->map[g->player.x + 2][g->player.y] == ' '){
					g->player.x++;
					g->map[g->player.x + 1][g->player.y] = 'X';
				}
			}
			break;
		case DOWN :
			if(g->map[g->player.x][g->player.y + 1] == ' '){
				g->player.y++;
			}else if(g->map[g->player.x][g->player.y + 1] == 'X'){
				if(g->map[g->player.x][g->player.y + 2] == ' '){
					g->player.y++;
					g->map[g->player.x][g->player.y + 1] = 'X';
				}
			}
			break;
	}
	g->map[g->player.x][g->player.y] = 'o';
}

void print_map(struct game *g){
	printf("\033[H\033[J");
	for(int i = 0;i < MAP_HEIGHT;i++){
		for(int j = 0;j < MAP_WIDTH;j++){
			printf("%c ",g->map[j][i]);
		}
		printf("\n");
	}
}













