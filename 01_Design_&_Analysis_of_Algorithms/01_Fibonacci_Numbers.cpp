#include <bits/stdc++.h>
using namespace std;

// TC - O(2^N) , SC - O(N) (stack space)
// Recursive Approach
int helper1(int n){
    if(n <= 1){
        return n;
    }
    return helper1(n-1) + helper1(n-2);
}


//  TC - O(N) , SC - O(1) 
// Iterative Approachx
int helper2(int n){
    int first = 0;
    int second = 1;
    for(int i=2;i<=n;i++){
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main()
{
    int n = 10;
    cout<<helper1(n)<<endl;
    cout<<helper2(n)<<endl;
    return 0;
}
