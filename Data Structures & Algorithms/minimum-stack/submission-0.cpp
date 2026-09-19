class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.size()==0)
            st.push({val,val});
        else{
            int k=st.top().second;
            if(k>val)
                st.push({val,val});
            else
                st.push({val,k});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() { 
        return st.top().second;
    }
};
