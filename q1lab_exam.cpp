#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
//**********************************************
// name: Ravi sawlani
// Student Id: 201601120
//**********************************************
//data structure used is stack
class Employee
{
	string name;
	int id;
	int doj[3];//created an array of 3 elements for date of joining.
	
	public:
		//getters and setters.............
		void setname(string iname)
		{
			name=iname;
		}
		void setid( int iid)
		{
			id=iid;
		}
		void setdoj(int a[])
		{
			doj[0]=a[0];
			doj[1]=a[1];
			doj[2]=a[2];
		}
		int getid()
		{
			return id;
		}
		int *getdoj()
		{
			return doj;
		}
		string getname()
		{
			return name;
			
		}
		//getters and setter..........
};
class stack
{
	Employee e[100];//created array of employee..........
	int nemployee=0;//number of employee...........
	int top=0;//points one space ahead of last inserted data 
	
	public:
		//getters and setters..............................
		Employee * getarrayofemployee()
		{
			return e;
		}
		
		int getnemployee()
		{
			return nemployee;
		}
	 //getters and setters....................................
	 void push(string name,int id,int a[]) // enters the detail of the employee.................
	 {
	 	if(top==100)
	 	{
	 		cout<<"sorry no space left for allocation"<<endl;	
		}
		else
		{
			e[top].setid(id);
			e[top].setname(name);
			e[top].setdoj(a);
			top++;
			nemployee++;
			cout<<endl;
			cout<<"employee details succesfully reocrded"<<endl;
		}
	 }
	 
	 void pop() //deletes last element entered i.e. last employee joined.
	 {
	 	if(top==0)
	 	{
	 		cout<<"no employee is left to laid off"<<endl;
		 }
		 else{
		 
		 cout<<"employee with name "<<e[top-1].getname()<<" laid off"<<endl;
	 	top--;
	 	nemployee--;}
	 }
	 Employee * sort(Employee a[],int nemployee) //sorting function to sort details of employee based on joined date..........(bubble sort)
{
	a=getarrayofemployee();
	int i,j;
	for(i=0;i<nemployee-1;i++)
	{
		for(j=0;j<nemployee-1-i;j++)
		{
			int *a1,*a2;
			a1=a[j].getdoj();
			a2=a[j+1].getdoj();
			if(a1[2]>a2[2])
			{
				Employee z;
				z=a[j];
				a[j]=a[j+1];
				a[j+1]=z;
			}
		else	if(a1[2]==a2[2])
			{
				if(a1[1]>a2[1])
				{
						Employee z;
				z=a[j];
				a[j]=a[j+1];
				a[j+1]=z;
				}
			else	if(a1[1]==a2[1])
				{
					if(a1[0]>a2[0])
					{
							Employee z;
				z=a[j];
				a[j]=a[j+1];
				a[j+1]=z;
					}
					
				}
			}
		}
		
	}
}

void display()
{
	int i;
	cout<<"***********************************"<<endl<<endl;
	if(nemployee==0)
	{
		cout<<"no employees are left"<<endl;
	}
	else 
	{
	
	for(i=0;i<nemployee;i++)
	{
		cout<<e[i].getname()<<endl;
	}
}
}
	
};
int main()
{
	int signal=0;
	stack s;
	int k;
	int a=1;
	while(a!=0)
	{
	cout<<"************************************************************************************************"<<endl;
	cout<<"1. enter the details of all employee "<<endl;
	cout<<"2. remove employee "<<endl;
	cout<<"3. display employee name according to date of joining(recently joined employee will be at last.)"<<endl;
	cout<<"4. exit program"<<endl;
	cout<<"************************************************************************************************"<<endl;
	cin>>k;

	
	if(k==1)
{
	signal=1;
		while(1)
		{
		
		string name,k;
			int i;
			int iid;
			int a[3];
			cout<<"enter name"<<endl;
			cin>>name;
			cout<<"enter ID"<<endl;
			cin>>iid;
			cout<<"enter date of joining in format dd mm yyyy"<<endl;
			for(i=0;i<3;i++)
			{
				cin>>a[i];
			}
			s.push(name,iid,a);
			
			cout<<"do want enter details for another employee ans in yes or no"<<endl;
			cin>>k;
			if(k=="yes")
			{
				cout<<endl;
				cout<<endl;
				continue;
			}
			else{
				s.sort(s.getarrayofemployee(),s.getnemployee());
			   break;
			}
	}
	
}
if(k==2)
{
	s.pop();
	signal=1;
}
if(k==3)
{
	s.display();
	signal=1;
}
if(k==4)
{
	a=0;
	signal=1;
}
else if(signal==0)
{
	cout<<"please choose valid option"<<endl;
}
}
	return 0;
	
}


