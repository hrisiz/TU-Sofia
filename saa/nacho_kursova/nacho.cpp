#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){	
	int n;
	
	//chetem kolko shte e golqm masiva trqbva da e povecheot 1 na 1 
	do{
		cout << "N(>1):";
		cin >> n;
	}while(n < 2);
	// krai na cheteneto
	//suzdavame masiva spored vuvedenoto n
	int array[n*n][n*n];
	int array_size = n*n;
	//chetem simvolite na masiva
	for(int i = 0; i < array_size; i++){
		for(int j = 0; j < array_size; j++){
			cout << "Element [" << i << "]" << "[" << j << "]: ";
			cin >> array[i][j];
		}
	}
	// krai na cheteneto
	int r = array_size/2; // suzdavame kolko e radiusa sprqmo sredata toest elementite/2
	int new_array[array_size*array_size]; // suzdavame noviq ednomeren masiv v koito shte zapishem razguvkata na dvumerniq po spirala(toest pravim masiva ot dvumeren na ednomeren)
	int array_in = 0; // promenliva s koqto gledame do kude sme stignali
	int elem = 0; // counter za ednomerniq masiv
	//vurtim edin cikul po dvumerniq masiv i vadim silvolite koito ni trbqvat
	while(1){ 
		int max_elements = ((r*2)-1)+array_in; // zimame nomercheto na purviq element na kvadrata ot dvumerniq masiv kato otpravna tochka
		//vzimame elementite po x ot purviq red ot lqvo na dqsno
		for(int x = array_in; x < max_elements; x++){
			new_array[elem++] = array[array_in][x];
		}
		//vzimame elementite po y ot poslednata kolona ot gore na dolu
		for(int y = array_in; y < max_elements; y++){
			new_array[elem++] = array[y][max_elements];
		}
		//vzimame elementite po x ot posledniq red ot dqsno na lqvo
		for(int x = max_elements; x > array_in; x--){
			new_array[elem++] = array[max_elements][x];
		}
		//vzimame lementite po y ot purvata kolona ot dolu na gore
		for(int y = max_elements; y > array_in; y--){
			new_array[elem++] = array[y][array_in];
		}
		if(r == 1){ // prowerqvame dali sme stignali nai malkiq kvadrat ako sme izlizame ot cikula
			break;
		}	
		r--;	// namalqvame r zashtoto vlizame v maluk kvadrat(toest sme se zavurtqli 1 put po spiralata)
		array_in++; // uvelichavame promenliva da znaem v koi tochno kvadrat sme
	}
	int prev_elem = new_array[0]; // suzdavame si promenliva za predishen element i slagame purviq element kato predishen
	int result = 1; // priemame che redicata e trionoobrazna i ako po dolu razberem che ne e pravim tazi promenliva 0 ako ne si sedi 1
	int bigger; // trqbva ni za da znaem dali posle trqbva da e po golqmo ili po malko chisloto
	// proverqvame koe e po golqmo purvoto ili vtoroto za da znaem kak da trugnem da proverqvame trionoobraznata redica
	if(new_array[0] > new_array[1]){ 
		bigger = 1;
	}else{
		bigger = -1;
	}
	// vurtim cikul po elementite na masiva i ako namerim element koito e po golqm a trqbva da e po maluk ili e po maluk a trqbva da e po golqm pravim result 0 i izlizame ot cikula
	for(int i = 1; i < elem ;i++){ // zapochvame ot vtoriq element purviq sedi v prev_elem
		//proverka dali predniq element e po maluk ot tekushtiq i ako e a trqbva da e obratnoto result stava 0 i izlizame ot cikula
		if(prev_elem < new_array[i] && bigger == 1){
			result = 0;
			break;
		}else if(prev_elem > new_array[i] && bigger == -1){ // ako ne e purvoto to proverqvame dali sluchaino purvoto ne e po golqmo ot vtoroto a da trqbva da e po malko i ako e taka otnovo result 0 i izlizame ot cikula
			result = 0;
			break;
		}
		bigger *= -1; //promenqme znaka na dali trqbva da e po golqmo ili po malko 
		prev_elem = new_array[i]; // slagame tekushtiq kato predishen element
	}
	//proverqvame resultata ako e 1 znachi redicata e trionoobrazna i printirame OK ako e 0 to redicata ne e trionoobrazna i printirame NOT OK
	if(result == 1){
		cout << "OK!" << endl;
	}else{
		cout << "NOT OK!" << endl;
	}
	return EXIT_SUCCESS; // tova si e defaultno zaduljitelno za main programata EXIT_SUCCESS e ot stdlib.h definirana globalna promenliva mislq che e 1
}
