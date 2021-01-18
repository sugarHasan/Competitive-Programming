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
bool helper(const vector<vector<int>> &v , vector<int> &col , int node , int color){
	if(col[node] != -1){
		if(color != col[node])	return false;
		return true;
	}
	col[node] = color;
	bool temp = true;
	for(int i = 0 ; i < v[node].size() ; i++){
		if(!temp)	break;

		temp = temp&helper(v , col , v[node][i] , !color);
	}
	return temp;
}
bool isBipartite(const vector<vector<int>> &v){
	int n = v.size();
	if(!n)	return true;	
	vector<int> color(n , -1);
	return helper(v , color, 0 , 0);
}

class f(){
	priority_queue<pair<int,int>> pq;
	int count = 0;
	void add(int x){
		pq.push({--count , x});
	}
};
int longestPal(string str){
	int res = 0;
	//case 1
	for(int i = 0 ; i < str.size() ; i++){
		for(int j = 0 ; j < str.size() ; j++){
			if(i-j < 0 || i+j >= str.size())	break;
			if(str[i-j] != str[i+j]) break;
			res = max(res , 2*j+1);
		}
	}
	//case 2
	for(int i = 1 ; i < str.size() ; i++){
		for(int j = 1 ; j < str.size() ; j++){
			if(i-j < 0 || i+j >= str.size())	break;
			if(str[i-j] != str[i+j-1])	break;
			res = max(res , j*2);
		}
	}
	return res;
} 
int mn(vector<int> v , int k){
	priority_queue<int , vector<int> , greater<int>> pq;
	unordered_map <int,int> mp;
	for(auto a:v){
		mp[a]++;
	}
	map<int,int> ::iterator it;
	for(it = mp.begin() ; it!=mp.end() ; it++){
		pq.push(it->second);
	}
	while(pq.size()){
		if(pq.top() > k)	break;
		k -= pq.top();
		pq.pop();
	}
	return pq.size();

}
int main() {
    // setIO("measurement");
   
    printf("%s %s" , str1 , str2);
}





