#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

vector<pair<ii, int>> edges;

vi belmannFord(int N, int E, int src, int k) {
    vi ans(N, 1e9);
    vi prev(N, -1);

    ans[src] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].first.first, v = edges[j].first.second;
            if(ans[v] > ans[u] + edges[j].second) {
                ans[v] = ans[u] + edges[j].second;
                prev[v] = u;
            }
        }
    }

    return ans;
}


int main() {
    edges = vector<pair<ii, int>>(7);

    edges[0] = {{0,1}, 5};
    edges[1] = {{1,4}, -7};
    edges[2] = {{1,3}, -2};
    edges[3] = {{3,4}, 1};
    edges[4] = {{0,2}, 2};
    edges[5] = {{2,3}, 6};
    edges[6] = {{3,2}, -3};

    vi ans = belmannFord(5, 7, 0);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}