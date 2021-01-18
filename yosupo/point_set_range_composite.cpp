/*
    *
    * Hasan Yildirim
    * 
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define MOD 998244353
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define ll long long
#define all(n) n.begin(), n.end()
#define sz(n) (ll)(n).size()
#define pi pair<ll,ll>
#define pl pair<ll,ll>
#define f first
#define s second
#define mp make_pair
#define left(n) (ll)(2*n)
#define right(n) (ll)(2*n+1)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define FORL(i,n) for(ll i=0;i<n;i++)
#define FORR(i,i_e,n,x) for(ll i=i_e;i<n;i+=x)
#define FORRL(i,i_e,n,x) for(ll i=i_e;i<n;i+=x)

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
    else{
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    }
}
const int MXN = (int)1e5*5;
struct Node{
	ll a = 0,b = 0;
};
struct Node seq[4*MXN];
void merge(ll n){
	seq[n].a = (seq[left(n)].a*seq[right(n)].a)%MOD;
	seq[n].b = (((seq[left(n)].b*seq[right(n)].a)%MOD)+seq[right(n)].b)%MOD;
}
void build (int n , int l , int r ,const vector<pair<ll,ll>> &v){
	if(l == r){
		seq[n].a = v[l].f;
		seq[n].b = v[l].s;
	}
	else{
		int mid = (l+r)/2;
		build(left(n) , l , mid , v);
		build(right(n) , mid+1 , r, v);
		merge(n);
	}
}
void update(int n , int l , int r , int pos , const pair<ll,ll>& temp){
	if(l > pos || r < pos)	return;
	if(l == r && pos == l){
		seq[n].a = temp.f;
		seq[n].b = temp.s;
	}
	else{
		int mid = (l+r)/2;
		update(left(n) , l , mid ,pos ,  temp);
		update(right(n) , mid+1 , r , pos , temp);
		merge(n);
	}
}
struct Node mg(struct Node l , struct Node r){
	struct Node ret;
	ret.a = (l.a*r.a)%MOD;
	ret.b = (((l.b*r.a)%MOD)+r.b)%MOD;
	return ret;
}
struct Node find(int n , int l , int r, int lw , int rw){
	if(l >= lw && r <= rw)	return seq[n];
	if(rw < l || lw > r){
		struct Node nll;
		nll.a=1 , nll.b = 0;
		return nll;
	}
	int mid = (l+r)/2;
	return mg(find(left(n) , l , mid , lw , rw) , find(right(n) , mid+1 , r , lw , rw));
}
int main() {
    // setIO("");
    int n,t;
    cin>>n>>t;
    vector<pair<ll,ll>> v(n);
    FOR(i,n)	scanf("%lld%lld" , &v[i].f , &v[i].s);
    build(1 , 0 , n-1 , v);
    // FOR(i,20){
    // 	cerr<<i<<' '<<seq[i].a<<' '<<seq[i].b<<endl;
    // }
    while(t--){
    	int x,y,z,q;
    	scanf("%d%d%d%d" , &x , &y , &z , &q);
    	if(x==0){
    		update(1 , 0 , n-1 , y , {z,q});
    	}
    	else{
    		struct Node res = find(1 , 0 , n-1 , y , z-1);
    		printf("%d\n" ,(int) ((res.a*q)%MOD+res.b)%MOD);
    	}	
    }
}

