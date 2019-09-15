#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
#include"HashTable.h"
using namespace std;
class info
{
 public:
 	string name,ph;
 	info()
 	{
 		name = "New";
 		ph = "ph";
 	}
 	info(string n,string p)
 	{
 		name = n;
 		ph = p;
 	}
};
int main()
{
  vector<info> vec_data;
	ifstream inFile("phone.csv");
  if(!inFile.is_open())
  {
    cerr<<"Error opening file.";
    return 0;
  }

  string name, phone, line;
  while(getline(inFile,line))
  {
    stringstream ss(line);
    getline(ss,name,',');
    getline(ss,phone,',');
    //cout<<name<<":"<<phone<<endl;
    info stu(name,phone);
    vec_data.push_back(stu);
  }
  HT<info> table(6/*vec_data.size()*/);
  for(int i = 0; i<vec_data.size(); i++)
    table.insert(vec_data[i]);

	//table.display_all();

    int nChoice;
  	cout<<"1.Enter more keys\n2.Search names\n3.Display the table\n4.Exit\n";
  	do
  	{
  		cout<<"\nEnter a choice:\t";
  		cin>>nChoice;

  		//Validate input for choice to avoid infinite looping
  		while(nChoice < 1 || nChoice >4)
  		{
  			cout<<"Invalid input\nEnter a choice:\t";
  			cin.clear();			//Clears the state of input buffer flag
  			cin.ignore(1000, '\n');		//Flushes out the 1000 characters in the buffer or until first '\n' is encountered
  			cin>>nChoice;
  		}								//end of while
  		switch(nChoice)
  		{
  			case 1:
          {
          	cout<<"\nEnter a new record:"<<endl;
  			info temp_stu;
  			cin.clear();
  			cin.ignore(1000,'\n');
            cout<<"Enter the name: ";
            getline(cin,temp_stu.name);
            cout<<"Enter the phone number: ";
            cin>>temp_stu.ph;
            table.insert(temp_stu);
          }
  			 break;
  			case 2:
          {
          	cout<<"\nSearch a record:"<<endl;
            string name;
            cin.clear();
  			cin.ignore(1000,'\n');
            cout<<"Enter the name: ";
            getline(cin,name);
            if(table.search(name))
              ;
            else
              cerr<<"Key not present";
          }
  			 break;
  			case 3:
  				cout<<"\nTHE TABLE:"<<endl;
          		for(int i = 0; i< table.max; i++)
            	table.display(i);
  			 break;
  			case 4:	cout<<"\n\nExiting\a\n";
  			 break;
  			default: cout<<"Please enter a valid choice\n";
  		}					//End of switch
  	}while(nChoice!=4);
  	cout<<"Thankyou!\n\n";
  	return 0;
}
