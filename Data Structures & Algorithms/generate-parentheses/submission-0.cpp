class Solution {
public:
    vector<string> res;
    string ans="";
    void f(string &ans,int bal,int cnt){
        
        if(bal==0 && cnt==0){
            res.push_back(ans);
            return;
        }
        else if(bal==0 && cnt>0){
            ans.push_back('(');
            f(ans,bal+1,cnt-1);
            ans.pop_back();
        }
        else if(bal>0 && cnt==0){
            ans.push_back(')');
            f(ans,bal-1,cnt);
            ans.pop_back();
        }
        else{
            ans.push_back('(');
            f(ans,bal+1,cnt-1);
            ans.pop_back();
            ans.push_back(')');
            f(ans,bal-1,cnt);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        f(ans,0,n);
        return res;
    }
};
