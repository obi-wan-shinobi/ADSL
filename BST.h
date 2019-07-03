#include<iostream>
#include"Node.h"
using namespace std;
template<class T>
class BST
{
 private:
	//T should not appear anywhere in the code now
	typedef Node<T> node_type;
	typedef node_type* node_pointer;
	typedef typename node_type:: value_type value_type;
	typedef typename node_type:: pointer_type pointer_type;

 public:
 
 	node_pointer pRoot;
 	BST()
 	{
 		pRoot=NULL;
 	}
 	node_pointer create(value_type);
 	bool insert(value_type);
 	bool inorder(node_pointer);
 	bool preorder(node_pointer);
 	bool postorder(node_pointer);
 	value_type search(node_pointer, value_type);
 	value_type max();
 	value_type min();
 	value_type height(node_pointer);
 	bool empty();
};
template<class T>
bool BST<T>:: empty()
{
	if(pRoot == NULL)
		return true;
	else 
		return false;
}
template<class T>
typename BST<T>::node_pointer BST<T>:: create(value_type d)
{
	node_pointer pTemp=new node_type;
	pTemp->data=d;
	pTemp->left=pTemp->right=NULL;
	return pTemp;
}
template<class T>
bool BST<T>:: insert(value_type d)
{
	node_pointer pTemp, pNew_node;
	pNew_node = create(d);
	if(pRoot==NULL)
		pRoot=pNew_node;									//If node is the first to be inserted
	else
	{
		pTemp=pRoot;
		while(true)
		{
			if(pNew_node->data< pTemp->data)					//If data is less than the parent
			{
				if(pTemp->left==NULL)
				{
					pTemp->left=pNew_node;
					break;
				}
				else
					pTemp=pTemp->left;
			}
			else											//If data is greater than or egual to the parent
			{
				if(pTemp->right==NULL)
				{
					pTemp->right=pNew_node;
					break;
				}
				else
					pTemp=pTemp->right;
			}//end of inner if-else
		}//end of while
	}//End of outer if-else
	return true;													
}
template<class T>
typename BST<T>::value_type BST<T>:: search(node_pointer pNode, value_type key)
{
	if(pNode==NULL)										//If element not found
		return 0;
	else if(pNode->data==key)							//If element found, return the element
		return pNode->data;
	else
	{
		if(key>pNode->data)					
			search(pNode->right,key);					//Recursive call to traverse right side
		else
			search(pNode->left,key);					//Recursive call to traverse left side
	}
}
template<class T>
typename BST<T>::value_type BST<T>:: max()
{
	node_pointer pNode = pRoot;
	while(pNode->right != NULL)
		pNode=pNode->right;
	return pNode->data;
}
template<class T>
typename BST<T>::value_type BST<T>:: min()
{
	node_pointer pNode = pRoot;
	while(pNode->left != NULL)
		pNode=pNode->right;
	return pNode->data;
}
template<class T>
bool BST<T>:: inorder(node_pointer pRoot)
{
	if(pRoot != NULL)									//Terminating condition
	{	
		inorder(pRoot->left);							//Traverse to the left most node
		cout<<pRoot->data<<"\t";						
		inorder(pRoot->right);							//Traverse to the right mose node
	}	
	return true;
}
template<class T>
bool BST<T>:: preorder(node_pointer pRoot)
{
	if(pRoot != NULL)
	{
		cout<<pRoot->data<<"\t";
		preorder(pRoot->left);
		preorder(pRoot->right);
	}
	return true;
}
template<class T>
bool BST<T>:: postorder(node_pointer pRoot)
{
	if(pRoot != NULL)
	{
		postorder(pRoot->left);
		postorder(pRoot->right);
		cout<<pRoot->data<<"\t";
	}
	return true;
}
template<class T>
typename BST<T>:: value_type BST<T>:: height(node_pointer pRoot)
{
	if(pRoot == NULL)
		return 0;
	else
	{
		if(height(pRoot->right) > height(pRoot->left))
			return 1+height(pRoot->right);
		else
			return 1+height(pRoot->left);
	}
}
