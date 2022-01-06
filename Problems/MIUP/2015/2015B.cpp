#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> numberToBitset(int number, int n) {
    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++) {
        if(number & (1 << i)) 
            ans[i] = 1;
    }

    return ans;
}

vector<vector<string> > lst;

bool valid(vector<int> bitset) {
    for(int i = 0; i < lst.size(); i++) {
        stack<bool> operators;
        for(int j = 0; j < lst[i].size(); j++) {
            if(lst[i][j] == "+") {
                bool fst = operators.top();
                operators.pop();
                bool snd = operators.top();
                operators.pop();

                operators.push(fst | snd);
            } else if(lst[i][j] == "*") {
                bool fst = operators.top();
                operators.pop();
                bool snd = operators.top();
                operators.pop();

                operators.push(fst & snd);
            } else if(lst[i][j] == "-") {
                bool fst = operators.top();
                operators.pop();

                operators.push(!fst);
            } else {
                int index = stoi(lst[i][j]);
                operators.push((bitset[index] == 1));
            }
        }

        if(operators.top() != (bitset[i] == 1))
            return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;

    lst = vector<vector<string> > (n);

    for(int i = 0; i < n; i++) {
        int count;
        cin >> count;
        lst[i] = vector<string>(count);

        for(int j = 0; j < count; j++)
            cin >> lst[i][j];
    }

    int ans = 0;
    int limit = 1 << n;

    for(int i = 0; i < limit; i++) {
        vector<int> bs = numberToBitset(i, n);

        if(valid(bs))
            ++ans;
    }

    cout << ans << endl;

    return 0;
}