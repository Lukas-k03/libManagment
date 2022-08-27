#include <iostream>

void addBook();
void addMem();
void modBook();
void modMem();
void delBook();
void delMem();
void issueBook();
void returnBook();

int main(){
    
    int userIn;

    std :: cout << "What Would You Like To Do?" << std :: endl << 
    "1. Add Book" << std :: endl << "2. Add Member" << std :: endl
    << "3. Modify Book" << std :: endl << "4. Modify Member" <<
    std :: endl << "5. Delete Book" << std :: endl << "6. Delete Member"
    << std :: endl << "7. Issue Book" << std :: endl << "8. Return Book"
    << std :: endl;
    
    std :: cin >> userIn;

    switch(userIn){
        case 1 : addBook();
            break;
        case 2 : addMem();
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
            break;    
    }
    
}