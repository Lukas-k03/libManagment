#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

//albert said 160
void addBook ();
void addMem ();
void modBook ();
void modMem ();
void delBook ();
void delMem ();
void issueBook ();
void returnBook ();

int main (){
    
    int userIn;

    std :: cout << "What Would You Like To Do?" << std :: endl 
    << "1. Add Book" << std :: endl << "2. Add Member" << std :: endl
    << "3. Modify Book" << std :: endl << "4. Modify Member" 
    << std :: endl << "5. Delete Book" << std :: endl << "6. Delete Member"
    << std :: endl << "7. Issue Book" << std :: endl << "8. Return Book"
    << std :: endl;
    
    std :: cin >> userIn;

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
        default : std :: cout << "Incorrect Input" << std :: endl;
    }
}

void addBook() {
    
    int index,i;
    char c;
    std :: string bookName,authorFirstName,authorLastName,isbn;
  
    while(true){
        
        std :: cout << "Enter Name Of Book:";
       
        std :: cin.sync(); //Discards unread characters, makes get line work
        std :: getline(std :: cin, bookName);  
       
        std :: cout << "Enter First Name Of Author:";
        std :: cin >> authorFirstName;
        
        std :: cout << "Enter Last Name Of Author:";
        std :: cin >> authorLastName;
       
        std :: cout << "Enter ISBN:";
        std :: cin >> isbn;
    
        std :: string allData = bookName + "|" + authorFirstName + "|" + authorLastName + "|" + isbn + "\n";
        //opens the file, then writes the string to it.
        std :: ifstream bookListData; //object
            int index=0;
            bookListData.open("bookList.txt");
            
            if(!bookListData){
                std :: cout << "Unable to Open File"; //case for not being able to open file
                exit(1);
            }

             bookListData.seekg (0, bookListData.end); //get total length of file
             int length = bookListData.tellg();
             bookListData.seekg (0, bookListData.beg);

             char buffer[length];

             bookListData.read (buffer,length);

             for(int i=0;buffer[i]<length;i++){

             }
            for(int i=0;buffer[i]< length;i++){
                if( buffer[i] == '\n'){
                    index++;
                    continue;
                }
            }
            std :: cout << "Index of This Book is" << index;

        // Work On this Part
    
        std :: cout << "Press ` to Quit\nPress Enter To Add Another Book";
        std :: cin >> c;
        if(c=='`') {break;};
        
     }
    
    }
