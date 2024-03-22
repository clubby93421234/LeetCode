#include "MergekSortedLists.h"
ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {

    if (lists.empty()) {
        return nullptr;
    }

    std::vector<int> v{};
    for (int i = 0; i < lists.size(); i++) {
        ListNode* helper = lists[i];
        while (helper != nullptr) {
            v.emplace_back(helper->val);

            helper = helper->next;


        }
    }
    std::sort(v.begin(), v.end());
    //create a List
    ListNode* LeBegin = new ListNode();
    ListNode* runner = LeBegin;
    for (auto x : v) {
        ListNode* dummy = new ListNode(x);
        runner->next = dummy;
        runner = dummy;
    }



    return LeBegin->next;
}
