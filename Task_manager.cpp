#include<iostream>
#include<string>
using namespace std;

/*******************************************
Name : Ravi Sawlani
Student ID: 201601120
/******************************************/
//data structures used is 4 queue 
class Teaching	//Created nodes of teaching class
{
	
	string description;
	Teaching *next;
	
	public:
	//getters and setters..................
	void setdescription(string idescription)
	{
		description=idescription;
	}
	
	void setnext(Teaching *t)
	{
		next=t;
	}
	
	Teaching *getnext()
	{
		return next;
	}
	
	string getdescription()
	{
		return description;
	}
	//getters and setters...................
};

class Academic		//created node of academic class
{

	string description;
	Academic *next;
	
	//getters and setters...................
	public:
			void setdescription(string idescription)
	{
		description=idescription;
	}
	
	void setnext(Academic *t)
	{
		next=t;
	}
	
	Academic *getnext()
	{
		return next;
	}
	
	string getdescription()
	{
		return description;
	}
	//getters and setters.................
};

class Research //node of research class
{
	
	string description;
	Research *next;
	public:
		
		//getters and setters..................
			void setdescription(string idescription)
	{
		description=idescription;
	}
	
	void setnext(Research *t)
	{
		next=t;
	}
	
	Research *getnext()
	{
		return next;
	}
	
	string getdescription()
	{
		return description;
	}
	
	//getters and setters..................
};

class Administrative
{
	
	string description;
	Administrative *next;
	public:
			void setdescription(string idescription)
	{
		description=idescription;
	}
	
	void setnext(Administrative *t)
	{
		next=t;
	}
	
	Administrative *getnext()
	{
		return next;
	}
	
	string getdescription()
	{
		return description;
	}
	
};

class Queue:public Teaching,public Academic,public Research,public Administrative
{

//created head and tail for each class node(example headt,tailt are pointers of queue of teaching type)
	Teaching *headt=NULL; 
	Teaching *tailt=NULL;
	Research *headr=NULL;
	Research *tailr=NULL;
	Academic *heada=NULL;
	Academic *taila=NULL;
	Administrative *headi=NULL;
	Administrative *taili=NULL;
	public:
  void	Enque(string type,string idescription)  // enque function for all four queue according to type..............
	{
		int signal=0;
		if(type=="teaching")
		{
			Teaching *temp=new Teaching;
			temp->setdescription(idescription);
			temp->setnext(NULL);
			if(headt==NULL)
			{
				headt=tailt=temp;
			}
			else
			{
				tailt->setnext(temp);
				tailt=temp;
			}
			signal=1;
		}
		
			if(type=="research")
		{
			Research *temp=new Research;
			temp->setdescription(idescription);
			temp->setnext(NULL);
			if(headr==NULL)
			{
				headr=tailr=temp;
			}
			else
			{
				tailr->setnext(temp);
				tailr=temp;
			}
			signal=1;
		}
		
			if(type=="academic")
		{
			Academic *temp=new Academic;
			temp->setdescription(idescription);
			temp->setnext(NULL);
			if(heada==NULL)
			{
				heada=taila=temp;
			}
			else
			{
				taila->setnext(temp);
				taila=temp;
			}
			signal=1;
		}
		
			if(type=="administrative")
		{
			Administrative *temp=new Administrative;
			temp->setdescription(idescription);
			temp->setnext(NULL);
			if(headi==NULL)
			{
				headi=taili=temp;
			}
			else
			{
				taili->setnext(temp);
				taili=temp;
			}
			signal=1;
		}
		if(signal==1){
		cout<<"task succesfully added"<<endl;}
		
		if(signal==0){
			cout<<"Invalid option"<<endl<<"Please enter valid option"<<endl<<endl;
		}
		
	}
	void removefrom(string type) 		//removefrom function is used to deque based on type given.
	{
	int	signal=0;
		if(type=="teaching")
		{
			headt=headt->getnext();
			signal=1;
		}
		
		if(type=="research")
		{
			headr=headr->getnext();
			signal=1;
		}
		
		if(type=="academic")
		{
			heada=heada->getnext();
			signal=1;
		}
		
		if(type=="administrative")
		{
			headi=headi->getnext();
			signal=1;
		}
		if(signal==1)
		{
			cout<<"task completed"<<endl;
			cout<<endl<<endl;
		}
	}
	
