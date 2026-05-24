class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        if(s.size()==0) return res;
        int resL=1;
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 >= resL){
                    res=s.substr(l,r-l+1);
                    resL=r-l+1;
                    // l--;
                    // r++;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 >= resL){
                    res=s.substr(l,r-l+1);
                    resL=r-l+1;
                    // l--;
                    // r++;
                } 
                l--;
                r++;
            }
        }
        return res;
    }
};
