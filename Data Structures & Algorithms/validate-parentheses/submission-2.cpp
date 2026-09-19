class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char i:s)
        {
            if(i=='('||i=='{'||i=='[')
            {
                st.push(i);
            }
            else {
                if(st.size()==0)
                {
                    return false;
                }
                if((i==')'&&st.top()!='(')||(i==']'&&st.top()!='[')||(i=='}'&&st.top()!='{'))
                {
                    return false;
                }
                else 
                st.pop();
            }
        }
        if(st.size()!=0)
        return false;
        return true;
        
    }
};
