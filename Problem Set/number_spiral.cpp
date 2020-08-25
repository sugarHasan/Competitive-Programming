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
#define FOR(i,n) for(int i=0;i<n;i++)

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
    // setIO("");
    int t;
    cin>>t;
    while(t--){
    	ll x,y;
    	cin>>y>>x;
    	if(x>y){
    		if(x%2){
    			cout<<x*x-y+1<<"\n";
    		}
    		else{
    			cout<<(x-1)*(x-1)+y<<"\n";
    		}
    	}
    	
    	else{
    		if(y%2){
    			cout<<(y-1)*(y-1) + x<<"\n";
    		}
    		else{
				cout<<y*y-x+1<<"\n";
    		}
    	}
    }
}
