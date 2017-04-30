#include<iostream>
using namespace std;
int main(){
	int x[] = {1,2,3,3,11,6,6,6,0,8,8};
	int br = 0;
	for(int i = 0; i < 11;i++){
		int number = x[i];
		int counter = 1;
		for(int i1 = (i+1); i1 < 11; i1++){
			if(x[i] == x[i1]){
				counter++;
			}
		}
		if(br < counter){
			br = counter;
		}
	}
	cout << br;
	return 1;
}
