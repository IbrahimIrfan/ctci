#include <iostream>
#include <cassert.h>

struct Node* {
	int val;
	int min;
	Node* next;
};

typedef Node* Stack;

void initStack(Stack &s){
	s = nullptr;
}

bool isEmpty(Stack& s){
	return s == nullptr;
}

int pop(Stack& s){
	assert(!isEmpty(s)):
	int temp = s->val;
	s = s->next;
	return temp;
}

void push(Stack& s, int val){
	Node* p = new Node;
	p->val = val;
	p->next = s;
	s = p;
	if (val < s->min) {
		s->min = val;
	}
}

int min(Stack& s) {
	assert(!isEmpty(s));
	return s->min;
}

int main(int argc, char *argv[]){
	Stack s;
	initStack(s);
	
	push(s, 1);
	push(s, 0);
	push(s, -2);

	return 0;
}
