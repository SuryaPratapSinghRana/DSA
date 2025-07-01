struct Node{
 Node* link[26];
 int flag=false;
 Node(){
     for(int i=0;i<26;i++){
         link[i]=NULL;
     }
 }

 bool iscontain(char ch){
     return (link[ch-'a']!=NULL);
 }
 void put(char ch,Node* node){
     link[ch-'a']=node;
 }
 Node* get(char ch){
     return link[ch-'a'];
 }
 void setend(){
     flag=true;
 }
 bool isend(){
     return flag;
 }

};

void insert(Node* node,string word){
    for(int i=0;i<word.length();i++){
        if(!node->iscontain(word[i]))
        {
            node->put(word[i],new Node());
        }
        node=node->get(word[i]);
    }
    node->setend();
}

bool isAllPrefix(Node* node,string word){
    for(int i=0;i<word.length();i++){
       node=node->get(word[i]);
       if(!(node->isend()))
       {
         return false;
       }
    }
    return true;
}




class Solution {
    public: 
    string longestValidWord(vector<string>& arr) {
        // code here
         Node* root=new Node();
 // insert in trie
    for(int i=0;i<arr.size();i++){
       insert(root,arr[i]);
    }
    string ans="";
    for(int i=0;i<arr.size();i++){
        if(isAllPrefix(root,arr[i]))
        {
            if(arr[i].length()>ans.length())
            {
                ans=arr[i];
            }
            else if(arr[i].length()==ans.length() && arr[i]<ans)
            {
                ans=arr[i];
            }
        }
    }

    return ans;
    }
};