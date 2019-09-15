#include<iostream>
using namespace std;
template<class T>
class stack
{
 public:
	int n;
	T a[100];
	stack()
	{
		n=0;
	}
	T pop();
	void push(T);
	bool empty();
	bool full();
	void get();
	void display();
	T get_top();
};
template<class T> 
void stack<T>:: get()
{
	int i=0;
	char ch;
	cout<<"Enter the stack:\n";
	while(ch!='n'&&i<100)
	{
		cin>>a[i];
		i++;
		n++;
		cout<<"Enter more?(y/n)";
		cin>>ch;
	}
	n--;
}
template<class T>
void stack<T>:: display()
{
	int i=n;
	while(i>=0)
	{
		cout<<a[i]<<endl;
		i--;
	}
}
template<class T>
void stack<T>:: push(T ele)
{
	if(full()==true)
		cout<<"Stack overflow"<<endl;
	else
	{
		n++;
		a[n]=ele;
	}
}
template<class T>
T stack<T>::get_top()
{
	if(!empty())
		return a[n];
}
template<class T>
T stack<T>:: pop()
{
	if(empty()==true)
		cout<<"Stack underflow"<<endl;
	else
	{
		T temp;
		temp=a[n];
		n--;
		return temp;
	}
}
template<class T>
bool stack<T>:: full()
{
	if(n>100)
		return true;
	else 
		return false;
}
template<class T>
bool stack<T>:: empty()
{
	if(n<0)
		return true;
	else 
		return false;
}
