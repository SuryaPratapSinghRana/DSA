
//a bina trie ke modify  coding ninja

struct Node{
    Node* link[26];
    bool flag=false;
    Node(){
        for(int i=0;i<26;i++){
            link[i]=NULL;
        }
    }
    
    bool iscontain(char ch)
    {
        return (link[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return link[ch-'a'];
    }
    void setend(){
       flag=true;
    }
    bool isset(){
        return flag;
    }
};

int countDistinctSubstrings(string &s)
{
    Node* root=new Node();
    
    Node* node=root;

     int count=0;
     
     // ek tarike se yahi pe bana diya insert function usme count bhi lga diya
    
    for(int i=0;i<s.length();i++)
      {  Node* node=root;
          for(int j=i;j<s.length();j++){
            if(!node->iscontain(s[j]))
            {
            node->put(s[j],new Node());
            count++;
            }
            node=node->get(s[j]);
         }
         node->isset();
       }
       
       return count+1;
}


// trie modify only take unordered map   gfg

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    unordered_map<char, Node*> link;
};

int countDistinctSubstring(string s) {
    Node* root = new Node();
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        Node* node = root;
        for (int j = i; j < s.length(); j++) {
            char ch = s[j];
            if (node->link.find(ch) == node->link.end()) {
                node->link[ch] = new Node();
                count++;
            }
            node = node->link[ch];
        }
    }

    return count + 1;  // +1 for empty string
}