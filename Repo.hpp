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
        void addFile(string fileName);
        bool removeFile(string fileName);
        // same as above although per writeup there are multiple error messages so error msgs must be included in function
        void commit();
        void checkout();
        doublyNode* getCurrentCommit();
        Repo();
        bool currentLatestMismatch();
        int getDoublyNodeCount();
        doublyNode* createDoublyNode(int commitNum);
        doublyNode* createDoublyNode(int commitNum, doublyNode* previous);
    private:
        doublyNode* headNode;
        doublyNode* latestCommit;
        doublyNode* currentCommit;
        int nodeCount;
};

#endif