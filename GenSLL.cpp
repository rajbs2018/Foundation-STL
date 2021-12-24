#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
	struct node *next;
};

template<class T>
class SinglyLL
{
private:
	node<T>*first;
	int size;
	
public:
	SinglyLL();
	void InsertFirst(T no);
	void InsertLast(T no);
	void DeleteFirst();
	void DeleteLast();
	void InsertAtPos(T no ,int);
	void DeleteAtPos(int);
	void Display();
	int Count();
};

template<class T>
	SinglyLL<T>::SinglyLL()
	{
		first =NULL;
		size = 0;
	}
	
template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
	node<T>*newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE));
		
	newn -> data = no;
	newn -> next = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn -> next = first;
		first = newn;
	}
	size++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
	node<T>*newn = new node<T>; // newn = (PNODE)malloc(sizeof(NODE));
		
	newn -> data = no;
	newn -> next = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		node<T>*temp = first;
			
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
	size++;
}
	
template<class T>	
void SinglyLL<T>::DeleteFirst()
{
	node<T>*temp = first;
		
	if(first != NULL)
	{
		first = first -> next;
		delete temp;
			
		size--;
	}
}

template<class T>	
void SinglyLL<T>::DeleteLast()
{
	node<T>*temp = first;
		
	if(first == NULL)
	{
		return;
	}
	if(first -> next == NULL)
	{
		delete first;
		first =NULL;
		size--;
	}
	else
	{
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
			
		delete temp -> next;
		temp -> next =NULL;
		size--;
	}
}

template<class T>	
void SinglyLL<T>::InsertAtPos(T no , int ipos)
{
	node<T>*newn = new node<T>;
	node<T>*temp = first;
	int i = 0;
		
	newn -> data = no;
	newn -> next = NULL;
		
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		node<T>*newn = new node<T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		for(i = 1 ; i < ipos - 1 ; i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;
		}	
		size++;
	}
	
template<class T>	
void SinglyLL<T>::DeleteAtPos(int ipos)
{
	node<T>*temp = first;
	node<T>*targated = NULL;
	int i = 0;
		
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos  == size + 1)
	{
		DeleteLast();
	}
	else
	{
		for(i = 1; i < ipos -1 ; i++)
		{
			temp = temp -> next;
		}
		targated = temp -> next;
		temp -> next = targated -> next;
		delete(targated);
	}
	size--;
}

template<class T>	
void SinglyLL<T>::Display()
{
		
	node<T>*temp = first;
		
	if(size == 0)
	{
		cout<<"Linked list is empty \n";
		cout<<"NULL";
	}
		
	while(temp != NULL)
	{
		cout<<temp -> data <<"\t";
		temp = temp -> next;
	}
	cout<<"\n";
}
	
template<class T>	
int SinglyLL<T>::Count()
{
	return size;
}


int main()
{
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Singly Linear Linked List.
	// Input		 : Integer.
	// Output		 : Integer.
	/////////////////////////////////////////////////////////////////////
	SinglyLL <int>iobj;
	
	iobj.InsertFirst(21);
	iobj.InsertFirst(11);
	
	iobj.InsertLast(51);
	iobj.InsertLast(101);
	
	iobj.InsertAtPos(75,3);
	iobj.Display();
	
	int iRet = iobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	iobj.DeleteAtPos(3);
	iobj.DeleteFirst();
	iobj.DeleteLast();
	
	iRet = iobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	iobj.Display();
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Singly Linear Linked List.
	// Input		 : float.
	// Output		 : float.
	/////////////////////////////////////////////////////////////////////
	
	SinglyLL <float>fobj;
	
	fobj.InsertFirst(21.5);
	fobj.InsertFirst(11.5);
	
	fobj.InsertLast(51.5);
	fobj.InsertLast(101.5);
	
	fobj.InsertAtPos(75.5,3);
	fobj.Display();
	
	iRet = fobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	fobj.DeleteAtPos(3);
	fobj.DeleteFirst();
	fobj.DeleteLast();
	
	iRet = iobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	fobj.Display();
	
	///////////////////////////////////////////////////////////////////// 
	// Function Name : Singly Linear Linked List.
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	SinglyLL <char>cobj;
	
	cobj.InsertFirst('B');
	cobj.InsertFirst('A');
	
	cobj.InsertLast('C');
	cobj.InsertLast('D');
	
	cobj.InsertAtPos('E',3);
	cobj.Display();
	
	iRet = cobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	cobj.DeleteAtPos(3);
	cobj.DeleteFirst();
	cobj.DeleteLast();
	
	iRet = iobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	cobj.Display();
	
	
	
	
	
	/*SinglyLL <int>obj;
	int iret = 0,value = 0,pos = 0,ichoice = 1; 
	
	while(ichoice != 0)
	{
		cout<<"\n----------------------------------------------------------\n";
		cout<<"1 : Insert a node at First Position \n";
		cout<<"2 : Insert a node at Last Position \n";
		cout<<"3 : Insert a node at At Position \n";
		cout<<"4 : Delete a node at First Position \n";
		cout<<"5 : Delete a node at Last Position \n";
		cout<<"6 : Delete a node at At Position \n";
		cout<<"7 : Display the linked list \n";
		cout<<"8 : Count Of Linked list \n";
		cout<<"0 : Exit from Linked list \n";
		cout<<"\n----------------------------------------------------------\n";
		
		cin>>ichoice;
		
		switch(ichoice)
		{
			case 1 :
			cout<<"Enter a number to insert in first Position \n";
			cin >>value;
			obj.InsertFirst(value);
			break;
			
			case 2 :
			cout<<"Enter a number to insert in last position \n";
			cin>>value;
			obj.InsertLast(value);
			break;
			
			case 3:
			cout<<"Enter a number to insert in linked list \n";
			cin>>value;
			cout<<"Enter a position to add node in linkedlist \n";
			cin>>pos;
			obj.InsertAtPos(value,pos);
			break;
			
			case 4:
			cout<<"Deleted first node \n";
			obj.DeleteFirst();
			break;
			
			case 5:
			cout<<"Deleted last node \n";
			obj.DeleteLast();
			break;
			
			case 6:
			cout<<"Enter a position to delete a node \n";
			cin>>pos;
			obj.DeleteAtPos(pos);
			break;
			
			case 7:
			cout<<"Linked List is : \n";
			obj.Display();
			break;
			
			case 8:
			iret = obj.Count();
			cout<<"Number of elements are : "<<iret<<"\n";
			break;
			
			case 0:
			cout<<"Thanks for using Linked list";
			break;
			
			default:
			cout<< "Enter a choice in range of 0 to 8";
			break;
		}
	}*/
	return 0;
}