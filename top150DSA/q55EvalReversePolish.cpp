class Solution {
public:
    int cal(int a,int b,char ch)
    {
        switch(ch)
        {
            case'-':return a-b;
            case'+':return a+b;
            case'/':return a/b;
            case'*':return a*b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens)
        {
            if(it=="+" || it=="-"  || it=="*" || it=="/")
            {
               int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int calcu=cal(a,b,it[0]);
                st.push(calcu);
            }
            else
            {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};