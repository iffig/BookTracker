//
//  BookTree.hpp
//  BookTracker
//
//  Created by Francesca Figueroa on 11/21/16.
//  Copyright © 2016 iffig. All rights reserved.
//

#ifndef BookTree_hpp
#define BookTree_hpp

#include <stdio.h>
#include <string>

struct BookNode{
    
    int completed;
    std::string title;
    std::string author;
    std::string published;
    int rating;
    
    BookNode *parent;
    BookNode *leftChild;
    BookNode *rightChild;
    
    
    BookNode(){};
    BookNode(int _completed, std::string _title, std::string _author, std::string _published, int _rating){
        
        completed = _completed;
        title = _title;
        author = _author;
        published = _published;
        rating = _rating;
        
        leftChild = NULL;
        rightChild = NULL;
    }
    
};


class BookTree{
    
    public:
        BookTree();
        ~BookTree();
        void addBook(int _completed, std::string _title, std::string _author, std::string _published, int _rating);
        void deleteBook(std::string _title);
        void printLibrary();
        void printRead();
        void printUnread();
        void getBookInfo(std::string);
        int countRead();
        int countUnread();
        BookNode *highestRated(BookNode *node, std::string);
    

    protected:
    
    private:
        BookNode *root;
        void deleteAll(BookNode *node);
        void printLibrary(BookNode *node);
        void printRead(BookNode *node);
        void printUnread(BookNode *node);
        BookNode *searchLibrary(BookNode *node, std::string);
        int countRead(BookNode *node);
        int countUnread(BookNode *node);
        void updateBook(std::string _title);
};

#endif /* BookTree_hpp */
