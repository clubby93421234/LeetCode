#include "InsertInterval.h"
#include "MergeIntervals.h"

std::vector<std::vector<int>> InsertInterval::insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    if (intervals.empty()) {
        return { newInterval };
    }
    int n = intervals.size();
    int target = newInterval[0];
    int left = 0, right = n - 1;

    // Binary search to find the position to insert newInterval
    while (left <= right) {
        int mid = (left + right) / 2;
        if (intervals[mid][0] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    //insert new Interval
    intervals.insert(intervals.begin() + left, newInterval);

    //Merge overlaping ons
    std::vector<std::vector<int>>  res;
    for (const auto& interval : intervals) {
        // If res is empty or there is no overlap, add the interval to the result
        if (res.empty() || res.back()[1] < interval[0]) {
            res.push_back(interval);
            // If there is an overlap, merge the intervals by updating the end of the last interval in res
        }
        else {
            res.back()[1] = std::max(res.back()[1], interval[1]);
        }
    }

    return res;
}
