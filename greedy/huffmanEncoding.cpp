class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class cmp{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
class Solution
{
	public:
	 void preorder(node* root,vector<string> &ans,string str)
	 {
	     if(root->left==NULL && root->right==NULL){
	         ans.push_back(str);
	         return;
	     }
	     preorder(root->left,ans,str+'0');
	     preorder(root->right,ans,str+'1');
	 }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<node*,vector<node*>,cmp> pq;
		    for(int i=0;i<N;i++){
		        node* temp=new node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size()>1)
		    {
		        node* temp1=pq.top();
		        pq.pop();
		        node* temp2=pq.top();
		        pq.pop();
		        node* temp=new node(temp1->data+temp2->data);
		        temp->left=temp1;
		        temp->right=temp2;
		        pq.push(temp);
		    }
		    node* root=pq.top();
		    vector<string> ans;
		    preorder(root,ans,"");
		    return ans;
		}
};