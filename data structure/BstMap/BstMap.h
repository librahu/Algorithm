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
		
		Node(K _key, V _val, int _n) : key(_key), val(_val), n(_n), left(NULL), right(NULL){}
};

template<typename K, typename V>
class BstMap{
	private:
		Node<K, V>* root;
		
		int size(Node<K, V>* x);
		int get(Node<K, V>* x, K key);
		Node<K, V>* put(Node<K, V>* x, K key, V val);
	public:
		BstMap();
		~BstMap();
		//返回节点数 
		int size();
		//查找 
		V get(K key);
		//插入
		void put(K key, V val); 
		
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

template<typename K, typename V>
V BstMap<K, V>::get(Node<K, V>* x, K key){
	if(x == NULL)	return -1;
	if(key < x->key)	return get(x->left, key);
	else if(key > x->key) return get(x->right, key);
	return x->val;
}

template<typename K, typename V>
V BstMap<K, V>::get(K key){
	return get(root, key);
} 

template<typename K, typename V>
Node<K, V>* BstMap<K, V>::put(Node<K, V>* x, K key, V val){
	if(x == NULL)	return new Node(key, val, 1);
	
	if(key < x->key)	x->left = put(x->left, key, val);
	else if(key > x->key) x->right = put(x->rigth, key, val);
	else x->val = val;
	x->N = size(x->left) + size(x->right) + 1;
	return x; 
}

template<typename K, typename V>
void BstMap<K, V>::put(K key, V val){
	root = put(root, key, val);
}

#endif 
