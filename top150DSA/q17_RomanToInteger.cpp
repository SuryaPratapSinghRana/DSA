class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int n=s.length();
        int sum=m[s[n-1]];  // akhari wala to add krna hi h
       for(int i=n-2;i>=0;i--)
       {
        if(s[i]=='I' && (s[i+1]=='X' || s[i+1]=='V') )
        {
            sum-=1;
        }
        else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C') )
        {
            sum-=10;
        }
        else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M') )
        {
            sum-=100;
        }
        else
        {
            sum+=m[s[i]];
        }
       }
       return sum;

    }
};