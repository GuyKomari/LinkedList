#include <stdio.h>
#include <stdlib.h>

typedef struct node * ptr;/*pointer to node*/

typedef struct node{
	int key;
	ptr next;
}item;

void addToList(ptr *, int);
void printList(ptr);
void delete(ptr *,int);
void freeList(ptr *);
#define x 3

int main()
{
	ptr head=NULL;
	int num;
	while(scanf("%d",&num)==1)
		addToList(&head,num);
	printList(head);
	delete(&head,x);
	printf("after deleting %d\n", x);
	printList(head);
	freeList(&head);
return 0;
}

void printList(ptr h)
{
	while(h){
		printf("%d --> ",h->key);
		h=h->next;
	}
	printf("***\n");
}

void freeList(ptr *h)
{
	ptr temp;
	while(*h)
	{
		temp=*h;
		*h=(*h)->next;
		free(temp);
	}
}
void addToList(ptr * h,int n)
{
	ptr new,p1,p2;
	new=(ptr) malloc(sizeof(item));
	if(!new){
		printf("cannot allocate memory\n");
		exit(0);
	}
	new->key=n;
	if((*h)==NULL)/* case - empty list */
	{
		*h=new;
		new->next = NULL;
		return;
	}
	else/* case - not empty list */
	{
		p1=*h;/* pointer to the head of the list */
		while((p1)&&((p1->key)<n))/* finding where to insert the new key */
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1==(*h))/* case - the new kew is lower then the head, than insert the new key to the head of the list */
		{
			*h=new;
			new->next=p1;
		}
		else /*case - the new key need to be insert between two nodes or at the end of the list */
		{
			p2->next=new;
			new->next=p1;
		}
	}
}

void delete(ptr *h,int key)
{
	ptr p1,p2;
	if((*h)==NULL)/*case - empty list*/
		return;
	else
	{
		p1=*h;
		while((p1)&&((p1->key)!=key))/* finding the key should be deleted */
		{
			p2=p1;
			p1=p1->next;
			if(p1==NULL)/* case - there is no such this key in the list */
				return;
		}
		if(p1==(*h))/* case - the key is the head of the list */
		{
			(*h)=p1->next;
			free(p1);
		}
		else
		{
			if(p1->next!=NULL)/* case - the key is between two nodes */
			{
				p2->next=p1->next;
				free(p1);
			}
			else/* case - the key is the tail of the list */
			{
				p2->next=NULL;
				free(p1);
			}
		}
	}
}









