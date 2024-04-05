#include "MergeIntervals.h"
#include<algorithm>
std::vector<std::vector<int>> MergeIntervals::merge(std::vector<std::vector<int>>& intervals)
{
    if (intervals.size() <= 1)
        return intervals;
    std::sort(intervals.begin(),intervals.end());
    
    std::vector<std::vector<int>> merged;
    
    for (auto interval: intervals)
    {
        //Falls die Lsite leer ist ODER es keine Überschneidung gibt --> einfach neues interval einfügen
        if (merged.empty()|| merged.back()[1] < interval[0]) {
            merged.emplace_back(interval);
        }
        else {
            //wir haben eine Überlappung. Wir ersetzen das Ende des letzten Eintrags durch das Ende des Intervals was
            //am größten ist
            merged.back()[1]=std::max(merged.back()[1],interval[1]);
        }
    }

    return merged;
}
