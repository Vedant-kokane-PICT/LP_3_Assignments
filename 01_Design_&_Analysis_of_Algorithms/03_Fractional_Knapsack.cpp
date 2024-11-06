#include <bits/stdc++.h>
using namespace std;

const static bool cmp(pair<int,int> &a,pair<int,int> &b){
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;
    
    return r1 > r2;
}

// Write a program to solve a fractional Knapsack problem using a greedy method.
void helper(vector<int> wt, vector<int> val, int W){
    vector<pair<int,int>> arr;
    for(int i=0;i<wt.size();i++){
        arr.push_back({wt[i],val[i]});
    }
    
    sort(arr.begin(),arr.end(),cmp);
    double ans = 0.0;
    for(auto x:arr){
        if(W > 0){
            if(x.first <= W){
                W = W - x.first;
                ans += x.second;
            }
            else{
                double fractionalValue = (W * x.second) / x.first;
                W = 0;
                ans += fractionalValue;
            }
        }
    }
    
    cout<<ans<<endl;
}


int main()
{
    // vector<int> val = {60, 100, 120};
    // vector<int> wt = {10, 20, 30};
    // int W = 50;
    // helper(wt,val,W);
    // vector<int> val = {10, 20, 30};
    // vector<int> wt = {5, 10, 15};
    // int W = 100;
    // helper(wt,val,W);
    vector<int> val = {60,100};
    vector<int> wt = {10,20};
    int W = 50;
    helper(wt,val,W);
    return 0;
}
