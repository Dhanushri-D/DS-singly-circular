//circular singly linked list
#include<stdio.h>
#include<stdlib.h>
//creating structure
struct node{
	int data;
	struct  node *next;
};
//function to create node
struct node* Create(int data)
{
	struct node *nn=(struct node*)malloc(sizeof(struct  node));
	nn->data=data;
	nn->next=NULL;
	return nn;	
}
//1.insert at beginning
//void insertAtBegin(struct node **head,int data)
//{
//	struct node *nn=Create(data);
//	if(*head==NULL)
//	{
//		*head=nn;
//		nn->next=nn;
//	}
//	else
//	{
//		struct node *temp=*head;
//		nn->next=*head;
//		while(temp->next!=*head){
//			temp=temp->next;
//		}
//		temp->next=nn;
//		*head=nn;
//	}
//}
//2.insert at end
void insertAtEnd(struct node **head,int data)
{
	struct node *nn=Create(data);
	if(*head==NULL)
	{
		*head=nn;
		nn->next=nn;
	}
	else
	{
		struct node *temp=*head;
		while(temp->next!=*head)
		{
			temp=temp->next;
		}
		temp->next=nn;
		nn->next=*head;
	}
}
////3.insert at specific position
//void insertAtPosition(struct node **head,int data,int pos)
//{
//	struct node *nn=Create(data);
//	struct node *temp=*head;
//	struct node *prev=*head;
//	int count=0;
//	if(*head==NULL){
//		*head=nn;
//		nn->next=nn;
//	}
//	else if(pos==1){
//		while(temp->next!=*head){
//			temp=temp->next;
//		}
//		temp->next=nn;
//		nn->next=*head;
//		*head=nn;
//	}
//	else{
//		while(count<pos-1)//at current position
//		{
//			prev=temp;
//			temp=temp->next;
//			count++;
//		}
//		prev->next=nn;
//		nn->next=temp;
//	}	
//}
//deletion
void deletionAtPosition(struct node **head,int pos,int n)
{
	struct node *temp=*head;
	struct node *prev=*head;
	if(pos>n){
		printf("Invalid position");
	}
	else if(*head==NULL){
		printf("No element to delete\n");
		return;
	}
	else if(pos==1){
		while(temp->next!=*head){
			temp=temp->next;
		}
		*head=prev->next;
		temp->next=*head;
		free(prev);
	}
	else if(pos==n){
		while(temp->next!=*head){
			prev=temp;
			temp=temp->next;
		}
		prev->next=*head;
		free(temp);
	}
	else{
		int count=0;
		while(count<pos-1){
			prev=temp;
			temp=temp->next;
			count++;
		}
		prev->next=temp->next;
		free(temp);
	}
	printf("List after deletion at specific position:\n");
}
void display(struct node *head){
	struct node *temp = head;
	while(temp->next!=head){
		printf("%d <-> ",temp->data);
		temp=temp->next;
	}
	printf("%d ",temp->data);
}
int main(){
	struct node *head=NULL;
	int i,n,data,pos;
	printf("\nEnter number of elements to be entered : ");
	scanf("%d",&n);
	printf("Enter elements :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
//	printf("Enter position of element to entered : ");
	printf("Enter position to delete ; ");
	scanf("%d",&pos);
	deletionAtPosition(&head,pos,n);
//	printf("Enter element : ");
//	scanf("%d",&data);
//	insertAtPosition(&head,data,pos);
	display(head);
}
