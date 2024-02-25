//
//  List.cpp
//  DoublyLinkedList
//
//  Created by Madhuri Debnath on 9/24/20.
//

#include<iostream>
#include "List.h"
using namespace std;

void List::insert(int value) {   
    Node* temp = new Node(value);
    if (!headPtr->getNextPtr()) {
        headPtr->setNextPtr(temp);
    
    } else {
        Node* prev = tailPtr->getPrevPtr();
        prev->setNextPtr(temp);
        temp->setPrevPtr(prev);
    }
    tailPtr->setPrevPtr(temp);
}

void List::insertAtIndex(int data, int index) {
    if (!headPtr->getNextPtr()) {
        if (index) {
            return;
        }
        Node* temp = new Node(data);
        headPtr->setNextPtr(temp);
        tailPtr->setPrevPtr(temp);
        return;
    }
    Node* curr = headPtr->getNextPtr();
    Node* prev = headPtr->getPrevPtr();
    while (curr && index) {
        prev = curr;
        curr = curr->getNextPtr();
        index--;
    }
    if (index) {
        return;
    }
    Node* temp = new Node(data, curr, prev);
    prev->setNextPtr(temp);
    curr->setPrevPtr(temp);
}
void List::deleteAtIndex(int index) {
    if (!headPtr->getNextPtr()) {
        return;
    }
    Node* curr = headPtr->getNextPtr();
    Node* prev = headPtr;
    while (curr && index) {
        prev = curr;
        curr = curr->getNextPtr();
        index--;
    }
    if (index) {
        return;
    }
    prev->setNextPtr(curr->getNextPtr());
    prev->getNextPtr()->setPrevPtr(prev);
}

void List::readItem(int index) {
    Node* curr = headPtr->getNextPtr();
    while (curr && index) {
        curr = curr->getNextPtr();
        index--;
    }
    cout << curr->getData() << endl;
}
    
void List::reverseList() {
    Node* temp = headPtr;
    Node* curr = headPtr->getNextPtr();
    while (curr) {
        temp = curr->getPrevPtr();
        curr->setPrevPtr(curr->getNextPtr());
        curr->setNextPtr(temp);
        curr = curr->getPrevPtr();
    }
    if (temp) {
        headPtr->setNextPtr(temp->getPrevPtr());
    }
}

void List::printForward() {
    Node* curr = headPtr->getNextPtr();
    while (curr) {
        cout << curr->getData() << ' ';
        curr = curr->getNextPtr();
    }
    cout << endl;
}

void List::printBackward() {
    Node* curr = tailPtr->getPrevPtr();
    while (curr) {
        cout << curr->getData() << ' ';
        curr = curr->getPrevPtr();
    }
    cout << endl;
}

