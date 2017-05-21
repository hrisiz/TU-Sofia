#include<iostream>

using namespace std;
#define ARRAY_SIZE 10
int main(){
	int array[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++){
		cout << "number " << (i+1) << ": ";
		cin >> array[i];
		if(cin.eof()){
			break;
		}
	}
	cout << endl;
	for(int i = 1; i < ARRAY_SIZE; i+=2){
		if(array[i-1] >= array[i] ||
		   (i+1 < ARRAY_SIZE && array[i] <= array[i+1])){
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}

/*
-1
1
-1
1
-1
1
-1
1
-1
1
-1
1

*/
