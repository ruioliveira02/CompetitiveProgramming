#include <bits/stdc++.h>

using namespace std;

const int alphabetSize = 27;

struct Trie {
    Trie* children[alphabetSize];
};


Trie* createTrie() {
    Trie* result = new Trie();
    
    for(int i = 0; i < alphabetSize; i++)
        result->children[i] = nullptr;

    return result;
}

void insertTrie(Trie* trie, string str) {
    int n = str.size();

    int index = 0;

    Trie* cur = trie;
    for(int i = 0; i < n; i++) {
        if(cur->children[str[i] - 'A'] == nullptr) {
            cur->children[str[i] - 'A'] = createTrie();
        }
        cur = cur->children[str[i] - 'A'];
    }

    //Null terminate string
    if(cur->children[alphabetSize - 1] == nullptr) {
        cur->children[alphabetSize - 1] = createTrie();
    }
}

void insertTrieMult(Trie* trie, vector<string> list) {
    for(int i = 0; i < list.size(); i++) {
        insertTrie(trie, list[i]);
    }
}

bool search(Trie* trie, string str) {
    Trie* cur = trie;

    for(int i = 0; i < str.size(); i++) {
        if(cur->children[str[i] - 'A'] == nullptr)
            return false;

        cur = cur->children[str[i] - 'A'];
    }

    return (cur->children[alphabetSize - 1] != nullptr);
}


int main() {
    Trie* trie = createTrie();

    vector<string> list({"ABC", "TESTE", "PROGRAMCAO"});

    insertTrieMult(trie, list);

    cout << search(trie, "ABC") << endl;
    cout << search(trie, "TES") << endl;
    cout << search(trie, "PROGRAMACAO") << endl;

    return 0;
}