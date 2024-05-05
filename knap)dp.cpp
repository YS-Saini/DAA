#include<iostream>
#include<vector>
using namespace std;

void Knapsack(vector<int> wt,vector<int> v,int n){
    vector<vector<int>> dp(wt.size()+1,vector<int>(n+1,0));
    for (int i=1;i<=wt.size();i++){
        for (int w=1;w<=n;w++){
            if (w>=wt[i-1])
                dp[i][w]=max(dp[i-1][w],dp[i-1][w-wt[i-1]]+v[i-1]);
            else    
                dp[i][w]=dp[i-1][w];
            cout<<dp[i][w]<<' ';
        }
        cout<<endl;
    }

    int current_weight=n;
    for (int i=wt.size();i>=1;i--){
        if (dp[i][current_weight]!=dp[i-1][current_weight]){
            cout<<i<<' ';
            current_weight-=wt[i-1];
        }
    }

}
main(){
    vector<int> wt={2,3,4,5};
    vector<int> p={3,4,5,6};
    Knapsack(wt,p,5);
}