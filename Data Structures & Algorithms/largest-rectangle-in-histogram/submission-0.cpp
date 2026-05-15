class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,0),right(n,0);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({heights[i],i});
                right[i]=n-1-i;
            }
            else{
                while(!st.empty() && heights[i]<=st.top().first){
                    st.pop();
                }
                if(st.empty()) right[i]=n-1-i;
                else right[i]=st.top().second-1-i;
                st.push({heights[i],i});
            }
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({heights[i],i});
                left[i]=i;
            }
            else {
                while(!st.empty() && heights[i]<=st.top().first){
                    st.pop();
                }
                if(st.empty()) left[i]=i;
                else left[i]=i-st.top().second-1;
                st.push({heights[i],i});
            }
        }
        
        int area=0;
        for(int i=0;i<n;i++){
            int curr=heights[i]*(1+left[i]+right[i]);
            area=max(area,curr);
        }
        return area;
    }
};
