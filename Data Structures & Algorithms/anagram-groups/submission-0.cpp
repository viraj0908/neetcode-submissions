class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> hash;
        for(int i=0;i<strs.size();i++){
            vector<int> count(26,0);
            for(int j=0;j<strs[i].size();j++){
                count[strs[i][j]-'a']+=1;
            }
            hash[count].push_back(strs[i]);
        }
        for(auto i: hash){
            ans.push_back(i.second);
        }
        return ans;
    }
};
