/*
    Basic book tracker.
    Keep logs of your personal library of books
    Along with the books you've read and your ratings.

 */

#include <iostream>
#include <fstream>
#include "BookTree.hpp"

using namespace std;


void readLibraryIn(BookTree *booktree, string filename);
void bookTrackerMenu();

int main(int argc, const char * argv[]) {
    
    
    BookTree *library = new BookTree();
    
    /* Reading in library file  and builds library BST */
    
    readLibraryIn(library, argv[1]);
    
    
    /* User Interaction */
    string selection;
    
    while(selection != "8"){
        
        bookTrackerMenu();
        getline(cin, selection);
        
        if(selection == "1"){
            
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "        Your Library          " << endl;
            cout << "------------------------------" << endl;
            library -> printLibrary();
            cout << "------------------------------" << endl;
            cout << endl;

        }
        else if(selection == "2"){
            string _searchTitle;
            
            cout << "Please enter a title: ";
            getline(cin, _searchTitle);
            library->getBookInfo(_searchTitle);
            
        }
        else if(selection == "3"){
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "          Books Read          " << endl;
            cout << "------------------------------" << endl;
            library -> printRead();
            cout << "------------------------------" << endl;
            cout << endl;
            
        }
        else if(selection == "4"){
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "        Unread Books          " << endl;
            cout << "------------------------------" << endl;
            library -> printUnread();
            cout << "------------------------------" << endl;
            cout << endl;
        }
        else if(selection == "5"){
            string completed;
            int comp = 0;
            string title;
            string author;
            string published;
            string rating;
            
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "           New Book           " << endl;
            cout << "------------------------------" << endl;
            
            cout << "Book Title: " ;
            getline(cin, title);
            
            cout << "Author: " ;
            getline(cin, author);
            
            cout << "Year Published: " ;
            getline(cin, published);
            
            cout << "Have you read this book? [y/n] " ;
            getline(cin, completed);
            
            if(completed == "y"){
                comp = 1;
                cout << "Book Rating [1-5]: " ;
                getline(cin, rating);
            }
            cout << "------------------------------" << endl;
            library->addBook(comp, title, author, published, atoi(rating.c_str()));
            
            cout << "      [Book Added]" << endl;
            
        }
        else if(selection == "6"){
            
        }
        else if(selection == "7"){
            
            int readBooks = library->countRead();
            int unreadBooks = library->countUnread();
            int totalBooks = readBooks + unreadBooks;
            
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "         Your Library         " << endl;
            cout << "------------------------------" << endl;
            
            cout << "Books in Your Library: " << totalBooks << endl;
            cout << "Books Read: " << readBooks<< endl;
            cout << "Books Not Read: " << unreadBooks << endl;
            cout << "Highest Rated Books: " << endl;

             cout << "------------------------------" << endl;
            
        }
        else if(selection == "8"){
            cout << "Goodbye" << endl;

        }
        else{
            cout << "Please Enter Another Option." << endl;
        }
    }
}


void readLibraryIn(BookTree *bookLib, string _file){
    
    ifstream in;
    in.open(_file);
    if (!in)
    {
        cout << "Could not open file" << endl;
        return;
    }
    string completed;
    string title;
    string author;
    string published;
    string rating;
    
    while (!in.eof())
    {
        completed = "";
        getline(in, completed, ',');
        getline(in, title, ',');
        getline(in, author, ',');
        getline(in, published, ',');
        getline(in, rating);
        
        if(completed != ""){
            
            bookLib->addBook(atoi(completed.c_str()), title, author, published, atoi(rating.c_str()));
        }
        
    }
  
}


void bookTrackerMenu(){
    
    cout << "------------------------------" << endl;
    cout << "        Book Tracker          " << endl;
    cout << "------------------------------" << endl;
    cout << "1. View Your Library" << endl;
    cout << "2. Find A Book" << endl;
    cout << "3. Books You've Read" << endl;
    cout << "4. Books To Read" << endl;
    cout << "5. Add to Your Library" << endl;
    cout << "6. Get Rid of Books" << endl;
    cout << "7. About Your Library" << endl;
    cout << "8. Quit " << endl;
    cout << "------------------------------" << endl;
    
}
