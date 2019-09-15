/*
Problem Statement: Implement infix to postfix and infix to prefix conversion using stack
Created on: 23/9/2018
Author: Shreyas Kalvankar
*/
#include<iostream>
#include"Stack.h"
struct symbol					//Defining a structure for storing the values of ISP and ICP for an operator
{
	int nISP,nICP;
	char cOp;
};
stack<char>oOutput;
stack<symbol>oOperator;			//Creating stacks for operator and output
class Expression
{
 public:
	char cExp[100];				//Character array for storing expression
	friend symbol m_get_priority(char);
	bool bGetexp();
	bool bPostfix();
	bool bPrefix();
};
bool Expression::  bGetexp()
{
	cout<<"Enter the expression and please enter a '#' for denoting end of expression"<<endl;
	cin>>cExp;
	return false;
}
symbol get_priority(char cOperator)		//Returns the structure for getting priorities of variables
{
	symbol m_temp;						//Declaring a temporary structure
	m_temp.cOp=cOperator;
	switch(cOperator)
	{
		case ')': m_temp.nISP = -1;
				  m_temp.nICP = -1;
		break;
		case '^': m_temp.nISP = 3;
				  m_temp.nICP = 4;
		break;
		case '*': m_temp.nISP = 2;
				  m_temp.nICP = 2;
		break;
		case '/': m_temp.nISP = 2;
				  m_temp.nICP = 2;
		break;
		case '+': m_temp.nISP = 1;
				  m_temp.nICP = 1;
		break;
		case '-': m_temp.nISP = 1;
				  m_temp.nICP = 1;
		break;
		case '(': m_temp.nISP = 0;
				  m_temp.nICP = 4;
		break;
		default:cout<<"\nInvalid operator"<<endl;
	}
	return m_temp;						//returning the priorities
}
bool Expression:: bPostfix()
{
	char Postarr[20];
	for(int i=0; cExp[i]!='#'; i++)		//Processing the expression till the end
	{
		if(cExp[i]>='A' && cExp[i]<='Z')	//Checking for operands
			cout<<cExp[i];
		if(cExp[i]==')'||cExp[i]=='^'||cExp[i]=='*'||cExp[i]=='/'||cExp[i]=='+'||cExp[i]=='-'||cExp[i]=='(')	//checking for operators
		{
			symbol m_op,m_temp;
			m_op=get_priority(cExp[i]);		//Getting the ISP and ICP
			if(oOperator.empty())		//If stack empty
				oOperator.push(m_op);
			if(!oOperator.empty())		//If stack not empty
			{
				symbol m_top;
				m_top=oOperator.get_top();	//Get the top of the stack
				if(m_op.nICP>m_top.nISP && m_op.nICP>0)
					oOperator.push(m_op);
				else if(m_op.nICP<m_top.nISP && m_op.nICP>0)
				{
					m_temp=oOperator.pop();	//If ICP<ISP, Pop the stack
					cout<<m_temp.cOp;
				}
				else if(m_op.nICP==m_top.nISP)
				{
					m_temp=oOperator.pop();	//If ICP and ISP are equal, Pop the stack and then push the new operator
					cout<<m_temp.cOp;
					oOperator.push(m_op);
				}
				if(m_op.nICP == -1)			//If operator is ')'
				{
					do
					{
						m_temp = oOperator.pop();
						if(m_temp.cOp!='(')
							cout<<m_temp.cOp;
					}while(m_temp.cOp!='(');		//Pop until first '('
				}
			}
		}
	}
	symbol m_last;
	m_last=oOperator.pop();					//Popping the last operator out of the stack
	cout<<m_last.cOp;
	return true;
}
bool Expression:: bPrefix()
{
	int n=0;
	while(cExp[n]!='#')						//Calculating the number of characters
		n++;
	for(int i=n; i>=0; i--)
	{
		if(cExp[i]>='A' && cExp[i]<='Z')	//Checking for operands
			cout<<cExp[i];
		if(cExp[i]==')'||cExp[i]=='^'||cExp[i]=='*'||cExp[i]=='/'||cExp[i]=='+'||cExp[i]=='-'||cExp[i]=='(')	//checking for operators
		{
			symbol m_op,m_temp;
			m_op=get_priority(cExp[i]);		//Getting the ISP and ICP
			if(oOperator.empty())		//If stack empty
				oOperator.push(m_op);
			if(!oOperator.empty())		//If stack not empty
			{
				symbol m_top;
				m_top=oOperator.get_top();	//Get the top of the stack
				if(m_op.nICP>m_top.nISP && m_op.nICP>0)
					oOperator.push(m_op);
				else if(m_op.nICP<m_top.nISP && m_op.nICP>0)
				{
					while(!oOperator.empty())
					{
						m_temp=oOperator.pop();	//If ICP<ISP, Pop the stack
						oOutput.push(m_temp.cOp);
					}
				}
				else if(m_op.nICP==m_top.nISP)
				{
					oOperator.push(m_op);		//If ICP and ISP are equal, push the new operator
				}
				if(m_op.cOp == '(')			//If operator is '('
				{
					do
					{
						m_temp = oOperator.pop();
						if(m_temp.cOp!=')')
							oOutput.push(m_temp.cOp);
					}while(m_temp.cOp!=')');		//Pop until first '('
				}
			}
		}
	}
	symbol m_last;
	m_last=oOperator.pop();					//Popping the last element out of the operator stack
	oOutput.push(m_last.cOp);				//Pushing the last element into the output stack
	while(!oOperator.empty())
	{
		symbol m_display;
		m_display=oOperator.pop();
		cout<<m_display.cOp;
	}
	return true;
}
int main()
{
	char ch;
	Expression oExpr;
	oExpr.bGetexp();
	cout<<"\nPostfix Expression:\t";
	oExpr.bPostfix();
	cout<<"\nDo you want to enter another expression?(y/n):\t";
	cin>>ch;
	if(ch=='y')
		oExpr.bGetexp();
	cout<<"\nPrefix Expression:\t";
	oExpr.bPrefix();
}
