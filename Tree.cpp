#include<bits/stdc++.h>
#include"BST.h"
using namespace std;
int main()
{
	BST<int> oTree;
	int nChoice;
	cout<<"1.Enter elements in the tree\n2.Search elements\n3.Traverse the Tree\n4.Find minimum element\n5.Find maximum element\n6.Height of the tree\n7.Exit\n";
	do
	{
		cout<<"\nEnter a choice:\t";
		cin>>nChoice;

		//Validate input for choice to avoid infinite looping
		while(nChoice < 1 || nChoice >8)
		{
			cout<<"Invalid input\nEnter a choice:\t";
			cin.clear();			//Clears the state of input buffer flag
			cin.ignore(1000, '\n');		//Flushes out the 1000 characters in the buffer or until first '\n' is encountered
			cin>>nChoice;
		}								//end of while
		switch(nChoice)
		{
			case 1:	cout<<"Enter the numbers and enter -1 to quit\n";
					int a;
					do
					{
						cin>>a;
						if(a!= -1)
							oTree.insert(a);
						cin.clear();
						cin.ignore(1000, '\n');
					}while(a!=-1);
			 break;
			case 2: if(!oTree.empty())
					{
						cout<<"Enter the element to be searched\n";
						int nKey,found;
						cin>>nKey;
						found = oTree.search(oTree.pRoot, nKey);
						if(found == 0)
							cout<<"Element not found\n";
						else
							cout<<"Element "<<nKey<<" Found";
					}			//End of if
					else
						cout<<"Tree is empty\n";
			 break;
			case 3: if(!oTree.empty())
					{
						cout<<"How do you want to traverse the tree?\n1.Preorder\n2.Postorder\n3.Inorder\n";
						int choice;
						cin>>choice;
						while(choice<1 || choice>3)
						{
							cout<<"Invalid input\n";
							cin>>choice;
						}
						switch(choice)
						{
							case 1: cout<<"Preorder:\t";
									oTree.preorder(oTree.pRoot);
									cout<<endl;
							 break;
							case 2: cout<<"Postorder:\t";
									oTree.postorder(oTree.pRoot);
									cout<<endl;
							 break;
							case 3: cout<<"Inorder:\t";
									oTree.inorder(oTree.pRoot);
									cout<<endl;
						}		//End of switch
					}			//end of if
					else
						cout<<"Tree is empty\n";
			 break;
			case 4: if(!oTree.empty())
					{
						int max;
						max=oTree.max();
						cout<<"Max:\t"<<max<<endl;
					}
					else
						cout<<"Tree is empty\n";
			 break;
			case 5: if(!oTree.empty())
					{
						int min;
						min = oTree.min();
						cout<<"Min:\t"<<min<<endl;
					}
					else
						cout<<"Tree is empty\n";
			 break;
			case 6: if(oTree.empty())
						cout<<"Tree is empty\n";
					else
					{
						int height= oTree.height(oTree.pRoot);
						cout<<"Height:\t"<<height<<endl;
					}
			 break;
			//case 7: oTree.~BST<int>();
			// break;
			case 7:	cout<<"Exiting\a\n";
			 break;
			default: cout<<"Please enter a valid choice\n";
		}					//End of switch
	}while(nChoice!=7);
	cout<<"Thankyou!\n\n";
	return 0;
}
