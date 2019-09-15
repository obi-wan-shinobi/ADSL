#include<iostream>
#include"Node.h"
template<typename T>
class List
{
	typedef Node<T> node_type;
	typedef node_type* node_pointer;
	typedef typename node_type:: value_type value_type;
	typedef typename node_type:: pointer_type pointer_type;
 public:
 	node_pointer Head;
 	node_pointer create(value_type);
 	bool insert(value_type);
 	bool search(value_type);
 	node_pointer last();
	bool Delete(value_type);
	bool display();
	List()
	{
		Head = NULL;
	}
};
template<typename T>
typename List<T>:: node_pointer List<T>:: create(value_type dat)
{
	node_pointer temp = new node_type;
	temp->data = dat;
	temp->next = NULL;
	return temp;
}
template<typename T>
bool List<T>:: insert(value_type data)
{
	node_pointer temp = create(data);
	if(Head == NULL)
		Head = temp;
	else
	{
		node_pointer curr = Head;
		while(curr->next!= NULL)
			curr = curr->next;
			
		curr->next = temp;
	}

	return true;
}
template<typename T>
bool List<T>:: search(value_type key)
{
	node_pointer temp = Head;
	bool flag = false;
	while(!flag)
	{
		if(temp->data == key)
			flag = true;
		temp = temp->next;
	}
	if(flag)
		return true;
	else
		return false;
}
template<typename T>
typename List<T>:: node_pointer List<T>:: last()
{
	node_pointer temp = Head;
	while(temp->next!= NULL)
		temp = temp->next;
	return temp;
}
template<typename T>
bool List<T>:: Delete(value_type dat)
{
	node_pointer curr = Head->next, prev = Head, next = curr->next;
	bool flag = true;
	if(Head->data == dat)
	{
		Head = next;
		free(curr);
	}
	else
	{
		while(flag && next!=NULL)
		{
				if(curr->data == dat)
				{
					prev->next = next;
					free(curr);
					flag = false;
				}
				else
				{
					curr= curr->next;
					prev= prev->next;
					next = next->next;
				}
		}
	}
}
template<typename T>
bool List<T>:: display()
{
	node_pointer temp = Head;
	while(temp!=NULL)
	{
		cout<<temp->data.name<<" : "<<temp->data.ph<<endl;
		//cout<<temp->data<<"\t";
		temp=temp->next;
	}
	return true;
}
