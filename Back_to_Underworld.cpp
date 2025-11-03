 #include <bits/stdc++.h>
using namespace std;
#define  optimize() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;

#define pb push_back
#define sz size()
#define F first
#define S second
#define y() cout << "YES" << endl;
#define n() cout << "NO" << endl;
#define all(x) (x).begin(),(x).end()
#define input(x) for(auto &u:(x)) cin >> u;
#define print(x) for(auto &u:(x)) cout << u;
#define endl '\n'
const ll mod = 2e4+123;
ll tp = 1;
ll cnt = 0, cnt1 = 0;
vl adj[mod];
bool vis[mod];
vl ache(mod);

void dfs(ll n, ll col) {
    vis[n] = 1;
    cnt++;
    ll tem;
    if (col == 1) {
        tem = 2;
        cnt1++;
    } else tem = 1;
    for (auto &u : adj[n]) {
        if (!vis[u]) dfs(u, tem);
    }
   // ekhane mainly DFS er moddhe color change korte korte traversal hocche
// backtracking mane, jokhon ekta node theke return hocche, tokhon tar parent node e fire ashe
// and next unvisited node e jaye, parent-er color dekhe opposite color dei

// example:
// adj[1] = 2,3
// adj[2] = 1
// adj[3] = 4,5
// adj[4] = 3
// adj[5] = 3

// prothome 1 ke color 1 dei
// tarpor 1 theke 2 e gele 2 ke color 2 dei
// 2 theke back kore ashe, erpor 1 theke 3 e jai, 3 ke color 2 dei (opposite of 1)
// 3 theke 4 e gele 4 ke color 1 dei
// pore 3 theke 5 e gele 5 ke color 1 dei

// eivabe dfs diye ekta component er moddhe alternately color deya hocche
// cnt = total node count, cnt1 = color 1 er count
// output e max(cnt1, cnt - cnt1) deya mane — kon color group boro seta print korche

}

void restore() {
    
    cnt = 0;
    cnt1 = 0;
    for (int i = 0; i < mod; i++) {
        adj[i].clear();
        vis[i] = 0;
        ache[i] = 0;
    }
}

void test() {
    ll m;
    cin >> m;

    while (m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        ache[a] = 1;
        ache[b] = 1;
    }

    for (int i = 1; i < mod; i++) {
        if (!ache[i]) continue;
        if (!vis[i]) {
            dfs(i, 1);
        }
    }
    cout << "Case "<<  tp << ": "<<max(cnt1,cnt-cnt1) << endl;
    tp++;
    restore(); 
}

int main() {
    optimize()
    ll testCase;
    cin >> testCase;
    while (testCase--) test();
    return 0;
}
