//celochisleno desetichno kum dvoichno chrez rekursiq

#include<iostream>

using namespace std;

void binary(int a){
	if(a > 0){
		binary(a/2);
		cout << a%2;
	}
}

int main(){
	int a;
	cin >> a;
	binary(a);
	return 1;
}
