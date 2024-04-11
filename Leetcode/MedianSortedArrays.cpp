#include "MedianSortedArrays.h"


double MedianSortedArrays::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    BruteForceMethod(nums1, nums2);
    return 0.0;
}

double MedianSortedArrays::BruteForceMethod(std::vector<int>& nums1, std::vector<int>& nums2)
{
    //merge the array , sort and print median.
    std::vector<int> nums3;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        nums3.emplace_back(nums1[i]);
    }

    for (size_t i = 0; i < nums2.size(); i++)
    {
        nums3.emplace_back(nums2[i]);
    }

    std::sort(nums3.begin(),nums3.end());
   
    if (nums3.size() % 2 == 1) {
        return static_cast<double> (nums3[nums3.size() / 2]);
    }
    else {
        return static_cast<double> (nums3[nums3.size() / 2] + nums3[(nums3.size() / 2) - 1]) / 2;
    }
}

double MedianSortedArrays::DoublePointerMethod(std::vector<int>& nums1, std::vector<int>& nums2)
{
    
    return 0.0;
}
