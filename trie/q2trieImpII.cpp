#include <bits/stdc++.h> 

struct Node{
Node* link[26];
int endwith=0;
int countpref=0;

bool containkey(char ch){
    return (link[ch-'a']!=NULL);
}
Node* get(char ch){
    return link[ch-'a'];
}
void put(char ch,Node* node){
    link[ch-'a']=node;
}
void increaseprefix()
{
    countpref++;
}
void increaseend(){
    endwith++;
}

void deleteEnd(){
    endwith--;
}
void reducePref()
{
    countpref--;
}

int getEnd(){
    return endwith;
}
int getPref(){
    return countpref;
}


};

class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containkey(word[i]))
            {
                node->put(word[i],new Node);
            }
            node=node->get(word[i]);
            node->increaseprefix();
        }
        node->increaseend();
    }

    int countWordsEqualTo(string &word){
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(node->containkey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containkey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        node->getPref();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containkey(word[i]))
            {
                node=node->get(word[i]);
                node->reducePref();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};
