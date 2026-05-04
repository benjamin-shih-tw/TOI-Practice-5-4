#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;
#define pii pair<ll,ll>
#define SZ(x) ((ll)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define fo(i,n) for(ll i = 0 ; i < (n) ; i++)
#define foo(i,a,b) for(ll i = (a) ; i <= (b) ; i++)
#define F first
#define S second
#define pb push_back
const ll mxn = 2e5+10;
vector<ll> g[mxn];
ll indeg[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,m;
    cin >> n >> m;
    while(m--){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        indeg[v]++;
   }

   // topo
   bool only = 1;
   queue<ll> q;
   foo(i,1,n){
        if(!indeg[i]) q.push(i);
   }
   while(SZ(q)){
        ll now = q.front(); q.pop();
        for(auto nxt : g[now]){
            if(!--indeg[nxt]) q.push(nxt);
        }
        if(SZ(q) > 1) only = 0;
   }
   cout << (only ? "0" : "1");
}