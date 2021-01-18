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
int dp[2500][2500];
int main() {
    setIO("mowing");
    int t;
    cin>>t;
    int i = 1200 , j = 1200;
    int count = 1;
    int res = (int)1e5;
    while(t--){
        int n;
        char c;
        cin>>c>>n;
        if(c == 'E'){
            for(int k = 0 ; k < n ; k++){
                i++;
                count++;
                if(dp[i][j]){
                    res = min(count - dp[i][j] , res);
                }
                dp[i][j] = count;
            }
        }
        else if(c == 'W'){
            for(int k = 0 ; k < n ; k++){
                i--;
                count++;
                if(dp[i][j]){
                    res = min(count - dp[i][j] , res);
                }
                dp[i][j] = count;
            }
        }
        else if(c == 'N'){
            for(int k = 0 ; k < n ; k++){
                j--;
                count++;
                if(dp[i][j]){
                    res = min(count - dp[i][j] , res);
                }
                dp[i][j] = count;
            }
        }
        else if(c == 'S'){
            for(int k = 0 ; k < n ; k++){
                j++;
                count++;
                if(dp[i][j]){
                    res = min(count - dp[i][j] , res);
                }
                dp[i][j] = count;
            }
        }
    }
    if(res == (int)1e5)
        res = -1;
    cout<<res<<endl;
}

