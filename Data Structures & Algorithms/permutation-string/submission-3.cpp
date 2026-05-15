class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<s1.size();i++) freq1[s1[i]-'a'] +=1;
        int l=0,r=s1.size()-1;
        for(int i=l;i<=r;i++){
            freq2[s2[i]-'a']+=1;
        }
        while(r<s2.size()){
            if(freq1==freq2) return true;
            freq2[s2[l]-'a']-=1;
            l++;
            r++;
            freq2[s2[r]-'a']+=1;
        }
        return false;
    }
};
