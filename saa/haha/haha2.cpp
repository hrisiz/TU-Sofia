#include<iostream>
using namespace std;

#define X_Y 3
#define X_X 3

int main(){
	int x[X_Y][X_X] = {{1,1,1},{1,1,1},{1,1,1}};
	int xx[X_X+2] = {0};
	for(int i=0; i < X_Y; i++){
		xx[0] += x[i][i];
		if(i+1 < X_Y)
			xx[X_X+1]++;
		for(int j = 0; j < X_X; j++){
			xx[i+1] += x[i][j];
		} 
	}
	for(int i = 0; i < X_X+2; i++){
		cout << xx[i] << endl;
	}	
	return 1;
}
