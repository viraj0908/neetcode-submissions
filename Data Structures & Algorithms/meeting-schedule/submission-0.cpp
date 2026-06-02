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
    bool overlap(Interval &u,Interval &v){
        return !(v.start >= u.end || v.end <= u.start);
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<=1) return true;
        sort(intervals.begin(), intervals.end(),
         [](const Interval& a, const Interval& b){
             return a.start < b.start;
         });
        Interval previous=intervals[0];
        for(int i=1;i<n;i++){
            if(overlap(previous,intervals[i]) ) return false;
            else previous=intervals[i];
        }
        return true;
    }
};
