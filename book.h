#include <string>
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
    Book(string _bookName,string _authorFirst,string _authorLast,int _index){
        bookName = _bookName;
        authorFirst = _authorFirst;
        authorLast = _authorLast;
        index = _index;
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