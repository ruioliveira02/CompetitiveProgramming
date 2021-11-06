#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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


vector<ll> dp;

ll solve(Trie* trie, string str, int i) {
    if(dp[i] != -1)
        return dp[i];

    if(str.size() == i)
        return 0;

    ll res = 1e18;

    Trie* cur = trie;
    for(int j = 0; j < str.size(); j++) {
        int h = str[i + j] - 'A';
        cur = cur->children[h];
        if(cur == nullptr)
            break;

        if(cur->children[26] != nullptr)
            res = min(res, 1LL + solve(trie, str, i + j + 1));
    }
    
    dp[i] = res;
    return res;
}


int main() {
    int p;
    cin >> p;

    Trie* trie = createTrie();
    for(int i = 0; i < p; i++) {
        string str;
        cin >> str;

        insertTrie(trie, str);
    }

    int s;
    cin >> s;

    for(int i = 0; i < s; i++) {
        string str;
        cin >> str;

        dp = vector<ll>(205, -1);

        ll res = solve(trie, str, 0);

        if(res == 1e18) 
            cout << "no" << endl;
        else
            cout << res << endl;
    }


    return 0;
}