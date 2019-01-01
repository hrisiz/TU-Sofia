#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;
class NoteBook {
private:
	string title;
	int numberOfAutors;
	string *autors;
	int releaseNumber;// zashto int???
	string isbn;
	string releaseDate;
	int tiraj;
	double price;
	bool mon;
public:

	NoteBook(string title, int numberOfAutors, string *autors, int releaseNumber, string isbn, string releaseDate, int tiraj, double price, bool mon) {
		this->title = title;
		this->numberOfAutors = numberOfAutors;
		this->autors = autors;
		this->releaseNumber = releaseNumber;
		this->isbn = isbn;
		this->releaseDate = releaseDate;
		this->tiraj = tiraj;
		this->price = price;
		this->mon = mon;
		cout << "notebook created" << endl;
	}
	string getTitle() const{
		return title;
	}
	string *getAutors() const{
		return autors;
	}
	int getNumberOfAutors() const{
		return numberOfAutors;
	}
	int getReleaseNumber()const{
		return releaseNumber;
	}
	string getIsbn()const{
		return isbn;
	}
	string getReleaseDate()const{
		return releaseDate;
	}
	int getTiraj()const{
		return tiraj;
	}
	double getPrice() const{
		return price;
	}
	bool getMon()const{
		return mon;
	}
	void setTitle(string title) {
		this->title = title;
	}
	void setAutors(string *autors) {
		this->autors = autors;
	}
	int setNumberOfAutors(int numberOfAutors) {
		this->numberOfAutors = numberOfAutors;
	}
	void setReleaseNumber(int releaseNumber){
		this->releaseNumber = releaseNumber;
	}
	void setIsbn(string isbn){
		this->isbn = isbn;
	}
	void setReleaseDate(string ReleaseDate){
		this->releaseDate = releaseDate;
	}
	void setTiraj(int){
		this->tiraj = tiraj;
	}
	void setPrice(double price){
		this->price = price;
	}
	void setMon(bool mon){
		this->mon = mon;
	}
	~NoteBook() {
		cout << "Notebook destruction";
		delete[] autors;
	}
	void writeNotebookToFile() {

		ofstream myfile;
		myfile.open("Notebooks.txt", std::ios_base::app);
		myfile << title;
		myfile << "^&";

		myfile << numberOfAutors;

		for (int i = 0; i < numberOfAutors; i++){
			myfile << "^&";
			myfile << autors[i];

		}
		myfile << "^&";
		myfile << releaseNumber;
		myfile << "^&";
		myfile << isbn;
		myfile << "^&";
		myfile << releaseDate;
		myfile << "^&";
		myfile << tiraj;
		myfile << "^&";
		myfile << price;
		myfile << "^&";
		myfile << mon;
		myfile << "^&";
		myfile << endl;

		myfile.close();
	}
};
class Knigorazprostranitel{
private:
	string name;
	string address;
	string phoneNumber;
public:
	Knigorazprostranitel(string name, string address, string phoneNumber){
		this->name = name;
		this->address = address;
		this->phoneNumber = phoneNumber;
		cout << "Knigorazprostranitel created" << endl;
		//writeKnigorazprostranitelToFile();
		//cout << "Knigorazprostranitel saved" << endl;

	}
	string getName() const{
		return name;
	}
	string getAddress() const{
		return address;
	}
	string getPhoneNumber() const{
		return phoneNumber;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAddress(string address){
		this->address = address;
	}
	void setPhoneNumber(string phoneNumber){
		this->phoneNumber = phoneNumber;
	}
	void writeKnigorazprostranitelToFile() {
		ofstream myfile;
		myfile.open("Knigorazprostraniteli.txt", std::ios_base::app);
		myfile << name;
		myfile << "^&";
		myfile << address;
		myfile << "^&";
		myfile << phoneNumber;
		myfile << "^&";
		myfile << endl;
		cout << "Knigorazprostranitel saved" << endl;

		myfile.close();
	}
};
class Order{
private:
	NoteBook **noteBook;
	int *quantity;
	Knigorazprostranitel *knigorazprostranitel;
	double totalPrice;
	int notebooksN;
public:
	Order(int *quantity, Knigorazprostranitel *knigorazprostranitel, int notebooksN, NoteBook **noteBook = nullptr) :noteBook(noteBook), knigorazprostranitel(knigorazprostranitel){
		std::cout << "quantity:" << *quantity << std::endl;
		this->quantity = new int(*quantity);
		this->notebooksN = notebooksN;
		cout << "order created" << endl;
	}
	int getNotebooksN() const{
		return notebooksN;
	}
	int *getQuantity() const{
		return quantity;
	}
	NoteBook **getNotebook() const{
		return noteBook;
	}
	Knigorazprostranitel getKnigorazprostranitel() const{
		return *knigorazprostranitel;
	}
	/*void print(){
		cout << noteBook[0]->getTitle();
	}*/
	double calulateTotalPrice() const{
		double sum = 0;
		for (int i = 0; i < notebooksN; i++){
			sum += quantity[i] * noteBook[i]->getPrice();
		}
		return sum;
	}
	void writeOrderToFile(int knigorazprostranitelN) {
		ofstream myfile;
		myfile.open("orders.txt", std::ios_base::app);
		if (myfile.is_open())
		{
			myfile << knigorazprostranitelN;
			myfile << " ";
			cout << notebooksN;

			for (int i = 0; i < notebooksN; i++)
			{
				myfile << quantity[i];
				myfile << " ";
			}
			//	myfile << totalPrice;
			//myfile << "^&";
			myfile << endl;
			cout << "order saved" << endl;
			myfile.close();

		}
		//cout << "file close";
	}

};
ostream& operator<<(ostream& out, const Order& obj) {

	NoteBook** noteBook = obj.getNotebook();
	string* autors1;
	int *quantity = obj.getQuantity();
	out << obj.getKnigorazprostranitel().getName()<<endl;
	for (int i = 0; i < obj.getNotebooksN(); i++)
	{
		if (quantity[i]>0){

			//out << i << endl;
			out << "title:" << noteBook[i]->getTitle() << endl;
			autors1 = noteBook[i]->getAutors();

			for (int j = 0; j < noteBook[i]->getNumberOfAutors(); j++) {
				out << "autor[" << j << "]:" << autors1[j] << endl;
			}
			out << "order quantity:" << *quantity << endl;
		}

	}
	out << "total price:" << obj.calulateTotalPrice() << endl;
	return out;
}
ostream& operator<<(ostream& out, const NoteBook* obj) {
	
	int autorsN = obj->getNumberOfAutors();
	string *autors = obj->getAutors();
	out <<"title:"<< obj->getTitle()<<endl;


	for (int i = 0; i < autorsN; i++){
		out <<"autor:"<< autors[i] << endl;
	}
	out <<"getReleaseNumber:"<< obj->getReleaseNumber() << endl;
	out <<"ISBN:"<< obj->getIsbn() << endl;
	out <<"getReleaseDate:"<< obj->getReleaseDate() << endl;
	out <<"Tiraj:"<< obj->getTiraj() << endl;
	out <<"Price:"<< obj->getPrice() << endl;
	out <<"certicated:"<< obj->getMon() << endl;
	return out;
}
ostream& operator<<(ostream& out, const Knigorazprostranitel* obj) {
	cout << "fdfd";
	out << obj->getName() << endl;
	out << obj->getAddress() << endl;
	out << obj->getPhoneNumber() << endl;
	return out;
}
void writeNumbersToFile(int NotebooksN, int deliversN){
	ofstream myfile;
	myfile.open("numbers.txt");
	myfile << NotebooksN;
	myfile << " ";
	myfile << deliversN;
}
void readNumbersFromFile(int &NotebooksN, int &deliversN){
	ifstream myfile;
	myfile.open("numbers.txt");
	if (myfile.is_open())
	{
		myfile >> NotebooksN >> deliversN;
	
	}

}
void readKnigorazprostranitelFromFile(std::string line, Knigorazprostranitel *&knigorazprostranitel) {

	string token[3];
	for (int i = 0; i<3; i++)
	{
		token[i] = line.substr(0, line.find_first_of("^&"));
		line = line.substr(line.find_first_of("^&") + 2);

	}
	//	cout << token[0]<<token[1]<< token[2] << endl;
	knigorazprostranitel = new Knigorazprostranitel(token[0], token[1], token[2]);

	//cout << knigorazprostranitel[0];

}
void readKnArr(int knN, Knigorazprostranitel **&knigorazprostranitel){// vika se pri purvonahalno startirane, suzdava masiva
	ifstream myfile;
	string line;
	myfile.open("Knigorazprostraniteli.txt");
	if (myfile.is_open()){
		knigorazprostranitel = new Knigorazprostranitel*[knN];
		for (int i = 0; i < knN; i++)
		{

			getline(myfile, line);
			readKnigorazprostranitelFromFile(line, knigorazprostranitel[i]);

		}
		myfile.close();
	}
	else
		cout << "there is no file Knigorazprostraniteli.txt"<<endl;
}
void readNotebookFromFile(std::string line, NoteBook *&notebook) {

	string token[8];
	string *autors;
	istringstream str;
	bool mon;
	int autorsNumber;
	for (int i = 0; i<8; i++)
	{
		token[i] = line.substr(0, line.find_first_of("^&"));
		line = line.substr(line.find_first_of("^&") + 2);
		if (i == 1){
			autorsNumber = atoi(token[i].c_str());
			autors = new string[autorsNumber];
			for (int j = 0; j < autorsNumber; j++)
			{
				autors[j] = line.substr(0, line.find_first_of("^&"));
				line = line.substr(line.find_first_of("^&") + 2);
			}
		}

	}
	
	//cout << token[6];
	istringstream(token[7]) >> mon;
	notebook = new NoteBook(token[0], autorsNumber, autors, atoi(token[1].c_str()), token[3], token[4], atoi(token[5].c_str()), stod(token[6], nullptr), mon);
	
}
void extendArr(int size,int newSize, Knigorazprostranitel **&knigorazprostranitel){
	Knigorazprostranitel **knigorarzprostranitel1 = new Knigorazprostranitel*[newSize];
	if (knigorazprostranitel){

		for (int i = 0; i < size; i++){
			knigorarzprostranitel1[i] = knigorazprostranitel[i];
		}
	}
	knigorazprostranitel = knigorarzprostranitel1;
}
void readNotebookArr(int nBN, NoteBook **&notebook){
	ifstream myfile;
	string line;
	myfile.open("Notebooks.txt");
	
	if (myfile.is_open()){

		notebook = new NoteBook*[nBN];
		for (int i = 0; i < nBN; i++)
		{

			getline(myfile, line);
			readNotebookFromFile(line, notebook[i]);

		}
		myfile.close();
	}
	else
		cout << "there is no file Notebooks.txt"<<endl;
	
}
void extendNotebookArr(int size, int newSize, NoteBook **&notebook){
	NoteBook **notebook1 = new NoteBook*[newSize];
	if (notebook){
		for (int i = 0; i < size; i++){
			notebook1[i] = notebook[i];
		}
	}
	notebook = notebook1;
}
void extendOrderArr(int size, int newSize, Order **order){// should be here
	Order **order1 = new Order*[newSize];
	if (order){
		for (int i = 0; i < size; i++){
			order1[i] = order[i];
		}
		order = order1;
	}
}
void readOrderFromFile(int &orderCnt, int *&quantity, Knigorazprostranitel **&knigorazprostranitel, int notebooksN, NoteBook **&noteBook, Order **&order)
{
	ifstream  myfile;
	myfile.open("orders.txt");
	string *token = new string[notebooksN + 1];
	int index = 0;
	string line;
	string str;
	order = new Order *[orderCnt];
	if (myfile.is_open())
	{
		while (getline(myfile, str))
		{
		//	cout << "hahah";
			istringstream ss(str);	
			for (int i = 0; i < notebooksN+1 ; i++){
				if (i == 0){
					ss >> index;
				//	cout << index<<endl;
				}
				else
				{
					ss >> quantity[i-1];
				//	cout << quantity[i - 1] << endl;

				
				}
			}
			orderCnt++;
			//cout << "haha" << orderCnt;
			extendOrderArr(orderCnt - 1, orderCnt, order);
			cout << "quantity" << quantity << std::endl;
			order[orderCnt-1] = new Order(quantity, knigorazprostranitel[index], notebooksN, noteBook);

		
		}
	//	cout << order[0];
	//	cout << order[1];
	//	cout << order[2];
	//	cout << order[3];



	for (int i = 0; i < orderCnt;i++)
			cout << *order[i];
	
		//cout <<"hah"<< order[0]->getQuantity()[1]<<endl;
		myfile.close();
	}

} //should be ok


int main()
{
	int broiUchebnici = 0;
	int broiUchebnici1 = 0;
	int orderCnt = 0;
	int broiKnigorazprostraniteli = 0;
	string title;
	int numberOfAutors = 0;
	string *autors;
	int releaseNumber = 0;
	string isbn;
	string releaseDate;
	int tiraj = 0;
	double price=0;
	bool mon=0;
	string name;
	string address;
	string phoneNumber;
	int index=0;
	int *quantiti;
	int bookIndex=0;
	NoteBook** noteBook=nullptr;
	Knigorazprostranitel **knigorazprostranitel = nullptr;
	Knigorazprostranitel **knigorazprostranitel1 = nullptr;
	Order **order = nullptr;//
	readNumbersFromFile(broiUchebnici, broiKnigorazprostraniteli);
	readKnArr(broiKnigorazprostraniteli, knigorazprostranitel);
	readNotebookArr(broiUchebnici, noteBook);
	quantiti = new int[broiUchebnici];
	readOrderFromFile(orderCnt ,quantiti, knigorazprostranitel, broiUchebnici, noteBook, order);
//for (int i = 0; i < orderCnt;i++)
	//cout << order[i];
	//cout << order[1];
	cout << "vuvedete broi uchebnici, koito iskate da vuvedete:";
	cin >> broiUchebnici1;
	cin.ignore();
	
	//*quantiti = {0,};
	bool flag = true;
	if (broiUchebnici1 != 0)
	{
		extendNotebookArr(broiUchebnici, broiUchebnici1 + broiUchebnici, noteBook);
		broiUchebnici += broiUchebnici1;
		for (int i = broiUchebnici - broiUchebnici1; i < broiUchebnici; i++)
		{
			cout << "zaglavie:";
			cin.clear();
			getline(cin, title);
			cout << "broi avtori:";
			cin >> numberOfAutors;
			cin.ignore();
			autors = new string[numberOfAutors];
			for (int j = 0; j < numberOfAutors; j++)
			{
				cout << "avtor:";
				cin.clear();
				getline(cin, autors[j]);
			}
			cout << "vuvedete poredno izdanie:";
			cin >> releaseNumber;
			cout << "vuvedete ISBN:";
			cin.clear();
			cin.ignore();
			getline(cin, isbn);
			cout << "vuvedete data na izdavane:";
			cin.clear();
			getline(cin, releaseDate);
			cout << "vuvedete tiraj:";
			cin >> tiraj;
			cout << "vuvedete cena:";
			cin >> price;
			cout << "sertificirana li e knigata ot mon?(true/false):";
			cin >> mon;
			cin.ignore();
			noteBook[i] = new  NoteBook(title, numberOfAutors, autors, releaseNumber, isbn, releaseDate, tiraj, price, mon);
			noteBook[i]->writeNotebookToFile();
		}
	}
	cout << "vuvedete broi knigorazprostraniteli, koito iskate da vuvedete:";
	int broiKnigorazprostraniteli1 = 0;
	cin >> broiKnigorazprostraniteli1;
	cin.ignore();
	if (broiKnigorazprostraniteli1 != 0)
	{
		extendArr(broiKnigorazprostraniteli, broiKnigorazprostraniteli1 + broiKnigorazprostraniteli, knigorazprostranitel);
		broiKnigorazprostraniteli += broiKnigorazprostraniteli1;
		for (int i = broiKnigorazprostraniteli - broiKnigorazprostraniteli1 ; i < broiKnigorazprostraniteli; i++)
		{
			cout << "ime na knigorazprostranitelq:";
			cin.clear();
			getline(cin, name);
			cout << "adress na knigorazprostranitelq:";
			cin.clear();
			getline(cin, address);
			cout << "telefon na knigorazprostranitelq:";
			cin.clear();
			getline(cin, phoneNumber);
			knigorazprostranitel[i] = new Knigorazprostranitel(name, address, phoneNumber);
			knigorazprostranitel[i]->writeKnigorazprostranitelToFile();
			cin.clear();
		}
	}
	cout << "Enter order details" << endl;
	cout << knigorazprostranitel[0]->getName() << endl;

	cout << "Izberete knigorazprostranitel ot spisuka:" << endl;
	for (int i = 0; i < broiKnigorazprostraniteli; i++)
	{
		cout << "knigorazprostranitel[" << i << "]:" << knigorazprostranitel[i]->getName() << endl;
	}
	cout << "Vuvedete nomera na izbraniq knigorazprostranitel:";
	cin >> index;
	string temp;
	while (flag){
		cout << "Izberete ot spisuka uchebnik, koito knigorazprostranitelq jelae da porucha:" << endl;
		for (int i = 0; i < broiUchebnici; i++)
		{
			cout << "notebook[" << i << "]" << noteBook[i]->getTitle() << endl;

		}
		cout << "Vuvedete nomera na izbraniq uchebnik:";
		cin.ignore();
		getline(cin, temp);
		cout << temp;
		if (temp.compare("#") == 0){
			break;
		}
		bookIndex = atoi(temp.c_str());
		if (bookIndex<0 || bookIndex>broiUchebnici)
		{
			cout << "Invalid choice";
			continue;
		}
		memset(quantiti, 0, sizeof(int)*broiUchebnici);

		cout << "Vuvedete kolichestvo ot izbraniq uchebnik, koeto jelaete da poruchate:";
		cin >> quantiti[bookIndex];
	}
	orderCnt++;
//	cout << "orderCnt:"<<orderCnt<<endl;
	extendOrderArr(orderCnt - 1, orderCnt, order);
	//cout << "orderCnt1:" << orderCnt << endl;
	order[orderCnt-1]=new Order(quantiti, knigorazprostranitel[index], broiUchebnici, noteBook);
	//cout << order[0];
	//cout << order[orderCnt];
	//order[0]->writeOrderToFile(index);
	//cout << noteBook[0];
	for (int i = 0; i < orderCnt; i++){
		cout << "i:" << i << endl;
		order[i]->writeOrderToFile(index);
	
	//	cout << order[i]<<endl;
	}
	writeNumbersToFile(broiUchebnici, broiKnigorazprostraniteli);
	delete noteBook;
	delete knigorazprostranitel;
//	free(quantiti);
	system("pause");
	return 0;
}
