class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        int n=strs.size();
        for(int i=0;i<n;i++){
            res+=(to_string(strs[i].size()));
            res.push_back('#');
            res+=strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        string num="";
        vector<string> res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                string str="";
                for(int j=0;j<stoi(num);j++){
                    str.push_back(s[i+j+1]);
                }
                res.push_back(str);
                i+=(stoi(num));
                num="";

            }
            else{
                num.push_back(s[i]);
            }
        }
        return res;
    }
};
