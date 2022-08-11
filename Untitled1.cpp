#include <iostream>
#include<windows.h>
using namespace std;
class Contact
{
struct Node
{
	string name;
	//string address;
	long long int phone_number;
	Node*next;
};

  string a;
  string b;
  long long int y;
  Node*head;
  public:
  Contact()
  {
    a="";
    //b="";
    y=0;
    head=NULL;	
  }	
  void choice()
  {
     	int n;
     	cout<<"\n\t\t-------------------------------------"<<endl;
  		cout<<"\n\t\tENTER 1 TO INSERT CONTACTS"<<endl;
		cout<<"\n\t\tENTER 2 TO DELETE CONTACTS"<<endl;
		cout<<"\n\t\tENTER 3 TO EDIT CONTACTS"<<endl;
		cout<<"\n\t\tENTER 4 TO DISPLAY CONTACTS"<<endl;
		cout<<"\n\t\tENTER 5 TO SEARCH CONTACTS"<<endl;
		cout<<"\n\t\t-------------------------------------"<<endl<<endl;
		cout<<"Your  choice: ";
		cin>>n;
		system("cls");
		switch(n)
		{
			case 1:
		         Add();
                 cout<<endl;
		         break;
		    case 2:
		    	
		    		deletion();
                	cout<<endl;
		  	        break;
		   	case 3:
		   		    system("cls");
		        	int a;
		        	cout<<"\n\t\t-------------------------------------"<<endl;
		        	cout<<" \n\t\t1. EDIT NUMBER: "<<endl;
		         	cout<<" \n\t\t2. EDIT NAME:"<<endl;
		         	cout<<"\n\t\t-------------------------------------"<<endl;
		        	cout<<"Your Choice: ";
		        	cin>>a;
		        	system("cls");
		            	if(a==1)
		               	{
			               	edit_Num();
				            cout<<endl;
		    	            choice();
			            }
		               	else if(a==2)
		               	{
		             	   edit_Name();	
	            		   cout<<endl;
	            		   choice();
	                	}
	                	else
                    	{
						   system("cls");
	                	   choice();
		            	} 
			             break;
			             
	        	case 4:	
		                display();
		                cout<<endl;
		                choice();
		                break;
		                
		       case 5:
		               	 search();
        	             cout<<endl;
                    	 choice();
		  	             break;
		  	    
		  	            default:
		  	            cout<<"\n\n\t\t  INVALID CHOICE!ENTER AGAIN"<<endl<<endl;
		  	            choice();
		  	            
		  	    	   
		  	 
		}
	}
		


