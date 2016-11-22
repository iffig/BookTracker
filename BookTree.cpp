#include <iostream>
#include "BookTree.hpp"
using namespace std;



BookTree::BookTree(){
    
    root = NULL;
}
BookTree::~BookTree(){
    
    deleteAll(root);
    
}

void BookTree::deleteAll(BookNode *node){
    
    
}

void BookTree::addBook(int _completed, string _title, string _author, string _published, int _rating){
    
    BookNode *newBook = new BookNode(_completed, _title, _author, _published, _rating);
    BookNode *x = root;
    BookNode *y = NULL;
    
    // Case One: Empty Tree
    
    if(root == NULL){
        root = newBook;
    }
    
    // Case Two: Not Empty Tree
    else{
        while(x != NULL){
            y =x;
            if(newBook->title < x->title){
                x = x->leftChild;
            }
            else{
                x = x->rightChild;
            }
        }
        
        newBook->parent = y;
        if(newBook->title < y->title){
            y->leftChild= newBook;
        }
        else{
            y->rightChild = newBook;
        }
        
    }
    
}
void BookTree::deleteBook(string _title){
    
}

/* IN-ORDER Traversal: Left Child, Parent, Right Child*/
void BookTree::printLibrary(BookNode *node){
    
    if(node->leftChild != NULL){
        printLibrary(node->leftChild);
    }
    
    cout << node->title << " " << node -> rating << endl;
    
    if(node->rightChild != NULL){
        printLibrary(node->rightChild);
    }
    
}
void BookTree::printLibrary(){
    
    printLibrary(root);
    
}

void BookTree::printRead(BookNode *node){
    
    if(node->leftChild != NULL){
        printRead(node->leftChild);
    }
    
    if(node->completed == 1){
        cout << node->title << endl;
    }
    
    if(node->rightChild != NULL){
        printRead(node->rightChild);
    }
}


void BookTree::printRead(){
    
    printRead(root);
}

void BookTree::printUnread(BookNode *node){
    
    if(node->leftChild != NULL){
        printUnread(node->leftChild);
    }
    
    if(node->completed == 0){
        cout << node->title << endl;
    }
    
    
    if(node->rightChild != NULL){
        printUnread(node->rightChild);
    }
    
}

void BookTree::printUnread(){
    
    printUnread(root);
}

int BookTree::countBooks(){
    return 0;
}

BookNode* BookTree::searchLibrary(BookNode *node, string _title){
    
    if(node == NULL) return NULL;
    
    else if(node->title == _title) return node;
    
    // Continue Searching Recursively.
    else{
        
        if(node->title < _title){
            return searchLibrary(node -> leftChild, _title);
        }
        else {
            
            return searchLibrary(node->rightChild, _title);
        }
        
    }

}

void BookTree::getBookInfo(string _title){
    
    BookNode *searchedBook = searchLibrary(root, _title);
    
    if(searchedBook != NULL){
        cout << searchedBook->title << endl;
        cout << "======================================" << endl;
        cout << "Written by: " << searchedBook->author << " in " << searchedBook->published << endl;
        if(searchedBook->rating != 0){
             cout << "Your rating: " << searchedBook->rating << "/5" << endl;
        }
        else{
            cout << "[You have not rated this book.]" << endl;
        }
       
    }
    else {
        cout << "Book not in your library" << endl;
    }
    
}


void BookTree::updateBook(string _title){
    
}
