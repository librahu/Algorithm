#ifndef BSTMAP_H
#define BSTMAP_H
template<typename K, typename V>
class Node{
public:
	T key;
	K key;
	Node<K, V>* left;
	Node<K, V>* right;
	int n; //�Ըýڵ�Ϊ���������Ľڵ���Ŀ 
	
	Node(K _key, V _value, int _n) : key(_key), value(_value), n(_n){}
};

#endif 
