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
        //complete
        void commit();
        void checkout();
        doublyNode* getCurrentCommit();
        //returns the currently opened commit
        Repo();
        //constructor
        bool currentLatestMismatch();
        //checks whether current commit is latest; add/remove/commit disabled when checking out code
        int getLatestCommitNum();
        //returns num of latest commit
        doublyNode* createDoublyNode(int commitNum);
        //for first node
        doublyNode* createDoublyNode(int commitNum, doublyNode* previous);
    private:
        doublyNode* headNode;
        //first node
        doublyNode* latestCommit;
        doublyNode* currentCommit;
        int nodeCount;
};

#endif