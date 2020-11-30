#include <fstream>
#include "Node.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;
#ifndef LIST
#define LIST
template<class T>
class List;

template<class T>

ostream& operator<< (ostream &, List<T>);

template<class T>
istream& operator>>(istream &, List<T>&);

template<class T>
class List : public Node<T>{
private:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    List(const List &other);
    ~List();
     //overloading operators

    List& operator=(const List& other);
	
    inline bool operator==(const List&);
    inline bool operator!=(const List&);
    List operator+(const List &);
    List operator+=(const List &);
    List operator++();
    List operator++(int);
    List operator--();
    List operator--(int);
	
    friend ostream& operator<< <T>(ostream &, List);
    friend istream& operator>> <T>(istream &, List&);

    int setLength(unsigned int);
    unsigned int getLength()const;
    int resetLength(unsigned int);
    int clear();
    int setElement(unsigned int, T val);
    T getElement(unsigned int)const;
};



template<class T>
List<T>::List() : Node<T>() {
    length = 0;
}
template<class T>
List<T>::List(unsigned int _length) : Node<T>(_length) {
    length = _length;
    if (length == 0)
        this->_Node = NULL;
    else {
        assert(this->_Node != NULL);
    }
	
}
template<class T>
List<T>::List(const List &other) : Node<T>(other.length) {
    length = other.length;
    for (unsigned int i = 0; i < length; i++)
		this->setelement(i,other.getelement(i));
        //_Node[i] = other._Node[i];
}
template<class T>
List<T>::~List() {
    if (length == 0)
        assert(this->_Node == NULL);
    else {
        length = 0;
    }
}
template<class T>
int List<T>::setLength(unsigned int _length) {
    if (length == 0) {
        length = _length;
        this->reCreate(length);
        assert(this->_Node != NULL);
        return 1;
    } else {
        std::cout << "List is not empty, cannot set length\n";
        return 0;
    }
}

template<class T>
unsigned int List<T>::getLength() const{
    return length;
}
template<class T>
int List<T>::resetLength(unsigned int _length) {
    length = _length;
    this->reCreate(length);
    assert(this->_Node != NULL);

    return 1;
}
template<class T>
int List<T>::clear() {
    if (length != 0) {
        length = 0;
        delete [] this->_Node;
        this->_Node = NULL;
    } else {
        length = 0;
        assert(this->_Node == NULL);
    }
    return 1;
}
template<class T>
int List<T>::setElement(unsigned int pos, T val) {
    if (pos >= length) {
        std::cout << "Given position is larger than the list size\n";
        return 0;
    } else {
        //_Node[pos] = val;
		this->setelement(pos,val);
        return 1;
    }
}
template<class T>
T List<T>::getElement(unsigned int pos)const{
    if (pos >= length) {
       std::cout << "Given position is larger than the list size\n";
        return 0;
    } else
        return this->getelement(pos);
}

//-----------------------DONE
template<class T>
List<T>& List<T>::operator=(const List<T> &other) {
    if (this != &other) {
        this->reCreate(0);
        length = other.length;
        if (length != 0) {
            this->reCreate(length);
            assert(this->_Node != NULL);
            for (unsigned int i = 0; i < length; i++)
                //_Node[i] = other._Node[i];
				setElement(i,other.getElement(i));
        }
    }
    return *this;
}

template<class T>
List<T> List<T>::operator+(const List<T> &other) {
    unsigned int loop = length < other.length ? length:other.length;
    List<T> list(loop);

    for (unsigned int i = 0; i < loop; i++) {
        list._Node[i] = this->_Node[i] + other._Node[i];
    }
    return list;
}
template<class T>
List<T> List<T>::operator+=(const List<T> &other) {
    unsigned int loop = length < other.length ? length:other.length;

    for (unsigned int i = 0; i < loop; i++) {
        this->_Node[i] += other._Node[i];
    }
    return *this;
}
template<class T>
List<T> List<T>::operator++() {
    for (unsigned int i = 0; i < length; i++) {
        ++this->_Node[i];
    }
    return *this;
}
template<class T>
List<T> List<T>::operator++(int) {
    List tmp(*this);
    for (unsigned int i = 0; i < tmp.length; i++) {
        this->_Node[i]++;
    }
    return tmp;
}
template<class T>
List<T> List<T>::operator--() {
    for (unsigned int i = 0; i < length; i++) {
        --this->_Node[i];
    }
    return *this;
}
template<class T>
List<T> List<T>::operator--(int) {
    List tmp(*this);
    for (unsigned int i = 0; i < length; i++) {
        this->_Node[i]--;
    }
    return tmp;
}
template<class T>
inline bool List<T>::operator==(const List<T> &r) {
    if (this == &r)
        return true;
    if (this->length != r.length)
        return false;
    for (unsigned int i = 0; i < this->length; i++) {
        if (this->getElement(i) != r.getElement(i))
            return false;
    }
    return true;
}
template<class T>
inline bool List<T>::operator!=(const List<T> &r) {
    if (this == &r)
        return false;
    if (this->length != r.length)
        return true;
    for (unsigned int i = 0; i < this->length; i++) {
        if (this->_Node[i] != r._Node[i])
            return true;
    }
    return false;
}

template<class T>
ostream& operator<<(ostream &out, List<T> list) {
    for (unsigned int i = 0; i < list.length; i++)
        out << list.getElement(i) << " ";
    out << endl;
    return out;
}

template<class T>
istream& operator>>(istream &in, List<T> &list) {
    for (unsigned int i = 0; i < list.length; i++)
	{
		T variable;
        in >> variable;
		list.setElement(i,variable);
	}
    return in;
}




#endif
