#include <stdio.h>

enum symbol{SYM_X = 'X',SYM_O = 'O'};
enum status{X_WON = 1,O_WON = -1,NOTHING = 0,DRAW = 2};

struct tictactoe{
	char table[3][3];
};

struct tictactoe create_game();
int play(struct tictactoe*,int,int,enum symbol);
enum status get_status(const struct tictactoe);
void print_game(const struct tictactoe);

int main(){
	int x = 0,y = 0;
	struct tictactoe g = create_game();
	enum status status;
	print_game(g);
	while(1){
		do{
		printf("Turn of 1.player : ");
		scanf("%d%d",&x,&y);
		}while(!play(&g,x,y,SYM_X));

		print_game(g);

		status = get_status(g);
		if(status == X_WON){
			printf("1.player won!\n");
			break;
		}else if(status == DRAW){
			printf("Draw!\n");
			break;
		}

		do{
		printf("Turn of 2.player : ");
		scanf("%d%d",&x,&y);
		}while(!play(&g,x,y,SYM_O));

		print_game(g);

		status = get_status(g);
		if(status == O_WON){
			printf("2.player won!\n");
			break;
		}else if(status == DRAW){
			printf("Draw!\n");
			break;
		}
	}
	return 0;
}

struct tictactoe create_game(){
	struct tictactoe g = {{{'_','_','_'},{'_','_','_'},{'_','_','_'}}};
	return g;
}

int play(struct tictactoe *g,int x,int y,enum symbol symbol){
	if(x > 2 || x < 0 || y > 2 || y < 0){
		return 0;
	}else if(g->table[x][y] == '_'){
		g->table[x][y] = symbol;
		return 1;
	}else{
		return 0;
	}
}

enum status get_status(const struct tictactoe g){
	if(g.table[0][0] == SYM_X && g.table[0][1] == SYM_X && g.table[0][2] == SYM_X)return X_WON;
	if(g.table[1][0] == SYM_X && g.table[1][1] == SYM_X && g.table[1][2] == SYM_X)return X_WON;
	if(g.table[2][0] == SYM_X && g.table[2][1] == SYM_X && g.table[2][2] == SYM_X)return X_WON;

	if(g.table[0][0] == SYM_X && g.table[1][0] == SYM_X && g.table[2][0] == SYM_X)return X_WON;
	if(g.table[0][1] == SYM_X && g.table[1][1] == SYM_X && g.table[2][1] == SYM_X)return X_WON;
	if(g.table[0][2] == SYM_X && g.table[1][2] == SYM_X && g.table[2][2] == SYM_X)return X_WON;

	if(g.table[0][0] == SYM_X && g.table[1][1] == SYM_X && g.table[2][2] == SYM_X)return X_WON;
	if(g.table[0][2] == SYM_X && g.table[1][1] == SYM_X && g.table[2][0] == SYM_X)return X_WON;

	if(g.table[0][0] == SYM_O && g.table[0][1] == SYM_O && g.table[0][2] == SYM_O)return O_WON;
	if(g.table[1][0] == SYM_O && g.table[1][1] == SYM_O && g.table[1][2] == SYM_O)return O_WON;
	if(g.table[2][0] == SYM_O && g.table[2][1] == SYM_O && g.table[2][2] == SYM_O)return O_WON;

	if(g.table[0][0] == SYM_O && g.table[1][0] == SYM_O && g.table[2][0] == SYM_O)return O_WON;
	if(g.table[0][1] == SYM_O && g.table[1][1] == SYM_O && g.table[2][1] == SYM_O)return O_WON;
	if(g.table[0][2] == SYM_O && g.table[1][2] == SYM_O && g.table[2][2] == SYM_O)return O_WON;

	if(g.table[0][0] == SYM_O && g.table[1][1] == SYM_O && g.table[2][2] == SYM_O)return O_WON;
	if(g.table[0][2] == SYM_O && g.table[1][1] == SYM_O && g.table[2][0] == SYM_O)return O_WON;

	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(g.table[i][j] == '_')return NOTHING;
		}
	}

	return DRAW;
}

void print_game(const struct tictactoe g){
	printf("\033[H\033[J");
	for(int y = 0;y < 3;y++){
		for(int x = 0;x < 3;x++){
			printf("%c   ",g.table[x][y]);
		}
		printf("\n\n");
	}
}
