#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
int readDataForIndex();
void issueBook ();
void returnBook ();
void delMem ();
void modMem ();
void addMem ();

class Book{
    public:
        string bookName,authorFirst,authorLast;
        int index,quantity;
    Book(){
        bookName="N/A";
        authorFirst = "N/A";
        authorLast = "N/A";
        index = 0;
        quantity =0;
    }
    Book(string _bookName,string _authorFirst,string _authorLast){
        bookName = _bookName;
        authorFirst = _authorFirst;
        authorLast = _authorLast;
        index = readDataForIndex();
    }
    void modBook (){

    }
    
    void delBook (){

    }
    
    void issueBook (){

    }
    void returnBook (){

    }
};
class Member{
    public:
        string firstName,lastName;
        int id;
    Member(){
        firstName,lastName = "N/A";
        id = 0;
    }
    Member(string _fN, string _lN){
        firstName,lastName = "N/A";
        id = 0;
    }
};
void writebookData(Book &_book){
    ofstream file;
    file.open("data.txt", ios::app); //will append the text
    file.write((char*)&_book, sizeof(_book));
}
void writeIndexData(int _index){
    ofstream fileIndex;
    fileIndex.open("index.txt");
    
     if(!fileIndex.is_open()){
        cout << "File Not Able To Be Open" << endl;
        exit(EXIT_FAILURE);
    }
    
    fileIndex << _index+1;
}
int readDataForIndex(){ //Just Make a seprate counter for each bppk
    ifstream fileIndex;      //stord in its own file, When index is acessesd read file for highest one
    fileIndex.open("index.txt");
   
    if(!fileIndex.is_open()){
        cout << "File Not Able To Be Open" << endl;
        return EXIT_FAILURE;
    }
    
    int indexnum=0;

    fileIndex >> indexnum;
    
    fileIndex.close();
    
    writeIndexData(indexnum);
    
    return indexnum;

    
} //figuire out why indexes are odd
void addBook(){
   while(true){
    string bookName,authorFirstName,authorLastName,isbn;

        cout << "Enter Name Of Book:";
       
        cin.sync(); //Discards unread characters, makes get line work
        getline(std :: cin, bookName);  
       
        cout << "Enter First Name Of Author:";
        cin >> authorFirstName;
        
        cout << "Enter Last Name Of Author:";
        cin >> authorLastName;
       
        cout << "Enter ISBN:";
        cin >> isbn;;

    Book book1(bookName,authorFirstName,authorLastName);
    
    book1.index=readDataForIndex();
    writebookData(book1);

    cout << "The Book Index is " << book1.index << endl;
    char b;
    cout << "Type 1 to add another book\nType ` to exit" << endl;
    cin >> b;
    
    if((b) == '`') break;
   }
}
int main (){
    while(true){
    int userIn;

    cout << "What Would You Like To Do?" << endl 
    << "1. Add Book" << endl << "2. Add Member" << endl
    << "3. Modify Book" << endl << "4. Modify Member" 
    << endl << "5. Delete Book" << endl << "6. Delete Member"
    << endl << "7. Issue Book" << endl << "8. Return Book"
    << endl << "9. Quit Program";
    
    cin >> userIn;
      if(userIn == 9) break;
      switch(userIn){
        case 1 : addBook();
            break;
      /*  case 2 : addMem();
            break;
        case 3 : modBook();
            break;
        case 4 : modMem();
            break;
        case 5 : delBook();
            break;
        case 6 : delMem();
            break;
        case 7 : issueBook();
            break;
        case 8 : returnBook();
            break; */
        default : cout << "Incorrect Input" << endl;
    }
    
    }
}

