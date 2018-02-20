#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

void printD(Node* tree){
	if (tree == nullptr){
		return;
	}
	std::cout << tree->val << std::endl;
	printD(tree->left);
	printD(tree->right);
}

int max(int a, int b){
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b){
	if (a > b) {
		return b;
	}
	return a;
}

int getMax(Node* n){
	if (n == nullptr){
		return 0;
	}
	return 1 + max(getMax(n->left), getMax(n->right));
}

int getMin(Node* n){
	if (n == nullptr){
		return 0;
	}
	return 1 + min(getMin(n->left), getMin(n->right));
}

bool checkBalance(Node* tree){
	int max = getMax(tree);
	int min = getMin(tree);
	return max - min <= 1;
}

int main(int argc, char *argv[]){
	Node* tree = new Node;	
	tree->val = 1;
	tree->left = new Node;
	tree->left->val = 2;
	tree->right = new Node;
	tree->right->val = 3;

	tree->left->left = new Node;
	tree->left->left->val = 4;
	tree->left->left->left = nullptr;
	tree->left->left->right = nullptr;
	tree->left->right = new Node;
	tree->left->right->val = 5;
	tree->left->right->left = nullptr;
	tree->left->right->right = nullptr;

	tree->right->left = new Node;
	tree->right->left->val = 6;
	tree->right->left->left = nullptr;
	tree->right->left->right = nullptr;
	tree->right->right = new Node;
	tree->right->right->val = 7;
	tree->right->right->left = nullptr;
	tree->right->right->right = nullptr;

	std::cout << checkBalance(tree) << std::endl;
	return 0;
}
