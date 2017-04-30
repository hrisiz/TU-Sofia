#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> array;
	while(true){
		int tmp;
		cout << "\nnumber " << array.size() << ": ";
		cin >> tmp;
		if(cin.eof()){
			break;
		}
		array.push_back(tmp);
	}
	cout << endl;
	for(int i = 1; i < array.size();i+=2){
		if(array.at(i-1) > array.at(i) ||
		   array.at(i) < array.at(i+1)){
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 1;
}
