#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define fo(i,n) for(int i = 0 ; i < (n) ; i++)
#define foo(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define F first
#define S second
#define pb push_back
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1),b(n+1);
    foo(i,1,n) { cin >> a[i]; b[i] = 500 - a[i]; }

    
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k,p;
            char f;
            cin >> k >> p >> f;
            if(f == 'A'){
                a[k] += p;
            }
            else{
                b[k] += p;
            }
        }
        else if(t == 2){
            int l,r;
            char f;
            cin >> l >> r >> f;
            int cnt = 0;
            if(f == 'A'){
                int sum = 0;
                foo(i,l,r) sum += a[i];
                int av = (sum) / (r-l+1);
                foo(i,l,r){
                    if(a[i] > av){
                        cnt++;
                    }
                }
            }
            else{
                int sum = 0;
                foo(i,l,r) sum += b[i];
                int av = (sum) / (r-l+1);
                foo(i,l,r){
                    if(b[i] > av){
                        cnt++;
                    }
                }
            }
            cout << cnt << '\n';
        }
    }
//     while(q--){
//         int t;
//         cin >> t;
//         int l,r;
//         cin >> l >> r;
//         char f;
//         cin >> f;
//         if(t == 1){
//             if(f == 'A'){
//                 a[l] += r;
//             }
//             else{
//                 a[l] -= r;
//             }
//         }
//         else if(t == 2){
//             int cnt = 0;
//             if(f == 'A'){
//                 int sum = 0;
//                 foo(i,l,r) sum += a[i];
//                 int av = sum / (r-l+1);
//                 foo(i,l,r){
//                     if(a[i] >= av) cnt++;
//                 }
//             }
//             else{
//                 int sum = 0;
//                 foo(i,l,r) sum += (500 - a[i]);
//                 int av = sum / (r-l+1);
//                 foo(i,l,r){
//                     if(b[i] >= av) cnt++;
//                 }
//             }
//             cout << cnt << '\n';
//         }
//     }
}