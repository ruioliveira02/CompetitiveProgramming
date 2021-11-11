#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;

    vii servers(n);
    for(int i = 0; i < n; i++) {
        cin >> servers[i].first;
        servers[i].second = 1;
    }

    int m;
    cin >> m;

    ll sum = 0;

    vector<ll> ans(n, 0LL);

    vector<int> carryover(n, 0);

    for(int i = 0; i < n; i++) 
        sum += (ll)servers[i].first;

        
    int cur = 0;

    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if(str == "S") {
            int x;
            cin >> x;

            x--;
            
            if(servers[x].second) {
                servers[x].second = 0;
                sum -= servers[x].first;
            } else {
                servers[x].second = 1;
                sum += servers[x].first;
            }

            carryover[x] = 0;
        } else {
            int x = stoi(str);

            for(int j = 0; j < n; j++) {
                int h = (cur + j) % n;
                if(carryover[h] == servers[h].first || !servers[h].second) {
                    carryover[h] = 0;
                    continue;
                }

                if(x <= servers[h].first - carryover[h]) {
                    carryover[h] = x;
                    ans[h] += x;
                    cur = h;
                    x = 0;
                    break;
                } else {
                    ans[h] += servers[h].first - carryover[h];
                    x -= servers[h].first - carryover[h];
                    carryover[h] = 0;
                }
            }
            
            int repetions = x / sum;
            x %= sum;

            for(int i = 0; i < n; i++) 
                if(servers[i].second)
                    ans[i] += repetions * servers[i].first;

            if(x == 0)
                continue;
            for(int j = 0; j < n; j++) {
                int h = (cur + j) % n;
                if(carryover[h] >= servers[h].first || !servers[h].second) {
                    carryover[h] = 0;
                    continue;
                }

                if(x <= servers[h].first - carryover[h]) {
                    carryover[h] = x;
                    ans[h] += x;
                    cur = h;
                    x = 0;
                    break;
                } else {
                    ans[h] += servers[h].first - carryover[h];
                    x -= servers[h].first - carryover[h];
                    carryover[h] = 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << endl;
    
    return 0;
}