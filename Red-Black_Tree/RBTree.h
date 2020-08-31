#ifndef RBTREE_H
#define RBTREE_H

#include "Node.h"
#include <algorithm>
#include <string>


template <class T>
class RBTree {
private:
	Node<T> *root;

private:
	COLOR getColor(Node<T> *);
	void swapColor(Node<T> *, Node<T> *);
	void leftRotate(Node<T> *&, Node<T> *&);					
	void rightRotate(Node<T> *&, Node<T> *&);					

	void fixInsertRBT(Node<T> *&, Node<T> *&);
	Node<T>* insertBST(Node<T> *, Node<T> *);

	void fixDeleteRBT(Node<T> *&);
	Node<T> *minKeyNode(Node<T> *);
	Node<T>* deleteBST(Node<T> *, const T &);

	void clearHelper(Node<T> *);

public:
	RBTree() { root = nullptr; }									
	~RBTree() { clear(); }											
	void insert(const T &, const T &);								
	void remove(const T &);											
	T search(const T &) const;
	bool modify(const T &, const T &);
	void inorderTraversal(fstream &) const;							

	void clear();	
};



#endif /* RBTREE_H */



// DEFINITION
	
template <class T>
COLOR RBTree<T>::getColor(Node<T> *p) {
	if (p == nullptr) return BLACK;
	return p->getColor();
}


template <class T>
void RBTree<T>::swapColor(Node<T> *p1, Node<T> *p2) {
	COLOR temp;
	temp = p1->getColor();
	p1->setColor(p2->getColor());
	p2->setColor(temp);
}


template <class T>
void RBTree<T>::leftRotate(Node<T> *&root, Node<T> *&x)
{
	Node<T> *y = x->getRight();
	x->setRight(y->getLeft());

	if (y->getLeft() != nullptr)
		y->getLeft()->setParent(x);

	y->setParent(x->getParent());

	if (x->getParent() == nullptr)
		root = y;
	else if (x == x->getParent()->getLeft())
		x->getParent()->setLeft(y);
	else x->getParent()->setRight(y);

	y->setLeft(x);
	x->setParent(y);
}


template <class T>
void RBTree<T>::rightRotate(Node<T> *&root, Node<T> *&x)
{
	Node<T> *y = x->getLeft();
	x->setLeft(y->getRight());

	if (y->getRight() != nullptr)
		y->getRight()->setParent(x);

	y->setParent(x->getParent());

	if (x->getParent() == nullptr)
		root = y;
	else if (x == x->getParent()->getLeft())
		x->getParent()->setLeft(y);
	else x->getParent()->setRight(y);

	y->setRight(x);
	x->setParent(y);
}


template <class T>
void RBTree<T>::fixInsertRBT(Node<T> *&root, Node<T> *&p)
{
	Node<T> *parent, *grand_parent;
	parent = nullptr;
	grand_parent = nullptr;

	while (p != root && getColor(p) != BLACK && getColor(p->getParent()) == RED)
	{
		parent = p->getParent();
		grand_parent = p->getParent()->getParent();

		/*  Case : A
			Parent of pt is left child of Grand-parent of pt */
		if (parent == grand_parent->getLeft())
		{

			Node<T> *uncle = grand_parent->getRight();

			/* Case : 1
			   The uncle of pt is also red
			   Only Recoloring required */
			if (uncle != nullptr && getColor(uncle) == RED)
			{
				grand_parent->setColor(RED);
				parent->setColor(BLACK);
				uncle->setColor(BLACK);
				p = grand_parent;
			}

			else
			{
				/* Case : 2
				   pt is right child of its parent
				   Left-rotation required */
				if (p == parent->getRight())
				{
					leftRotate(root, parent);
					p = parent;
					parent = p->getParent();
				}

				/* Case : 3
				   pt is left child of its parent
				   Right-rotation required */
				rightRotate(root, grand_parent);
				swapColor(parent, grand_parent);
				p = parent;
			}
		}

		/* Case : B
		   Parent of pt is right child of Grand-parent of pt */
		else
		{
			Node<T> *uncle = grand_parent->getLeft();

			/*  Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if (uncle != nullptr && getColor(uncle) == RED)
			{
				grand_parent->setColor(RED);
				parent->setColor(BLACK);
				uncle->setColor(BLACK);
				p = grand_parent;
			}
			else
			{
				/* Case : 2
				   pt is left child of its parent
				   Right-rotation required */
				if (p == parent->getLeft())
				{
					rightRotate(root, parent);
					p = parent;
					parent = p->getParent();
				}

				/* Case : 3
				   pt is right child of its parent
				   Left-rotation required */
				leftRotate(root, grand_parent);
				swapColor(parent, grand_parent);
				p = parent;
			}
		}
	}

	root->setColor(BLACK);
}


template <class T>
Node<T>* RBTree<T>::insertBST(Node<T>* root, Node<T> *p)
{
	if (root == nullptr)
		return p;

	if (p->getKey() < root->getKey())
	{
		root->setLeft(insertBST(root->getLeft(), p));
		root->getLeft()->setParent(root);
	}
	else if (p->getKey() > root->getKey())
	{
		root->setRight(insertBST(root->getRight(), p));
		root->getRight()->setParent(root);
	}

	return root;
}


template <class T>

void RBTree<T>::insert(const T &key, const T &value)
{
	Node<T> *p = new Node<T>(key, value);
	root = insertBST(root, p);
	fixInsertRBT(root, p);
}


