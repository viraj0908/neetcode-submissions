class Solution {
    bool is_number(string s){
        if(s[0]=='-' && s.size()>1){

            for(int i=1;i<s.size();i++){
                if(!isdigit(s[i])) return false;
            }

            return true;
        }
        for(char ch:s){
            if(!isdigit(ch)) return false;
        }
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(is_number(s)) {
                st.push(stoi(s));
            }
            else {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                if(s=="+") st.push(y+x);
                else if(s=="-") st.push(y-x);
                else if(s=="*") st.push(x*y);
                else st.push(y/x);
            }
        }
        int ans=st.top();
        st.pop();
        return ans;
        
    }
};
