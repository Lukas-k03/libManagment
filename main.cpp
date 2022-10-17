#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "book.h"

using namespace std;
int readDataForIndex();
void issueBook ();
void returnBook ();
void delMem ();
void modMem ();
void addMem ();

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
void printList(){
    ifstream file;
    char buffer[2000];
    file.open("data.txt");
    
    if(!file.is_open()){
        cout << "File Not Able To Be Open" << endl;
        exit(EXIT_FAILURE);
    }
    
    file.read((char*)buffer,2000);
    cout << buffer;

    file.close();

}

void writebookData(Book _book){
    ofstream file;
    file.open("data.txt", ios::app); //ios::app will append the text  to end
    
    string bookN,firstN,lastN,index;
    
    bookN=_book.bookName;
    firstN=_book.authorFirst;
    lastN=_book.authorLast;
    index = to_string(_book.index);

    const string input[5] = {_book.bookName,_book.authorFirst,_book.authorLast,to_string(_book.index)};
    
    file << fixed << left << setw(30) << input[0] << "|";
    for(int i=1; i<3;i++){
        file << fixed << left << setw(15) << input[i] << "|";
   }
    file << endl;
    file.close();
}
void writeIndexData(int _index){ //Make part of book class usign static
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

    Book book1(bookName,authorFirstName,authorLastName,readDataForIndex());
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
    << endl << "9.Show Book List"<< endl << "10. Quit Program";
    
    cin >> userIn;
      if(userIn == 10) break;
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
        case 9 : printList();
            break;
        default : cout << "Incorrect Input" << endl;
    }
    
    }
}

