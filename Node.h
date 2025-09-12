#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;
    
public:
    Node(int val) : data(val), link(nullptr) {}

    int getData() const { return data; }
    Node* getLink() const { return link; }
    void setLink(Node* nextNode) { link = nextNode; }
};

#endif