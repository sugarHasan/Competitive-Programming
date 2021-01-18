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
void make_par(int a , vector<int> &uni){
	uni[a] = a;
}
int parnt(int a , vector<int>& uni){
	if(a == uni[a])	return a;
	return uni[a] = parnt(uni[a] , uni);
}
void unip(int a , int b , vector<int> &uni){
	int x = parnt(a,uni);
	int y = parnt(b , uni);
	if(x!=y){
		uni[y] = x;
	}
}

int main() {
    // setIO("");
    int n;
    cin>>n;
    vector<int> uni(n);
    FOR(i,n)	uni[i] = i;
    int t;
    cin>>t;
    while(t--){
    	int a,b,c;
    	cin>>a>>b>>c;
    	if(a==0){
    		unip(b,c,uni);
    	}
    	else{
    		if(parnt(b , uni) == parnt(c , uni))	cout<<1<<endl;
    		else	cout<<0<<endl;
    	}
    }
}

