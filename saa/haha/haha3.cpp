#include<iostream>
using namespace std;

#define X_Y 3
#define X_X 3

int main(){
	int x[X_Y][X_X] = {{1,1,1},{1,1,1},{1,1,1}};
	int sum = 0;
	for(int i=0; i < X_Y; i++){
		sum += x[i][X_X-i-1];
		if(i+1 < X_X){
			if(x[i][i+1] > (i+1)*i){
				sum++;
			}
		}
	}
	cout << sum;	
	return 1;
}
