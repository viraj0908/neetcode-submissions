/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<=1) return n;
        vector<int> s(n),e(n);
        sort(intervals.begin(),intervals.end(),
        [](const Interval& a,const Interval& b){
            return a.start < b.start;
        });
        for(int i=0;i<n;i++){
            s[i]=intervals[i].start;
        }
        sort(intervals.begin(),intervals.end(),
        [](const Interval& a,const Interval& b){
            return a.end < b.end;
        });
        for(int i=0;i<n;i++){
            e[i]=intervals[i].end;
        }
        int start=0,end=0;
        int count=0,ans=0;
        while(start<n){
            if(s[start]<e[end]){
                start++;
                count++;
            }
            else{
                end++;
                count--;
            }
            ans=max(ans,count);
        }
        return ans;

        
    }
};
