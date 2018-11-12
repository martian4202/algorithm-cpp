#include "bst.h"



template<typename T>
BST<T>::BST()
{
}


template<typename T>
BST<T>::~BST()
{
}

template<typename T>
const BSTNode* BST<T>::minimum(BSTNode* x) {
	while (x != 0) {
		x = x->left;
	}
	return x;
}


// 节点v替换节点u，节点u的双亲成为节点v的双亲
// 节点v成为节点u的双亲的孩子
template<typename T>
void BST<T>::transplant(BSTNode* u, BSTNode* v)
{
	if (u.p == 0)
		root = v;
	else if (u == u.p.left)
		v = u.p.left;
	else
		v = u.p.right;

	if (v != 0)
		v.p = u.p;
}

template<typename T>
void BST<T>::remove(BSTNode* u) {
	if (u->left == 0)
		transplant(u, u->right);
	if (u->right == 0)
		transplant(u, u->left);
}