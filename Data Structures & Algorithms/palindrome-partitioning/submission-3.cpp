class Solution {
    bool is_palindrome(string s,int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    vector<vector<string>> res;
    vector<string> ans;
    void f(vector<string> &ans,int ind,string s){
        if(ind==s.size()){
            res.push_back(ans);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(is_palindrome(s,ind,i)) {
                string str="";
                for(int j=ind;j<=i;j++) str+=s[j];
                ans.push_back(str);
                f(ans,i+1,s);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        f(ans,0,s);
        return res;
    }
};
