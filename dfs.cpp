#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll N = 1e5+1;

void dfs(int x, int fa, int dep){
   vector<int> adj[500005], w[500005];
   int n, ans, f[500005], lim, cnt;
   bool on[500005];
   f[x] = fa;
   lim = max(lim, dep);
   w[dep].push_back(x);
   for(auto i: adj[x]){
    if(i != fa)
     dfs(i, x, dep+1);
   }
}

int dfs(int y, int x, vector<pair<int, int>> &arr){
     string s[55];
     int n, m, k;
     int visited[55][55];
      if(y<0 || y>=n || x<0 || x>=m){
         return 1;
      }
      if(s[y][x] == '*'){ return 0;}
      if(visited[y][x]){ return 0; }
      visited[y][x] = 1;
      arr.push_back({y, x});
      int r = 0;
      for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            if((i==0)^(j==0)){
                r |= dfs(y+i, x+j, arr);
            }
        }
      }
      return r;
}

int dfssolve(int x, int y, int d){
    vector<int> v[200005];
    int r[200005];
    int l = 0;
    for(auto i: v[x]){
        if(i!=y){
           l += dfssolve(i, x, d+1);
        }
    }
    r[x] = d-l;
    return l+1;
}

void dfs(int ch, int fa, vector<int> &ans, unordered_map<int, set<int>> &adj, vector<bool> &visited){
   ans.push_back(ch);
   visited[ch] = true;
   
   for(auto i: adj[ch]){
    if(i != fa && (visited[i] == false)){
        dfs(i, ch, ans, adj, visited);
    }
   }
} 

void dfs(int node, int fa, int d, int &ans, int fr) {
    vector<pair<int, int>> adjlist[N];
    ans = max(ans, d);
    for(auto it: adjlist[node]) {
        int y = it.first;
        int z = it.second;
        if(y != fa) {
            dfs(y, node, d + (z < fr), ans, z);  
        }
    }
}


void dfs(int x, int now) {
    int arr[100005];
    int ans = 0;
    unordered_map<int, vector<pair<int, int>>> adj;
     if(now > arr[x]) return;
     else{
        ++ans;
     }
     int len = adj[x].size();
     for(int i = 0; i<len; i++){
        dfs(adj[x][i].first, max(0, now+adj[x][i].second));
     }
}

void solve(){

}

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
     
    // func();
    // fact();
    // precheck();
    // prepower();
    // precompute();  
    // vector<bool> prime = sieveOfEratosthenes(1000);
    int t;
    cin >> t;
    while (t--) { 
     solve();
    }
    return 0;
}
