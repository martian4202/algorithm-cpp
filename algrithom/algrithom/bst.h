#pragma once

template<typename T>
class BST
{
public:
	struct BSTNode {
		BSTNode() {}
		~BSTNode() {}
		BSTNode(T& d, BSTNode* parent = 0, BSTNode* l = 0, BSTNode* r = 0) : data(d), p(parent)
			left(l), right(r) {}
		T data;
		BSTNode* p, left, right;
	};

	BST();
	~BST();

	void transplant(BSTNode* u, BSTNode* v);
	void remove(BSTNode* z);
	const BSTNode* minimum(BSTNode* x);

private:
	BSTNode* root;
};

