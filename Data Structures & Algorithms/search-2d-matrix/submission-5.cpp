class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,r=n*m-1;
        while(l<=r){
            int mid=(l+r)/2;
            int mi=mid/m;
            int mj=mid%m;
            if(matrix[mi][mj]<target) l=mid+1;
            else if(matrix[mi][mj]>target) r=mid-1;
            else return true;
        }
        return false;
    }
};
