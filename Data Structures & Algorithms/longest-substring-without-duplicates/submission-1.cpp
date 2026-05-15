class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_map<char,int> freq;
        int l=0,r=0,ans=1;
        while(r<n){
            freq[s[r]]+=1;
            if(freq[s[r]]>1){
                while(freq[s[r]]>1){
                    freq[s[l]]-=1;
                    l++;
                }
            }
            else {
                ans=max(ans,r-l+1);
                // r++;
            }
            r++;
        }
        return ans;
    }
};
