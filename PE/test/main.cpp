#include <cstdlib>
#include <iostream>

using namespace std;

class Books{
protected:
          string name;
          string author;
          string dateGet;
public:
       Books(string n, string a, string dateG){
            this->name =n;
            this->author = a;
            this->dateGet = dateG;
        }
        ~Books(){cout << "Destructing Books" << endl;}
        friend ostream& operator<<(ostream& out, const Books &book){
                 out << "Name: " << book.name << endl; 
                 return out;        
        }   
};
          
        
class Library{
protected:
      int numTitles;
      Books** books;
public:
       Library(int numTitles, Books ** b){ 
       this->books = b;
       this->numTitles = numTitles;
                     
       cout << "Constructing Library " << endl;
       }
       
       ~Library(){ 
       for(int i = 0; i < this->numTitles-1; i++)
       {
       		delete this->books[i];
       }  
       cout << "Destructing Library" << endl;
       }
       friend Library operator++( Library &l, int a);
       friend ostream &operator<<(ostream& out, Library &l);   
};
      
ostream &operator<<(ostream& out, Library &l)
{
       for(int i = 0; i < l.numTitles; i++)
       {
               out << (*l.books[i]);        
       }
       return out;
}  

Library operator++(Library &l,int a)
       {
       		Library result = l;
       		l.numTitles++;
       		cout << a << endl;
       		return result;
       }

int main(int argc, char *argv[])
{
    cout << "abcbavn" << endl;
    
    Books* books[3];
    books[0] = new Books("b1", "a1", "111");
    books[1] = new Books("b2", "a2", "222");
    books[2] = new Books("b3", "a3", "333");
    
    Library lib(3, books);
    
    cout << lib << endl;
    Library l = lib++;
    cout << l << endl;
    int a;
    cin >> a;
    return EXIT_SUCCESS;
}