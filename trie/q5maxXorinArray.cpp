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

//aap insert,getmax ye trie ki class bna ke usme bhi likh sakte ho for better looking

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
    int findMaximumXOR(vector<int>& nums) {
      Node* node=root;
      for(int i=0;i<nums.size();i++){
        insert(root,nums[i]);
      }
      // now do max xor of each number and find max of all max xor of number
      int maxi=INT_MIN;
      for(int i=0;i<nums.size();i++){
           maxi=max(getmaxXor(root,nums[i]),maxi);
      }
      return maxi;

    }
};