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
    /**
     * Inserts a node at the end of the list
     *
     * @param value Data for new node
     * @return void
     */

    Node* temp = new Node(value);

    // check if list is empty, update necessary pointers
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
    /**
     * Inserts a node at a given index, does nothing if index is out of bounds.
     *
     * @param data Data for new node, should a new node be inserted
     * @param index Insert node at this index
     * @return void
     */

    if (!headPtr->getNextPtr()) {
        // don't do anything if list is empty and index != 0
        if (index) {
            return;
        }
        Node* temp = new Node(data);
        headPtr->setNextPtr(temp);
        tailPtr->setPrevPtr(temp);
        return;
    }
    // traverse list until correct position is found
    Node* curr = headPtr->getNextPtr();
    Node* prev = headPtr;
    while (curr && index) {
        prev = curr;
        curr = curr->getNextPtr();
        index--;
    }
    // index isn't valid if index != 0 at this point
    if (index) {
        return;
    }
    // check if insert position is at front of list
    if (prev == headPtr) {
        Node* temp = new Node(data, curr, nullptr);
        headPtr->setNextPtr(temp);
        if (!tailPtr->getPrevPtr()) {
            tailPtr->setPrevPtr(temp);
        }

    // check if insert position is at end of list
    } else if (!curr) {
        Node* temp = new Node(data, nullptr, prev);
        tailPtr->setPrevPtr(temp);

    // insert position at middle of list
    } else {
        Node* temp = new Node(data, curr, prev);
        prev->setNextPtr(temp);
        curr->setPrevPtr(temp);
    }
}
void List::deleteAtIndex(int index) {
    /**
     * Deletes the node at a given index, does nothing if index is invalid.
     *
     * @param index Delete node at this index
     * @return void
     */

    // if there are no nodes in the list, do nothing
    if (!headPtr->getNextPtr()) {
        return;
    }
    // iterate through the list until node at given index is found
    Node* curr = headPtr->getNextPtr();
    Node* prev = headPtr;
    while (curr && index) {
        prev = curr;
        curr = curr->getNextPtr();
        index--;
    }
    // if index is greater than list length, do nothing
    if (index || !curr) {
        return;
    }
    // check if curr is last node
    if (tailPtr->getPrevPtr() == curr) {
        // check if curr is also first node
        if (prev != headPtr) {
            tailPtr->setPrevPtr(prev);

        } else {
            tailPtr->setPrevPtr(nullptr);
        }

    } else {
        // check if curr is first node
        if (prev != headPtr) {
            curr->getNextPtr()->setPrevPtr(prev);

        } else {
            curr->getNextPtr()->setPrevPtr(nullptr);
        }
    }
    // delete curr node
    prev->setNextPtr(curr->getNextPtr());
    
    // if curr is first node, no need to reassign prev pointer
    if (prev != headPtr) {
        prev->getNextPtr()->setPrevPtr(prev);
    }
}

void List::readItem(int index) {
    /**
     * Prints the node's data at a given index.
     *
     * @param index Print node's data at this index
     * @return void
     */

    Node* curr = headPtr->getNextPtr();
    while (curr && index) {
        curr = curr->getNextPtr();
        index--;
    }
    // if curr != nullptr, index is valid
    if (curr) {
        cout << curr->getData() << endl;
    }
}
    
void List::reverseList() {
    // Check for empty list
    if (headPtr->getNextPtr() == nullptr) {
        return;
    }

    Node* curr = headPtr->getNextPtr();
    Node* prev = nullptr;
    Node* next = nullptr;

    // Store new first and last nodes to change after list is reversed
    Node* newHead = tailPtr->getPrevPtr();
    Node* newTail = headPtr->getNextPtr();

    // Traverse through the list and change next and prev pointers accordingly
    while (curr) {
        next = curr->getNextPtr();
        curr->setNextPtr(prev);
        curr->setPrevPtr(next);
        prev = curr;
        curr = next;
    }
    // Update head and tail pointers
    headPtr->setNextPtr(newHead); 
    tailPtr->setPrevPtr(newTail);
}


void List::printForward() {
    /**
     * Prints each node's data of the list from front to back.
     *
     * @return void
     */

    // set curr to first node of list and traverse through the list
    Node* curr = headPtr->getNextPtr();
    while (curr) {
        cout << curr->getData() << ' ';
        curr = curr->getNextPtr();
    }
    cout << endl;
}

void List::printBackward() {
    /**
     * Prints each node's data of the list in reverse order.
     *
     * @return void
     */

    // set curr to last node of list and traverse through the list backwards
    Node* curr = tailPtr->getPrevPtr();
    while (curr) {
        cout << curr->getData() << ' ';
        curr = curr->getPrevPtr();
    }
    cout << endl;
}
