/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* l, ListNode* r) {
            return l->val > r->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> que(compare);

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                que.push(lists[i]);
        }

        ListNode *list = NULL, *cur = NULL;
        while (que.size()) {
            ListNode* curNode = que.top(); que.pop();

            if (list == NULL) {
                list = curNode;
                cur = list;
            } else {
                cur->next = curNode;
                cur = cur->next;
            }
            if (curNode->next != NULL)
                que.push(curNode->next);
        }
        return list;
    }
};
