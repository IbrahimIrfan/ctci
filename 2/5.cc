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

Node* rootOfLoop(Node* l){
	unordered_map<Node*, bool> seen;

	while (!seen[l]){
		seen[l] = true;
		l = l->next;
	}
	return l;
}


int main(int argc, char *argv[]){
	Node* list = new Node;
	list->val = 1;

	Node* b = new Node;
	b->val = 2;

	Node* c = new Node;
	c->val = 3;

	Node* d = new Node;
	d->val = 4;

	list->next = b;
	b->next = c; // root
	c->next = d;
	d->next = b;

	Node* root = rootOfLoop(b);

	std::cout << (root == b) << std::endl;
	return 0;
}
