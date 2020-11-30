#ifndef NODE
#define NODE
#include <cstddef>
#include <cassert>
template<class Tmplt> 
class Node {
protected:
    Tmplt *_Node;

public:
    Node();
	~Node();
    Node(unsigned int);
	void setelement(unsigned int ,Tmplt)const;
	Tmplt getelement(unsigned int)const;
    Node(const Node&);
	Node& operator=(const Node&);

    Tmplt* reCreate(unsigned int);
};

template<class T> 
Node<T>::Node() {
    _Node = NULL;
}
template<class T> 
Node<T>::Node(unsigned int _length) {
    if (_length == 0)
        _Node = NULL;
    else {
        _Node = new T[_length];
        assert(_Node != NULL);
    }
}
template<class T> 
Node<T>::Node(const Node& org) {
    if (org._Node != NULL) {
        unsigned int size = sizeof(org._Node);
        _Node = new T[size];
        assert(_Node != NULL);
        for (unsigned int i = size; i < size; i++)
            _Node[i] = org._Node[i];
    }
    else
       _Node = NULL;
}
template<class T> 
Node<T>::~Node() {
    if (_Node != NULL) {
        delete [] _Node;
        _Node = NULL;
    }
}
template<class T> 
Node<T>& Node<T>::operator=(const Node& other) {
    if (other._Node != NULL) {
        unsigned int size = sizeof(other._Node);
        if (this->_Node != NULL)
            delete [] this->_Node;
        this->_Node = new T[size];
        assert(_Node != NULL);
        for (unsigned int i = 0; i < size; i++)
            this->_Node[i] = other._Node[i];
    }
    return *this;
}
template<class T> 
T* Node<T>::reCreate(unsigned int _length) {
    if (_Node != NULL) {
       delete [] _Node;
       _Node = NULL;
    }
    if (_length == 0)
        _Node = NULL;
    else {
        _Node = new T[_length];
        assert(_Node != NULL);
    }
    return _Node;
}
template<class T>
void Node<T>::setelement(unsigned int pos,T val)const{
	_Node[pos]=val;
}

template<class T>
T Node<T>::getelement(unsigned int pos)const{
	return _Node[pos];
}
#endif
