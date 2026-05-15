class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']+=1;
            b[t[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
        
    }
};
