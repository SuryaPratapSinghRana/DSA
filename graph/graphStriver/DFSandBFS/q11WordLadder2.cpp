
// giving tle

class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord,
                                           vector<string>& wordList) {
            unordered_set<string> st(wordList.begin(), wordList.end());;
            vector<vector<string>> ans;
            queue<vector<string>> q;
            q.push({beginWord});
            int flag = 0;
            while (!q.empty()) {
                int size = q.size();
                unordered_set<string> usedInThisLevel;
                while (size--) {
                    vector<string> temp = q.front();
                    q.pop();
                    string s=temp.back(); //ex:"ab"->"cb" tha vector of string mein ab hum "cb" ke adjacent hi to dhoondege
                    if (s == endWord) {
                        ans.push_back(temp);
                        flag = 1;
                        continue;
                    }
                    for (int i = 0; i < s.length(); i++) {
                        for (char ch = 'a'; ch <= 'z'; ch++) {
                            string tempstr = s;
                            tempstr[i] = ch;
                            if (st.find(tempstr) != st.end()) {
                                temp.push_back(tempstr);
                                q.push({temp});
                                temp.pop_back();
                                usedInThisLevel.insert(tempstr);
                            }
                        }
                    }
                }
    
                for (auto& word : usedInThisLevel)
                {
                     st.erase(word);
                }
    
                if (flag)
                    return ans;
            }
    
            return {};
        }
    };