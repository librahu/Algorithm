#ifndef BSTMAP_H
#define BSTMAP_H
#include <iostream>

template<typename K, typename V>
class Node{
	public:
		K key;
		V val;
		Node<K, V>* left;
		Node<K, V>* right;
		int n; //以该节点为根的子树的节点数目 
		
		Node(K _key, V _val, int _n) : key(_key), val(_val), n(_n){}
};

template<typename K, typename V>
class BstMap{
	private:
		Node<K, V>* root;
		
		int size(Node<K, V>* x);
		
	public:
		BstMap();
		~BstMap();
		int size();
		
};

template<typename K, typename V>
BstMap<K, V>::BstMap(){
	root = NULL;
}

template<typename K, typename V>
BstMap<K, V>::~BstMap(){
	
}


template<typename K, typename V>
int BstMap<K, V>::size(Node<K, V>* x){
	if(x == NULL)
		return 0;
	return x.N;
}

template<typename K, typename V>
int BstMap<K, V>::size(){
	return size(root);
}

#endif 
