#include<iostream>
using namespace std;
template<typename T>
class Node
{
 public:
 	typedef T value_type;
 	typedef T* pointer_type;
 	typedef Node<T> node_type;
 	typedef node_type* node_pointer;

	node_pointer next;
	value_type data;
	Node()
	{
		this->next = NULL;
	}
};