	void Deque()	 // Removed node using removefrom function. only priorty is set here i.e. teaching --- research --- academic --- administrative and then according to priority type is given to removefrom function.
	{
		if(headt!=NULL)removefrom("teaching");
        else if(headt==NULL&&headr!=NULL)removefrom("research");
		else if(headt==NULL&&headr==NULL&&heada!=NULL)removefrom("academic");
		else if(headt==NULL&&headr==NULL&&heada==NULL&&headi!=NULL)removefrom("administrative");
		else if(headt==NULL&&headr==NULL&&heada==NULL&&headi==NULL)cout<<"no tasks are remaining"<<endl<<endl;
		
	}
	
	void display() //to display all task
	{
		cout<<"pending task of type teaching"<<endl;
		Teaching *current1=headt;
		while(current1!=NULL)
		{
			cout<<current1->getdescription()<<" ---> ";
			current1=current1->getnext();
		}
		cout<<endl<<endl;
		
		cout<<"pending task of type research"<<endl;
		Research *current2=headr;
		while(current2!=NULL)
		{
			cout<<current2->getdescription()<<" ---> ";
			current2=current2->getnext();
		}
		cout<<endl<<endl;
		
		cout<<"pending task of type academic"<<endl;
		Academic *current3=heada;
		while(current3!=NULL)
		{
			cout<<current3->getdescription()<<" ---> ";
			current3=current3->getnext();
		}
		cout<<endl<<endl;
		
		cout<<"pending task of type administrative"<<endl;
		Administrative *current4=headi;
		while(current4!=NULL)
		{
			cout<<current4->getdescription()<<" ---> ";
			current4=current4->getnext();
		}
		cout<<endl<<endl;
	}
	
	void displaynextpending() // display next task according to priority.................
	{
		
		if(headt!=NULL)
		cout<<headt->getdescription()<<endl;
	else	if(headt==NULL)
		{
			if(headr!=NULL)
			cout<<headr->getdescription()<<endl;
		else	if(headr==NULL)
			{
				if(heada!=NULL)
				cout<<heada->getdescription()<<endl;
			else	if(heada==NULL)
				{
					if(headi!=NULL)
					cout<<headi->getdescription()<<endl;
					
					else if(headi==NULL)
					{
						cout<<"no pending task"<<endl;
					}
				}
			}
		}
	}
	
};

int main()
{
	int signal;
	Queue q;
	int a=1;
	int k;
	while(a!=0)
	{
	signal=0;
	cout<<endl;
	cout<<"*************************************************"<<endl;
	cout<<"1. Add a new task"<<endl;
	cout<<"2. Next pending task"<<endl;
	cout<<"3. Next task completed"<<endl;
	cout<<"4. Display all pending task"<<endl;
	cout<<"5. Exit program."<<endl;
	cout<<"*************************************************"<<endl;
	cin>>k;
	
	if(k==1)
	{
		string itype;
		string idescription;
		cout<<"enter type of the the task(options available:teaching,academic,administrative and research)"<<endl;
		cin>>itype;
		cout<<"enter description with no spaces in between"<<endl;
		cin>>idescription;
		q.Enque(itype,idescription);
		continue;
		
	}
	if(k==2)
	{
			q.displaynextpending();
			continue;
	
	}
	
	if(k==3)
	{
		q.Deque();
		continue;
		
	}
	
	if(k==4)
	{
		q.display();
		continue;
	}
	
	if(k==5)
	{
		a=0;
	}
	else{
		cout<<"choose from given options"<<endl<<endl;
		
	}
}
return 0;
}

