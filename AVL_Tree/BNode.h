#ifndef BNODE_H
#define BNODE_H

#include <math.h>


template <class T>
class BNode
{
private:
	T key;
	T value;
	BNode<T> *left;
	BNode<T> *right;
	int height;

public:
	BNode();
	BNode(const T &, const T &);

	void setKey(const T &);
	void setValue(const T &);
	T getKey() const;
	T getValue() const;
	void setLeft(BNode<T> *);
	void setRight(BNode<T> *);
	BNode<T> *getLeft() const;
	BNode<T> *getRight() const;
	int Height();
	void setHeight(int);

	//~BNode();
};



// DEFINITION

template <class T>
BNode<T>::BNode()
{
	left = right = nullptr;
	height = 1; 
}

template <class T>
BNode<T>::BNode(const T &k, const T &v)
{
	key = k;
	value = v;
	left = right = nullptr;
	height = 1;
}

template <class T>
void BNode<T>::setKey(const T &k)
{
	key = k;
}

template <class T>
T BNode<T>::getKey() const
{
	return key;
}

template <class T>
void BNode<T>::setValue(const T &v)
{
	value = v;
}

template <class T>
T BNode<T>::getValue() const
{
	return value;
}

template <class T>
void BNode<T>::setLeft(BNode<T> *ptr)
{
	left = ptr;
}

template <class T>
void BNode<T>::setRight(BNode<T> *ptr)
{
	right = ptr;
}

template <class T>
BNode<T> *BNode<T>::getLeft() const
{
	return left;
}

template <class T>
BNode<T> *BNode<T>::getRight() const
{
	return right;
}

template <class T>
int BNode<T>::Height()
{
	return height;
}

template <class T>
void BNode<T>::setHeight(int h)
{
	height = h;
}




#endif /* BNODE_H */
