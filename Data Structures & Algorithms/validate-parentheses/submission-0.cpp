class Solution {
public:
    bool isValid(string s) {
        map<char,char> hash={
            {']','['},
            {'}','{'},
            {')','('}
        };
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(hash.count(s[i])){
                if(!st.empty() && st.top()==hash[s[i]]){
                    st.pop();
                }
                else return false;
            }
            else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
