//cifrite na desetichno na obratno

#include<iostream>

using namespace std;

int reverse(int a){
	if(a < 10) 
		cout << a;
	else{
		cout << a%10;
		reverse(a/10);
	}
}
int main(){
	int a;
	cin >> a;
	reverse(a);
	return 1;
}
