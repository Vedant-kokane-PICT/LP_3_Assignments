#include<bits/stdc++.h>
using namespace std;

// using recursive approach
int helper(int ind,int W, vector<int>& wt, vector<int>& val){
    if(ind == 0){
        if(wt[0] <= W){
            return val[0];
        }
        return 0;
    }
    
    int take = INT_MIN;
    int dontTake = INT_MIN;
    
    if(wt[ind] <= W){
        take = val[ind] + helper(ind-1,W-wt[ind],wt,val); 
    }
    dontTake = helper(ind-1,W,wt,val); 
    return max(take,dontTake);
}

int knapSack(int W, vector<int>& wt, vector<int>& val) {
    // Your code here
    int n = wt.size();
    //return helper(n-1,W,wt,val);


    // using iterative approach
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    for(int i=wt[0];i<=W;i++){
        dp[0][i] = val[0];
    }
    
    
    for(int ind=1;ind<n;ind++){
        for(int weight=1;weight<=W;weight++){
            int take = INT_MIN;
            int dontTake = INT_MIN;
            if(wt[ind] <= weight){
                take = val[ind] + dp[ind-1][weight-wt[ind]];
            }
            dontTake = dp[ind-1][weight];
            dp[ind][weight] = max(take,dontTake);
        }
    }
    
    
    return dp[n-1][W];
    
}
