#include <iostream>
#include <assert.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

int len(node *head)
{
	int x=0;
	while(head!=NULL)head=head->next,x++;
	return(x);
}

void Push(node **head,int d)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = d;
	temp->next = (*head);
	*head=temp;
}

void traverse(node *head)
{
	while(head!=NULL)
	{
		cout<<(head->data)<<" ";
		head=head->next;
	}
	cout<<endl;
}

node* TailInsert()
{
	/* Tail Insert */ 
	node *head = NULL,*tail;
	Push(&head,1);
	tail = head;
	for(int i=2;i<7;i++)
	{
		Push(&(tail->next),i);
		tail = tail->next;
	}
	return(head);
	/* Q.E.D. */
}
int count(node *head,int searchfor)
{
	int k=0;
	node *temp = head;
	while(temp!=NULL)
	{
		if(temp->data==searchfor)k++;
		temp = temp->next;
	}
	return(k);
}

int GetNth(node *head,int n)
{
	//Assuming all elements are non-negative
	//Returns -1 if NOT a valid index
	int k=0;
	node *temp = head;
	while(temp!=NULL)
	{
		if(k==n)break;
		k++;
		temp=temp->next;
	}
	if(temp==NULL)return(-1);
	return(temp->data);
}
void deleteLIST(node **head)
{
	node *temp=*head,*tp;
	while(temp!=NULL)
	{
		tp=temp->next;
		free(temp);
		temp=tp;
	}
	*head=NULL;
}
int pop(node **head)
{
	int x=(**head).data;
	node *temp = *head,*tp;
	tp = temp->next;
	free(temp);
	*head = tp;
	return(x);
}
void InsertNth(struct node** headRef, int index, int data) 
{
	// position 0 is a special case...
	if (index == 0) Push(headRef, data);
	else 
	{
		struct node* current = *headRef;
		int i;
		for (i=0; i<index-1; i++) {
		assert(current != NULL);
		current = current->next;
	}
	assert(current != NULL);
	// if this fails, index was too big
	// tricky: you have to check one last time
	Push(&(current->next), data); // Tricky use of Push() --
	// The pointer being pushed on is not
	// in the stack. But actually this works
	// fine -- Push() works for any node pointer.
	}
}
int main()
{
	node *t;
	t = (node*)malloc(sizeof(node));
	t->data = 2;
	t->next = NULL;
	cout<<len(t)<<endl;
	traverse(t);
	Push(&t,3);
	traverse(t);
	Push(&(t->next),5);
	traverse(t);

	node *a,b;
	a = &b;
	b.next = NULL;
	a->next = t->next;
	traverse(b.next);
	/*t = TailInsert();
	traverse(t);
	Push(&(t->next->next),21);
	Push(&(t->next->next),21);Push(&(t->next->next),21);
	traverse(t);
	cout<<count(t,4)<<endl;
	cout<<GetNth(t,5)<<endl;
	//deleteLIST(&t);
	pop(&t);
	traverse(t);*/

}
