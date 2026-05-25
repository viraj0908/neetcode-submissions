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
        int one=0;
        int two=0;
        if(s[0]=='0') {
            one=0;
            two=0;
        }
        else if(s[1]=='0'){
            one+=1;
            two=0;
        }
        else{
            one+=1;
            two+=1;
        }
        
        if(is_valid(s.substr(0,2))) two+=1;
        for(int i=2;i<n;i++){
            int temp=0;
            if(s[i]!='0') temp+=two;
            if(is_valid(s.substr(i-1,2))) temp+=one;
            one=two;
            two=temp;
        }
        return two;
    }
};
