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
        vector<int> rooms;
        sort(intervals.begin(),intervals.end(),
        [] (const Interval &a,const Interval &b){
            return a.start<b.start;
        });
        if(n==0) return 0;
        rooms.push_back(intervals[0].end);
        for(int i=1;i<intervals.size();++i){
            bool room_found=false;
            for(int j=0;j<rooms.size();j++){
                if(intervals[i].start>=rooms[j]){
                    rooms[j]=intervals[i].end;
                    room_found=true;
                    break;
                }
            }
            if(!room_found) rooms.push_back(intervals[i].end);
        }
        return rooms.size();
    }
};
