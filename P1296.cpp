//分形宇宙
#include<bits/stdc++.h>
using namespace std;
char maze[3000][3000];
void dfs(int n, int x, int y){
	if(n == 1){
		maze[x][y] = 'X';
	}
	else{
		int size = pow(3.0, n-2);
		dfs(n-1, x, y);//左上角
		dfs(n-1, x, y+2*size);//右上角
		dfs(n-1, x+size, y+size);//中间 
		dfs(n-1, x+2*size, y);//左下角
		dfs(n-1, x+2*size, y+2*size);//右下角
	}
	return;
}
int main(void){
	int n;
	while(~scanf("%d", &n)){
		int size = pow(3.0, n - 1);
		for(int i = 0; i <= size; i++){
			for(int j = 0; j <= size; j++){
				maze[i][j] = ' ';
			}
		}
		
		dfs(n, 1, 1);
		
		for(int i = 1; i <= size; i++){
			for(int j = 1; j <= size; j++){
				printf("%c", maze[i][j]);
			}
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
} 