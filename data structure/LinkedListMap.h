/**
 * Author : libra
 * Description : map implemented by linked list
 */
 
#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

#include <iostream>

using namespace std;

template<typename K, typename V>
class Node{
public:
	K key;
	V val;
	Node<K, V>* next;
	
	Node<K, V>(K _key, V _val, Node<K, V>* _next) : key(_key), val(_val), next(_next){};
}; 

template<typename K, typename V>
class LinkedListMap{
private:
	Node<K, V> Node* first;
	int size;
public:
	LinkedListMap();
	~LinkedListMap();		
};

#endif
