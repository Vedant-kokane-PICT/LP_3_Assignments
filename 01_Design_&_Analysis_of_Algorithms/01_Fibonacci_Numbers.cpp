#include<bits/stdc++.h>
using namespace std;

// Using recursive approach
int helper1(int n){
    if(n <= 1){
        return n;
    }
    return helper1(n-1) + helper1(n-2);
} 

// using iterative approach
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

int main(){
  cout<<helper1(8);
  cout<<endl;
  cout<<helper2(8);
  return 0;
}
