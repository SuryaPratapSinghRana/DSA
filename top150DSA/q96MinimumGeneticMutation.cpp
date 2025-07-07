class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());

        queue<string>q;
        unordered_map<string,int>vis;
     int level=0;
        //bfs
       q.push(startGene);

       while(!q.empty())
       {
         int N=q.size();
         while(N--)
         {
            string s=q.front();
            q.pop();
            if(s==endGene)
              return level;

            for(int i=0;i<s.length();i++)
            {
              for(char ch:"ACGT")
              {   string temp=s;
                temp[i]=ch;
                if(vis[temp]==0 && st.find(temp)!=st.end())
                {
                    q.push(temp);
                    vis[temp]=1;
                }
               }
            }
         }
         level++;
       }

       return -1;
    }
};