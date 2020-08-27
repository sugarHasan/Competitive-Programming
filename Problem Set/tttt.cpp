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

int solve(const vector<string> &v , int teamNo){
	int res = 0;
	set<int> s;
	FOR(i , 3){
		FOR(j, 3){
			s.insert(v[i][j]);
		}
		if(s.size() == teamNo)
			res++;
		s.clear();
	}
	FOR(i , 3){
		FOR(j, 3){
			s.insert(v[j][i]);
		}
		if(s.size() == teamNo)
			res++;
		s.clear();
	}
	s.insert(v[0][0]);s.insert(v[1][1]);s.insert(v[2][2]);
	if(s.size() == teamNo)
		res++;
	s.clear();
	s.insert(v[0][2]);s.insert(v[1][1]);s.insert(v[2][0]);
	if(s.size() == teamNo)
		res++;
	s.clear();
	return res;
}
int main() {
    setIO("tttt");
    vector<string> v(3);
    FOR(i , 3)
    	cin>>v[i];
    FORR(i , 1 , 3 , 1)
    	cout<<solve(v ,i)<<endl;
}

