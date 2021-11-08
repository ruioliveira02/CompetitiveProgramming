#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

vector<pair<ii, int>> edges;

vll belmannFord(int N, int E, int src, int k) {
    vll ans(N, 1e18);
    vi prev(N, 0);

    ans[src] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].first.first, v = edges[j].first.second;
            if(ans[v] > ans[u] + edges[j].second && prev[u] < k) {
                ans[v] = ans[u] + edges[j].second;
                prev[v] = prev[u] + 1;
            }
        }
    }

    return ans;
}


int main() {
    int n, r, c;

    cin >> n >> r >> c;

    edges = vector<pair<ii, int>>(c);
    for(int i = 0; i < c; i++) {
        int x, y, z;
        char ch;

        cin >> x >> y >> ch >> z;

        int cost = (ch == 'C' ? -1 * z : z);
        edges[i] = {{x,y}, cost};
    }

    vll ans = belmannFord(r, c, 0, n);

    string str = "yes";

    if(ans[r - 1] > 1e8)
        str = "impossible";
    else if(ans[r - 1] >= 0)
        str = "no";

    cout << str << endl;
    return 0;
}