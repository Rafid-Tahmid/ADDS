#include "Autocomplete.h"
#include <algorithm>

AutocompleteTrieNode::AutocompleteTrieNode() : isEndOfWord(false) {}
AutocompleteTrieNode::~AutocompleteTrieNode() {
    for (auto &p : children) {
        delete p.second;
    }
}

Autocomplete::Autocomplete() {
    root = new AutocompleteTrieNode();
}

void Autocomplete::insert(const string& word) {
    AutocompleteTrieNode* currentNode = root;
    for (char ch : word) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            currentNode->children[ch] = new AutocompleteTrieNode();
        }
        currentNode = currentNode->children[ch];
    }
    currentNode->isEndOfWord = true;
}

void Autocomplete::findAllWords(AutocompleteTrieNode* node, string prefix, vector<string>& results) {
    if (node->isEndOfWord) {
        results.push_back(prefix);
    }
    for (auto& child : node->children) {
        findAllWords(child.second, prefix + child.first, results);
    }
}

vector<string> Autocomplete::getSuggestions(const string& partialWord) {
    vector<string> suggestions;
    AutocompleteTrieNode* currentNode = root;

    for (char ch : partialWord) {
        if (currentNode->children.find(ch) == currentNode->children.end()) {
            return suggestions;
        }
        currentNode = currentNode->children[ch];
    }

    findAllWords(currentNode, partialWord, suggestions);
    sort(suggestions.begin(), suggestions.end());
    return suggestions;
}

Autocomplete::~Autocomplete() {
    delete root;
}