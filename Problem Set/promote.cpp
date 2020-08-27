#include <bits/stdc++.h> 
using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define all(n) n.begin(), n.end()
#define sz(n) (int)(n).size()
#define pi pair<int,int>
#define f first
#define s second
#define mp make_pair
#define left(n) 2*n
#define right(n) 2*n+1
#define mid(n) left(n)+right(n)/2

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}
/*
    *
    * Hasan Yildirim
    * 
*/
int main() {
    setIO("promote");
    int b1,b2,s1,s2,g1,g2,p1,p2;
    cin>>b1>>b2>>s1>>s2>>g1>>g2>>p1>>p2;
    vector<ll> res(3,0);
    res[2] = p2-p1;
    res[1] = res[2] + g2-g1;
    res[0] = res[1] + s2-s1;
    for(int i = 0 ; i < 3 ; i++){
    	cout<<res[i]<<endl;
    }
}

