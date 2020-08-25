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
    setIO("buckets");
    vector<pi >v(3);
    FOR(i,10){
    	string str;
    	cin>>str;
    	FOR(j,10){
    		if(str[j] == 'B'){
    			v[0].first = i;
    			v[0].second = j;
    		}
    		if(str[j] == 'R'){
    			v[1].first = i;
    			v[1].second = j;
    		}
    		if(str[j] == 'L'){
    			v[2].first = i;
    			v[2].second = j;
    		}
    	}
    }
    if(v[0].first == v[2].first || v[0].second == v[2].second){
    	if(abs(v[0].first-v[1].first+v[0].second-v[1].second)+abs(v[2].first-v[1].first+v[2].second-v[1].second) == abs(v[0].first-v[2].first+v[0].second-v[2].second)){
    		cout<<abs(v[0].first-v[2].first)+abs(v[0].second-v[2].second)+1;
    		return 0;
    	}
    }
    cout<<abs(v[0].first-v[2].first)+abs(v[0].second-v[2].second)-1;

}
