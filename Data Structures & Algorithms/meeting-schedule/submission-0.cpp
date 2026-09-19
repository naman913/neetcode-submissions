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
    static bool comp(Interval &a , Interval &b){
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int previous_meeting=0;
        for(auto i:intervals){
            if(previous_meeting>i.start){
                return false;
            }else {
                previous_meeting = i.end;
            }
        }
        return true;
        
    }
};
