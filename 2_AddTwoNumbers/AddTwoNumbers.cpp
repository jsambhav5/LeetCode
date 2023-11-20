/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Example:
	Input:
		2->4->3
		5->6->4

	Output:
		7->0->8

	Explanation:
		342 + 465 = 807
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* result = new ListNode(0);
	ListNode* temp = result;
	int carry = 0;
	while (l1 && l2) {
		int val = l1->val + l2->val + carry;
		result->val = val % 10;
		carry = val / 10;
		l1 = l1->next;
		l2 = l2->next;
		if (l1 == NULL && l2 != NULL)
			l1 = new ListNode();

		else if (l2 == NULL && l1 != NULL)
			l2 = new ListNode();
		if (l1 || l2 || carry) {
			result->next = new ListNode();
			result = result->next;
		}
	}
	return temp;
}

int main(int argc, const char** argv) {
	ListNode l14(2), l13(4, &l14), l12(4, &l13), l11(2, &l12);
	ListNode l23(5), l22(6, &l23), l21(5, &l22);
	ListNode* result = addTwoNumbers(&l11, &l21);
	while (result) {
		cout << result->val << " -> ";
		result = result->next;
	}
	cout << "NULL";
	return 0;
}
