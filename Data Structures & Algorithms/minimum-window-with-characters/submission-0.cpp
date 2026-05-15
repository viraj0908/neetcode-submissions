class Solution {
    bool check(vector<int> freq1,vector<int> freq2){
        bool f=false;
        for(int i=0;i<52;i++){
            if(freq1[i]<freq2[i]){
                f=true;
                break;
            }
        }
        return !f;
    }
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        vector<int> freq1(52,0),freq2(52,0);
        for(int i=0;i<t.size();i++){
            if(t[i]>='a' && t[i]<='z') freq2[t[i]-'a']+=1;
            else freq2[t[i]-'A'+26]+=1;
        }
        int l=0,r=0,resl=0,resr=s.size();
        while(r<s.size()){
            if(s[r]>='a' && s[r]<='z'){
                freq1[s[r]-'a']+=1;
            }
            else freq1[s[r]-'A'+26]+=1;
            while(check(freq1,freq2) && l<=r){
                if((r-l+1)<(resr-resl+1)){
                    resr=r;
                    resl=l;
                }
                if(s[l]>='a' && s[l]<='z') {
                    freq1[s[l]-'a']-=1;
                }
                else freq1[s[l]-'A'+26]-=1;
                l++;
            }
            // l-=1;
            r++;

        }
        if(resr-resl+1>s.size()) return "";
        string res="";
        for(int i=resl;i<=resr;i++){
            res+=s[i];
        }
        return res;
    }
};
