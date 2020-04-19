
#include<bits/stdc++.h>
using namespace std; 


int dp[100];

void dfs(int sv , int parent , vector<int> adj[] , int val[]){
	dp[sv] = val[sv];

	int maximum = 0;

	for(auto i : adj[sv]){
		if(i==parent) continue;

		dfs( i , sv , adj , val);
        maximum = max(maximum , dp[i]);

	}

	dp[sv] += maximum;
	

}

int main(){
   

   #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt","w", stdout);
#endif

int n  ;cin>>n;
vector<int> adj[n+1];

for(int i =1 ; i<=n -1 ; i++){
	int x, y;
	cin>>x>>y;
  adj[x].push_back(y);
  adj[y].push_back(x);
}

int val[n+1];
for(int i =1 ; i<=n ; i++) cin>>val[i];

dfs(1,0, adj, val);

cout<<dp[1];


}