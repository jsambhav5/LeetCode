#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct usageNode {
	int key;
	usageNode* prev, * next;

	usageNode(int key, usageNode* prev) {
		this->key = key;
		this->prev = prev;
		this->next = this->prev->next;
		this->prev->next = this;
	}
};

class LRUCache {
	map<int, int> a;

};
