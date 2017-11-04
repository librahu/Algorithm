/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if(intervals.size() == 0)   return intervals;
        
        sort(intervals.begin(), intervals.end(), [](Interval x1, Interval x2){
            if(x1.start == x2.start)
                return x1.end < x2.end;
            else
                return x1.start < x2.start; 
        });
        
        vector<Interval>  res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start > res.back().end)
                res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end, intervals[i].end);
        }
        return res;
    }
};
