class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            a[i].first=position[i];
            a[i].second=speed[i];
        }
        sort(a.begin(),a.end());
        vector<float> b(n);
        for(int i=0;i<n;i++){
            b[i]=((target-a[i].first)*1.0)/a[i].second;
        }
        stack<float> st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(b[i]);
            else{
                while(!st.empty() && b[i]>=st.top()){
                    st.pop();
                }
                st.push(b[i]);
            }
        }
        return st.size();
    }
};
