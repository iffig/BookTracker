/*
    Basic book tracker.
    Keep logs of your personal library of books
    Along with the books you've read and your ratings.

 */

#include <iostream>
#include <fstream>
#include "BookTree.hpp"

using namespace std;

struct Book{
    
    int completed;
    string title;
    string author;
    string published;
    int rating;
    
    Book(){};
    Book(int _completed, string _title, string _author, string _published, int _rating){
        
        completed = _completed;
        title = _title;
        author = _author;
        published = _published;
        rating = _rating;
    }
    
};



void readLibraryIn(BookTree *booktree, string filename);

int main(int argc, const char * argv[]) {
    
    
    BookTree *library = new BookTree();
    
    //Reading in library file.
    readLibraryIn(library, argv[1]);
    
    library->printLibrary();
    
}


void readLibraryIn(BookTree *bookLib, string _file){
    
    ifstream in;
    in.open(_file);
    if (!in)
    {
        cout << "Could not open file\n";
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
