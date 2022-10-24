class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length(),len =0,m_len =0;
    //stack for storing parenthesis
    stack<int> st;
    //insert 1st element as -1
    st.push(-1);
    for(int i =0;i<size;i++)
    {
        //if ( is the element, push in stack
        if(s[i] == '(')
            st.push(i);
        
        if(s[i] == ')')
        {
            st.pop();
            //if stack becomes empty after a pop, push i'th element
            if(st.empty())
                st.push(i);
            //store i - top index of stack in len
            len = i - st.top();
            m_len = max(m_len,len);
        }
    }
    return m_len;
    }
};