	void display_dot()
	{
		for(int i=0;i<3;i++)
	    {   
	        cout<<".";
	        Sleep(500);        
	    }
	}
	
void Add()
{
   
  	if(head==NULL)
  	{
  		 Node*new_node=new Node;
  		  cout<<"\n\t\t\t\t CONTACT INFORMATION"<<endl;
    	  cout<<"\t\t\t\t------------------------"<<endl;
    	  cout<<"\n\n\t\t\t\tNAME:\t\t";
		  cin>>a;
		  new_node->name=a;
		  cout<<"\n\n\t\t\t    PHONE NUMBER:\t";
		  cin>>y;
		  new_node->phone_number=y;
		  //cout<<"\n\n\t\t \t      ADDRESS:\t\t";
		  //cin>>b;
		  //new_node->address=b;
		  new_node->next=NULL;
		  head=new_node;
		  cout<<"\n\n\t\t\t\t\t";
		  display_dot();
		  system("cls");
		  cout<<"\n\t\tCONTACT ADDED SUCCESSFULLY\n\n"<<endl;
		  	char x;
			cout<<"  DO YOU WANT TO ADD MORE CONTACTS? ";
			cin>>x;
			cout<<"\n\n\t\t\t\t\t";
		    display_dot();
		    system("cls");
			if(x=='y'||x=='Y')
			{
			   Add();
		    }
		    else
		    {
		    	choice();
			}		
		   
	}	             

    else
    {
    	Node*temp=head;
    	Node*new_node=new Node;
    	new_node -> next = NULL;
    	   cout<<"\n\t\t\t\t CONTACT INFORMATION"<<endl;
    	   cout<<"\t\t\t\t------------------------"<<endl;
              cout<<"\n\n\t\t\t\tNAME:\t\t";
			  cin>>a;
			  new_node->name=a;
			  cout<<"\n\n\t\t\t    PHONE NUMBER:\t";
			  cin>>y;
			  new_node->phone_number=y;
			  // cout<<"\n\n\t\t \t      ADDRESS:\t\t";
	    	   //cin>>b;
	    	   //new_node->address=b;
			   while(temp->next!=NULL)
    	{
			  temp=temp->next;	  
     	}
     	temp->next=new_node;
     	cout<<"\n\n\t\t\t\t\t";
        display_dot();
        system("cls");
     	cout<<"\n\t\tCONTACT ADDED SUCCESSFULLY\n\n"<<endl;
     		char x;
			cout<<"  DO YOU WANT TO ADD MORE CONTACTS? ";
			cin>>x;
			cout<<"\n\n\t\t\t\t\t";
            display_dot();
            system("cls");
			if(x=='y'||x=='Y')
			{
			   Add();
		    }
		    else
		    {
		    	choice();
			}		
		  
}
choice();

}
void deletion()
{	
	if(head==NULL)
	{	
	    cout<<"\n\n\t\t\t\t\t";
	    display_dot();
	    system("cls");
	    cout<<"\n\n\t\tEMPTY CONTACT BOOK! NOTHING TO DELETE"<<endl;
		choice();
    } 
	long long int number_delete;
	cout<<"\n\n\t\t\tNUMBER TO BE DELETED\t";
	cin>>number_delete;
	Node*temp=head;
	Node*prev=NULL;
	if(temp!=NULL&&temp->phone_number==number_delete)
	{	
	
			head=temp->next;
		  	delete temp;
		  	cout<<"\n\n\n\t\t\t\t\t";
		  	display_dot();
		  	system("cls");
		  
			cout<<"\n\n\n\t\t\tCONTACT DELETED SUCCESSFULLY\n\n"<<endl;
			
			char x;
			cout<<"  DO YOU WANT TO DELETE MORE? ";
			cin>>x;
			cout<<"\n\n\t\t\t\t\t";
		    display_dot();
		    system("cls");
			if(x=='y'||x=='Y')
			{
			   deletion();
		    }
		    else
		    {
		    	choice();
			}		
	}
		else 
		{
			while(temp!=NULL&&temp->phone_number!=number_delete)
			{
			prev=temp;
			temp=temp->next;
	    	}
    		if (temp == NULL)
	    	{
	    		cout<<"\n\n\n\t\t\t\t\t";
		    	display_dot();
		     	system("cls");
	    		cout<<"\n\n\n\t\t\tNOT FOUND \n\n\n";
	    		choice();
			}
	    
	    	prev->next=temp->next;
	    	delete temp;
            cout<<"\n\n\n\t\t\t\t\t";
	    	display_dot();
            system("cls");
        
	    	cout<<"\n\n\n\t\t\tCONTACT DELETED SUCCESSFULLY\n\n"<<endl;
	    	
	        char x;
			cout<<" DO YOU WANT TO DELETE MORE? ";
			cin>>x;
			cout<<"\n\n\t\t\t\t\t";
		    display_dot();
		    system("cls");
			if(x=='y'||x=='Y')
			{
			   deletion();
		    }
		    else
		    {
		    	choice();
			}
		}
}

void edit_Num()
{
	if(head==NULL)
	{
		cout<<"\n\n\t\t\tNOTHING TO EDIT \n\n"<<endl;
		choice();
	}
	system("cls");
  	Node*temp=head;
    long long	int edit_number;
  	cout<<"\n\n\t\t\tNUMBER TO BE EDIT\t";
  	cin>>edit_number;
  	while(temp!=NULL)
  	{
  	  if(temp->phone_number==edit_number)
  	  {
  	    cout<<"\n\n\t\t\tNEW NUMBER\t";
  	    cin>>y;
		temp->phone_number=y;
		cout<<"\n\n\n\t\t\t\t\t";
		display_dot();
		system("cls");
		cout<<"\n\t\tNUMBER EDITTED SUCCESSFULLY \n\n"<<endl;
		 char x;
			cout<<" DO YOU WANT TO EDIT MORE? ";
			cin>>x;
			cout<<"\n\n\t\t\t\t\t";
		    display_dot();
		    system("cls");
			if(x=='y'||x=='Y')
			{
			   edit_Num();
		    }
		    else
		    {
		    	choice();
			}
		
	  }
	  else
	  {
	  	temp=temp->next;
	  }
 }
 	            cout<<"\n\n\n\t\t\t\t\t";
		    	display_dot();
		     	system("cls");
                cout<<"\n\n\t\t\tINVALID NUMBER\n\n"<<endl;
                choice();
		
}
 void edit_Name()
{
	string edit_name;
	Node*temp=head;
	if(head==NULL)
	{
		cout<<"\n\n\t\t\tNOTHING TO EDIT"<<endl;
		choice();
	}
	else
	{
		system("cls");
  	    cout<<"\n\n\t\t\tNAME TO EDIT\t"<<endl;
    	cin>>edit_name;
  	while(temp!=NULL)
  	{
  	
  		 if(temp->name==edit_name)
     	  {
	      	cout<<"\n\n\t\t\t NEW NAME ";
  	        cin>>a;
	     	temp->name=a;
	     	cout<<"\n\n\n\t\t\t\t\t";
	      	display_dot();
		    system("cls");
		    cout<<"\n\t\tNAME EDITTED SUCCESSFULLY\n\n "<<endl;
		    char x;
		    cout<<" DO YOU WANT TO EDIT MORE? ";
			cin>>x;
			cout<<"\n\n\t\t\t\t\t";
		    display_dot();
		    system("cls");
			if(x=='y'||x=='Y')
			{
			   edit_Name();
		    }
		    else
		    {
		    	choice();
			}
	        
  		  }
  		  else
  		  {
  		     temp=temp->next; 	
		  }
  	}
  	     	cout<<"\n\n\n\t\t\t\t\t";
	      	display_dot();
  	 	    system("cls");
  	        cout<<"\n\t\tNAME DOESNOT EXIST \n\n"<<endl;
  	        choice();
		
  }
}



void bubble_sorted()
{
	Node*srch=head;
	string n;
	string adr;
	long long int p_nm;
	Node*i;
	Node*j;
	for(i=head;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
		   if(i->name>j->name)
		   {
		    n=i->name;
		    i->name=j->name;
		    j->name=n;
		    
		    p_nm=i->phone_number;
		    i->phone_number=j->phone_number;
		    j->phone_number=p_nm;
		    
		   // adr=i->phone_number;
		    //i->address=j->address;
		    //j->address=adr;	    
		   }		
		}		
	}
}	


