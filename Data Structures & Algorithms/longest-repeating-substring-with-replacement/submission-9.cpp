class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==0) return 0;
        vector<int> freq(26,0);
        int l=0,r=0,ans=1,maxf=0;
        while(r<n){
            int ind=s[r]-'A';
            freq[ind]+=1;
            maxf=max(maxf,freq[ind]);
            int size=r-l+1;
            int count=size-maxf;
            if(count<=k){
                ans=max(ans,size);
                r++;
            }
            else {
                while(count>k && l<r){
                    freq[s[l]-'A']-=1;
                    maxf=0;
                    for(int i=0;i<26;i++){
                        maxf=max(maxf,freq[i]);
                    }
                    l++;
                    size=r-l+1;
                    count=size-maxf;                                       
                }
                r++;
            }
        }
        return ans;
    }
};
