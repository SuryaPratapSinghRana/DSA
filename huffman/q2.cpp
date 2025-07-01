#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    int freq;
    struct node* right,*left;
    node(char data,int freq)
    {
        this->data=data;
        this->freq=freq;
        this->right=NULL;
        this->left=NULL;
    }
};
typedef struct node node;
struct compare{
    bool operator()(node* a,node* b)
    {
        return a->freq>b->freq;
    }
};
void printcode(node* root,string str)
{
    if(root->data!='$')
    {
        cout<<root->data<<" : "<<str<<endl;
        return;
    }
    printcode(root->left,str+"0");
    printcode(root->right,str+"1");
}
void huffman(int freq[],char data[],int n)
{
 priority_queue<node*,vector<node*>,compare> pq;
 for(int i=0;i<n;i++)
 {
    pq.push(new node(data[i],freq[i]));
 }
 while(pq.size()!=1)
 {
    node* left=pq.top();
    pq.pop();
    node* right=pq.top();
    pq.pop();
    node *root=new node('$',right->freq+left->freq);
    root->left=left;
    root->right=right;
    pq.push(root);

 }
 printcode(pq.top(),"");
}
int main()
{   int n=6;
    char data[]={'A','B','C','D','E','F'};
    int freq[]={55,20,12,25,30,8};
    huffman(freq,data,n);
}