template <class T>
void RBTree<T>::inorderTraversal(fstream &file) const {
	Node<T> *pre, *cur;
	if (root == nullptr) return;
	cur = root;
	while (cur != nullptr) {
		if (cur->getLeft() == nullptr) {
			file << cur->getKey() << "  " << cur->getValue() << "\n\n";
			cur = cur->getRight();
		}
		else {
			pre = cur->getLeft();
			while (pre->getRight() != nullptr && pre->getRight() != cur) {
				pre = pre->getRight();
			}
			if (pre->getRight() == nullptr) {
				pre->setRight(cur);
				cur = cur->getLeft();
			}
			else {
				pre->setRight(nullptr);
				file << cur->getKey() << "  " << cur->getValue() << "\n\n";
				cur = cur->getRight();
			}
		}
	}
}


template <class T>
Node<T> *RBTree<T>::minKeyNode(Node<T> *node) {
	Node<T> *p = node;
	while (p->getLeft() != nullptr)
		p = p->getLeft();
	return p;
}


template <class T>
Node<T>* RBTree<T>::deleteBST(Node<T> *root, const T &k) {
	if (root == nullptr)
		return root;

	if (k < root->getKey())
		return deleteBST(root->getLeft(), k);

	if (k > root->getKey())
		return deleteBST(root->getRight(), k);

	if (root->getLeft() == nullptr || root->getRight() == nullptr)
		return root;

	Node<T> *tmp = minKeyNode(root->getRight());
	root->setKey(tmp->getKey());
	root->setValue(tmp->getValue());
	return deleteBST(root->getRight(), tmp->getKey());
}


template <class T>
void RBTree<T>::fixDeleteRBT(Node<T> *&node) {
	if (node == nullptr)
		return;

	if (node == root) {
		root = nullptr;
		return;
	}

	if (getColor(node) == RED || getColor(node->getLeft()) == RED || getColor(node->getRight()) == RED) {
		Node<T> *child;
		if (node->getLeft() != nullptr) child = node->getLeft();
		else child = node->getRight();

		if (node == node->getParent()->getLeft()) {
			node->getParent()->setLeft(child);
		}
		else {
			node->getParent()->setRight(child);
		}
		if (child != nullptr)
			child->setParent(node->getParent());
		if (child != nullptr) child->setColor(BLACK);
		delete node;
	}
	else {
		Node<T> *sibling = nullptr;
		Node<T> *parent = nullptr;
		Node<T> *p = node;
		p->setColor(DOUBLE_BLACK);
		while (p != root && getColor(p) == DOUBLE_BLACK) {
			parent = p->getParent();
			if (p == parent->getLeft()) {
				sibling = parent->getRight();
				if (getColor(sibling) == RED) {
					sibling->setColor(BLACK);
					parent->setColor(RED);
					leftRotate(root, parent);
				}
				else {
					if (getColor(sibling->getLeft()) == BLACK && getColor(sibling->getRight()) == BLACK) {
						sibling->setColor(RED);
						if (getColor(parent) == RED)
							parent->setColor(BLACK);
						else parent->setColor(DOUBLE_BLACK);
						p = parent;
					}
					else {
						if (getColor(sibling->getRight()) == BLACK) {
							sibling->getLeft()->setColor(BLACK);
							sibling->setColor(RED);
							rightRotate(root, sibling);
							sibling = parent->getRight();
						}
						sibling->setColor(getColor(parent));
						parent->setColor(BLACK);
						sibling->getRight()->setColor(BLACK);
						leftRotate(root, parent);
						break;
					}
				}
			}
			else {
				sibling = parent->getLeft();
				if (getColor(sibling) == RED) {
					sibling->setColor(BLACK);
					parent->setColor(RED);
					rightRotate(root, parent);
				}
				else {
					if (getColor(sibling->getLeft()) == BLACK && getColor(sibling->getRight()) == BLACK) {
						sibling->setColor(RED);
						if (getColor(parent) == RED)
							parent->setColor(BLACK);
						else parent->setColor(DOUBLE_BLACK);
						p = parent;
					}
					else {
						if (getColor(sibling->getLeft()) == BLACK) {
							sibling->getRight()->setColor(BLACK);
							sibling->setColor(RED);
							leftRotate(root, sibling);
							sibling = parent->getLeft();
						}
						sibling->setColor(getColor(parent));
						parent->setColor(BLACK);
						sibling->getLeft()->setColor(BLACK);
						rightRotate(root, parent);
						break;
					}
				}
			}
		}
		if (node == node->getParent()->getLeft())
			node->getParent()->setLeft(nullptr);
		else node->getParent()->setRight(nullptr);
		delete node;
		root->setColor(BLACK);
	}
}


template <class T>
void RBTree<T>::remove(const T &key) {
	Node<T> *node = deleteBST(root, key);
	fixDeleteRBT(node);
}


template<class T>
bool RBTree<T>::modify(const T &k, const T &v)
{
	Node<T> * p = root;
	while (p != nullptr) {
		if (p->getKey() == k) {
			p->setValue(v);
			return true;
		}
		else if (p->getKey() < k) p = p->getRight();
		else p = p->getLeft();
	}
	return false;
}


template<class T>
T RBTree<T>::search(const T &k) const
{
	Node<T> * p = root;
	while (p != nullptr) {
		if (p->getKey() == k)
			return p->getValue();
		if (k > p->getKey()) p = p->getRight();
		else p = p->getLeft();
	}
	T notfound{};
	return notfound;
}


template<class T>
void RBTree<T>::clearHelper(Node<T> *p) {
	if (p) {
		clearHelper(p->getLeft());
		clearHelper(p->getRight());
		delete p;
	}
}


// 10.1
template<class T>
void RBTree<T>::clear()
{
	clearHelper(root);
	root = nullptr;
}