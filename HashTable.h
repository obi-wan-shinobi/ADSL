#include<bits/stdc++.h>
#include"List.h"
using namespace std;
template<typename T>
class HT
{
	typedef Node<T> node_type;
	typedef node_type* node_pointer;
	typedef typename node_type:: value_type value_type;
	typedef typename node_type:: pointer_type pointer_type;
 public:
 	int max;
	List<T> *keys;
 	HT(int n)
 	{
 		max=n;
		keys = new List<T>[max];
 	}
	bool create_table();
	bool insert(value_type);
	int hash(string);
	int hash(int);
	bool search(string);
	bool display(int);
	bool display_all();
};
template<typename T>
int HT<T>:: hash(string key)
{
	int sum = 0;
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	for(int i=0; i<key.length(); i++)
		sum += key[i];
	return sum%max;
}
template<typename T>
int HT<T>:: hash(int key)
{
	return key%max;
}
template<typename T>
bool HT<T>:: insert(value_type data)
{
	int index = hash(data.name);
	//int index = hash(data);
	keys[index].insert(data);
}
template<typename T>
bool HT<T>:: search(string name)
{
	int index = hash(name);
	node_pointer temp = keys[index].Head;
	bool flag = false;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	while(!flag && temp!=NULL)
	{
		string temp_name;
		temp_name = temp->data.name;
		transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::tolower);
		if(temp_name == name)
		{
			flag = true;
			cout<<temp->data.ph;
		}
		else
			temp= temp->next;
	}
	return flag;
}
template<typename T>
bool HT<T>:: display(int index)
{
	cout<<index<<endl;
	keys[index].display();
}
template<typename T>
bool HT<T>:: display_all()
{
	for(int i=0; i<max; i++)
	{
		keys[i].display();
		//cout<<endl;
	}
}
