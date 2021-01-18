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
#define left(n) (int)(2*n)
#define right(n) (int)(2*n+1)
#define s second
#define mp make_pair
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
const int MX = (int)1e5*5;
ll seq[4*MX];
void build(int node , int l , int r , const vi &v){
	if(l==r){
		seq[node] = v[l];
	}
	else{
		int mid = (l+r)/2;
		build(left(node) , l , mid , v);
		build(right(node) , mid+1 , r , v);
		seq[node] = seq[left(node)]+seq[right(node)];
	}
}
void update(int node , int l , int r , int upd , int val){
	if(upd < l || upd > r)	return;
	if(l == r && l == upd){
		seq[node] += val;
	}	
	else{
		int mid = (l+r)/2;
		update(left(node) , l , mid , upd , val);
		update(right(node) , mid+1 , r , upd , val);
		seq[node] = seq[left(node)]+seq[right(node)];	
	}
}
ll findSum(int node, int l , int r , int lw , int rw){
	if(l>r || lw>r || l>rw)	return 0;
	if(l>=lw && r<=rw)	return seq[node];
	int mid= (l+r)/2;
	return findSum(left(node) , l , mid ,lw , rw) + findSum(right(node) , mid+1 , r , lw , rw);
}
int main() {
    // setIO("");
    int n,t;
    cin>>n>>t;
    vi v(n);
    FOR(i,n)	scanf("%d" , &v[i]);
    build(1 , 0 , n-1 , v);
    while(t--){
    	int a;
    	cin>>a;
    	if(a==0){
    		int b,c;
    		cin>>b>>c;
    		update(1 , 0 , n-1 , b , c);
    	}
    	else{
    		int b,c;
    		cin>>b>>c;
    		c--;
    		cout<<findSum(1 , 0, n-1 , b,c)<<endl;
    	}
    }
}

