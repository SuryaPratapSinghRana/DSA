class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        int count=0;
        while(i>=0)
        {
            if(s[i]!=' ')
            {
                count++;
            }
            else if(count>0)
            {
                
                return count;
            }
            i--;

        }
        return count;
    }
}; 