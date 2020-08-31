#ifndef AVLTREE_H
#define AVLTREE_H

#include "BNode.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


template <class T>
class AVLTree
{
private:
	BNode<T> *root;
private:
	int getHeight(BNode<T> *);										// 1
	int getBalance(BNode<T> *);										// 2
	BNode<T> *singleLeftRotate(BNode<T> *);							// 3
	BNode<T> *singleRightRotate(BNode<T> *);						// 4

	BNode<T> *insertHelper(const T &, const T &, BNode<T> *);		// 5	

	BNode<T> *minKeyNode(BNode<T> *);								// 6
	BNode<T> *removeHelper(const T &, BNode<T> *);					// 7
										
	void inorder(fstream &) const;										// 8
	void preorder(BNode<T> *) const;								// 9

	void clearHelper(BNode<T> *);									// 10
public:
	AVLTree();														// 11
	~AVLTree();														// 12
	void insert(const T &, const T &);								// 5.1
	void remove(const T &);											// 7.1
	void inorderTravesal(fstream &) const;							// 8.1
	void preorderTravesal() const;									// 9.1
	T search(const T &) const;										// 13
	bool modify(const T &, const T &);								// 14
	void clear();													// 10.1
	int HeightOfTree() { return getHeight(root); }
};



// DEFINITION


// 1
template<class T>
int AVLTree<T>::getHeight(BNode<T> *p)
{
	return p == nullptr ? 0 : p->Height();
}


// 2
template<class T>
int AVLTree<T>::getBalance(BNode<T> *p)
{
	if (p == nullptr) return 0;
	return getHeight(p->getLeft()) - getHeight(p->getRight());
}


// 3
template<class T>
BNode<T> *AVLTree<T>::singleLeftRotate(BNode<T> *p)
{
	BNode<T> *tmp = p->getRight();
	p->setRight(tmp->getLeft());
	tmp->setLeft(p);

	tmp->setHeight(max(getHeight(tmp->getLeft()), getHeight(tmp->getRight())) + 1);
	p->setHeight(max(getHeight(p->getLeft()), getHeight(p->getRight())) + 1);

	return tmp;
}


// 4
template<class T>
BNode<T> *AVLTree<T>::singleRightRotate(BNode<T> *p)
{
	BNode<T> *tmp = p->getLeft();
	p->setLeft(tmp->getRight());
	tmp->setRight(p);

	tmp->setHeight(max(getHeight(tmp->getLeft()), getHeight(tmp->getRight())) + 1);
	p->setHeight(max(getHeight(p->getLeft()), getHeight(p->getRight())) + 1);

	return tmp;
}


// 5
template<class T>
BNode<T> *AVLTree<T>::insertHelper(const T &k, const T &v, BNode<T> *p)
{
	if (p == nullptr) {
		p = new BNode<T>(k, v);
	}
	else if (k < p->getKey()) {
		p->setLeft(insertHelper(k, v, p->getLeft()));
		if (getBalance(p) > 1)
		{
			if (k > p->getLeft()->getKey()) {
				p->setLeft(singleLeftRotate(p->getLeft()));
			}
			p = singleRightRotate(p);
		}
	}
	else if (k > p->getKey()) {
		p->setRight(insertHelper(k, v, p->getRight()));
		if (getBalance(p) < -1)
		{
			if (k < p->getRight()->getKey()) {
				p->setRight(singleRightRotate(p->getRight()));
			}
			p = singleLeftRotate(p);
		}
	}
	p->setHeight(max(getHeight(p->getLeft()), getHeight(p->getRight())) + 1);
	return p;
}


// 5.1
template<class T>
void AVLTree<T>::insert(const T &k, const T &v)
{
	root = insertHelper(k, v, root);
}


// 6
template<class T>
BNode<T> * AVLTree<T>::minKeyNode(BNode<T> *p) {
	BNode<T> *cur = p;
	while (cur->getLeft() != nullptr){
		cur = cur->getLeft();
	}
	return cur;
}


