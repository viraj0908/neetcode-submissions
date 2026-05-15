class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        if(n > m){
            swap(nums1, nums2);
            swap(n, m);
        }

        int total = n + m;
        int half = total / 2;

        int l = -1;
        int r = n - 1;

        while(true){

            int mid1 = l + (r-l)/2;
            int mid2 = half - mid1 - 2;

            int aleft  = (mid1 >= 0)  ? nums1[mid1]   : INT_MIN;
            int aright = (mid1+1 < n) ? nums1[mid1+1] : INT_MAX;

            int bleft  = (mid2 >= 0)  ? nums2[mid2]   : INT_MIN;
            int bright = (mid2+1 < m) ? nums2[mid2+1] : INT_MAX;

            if(aleft <= bright && bleft <= aright){

                if(total % 2){
                    return min(aright, bright);
                }

                return ((double)max(aleft, bleft)
                        + min(aright, bright)) / 2.0;
            }

            else if(aleft > bright){
                r = mid1 - 1;
            }

            else{
                l = mid1 + 1;
            }
        }
    }
};