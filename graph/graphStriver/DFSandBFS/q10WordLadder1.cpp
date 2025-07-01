class Solution {
    public:
        int ladderLength(string beginWord, string endWord,
                         vector<string>& wordList) {
            unordered_set<string> st(wordList.begin(), wordList.end());
            unordered_map<string, int> vis;
    
            queue<pair<string,int>> q;
            q.push({beginWord,1});
            vis[beginWord] = 1;
            while (!q.empty()) {
                    string s = q.front().first;
                    int level = q.front().second;
                    q.pop();
                    if (s == endWord)
                        return level;
                    for (int i = 0; i < s.length(); i++) {
                        for (int j = 97; j <= 122; j++) {
                            string temp = s;
                            char ch = j;
                            temp[i] = ch;
                            if (vis[temp] == 0 && st.find(temp) != st.end()) {
                                q.push({temp,level+1});
                                vis[temp] = 1;
                            }
                        }
                    }
               
            }
            return 0;
        }
    };