#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
	string val;
	Node* next;
};

string nToLast(int n, Node* l){
	Node *first = l;
	for (int i = 0; i < n; i++){
		first = first->next;
	}

	Node* second = l;
	while (first != nullptr){
		first = first->next;
		second = second->next;
	}
	return second->val;
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
	
	std::cout << nToLast(1,list) << std::endl;
	return 0;
}
