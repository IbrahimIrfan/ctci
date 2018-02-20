#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
	string val;
	Node* next;
};

void printL(Node* l){
	Node* p = l;
	while(p != nullptr){
		std::cout << p->val << std::endl;
		p = p->next;
	}
}

void del(Node* n){ 
	n->val = n->next->val;
	Node* p = n->next;
	n->next = n->next->next;
	delete p;
}


int main(int argc, char *argv[]){
	Node* list = new Node;
	list->val = "a";

	Node* b = new Node;
	b->val = "b";

	Node* c = new Node;
	c->val = "c";

	list->next = b;
	b->next = c;
	c->next = nullptr;

	del(c);
	printL(list);
	return 0;
}
