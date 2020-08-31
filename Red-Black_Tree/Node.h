#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;



enum COLOR { RED, BLACK, DOUBLE_BLACK };

template<class T>
class Node {
private:
	T key;
	T value;
	COLOR color;
	Node<T> *parent;
	Node<T> *left;
	Node<T> *right;

public:
	Node();
	Node(const T &, const T &);

	void setKey(const T &);
	void setValue(const T &);
	void setColor(COLOR);

	T getKey() const;
	T getValue() const;
	COLOR getColor() const;

	void setLeft(Node<T> *);
	void setRight(Node<T> *);
	void setParent(Node<T> *);

	Node<T> *getLeft() const;
	Node<T> *getRight() const;
	Node<T> *getParent() const;
};




// DEFINITION

template<class T>
Node<T>::Node()
{
	left = right = nullptr;
	parent = nullptr;
}


template<class T>
Node<T>::Node(const T &k, const T &v)
{
	key = k;
	value = v;
	left = right = nullptr;
	parent = nullptr;
	color = RED;
}

template<class T>
void Node<T>::setKey(const T &k){
	key = k;
}


template<class T>
void Node<T>::setValue(const T &v){
	value = v;
}


template<class T>
void Node<T>::setColor(COLOR c){
	color = c;
}


template<class T>
T Node<T>::getKey() const{
	return key;
}



template<class T>
T Node<T>::getValue() const {
	return value;
}


template<class T>
COLOR Node<T>::getColor() const {
	return color;
}


template<class T>
void Node<T>::setParent(Node<T> *p) {
	parent = p;
}


template<class T>
void Node<T>::setLeft(Node<T> *p) {
	left = p;
}


template<class T>
void Node<T>::setRight(Node<T> *p) {
	right = p;
}


template<class T>
Node<T> *Node<T>::getLeft() const {
	return left;
}


template<class T>
Node<T> *Node<T>::getRight() const {
	return right;
}


template<class T>
Node<T> *Node<T>::getParent() const {
	return parent;
}







#endif /* NODE_H */
