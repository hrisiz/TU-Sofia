//x^n


#include<iostream>

using namespace std;

float up(float x,int n){
	if(n == 0){
		return 1;
	}
	else if(n > 0){
		return x*up(x,n-1);
	}else{
		return 1/up(x,-n);
	}
}
int main(){
	cout << up(2,-10);
	return 1;
}
