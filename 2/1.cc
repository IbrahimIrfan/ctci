#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
	string val;
	Node* next;
};

void removeDupes(Node* l){
	unordered_map<string, bool> seen;
	Node* p = l;
	seen[p->val] = 1;

	while (p != nullptr && p->next != nullptr){
		if (seen[p->next->val]){
			Node* temp = p->next;
			p->next = p->next->next;
			delete temp;
		} else {
			seen[p->next->val] = 1;
		}
		p = p->next;
	}
}

void printL(Node* l){
	Node* p = l;
	while(p != nullptr){
		std::cout << p->val << std::endl;
		p = p->next;
	}
}

int main(int argc, char *argv[]){
	Node* list = new Node;
	list->val = "a";

	Node* b = new Node;
	b->val = "b";

	Node* c = new Node;
	c->val = "a";

	list->next = b;
	b->next = c;
	c->next = nullptr;
	
	std::cout << "Before" << std::endl;
	printL(list);
	removeDupes(list);
	std::cout << "After" << std::endl;
	printL(list);

	return 0;
}