// 7
template<class T>
BNode<T> * AVLTree<T>::removeHelper(const T &k, BNode<T> *p) {

	//Step 1: perform standard BST delete
	if (p == nullptr) return p;
	
	if (k < p->getKey()) {
		p->setLeft(removeHelper(k, p->getLeft()));
	}
	else if (k > p->getKey()) {
		p->setRight(removeHelper(k, p->getRight()));
	}
	else {
		if (p->getLeft() == nullptr || p->getRight() == nullptr) {
			BNode<T> *tmp = p->getLeft() ? p->getLeft() : p->getRight();
			if (tmp == nullptr) {
				tmp = p;
				p = nullptr;
			}
			else *p = *tmp;

			delete tmp;
		}
		else {
			BNode<T> *tmp = minKeyNode(p->getRight());
			p->setKey(tmp->getKey());
			p->setValue(tmp->getValue());
			p->setRight(removeHelper(tmp->getKey(), p->getRight()));
		}
	}
	if (p == nullptr) return p;
	

	//Step 2: update height of the current node
	p->setHeight(max(getHeight(p->getLeft()), getHeight(p->getRight())) + 1);

	//Step 3: balance
	int balance = getBalance(p);

	if (balance > 1 && getBalance(p->getLeft()) >= 0) {
		return singleRightRotate(p);
	}

	if (balance > 1 && getBalance(p->getLeft()) < 0) {
		p->setLeft(singleLeftRotate(p->getLeft()));
		return singleRightRotate(p);
	}

	if (balance < -1 && getBalance(p->getRight()) <= 0) {
		return singleLeftRotate(p);
	}

	if (balance < -1 && getBalance(p->getRight()) > 0) {
		p->setRight(singleRightRotate(p->getRight()));
		return singleLeftRotate(p);
	}

	return p;
}


// 7.1
template<class T>
void AVLTree<T>::remove(const T &k) {
	root = removeHelper(k, root);
}


// 8
template <class T>
void AVLTree<T>::inorder(fstream &file) const {
	BNode<T> *pre, *cur;
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


// 8.1
template <class T>
void AVLTree<T>::inorderTravesal(fstream &file) const{
	inorder(file);
	//file << endl;
}


// 9
template <class T>
void AVLTree<T>::preorder(BNode<T> * p) const {
	if (p) {
		cout << p->getKey() << "  " << p->getValue() << "\n";
		preorder(p->getLeft());
		preorder(p->getRight());
	}
}


// 9.1
template <class T>
void AVLTree<T>::preorderTravesal() const {
	preorder(root);
	std::cout << std::endl;
}


// 10
template<class T>
void AVLTree<T>::clearHelper(BNode<T> *p) {
	if (p) {
		clearHelper(p->getLeft());
		clearHelper(p->getRight());
		delete p;
	}
}


// 10.1
template<class T>
void AVLTree<T>::clear()
{
	clearHelper(root);
	root = nullptr;
}



// 11
template<class T>
AVLTree<T>::AVLTree()
{
	root = nullptr;
}


// 12
template<class T>
AVLTree<T>::~AVLTree()
{
	clear();
}


// 13
template<class T>
T AVLTree<T>::search(const T &k) const
{
	BNode<T> * p = root;
	while (p != nullptr) {
		if (p->getKey() == k)
			return p->getValue();
		if (k > p->getKey()) p = p->getRight();
		else p = p->getLeft();
	}
	T notfound{};
	return notfound;
}



// 14
template<class T>
bool AVLTree<T>::modify(const T &k, const T &v)
{
	BNode<T> * p = root;
	while (p != nullptr) {
		if (p->getKey() == k){
			p->setValue(v);
			return true;
		}
		else if (p->getKey() < k) p = p->getRight();
		else p = p->getLeft();
	}
	return false;
}




#endif /* AVLTREE_H */
