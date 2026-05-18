class Solution {
    vector<string> res;
    string ans="";
    void f(string &digits,string &ans,int ind,map<char,string> &hash){
        if(ind==digits.size()){
            res.push_back(ans);
            return;
        }
        char ch=digits[ind];
        string str=hash[ch];
        for(int i=0;i<str.size();i++){
            ans.push_back(str[i]);
            f(digits,ans,ind+1,hash);
            ans.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        map<char,string> hash{
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        f(digits,ans,0,hash);
        return res;

    }
};
