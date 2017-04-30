#include<iostream>
using namespace std;

#define X_X 3
#define X_Y 3
int main(){
	int x[X_X][X_Y] = {{1,1,1},{1,1,1},{1,1,1}};
	int sum = 0;
	for(int i=1;i<X_X-1;i++){
		sum += x[i][0];
		sum += x[i][2];
	}
	for(int i =0; i <X_Y;i++){
		sum += x[0][i];	
		sum += x[X_X-1][i];
	}
	
	cout << sum;
	return 1;
}
