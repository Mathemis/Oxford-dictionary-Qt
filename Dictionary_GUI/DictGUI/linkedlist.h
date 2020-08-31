#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include <iostream>
using namespace std;


template <class T>
class Node
{
private:
    T key;
    T value;
    Node<T> *next;
public:
    Node(const T &a, const T &b) {
        key = a;
        value = b;
        next = nullptr;
    }
    T getKey() { return key; }
    T getValue() { return value; }
    Node<T> *getNext() { return next; }
    void setKey(const T &a) { key = a; }
    void setValue(const T &a) { value = a; }
    void setNext(Node<T> *p) { next = p; }
};


template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

private:
    void addLast(const T &w, const T &d) {
        Node<T> *p = new Node<T>(w, d);
        if (head == nullptr) {
            head = tail = p;
        }
        else {
            tail->setNext(p);
            tail = tail->getNext();
        }
        size++;
    }

    void removeFirst() {
        if (head == nullptr) return;
        Node<T> *tmp = head;
        if (tail == head) tail = nullptr;
        head = head->getNext();
        delete tmp;
        size--;
    }

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() { clear(); }

    int getSize() { return size; }

    T search(const T &key)
    {
        //if (tail->getKey() == key) return tail->getValue();
        for (Node<T> *p = head; p != nullptr; p = p->getNext()) {
            if (p->getKey() == key) return p->getValue();
        }
        T notFound{};
        return notFound;
    }

    void insert(const T &k, const T &v)
    {
        addLast(k, v);
    }

    bool modify(const T &k, const T &v)
    {
        for (Node<T> *p = head; p != nullptr; p = p->getNext()) {
            if (p->getKey() == k) {
                p->setValue(v);
                return 1;
            }

        }
        return 0;
    }

    void remove(const string &k)
    {
        Node<T> *p = nullptr;
        Node<T> *q = head;
        while (q != nullptr && q->getKey() != k) {
            p = q;
            q = q->getNext();
        }
        if (q == nullptr) return;
        if (p == nullptr) {
            removeFirst();
            return;
        }
        p->setNext(q->getNext());
        delete q;
        size--;
    }

    void traversal(fstream &file)
    {
        if (size == 0) return;
        for (Node<T> *p = head; p != nullptr; p = p->getNext()) {
            file << p->getKey() << "  " << p->getValue() << "\n\n";
        }
    }

    void clear() {
        while (size > 0) {
            removeFirst();
        }
        head = tail = nullptr;
    }
};

#endif // LINKEDLIST_H
