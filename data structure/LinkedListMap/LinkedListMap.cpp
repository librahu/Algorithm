#include "LinkedListMap.h"

template<typename K, typename V>
LinkedListMap<K, V>::LinkedListMap(){
    first = NULL;
    size = 0;
}

template<typename K, typename V>
LinkedListMap<K, V>::~LinkedListMap(){
    for(auto cur = first; cur != NULL; ){
        Node<K, V>* tmp = cur;
        cur = cur->next;
        delete cur;
    }
    first = NULL;
}

template<typename K, typename V>
bool LinkedListMap<K, V>::isEmpty(){
	return size == 0;
}

template<typename K, typename V>
bool LinkedListMap<K, V>::contains(K key){
	for(auto cur = first; cur != NULL; cur = cur->next)
		if(cur->key == key)	return true;
	return false;
}

template<typename K, typename V>
void LinkedListMap<K, V>::put(K key, V val){
	for(auto cur = first; cur != NULL; cur = cur->next){
		if(key == cur->key)	{
			cur->val = val;
			return;
		}
	}
	first = new Node<K, V>(key, val, first);
}

//V get(K key);
template<typename K, typename V>
V LinkedListMap<K, V>::get(K key){
	for(auto cur = first; cur != NULL; cur = cur->next)
		if(key == cur->key)	return cur->val;
	return -1;
}
