#include "LinkedList.h"
#include <iostream>
#include <limits>

// Constructor to initialize an empty list
LinkedList::LinkedList() : head(nullptr) {}

// Constructor to initialize list from array
LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = 0; i < len; ++i) {
        insertPosition(i + 1, array[i]);
    }
}

// Destructor to clean up the list
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getLink();
        delete temp;
    }
}

// Insert a new node at the specified position
void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);

    // Insert at the front if the position is less than or equal to 1
    if (pos <= 1 || head == nullptr) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    Node* current = head;
    // Traverse to the node before the desired position or the end of the list
    for (int i = 1; i < pos - 1 && current->getLink() != nullptr; ++i) {
        current = current->getLink();
    }

    // Insert the new node
    newNode->setLink(current->getLink());
    current->setLink(newNode);
}

// Delete a node at the specified position
bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos <= 0) return false;  

    // Special case: delete the head
    if (pos == 1) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }

    Node* current = head;
    // Traverse to the node before the desired position
    for (int i = 1; i < pos - 1 && current->getLink() != nullptr; ++i) {
        current = current->getLink();
    }

    Node* targetNode = current->getLink();
    if (targetNode == nullptr) return false;  

    // Delete the target node
    current->setLink(targetNode->getLink());
    delete targetNode;
    return true;
}

// Get the data at a specific position
int LinkedList::get(int pos) {
    if (pos <= 0) return std::numeric_limits<int>::max();

    Node* current = head;
    for (int i = 1; i < pos && current != nullptr; ++i) {
        current = current->getLink();
    }

    // Return data if the node exists, otherwise return max int value
    return current == nullptr ? std::numeric_limits<int>::max() : current->getData();
}

// Search for a target value and return its position
int LinkedList::search(int target) {
    Node* current = head;
    int pos = 1;

    // Traverse the list to find the target
    while (current != nullptr) {
        if (current->getData() == target) return pos;
        current = current->getLink();
        ++pos;
    }

    return -1;  // Return -1 if the target is not found
}

// Print the list
void LinkedList::printList() {
    if (head == nullptr) {
        std::cout << "[]";
        return;
    }

    Node* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->getData();
        current = current->getLink();
        if (current != nullptr) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}