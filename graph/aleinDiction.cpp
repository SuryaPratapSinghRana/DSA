
// 26 ki jgah k lelena agar question mein  diya

class Solution {
    public:
    void topsort(int src,vector<int>&vis,stack<char>&st,vector<int>adj[])
    {
        vis[src]=1;
        for(auto neigh:adj[src])
        {
            if(!vis[neigh])
            {
                topsort(neigh,vis,st,adj);
            }
        }
        st.push(src+'a');
        return;
    }
      string findOrder(vector<string> &words) {
          // code here
          vector<int>adj[26];
          vector<int>present(26,0);
          for(int i=0;i<words.size()-1;i++)
          {
              string s1=words[i];
              string s2=words[i+1];
              int minlen=min(s1.length(),s2.length());
              for(int j=0;j<minlen;j++)
              {
                  if(s1[j]!=s2[j])
                  {
                      adj[s1[j]-'a'].push_back(s2[j]-'a');
                      present[s1[j]-'a']=1;
                      present[s2[j]-'a']=1;
                      break;
                  }
              }
          }
          stack<char>st;
          vector<int>vis(26,0);
          for(int node=0;node<26;node++)
          {
              if(present[node] && !vis[node])
              {
                  topsort(node,vis,st,adj);
              }
          }
          string ans="";
          while(!st.empty())
          {
              ans+=st.top();
              st.pop();
          }
      return ans;
      }
  };