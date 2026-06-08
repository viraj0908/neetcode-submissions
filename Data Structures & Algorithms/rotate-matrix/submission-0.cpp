class Solution {
void f(vector<vector<int>>& matrix,
       int left,int right,
       int top,int down){

    if(left >= right) return;

    for(int offset = 0; offset < right-left; offset++){

        int temp = matrix[top][left+offset];

        matrix[top][left+offset]
            = matrix[down-offset][left];

        matrix[down-offset][left]
            = matrix[down][right-offset];

        matrix[down][right-offset]
            = matrix[top+offset][right];

        matrix[top+offset][right]
            = temp;
    }

    f(matrix,
      left+1,right-1,
      top+1,down-1);
}
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        f(matrix,0,n-1,0,n-1);
        return ;
    }
};
