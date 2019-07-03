#include<iostream>
template<class T>
class Node
{
 public:
//------------Defining alternate names so T does not appear in the program----------------

	typedef Node<T> node_type;
	typedef T* pointer_type;
	typedef T  value_type;

//----------------------------------------------------------------------------------------

	node_type *left,*right;
	T data;
};

