#include<iostream>
#include<map>
#include<queue>
using namespace std;
string nonrepeating(string str)
{
   map<char,int> count;
    queue<int> q;
    string ans="";
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        // increase count
        count[ch]++;
        // queue mein push karo
        q.push(ch);
        while(!q.empty())
        {
            if(count[q.front()]>1)
            {
                // repeating character
                 q.pop();
            }
            else{
                // non repeating character mil gaya
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
          ans.push_back('#');
    }
    return ans;

}
int main()
{
    string str="aabc";
    string ans=nonrepeating(str);
   cout<<ans;
    return 0;
}