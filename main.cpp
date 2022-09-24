#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

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
    file.open("data.txt");
    file.write((char*)&_book, sizeof(_book));
}
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
    
    writebookData(book1);

    char b;
    cout << "Type 1 to add another book\nType ` to exit" << endl;
    cin >> b;
    if((b) == '`') break;
   }
}
void issueBook ();
void returnBook ();
void delMem ();
void modMem ();
void addMem ();
int main (){
    while(true){
    int userIn;

    cout << "What Would You Like To Do?" << endl 
    << "1. Add Book" << endl << "2. Add Member" << endl
    << "3. Modify Book" << endl << "4. Modify Member" 
    << endl << "5. Delete Book" << endl << "6. Delete Member"
    << endl << "7. Issue Book" << endl << "8. Return Book"
    << endl;
    
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

