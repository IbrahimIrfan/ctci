#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
	int val;
	Node* next;
};

void printL(Node* l){
	Node* p = l;
	while(p != nullptr){
		std::cout << p->val << std::endl;
		p = p->next;
	}
}

Node* add(Node* l1, Node* l2){
	Node* p1 = l1;
	Node* p2 = l2;
	Node* result = new Node;
	Node* n = result;

	int sum = 0;
	int carry = 0;
	int term1, term2;

	while (p1 != nullptr || p2 != nullptr){
		if (p1 == nullptr) {
			term1 = 0;	
		} else {
			term1 = p1->val;
			p1 = p1->next;
		}

		if (p2 == nullptr) {
			term2 = 0;	
		} else {
			term2 = p2->val;
			p2 = p2->next;
		}

		sum = term1 + term2 + carry;
		carry = sum / 10;
		sum %= 10;

		n->val = sum;
		if (p1 == nullptr && p2 == nullptr) {
			n->next = nullptr;	
		} else {
			n->next = new Node;
			n = n->next;
		}
	}
	return result;


}


int main(int argc, char *argv[]){
	Node* list = new Node;
	list->val = 5;

	Node* b = new Node;
	b->val = 9;

	Node* c = new Node;
	c->val = 2;

	list->next = b;

	b->next = c;
	c->next = nullptr;

	Node* list2 = new Node;
	list2->val = 3;

	Node* b2 = new Node;
	b2->val = 1;

	Node* c2 = new Node;
	c2->val = 5;

	list2->next = b2;
	b2->next = c2;
	c2->next = nullptr;

	Node* sum = add(list, list2);
	printL(sum);
	return 0;
}
