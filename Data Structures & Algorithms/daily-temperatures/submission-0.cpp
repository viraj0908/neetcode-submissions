class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(st.empty()) st.push({temperatures[i],i});
            else{
                while(!st.empty() && temperatures[i]>st.top().first){
                    int ind=st.top().second;
                    res[ind]=i-ind;
                    st.pop();
                }
                st.push({temperatures[i],i});
            }
        }
        return res;
    }
};
