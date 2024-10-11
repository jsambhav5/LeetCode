// LeetCode : 21

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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == NULL) return list2;
		if (list2 == NULL) return list1;
		ListNode* itr;
		if (list1->val < list2->val) {
			itr = list1;
			list1 = list1->next;
		}
		else {
			itr = list2;
			list2 = list2->next;
		}
		ListNode* head = itr;
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				itr->next = list1;
				itr = itr->next;
				list1 = list1->next;
			}
			else {
				itr->next = list2;
				itr = itr->next;
				list2 = list2->next;
			}
		}
		if (list1 == nullptr) itr->next = list2;
		else if (list2 == nullptr) itr->next = list1;
		return head;
	}
};