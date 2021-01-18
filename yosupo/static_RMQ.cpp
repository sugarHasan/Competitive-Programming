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

#define MOD 1000000007
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define ll long long
#define all(n) n.begin(), n.end()
#define sz(n) (int)(n).size()
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second
#define mp make_pair
#define left(n) (int)(2*n)
#define right(n) (int)(2*n+1)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORL(i,n) for(ll i=0;i<n;i++)
#define FORR(i,i_e,n,x) for(int i=i_e;i<n;i+=x)
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
const int MX = (int)1e5 * 6;
int seg[4*MX];

void build(const vector<int>&v , int node , int l , int r){
	if(l == r){
		seg[node] = v[l];
	}
	else{
		int mid =(l+r)/2;
		build(v , left(node) , l , mid);
		build(v , right(node) , mid+1 , r);
		seg[node] = min(seg[left(node)] , seg[right(node)]);
	}
}
int minSeg(int node , int l , int r , int lw , int rw){
	// cerr<<node<< ' '<<l<<' '<<r<<endl;
	if(l > r || l > rw || r < lw)	return (int)1e9+1;
	if(l >= lw && r <= rw)	return seg[node];
	int mid = (l+r)/2;
	return min(minSeg(left(node) , l , mid , lw , rw) , minSeg(right(node) , mid+1 , r , lw, rw));
}
int main() {
    // setIO("");
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    FOR(i,n)	scanf("%d" , &v[i]);
    build(v , 1 , 0 , n-1);
    while(t--){
    	int a,b;
    	cin>>a>>b;
    	b--;
    	cout<<minSeg(1 , 0 , n-1 , a , b)<<endl;
    }
}

