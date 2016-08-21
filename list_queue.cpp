#include"stdafx.h"
#include <iostream>
#include<cassert>

using namespace std;

struct ListNode {
	int value;
	ListNode* next;
	ListNode(int value = 0, ListNode* next = NULL) : value(value), next(next){}
	~ListNode() {}
};
struct List {
	ListNode *head;
	List() {
		cerr << "List\n";
		head = new ListNode(-1);
	}

	ListNode* getNode(int val) {
		ListNode *start = head;
		while (start) {
			if (start->value == val)
				return start;
			start = start->next;
		}
		return NULL;
	}

	void printList() {
		ListNode *start = head;
		while (start->next) {
			start = start->next;
			cout << start->value << " ";
		}
		cout << endl;
		return;
	}

	void addNode(int value, int value_after = -1) {
		ListNode *pivot = getNode(value_after);
		if (!pivot) {
			cout << "No such element!\n";
			return;
		}
		ListNode *insert_node = new ListNode(value, pivot->next);
		pivot->next = insert_node;	//
	}

	void deleteNode(int value) {
		ListNode *start = head;
		ListNode *prevNode = head;
		if (!getNode(value)) {
			cout << "No such element!\n";
			return;
		}
		while (start->next) {
			if (start->value == value) {
				break;
			}
			prevNode = start;
			start = start->next;
		}
		prevNode->next = start->next;
		delete start;
	}

	~List() {
		cerr << "List out\n";
		while (head->next) {
			deleteNode(head->next->value);
		}
		delete head;
	}
};

struct Quene :List {
	ListNode* tail;
	Quene() {
		cerr<<"Queue"<<endl;
		tail=new ListNode(-1);
	}
	int size() {
		ListNode *start = head;
		int count = 0;
		while (start->next) {
			start = start->next;
			count++;
		}
		return count;
	}
	bool is_empty() {
		int a = size();
		if (a>0){
			return false;
		}
		return true;
	}
	void push(int value) {
		addNode(value, tail->value);
		tail->value = value;
	}
	int pop() {
		int result = -1;
		if (head->next) {
			result = head->next->value;
		}
		else
			cout << ("Queue is empty");
		deleteNode(result);
		if(size()==0){
			delete tail;
			tail = new ListNode(-1);
		}
		return result;
	}
	int front() {
		if (head->next) {
			return head->next->value;
		}
		return -1;
	}
	int back() {
		if (head->next) {
			return tail->value;
		}
		return -1;
	}
	~Quene() {
		cerr << "Queue out" << endl;
		delete tail;
	}
};
int main()
{
	Quene myQuene;
	assert(myQuene.size()==0);
	assert(myQuene.is_empty());
	myQuene.push(10);
	assert(myQuene.front() == 10);
	assert(myQuene.pop() == 10);
	myQuene.push(1);
	myQuene.push(2);
	myQuene.push(3);
	myQuene.push(4);
	assert(!myQuene.is_empty());
	for (int i = 1; i <= 4; i++) {
		assert(!myQuene.is_empty());
		assert(myQuene.front() == i);
		assert(myQuene.pop() == i);
	}
	assert(myQuene.is_empty());
	cerr<<"Success!"<<endl;
	return 0;
}
