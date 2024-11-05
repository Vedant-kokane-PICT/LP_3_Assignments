#include<bits/stdc++.h>
using namespace std;



class node{
public:
    char data;
    int frequency;
    node *left, *right;
    node(char data,int frequency){
        this->data = data;
        this->frequency = frequency;
        left = right = NULL;
    }
};

struct cmp{
    bool operator()(node *left,node *right){
        return left->frequency > right->frequency;
    }  
};



void printCodes(node* top,string ans){
    if(top == NULL){
        return;
    }
    if(top->data != '$'){
        cout<<top->data<<" : "<<ans<<endl;
    }
    printCodes(top->left,ans + "0");
    printCodes(top->right,ans + "1");
}



void huffmanCodes(vector<char> &data, vector<int> &freq, int n){
    node *left, *right, *top;
    priority_queue<node*, vector<node*>, cmp> minHeap;
    for(int i=0;i<n;i++){
        node* tempNode = new node(data[i],freq[i]);
        minHeap.push(tempNode);
    }
    
    while(minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new node('$',left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    
    printCodes(minHeap.top(),"");
}




int main()
{
    vector<char> data = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    vector<int> freq = { 5, 9, 12, 13, 16, 45 }; 
    int n = data.size();
    huffmanCodes(data,freq,n);
    return 0;
}
