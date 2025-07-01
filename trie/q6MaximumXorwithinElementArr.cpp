struct Node{
Node* link[2]; // ya to 0 ya 1 kyunki binary mein store hoga hmara number;
Node(){
    link[0]=NULL;
    link[1]=NULL;
}
bool iscontain(int bit){
    return (link[bit]!=NULL);
}
void put(int bit,Node* node){
    link[bit]=node;
}
Node* get(int bit){
    return link[bit];
}
};

class Solution {
private:
Node* root=new Node();
public:
 void insert(Node* node,int num){
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;  // ye ith bit of number dega
        if(!node->iscontain(bit))
        {
            node->put(bit,new Node());
        }
        node=node->get(bit);
    }
 }
 int getmaxXor(Node* node,int num)
 {
    int maxXor=0; // all bit of number initally 0 karo
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(node->iscontain(1-bit)){
            maxXor=maxXor|(1<<i);  //matlab hum i bit ko 1 kar rahe
            node=node->get(1-bit); 
        }
        else
        {  // else mein hume opposite bit nahi milli to hume zero karni thi ith bit of maxXor lekin by default all bit of max are zero so go to next bit
           node=node->get(bit);  
        }
    }
    return maxXor;
 }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int nq=queries.size();
        vector<pair<int,pair<int,int>>>offlineQry; // {mi,{xi,idx of qeury}}
        for(int i=0;i<nq;i++){
            offlineQry.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offlineQry.begin(),offlineQry.end());
        vector<int>ans(nq);
        int idx=0;  // num array ke 0 pe rakho vahi sabase chhote element pe h abhi
        for(int i=0;i<nq;i++){
           int x=offlineQry[i].second.first; // is number ka karo xor
           int m=offlineQry[i].first;  // isse chhote ke saath kro xor
           int idxQry=offlineQry[i].second.second; // onlineqry index means jis order mein input mila tha
           // now insert all elemen in trie which is smaller than or equal to m
           while(idx<nums.size() && nums[idx]<=m){
             insert(root,nums[idx]);
             idx++;
           }
           if(idx==0) // mean their is no number in arr smaller than m
           {  
              ans[idxQry]=-1;
           }
           else
           {
             ans[idxQry]=getmaxXor(root,x);
           }
        }
        return ans;
    }
};