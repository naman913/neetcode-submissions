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
        int max_meeting =INT_MIN;
        vector<int>start;
        vector<int>end;
        for(auto i:intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }
        if(intervals.size()==0)
        return 0;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int cnt =0;
        int i=0,j=0;
        int current_time =0;
        while(i<intervals.size()&&j<intervals.size()){
            current_time=end[j];
            if(start[i]<end[j]){
                i++;
                max_meeting = max(++cnt,max_meeting);
            }else{
                j++;
                max_meeting = max(--cnt,max_meeting);
            }
        }
        return max_meeting;
    }
};
