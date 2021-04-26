#ifndef REPO_H
#define REPO_H
#include <string>
#include <iostream>
using namespace std;

struct singlyNode{
    std::string fileName; // Name of local file
    std::string fileVersion; // Name of file in .minigit folder
    singlyNode * next;
};

struct doublyNode{
    int commitNumber;
    singlyNode * head;
    doublyNode * previous;
    doublyNode * next;
};


class Repo {
    public:
    bool addFile(string fileName);
    // true if succeeds, false allows for printing of error messages
    bool removeFile(string fileName);
    // same as above although per writeup there are multiple error messages so error msgs must be included in function
    void commit();
    void checkout();
    Repo();
    private:
    doublyNode* headNode;
    doublyNode* latestCommit;
};

#endif