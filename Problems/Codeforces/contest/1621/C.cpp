#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        vector<int> permutation(n, 0);

        int last = 1;
        
        for(int i = 0; i < n; i++) {
            if(!permutation[i]) {
                int x;
                do {
                    cout << "? " << i + 1 << endl;
                    cin >> x;
                } while(x != i + 1);

                last = x;

                while(!permutation[x - 1]) {
                    cout << "? " << i + 1 << endl;
                    cin >> x;
                    permutation[last - 1] = x; 
                    last = x;
                }
            }
        }

        cout << "! ";
        for(int i = 0; i < n; i++) {
            cout << permutation[i];

            if(i != n - 1)
                cout << " ";
        }

        cout << endl;

        cout.flush();
    }


    return 0;
}