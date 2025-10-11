#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class PrefixMatcherTrieNode {
public:
    int routerNumber;
    unordered_map<char, PrefixMatcherTrieNode*> children;

    PrefixMatcherTrieNode();
    ~PrefixMatcherTrieNode();
};

class PrefixMatcher {
private:
    PrefixMatcherTrieNode* root;

public:
    PrefixMatcher();

    void insert(const string& address, int routerNumber);

    int selectRouter(const string& networkAddress);
    // Owns and frees all trie nodes to avoid memory leaks
    ~PrefixMatcher();
};

#endif