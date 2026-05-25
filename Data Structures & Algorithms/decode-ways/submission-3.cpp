class Solution {
    bool is_valid(string str){
        if(str[0]=='0') return false;
        int x=stoi(str);
        return x>=0 && x<=26;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0) return 0;
        if(n==1) return (s[0]!='0');
        vector<int> dp(n,0);
        if(s[0]=='0') {
            dp[0]=0;
            dp[1]=0;
        }   
        else if(s[1]=='0'){
            dp[0]+=1;
            dp[1]=0;
        }
        else{
            dp[0]+=1;
            dp[1]+=1;
        }
        if(is_valid(s.substr(0,2))) dp[1]+=1;
        for(int i=2;i<n;i++){
            if(s[i]!='0') dp[i]+=dp[i-1];
            if(is_valid(s.substr(i-1,2))) dp[i]+=dp[i-2];
        }
        return dp[n-1];
    }
};
