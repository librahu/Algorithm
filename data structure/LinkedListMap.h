/**
 * Author : libra
 * Description : map implemented by linked list
 */

#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

#include <iostream>

template<typename K, typename V>
class Node{
public:
    K key;
    V val;
    Node<K, V>* next;

    Node();
    Node(K _key, V _val, Node<K, V>* _next) : key(_key), val(_val), next(_next){};
};

template<typename K, typename V>
class LinkedListMap{
private:
    Node<K, V>* first;
    int size;
public:
    LinkedListMap();
    ~LinkedListMap();
    bool isEmpty();
    bool contains(K key);
    void put(K key, V val);
    V get(K key);

};
#endif
