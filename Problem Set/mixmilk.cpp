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

int main() {
    setIO("mixmilk");
    vi c(3),m(3);
    FOR(i,3){
    	cin>>c[i]>>m[i];
    }
    FOR(i,100){
    	int temp = m[(i+1)%3];
    	m[(i+1)%3] = min(c[(i+1)%3] , m[(i+1)%3] + m[i%3]);
    	m[i%3] -= (m[(i+1)%3]-temp);
    }
    FOR(i,3){
    	cout<<m[i]<<endl;
    }
}

