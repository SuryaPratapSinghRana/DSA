class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int index = 0, lastindex = 0, n = words.size();
        vector<string> ans;
        while (index < n) {
            lastindex = index + 1;
            int count = words[index].length();
            // how many max words and character can come in this line'
            while (lastindex < n) {
                if (1 + words[lastindex].length() <= maxWidth) {
                    count += 1 + words[lastindex].length();
                    lastindex++;
                } else {
                    break;
                }
            }
            string s = words[index];
            int diff = lastindex - index - 1;
            // agar last length tak pahuch gaya to uske baad space dalenge or
            // agar ek hi word araha h to uske liye bhi dono karega ye if
            if (lastindex == n || diff == 0) {
                for (int i = index + 1; i < lastindex; i++) {
                    s += " ";
                    s += words[i];
                }
                for (int i = s.length(); i < maxWidth; i++) {
                    s += " ";
                }
            } else {
                int space =
                    (maxWidth - count) / diff; // spaces after every word
                int extraspace =
                    (maxWidth - count) % diff; // give extra space to left words
                for (int i = index + 1; i < lastindex; i++) {
                    // spaces after every word
                    for (int spc = 0; spc < space; spc++) {
                        s += " ";
                    }
                    // if extra space give to first word=
                    if (extraspace) {
                        s += " ";
                        extraspace--;
                    }
                    s += " "; // this space because we added 1 extra with each
                              // word because one space given atleast
                    s += words[i];
                }
            }
            ans.push_back(s);
            index = lastindex;
        }
        return ans;
    }
};