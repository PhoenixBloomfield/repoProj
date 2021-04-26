#include "Repo.hpp"
#include <iostream>
using namespace std;

doublyNode* Repo::createDoublyNode(int commitNum) {
    doublyNode* initialNode = new doublyNode;
    initialNode->head = NULL;
    initialNode->previous = NULL;
    initialNode->commitNumber = commitNum;
    nodeCount ++;
    initialNode->next = NULL;
    return initialNode;
}

doublyNode* Repo::createDoublyNode(int commitNum, doublyNode* previous) {
    doublyNode* initialNode = new doublyNode;
    initialNode->head = NULL;
    initialNode->previous = previous;
    initialNode->commitNumber = commitNum;
    nodeCount ++;
    initialNode->next = NULL;
    return initialNode;
}


Repo::Repo() : nodeCount(0)
//constructor
{
    headNode = createDoublyNode(getLatestCommitNum());
    latestCommit = headNode;
    currentCommit = headNode;
}

void Repo::commit() {
    latestCommit->next = createDoublyNode(getLatestCommitNum(), latestCommit);
    latestCommit = latestCommit->next;
    currentCommit = latestCommit;
}

bool Repo::currentLatestMismatch() {
    if((currentCommit->commitNumber) == latestCommit->commitNumber) return false;
    cout << "Error: operation prohibited while checking out code." << endl;
    return true;
}

doublyNode* Repo::getCurrentCommit()  {
    return currentCommit;
}

singlyNode* createSinglyNode(string fileName, singlyNode* next) {
    singlyNode* newNode = new singlyNode;
    newNode->fileName = fileName;
    newNode->next = next;
    newNode->fileVersion = "00";
    return newNode;
}

void Repo::addFile(string fileName) {
    singlyNode* newNode = createSinglyNode(fileName, latestCommit->head);
    latestCommit->head = newNode;
    cout << " Successfully added." << endl;
}

int Repo::getLatestCommitNum() {
    return nodeCount;
}

bool Repo::removeFile(string fileName) {
    bool found = false;
    singlyNode* current = latestCommit->head;
    if(current == NULL) {
        return false;
    }
    if(current->fileName == fileName) {
        latestCommit->head = current->next;
        delete current;
        return true;
    }
    while(found == false && current->next != NULL) {
        if(current->next->fileName == fileName) found == true;
        else current = current->next;
    }
    if(found == false) return false;
    singlyNode* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return true;
}
