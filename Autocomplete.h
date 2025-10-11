#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class AutocompleteTrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, AutocompleteTrieNode*> children;

    AutocompleteTrieNode();
    ~AutocompleteTrieNode();
};

class Autocomplete {
private:
    AutocompleteTrieNode* root;

    void findAllWords(AutocompleteTrieNode* node, string prefix, vector<string>& results);

public:
    Autocomplete();

    void insert(const string& word);

    vector<string> getSuggestions(const string& partialWord);
    // Owns and frees all trie nodes to avoid memory leaks
    ~Autocomplete();
};

#endif