void search()
{
	bool found =false;
	if(head==NULL)
	{
		cout<<"\n\n\t\t\EMPTY CONTACT LIST"<<endl;
		choice();
	}
	else
  {
	
		Node*sch=head;
		int sch_num;
		cout<<"\n\n\t\t\tNUMBER TO BE SEARCHED\t";
		cin>>sch_num;
		while(sch!=NULL)
	{
		
	    	if(sch->phone_number==sch_num)
		{
		     found =true;
		     break;
		}
        	sch=sch->next;
    }
    cout<<"\n\n\n\t\t\t\t\t";
	display_dot();
    system("cls");
  if(found==true)
    {
    	   
		   
    	   cout<<"\n\n\t\t\tFOUNDED \n\n\n";
    	   
		   cout<<"\t\t\tNAME\t PHONE NUMBER\t "<<endl;//ADDRESS"<<endl;
		   cout<<"\t\t\t"<<sch->name<<"  \t "<<sch->phone_number;//<<"\t\t "<<sch->address;
		   cout<<endl<<endl;
		   choice();
		   
	}
       else
	   {
	     cout<<"\n\n\n\t\t\t\tNOT FOUNDED"<<endl;	
	     choice();
	     
	   } 	    	
}
}
	void display()
	{
		if(head==NULL)
		{
			cout<<"NO CONTACT TO SHOW!";
			
		}
		else
		{
			cout<<"\n\n\n\tNAME\t  PHONE NUMBER"<<endl;
			bubble_sorted();
	        Node*temp=head;
	        int count=0;
	        while(temp!=NULL)
	      {
	      	count++;
		    cout<<"\t"<<temp->name<<"      ";
		    cout<<temp->phone_number<<"          ";
		    //cout<<temp->address;
		    cout<<endl;
	      	temp=temp->next;
		  }
		  cout<<endl<<endl;
		  cout<<"\n\t\tTOTAL CONTACTS "<<count<<endl;
		}
		char x;
		cout<<"\n PRESS ANY KEY TO CONTINUE OR -1 TO EXIT ";
		cin>>x;
		cout<<"\n\n\n\t\t\t\t\t";
     	display_dot();
        system("cls");
		while(x!=-1)
		{
			return;
		}
			
	}
};

int main()
{
	    cout<<"\n\n\n\t\t\t---------------------------------------";
		cout<<"\n\n\t\t\t          CONTACT BOOK SYSTEM   "<<endl;
	    cout<<"\t\t\t---------------------------------------"<<endl<<endl<<endl;
	    cout<<"\t\t\t ENTER CREDENTIALS "<<endl;
	    cout<<"\t\t\t--------------------"<<endl<<endl;
	    
	Contact c;
	string user_name;
	int password;
	cout<<"\tUSER NAME\t\t";
	cin>>user_name;
	cout<<endl;
	cout<<"\tPASSWORD\t\t ";
	cin>>password;
	system("CLS");
	
	cout<<"\n\n\n\n\n\t\t\t\t\tVALIDATING YOUR CREDENTIALS.";
	if(user_name=="Huzaifa"&&password==789)
	{	
		c.display_dot();
		system("cls");
		cout<<"\n\n\n\n\n\t\t\t\tSUCCESSFULLY LOGIN "<<endl;
	    c.choice();	  
	}
	else
	{
	  c.display_dot();
	  system("cls");
	  cout<<"\n\n\n\n\n\t\t\t\tINVALID CREDENTIALS TRY AGAIN!"<<endl;
	  main();	
	}
	
}
