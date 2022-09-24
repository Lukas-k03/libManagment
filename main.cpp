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
    void addBook (){

    }
    void addMem (){

    }
    void modBook (){

    }
    void modMem (){

    }
    void delBook (){

    }
    void delMem (){

    }
    void issueBook (){

    }
    void returnBook (){

    }
};

int main (){
    
    int userIn;

    cout << "What Would You Like To Do?" << endl 
    << "1. Add Book" << endl << "2. Add Member" << endl
    << "3. Modify Book" << endl << "4. Modify Member" 
    << endl << "5. Delete Book" << endl << "6. Delete Member"
    << endl << "7. Issue Book" << endl << "8. Return Book"
    << endl;
    
    cin >> userIn;

}

