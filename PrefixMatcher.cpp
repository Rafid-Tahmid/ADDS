#include "PrefixMatcher.h"

PrefixMatcherTrieNode::PrefixMatcherTrieNode() : routerNumber(-1) {}
PrefixMatcherTrieNode::~PrefixMatcherTrieNode() {
    for (auto &p : children) {
        delete p.second;
    }
}

PrefixMatcher::PrefixMatcher() {
    root = new PrefixMatcherTrieNode();
}

void PrefixMatcher::insert(const string& address, int routerNumber) {
    PrefixMatcherTrieNode* currentNode = root;
    for (char bit : address) {
        if (currentNode->children.find(bit) == currentNode->children.end()) {
            currentNode->children[bit] = new PrefixMatcherTrieNode();
        }
        currentNode = currentNode->children[bit];
    }
    currentNode->routerNumber = routerNumber;  // Set router number at the end of the address
}

int PrefixMatcher::selectRouter(const string& networkAddress) {
    PrefixMatcherTrieNode* currentNode = root;
    int longestMatchRouter = -1;

    for (char bit : networkAddress) {
        if (currentNode->routerNumber != -1) {
            longestMatchRouter = currentNode->routerNumber;
        }

        if (currentNode->children.find(bit) == currentNode->children.end()) {
            break;
        }
        currentNode = currentNode->children[bit];
    }

    if (currentNode->routerNumber != -1) {
        longestMatchRouter = currentNode->routerNumber;
    }

    return longestMatchRouter;
}

PrefixMatcher::~PrefixMatcher() {
    delete root;
}