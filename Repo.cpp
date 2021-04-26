#include "Repo.hpp"
#include <iostream>
using namespace std;

int count = 0;

doublyNode* createDoublyNode(int commitNum) {
    doublyNode* initialNode = new doublyNode;
    initialNode->head = NULL;
    initialNode->previous = NULL;
    initialNode->commitNumber = commitNum;
    count ++;
    initialNode->next = NULL;
}

doublyNode* createDoublyNode(int commitNum, doublyNode* previous) {
    doublyNode* initialNode = new doublyNode;
    initialNode->head = NULL;
    initialNode->previous = previous;
    initialNode->commitNumber = commitNum;
    count ++;
    initialNode->next = NULL;
}

Repo::Repo()
//constructor
{
    headNode = createDoublyNode(count);
    latestCommit = headNode;
}

void Repo::commit() {
    latestCommit->next = createDoublyNode(count, latestCommit);
}

