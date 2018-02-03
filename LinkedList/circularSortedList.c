#include <stdio.h>
#include <stdlib.h>

typedef struct node * ptr;

typedef struct node{
	int key;
	ptr next;
}item;

void addToList(ptr *,ptr *,int);
void printList(ptr);
void delete(ptr *,ptr*,int);
void freeList(ptr *);

#define x 3
int main()
{
	ptr head=NULL;
	ptr tail=NULL;
	int num;
	while(scanf("%d",&num)==1)
		addToList(&head,&tail,num);
	printList(head);
	delete(&head,&tail,x);
	printf("after deleting %d\n", x);
	printList(head);
	freeList(&head);
	return 0;
}

void printList(ptr h)
{
	ptr temp=h;
	if(h==NULL)
		return;
	do{
		printf("%d --> ",h->key);
		h = h->next;

	}while(h!=temp);
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

void addToList(ptr * h,ptr * tail,int n)
{
	ptr new,p1,p2;
	new=(ptr) malloc(sizeof(item));
	if(!new){
		printf("cannot allocate memory\n");
		exit(0);
	}
	new->key=n;
	if((*h)==NULL)/*case - empty list*/
	{
		*h=new;
		*tail=new;
		new->next = (*h);
		return;
	}
	else/* case - not empty list */
	{
		p1=*h;
		p2=*tail;
		if((p2->key)<n)/* case - the new kew is bigger then the tail, than insert the new key to the tail of the list */
		{
			(*tail)->next=new;
			(*tail) = new;
			new->next=(*h);
			return;
		}
		while((p1)&&((p1->key)<n))/* finding where to insert the new key */
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1==(*h))/* case - the new kew is lower then the head, than insert the new key to the head of the list */
		{
			*h=new;
			new->next=p1;
			(*tail)->next=new;
		}
		else/* case - the new key need to be insert between two nodes */
		{
			p2->next=new;
			new->next=p1;
		}
	}
}
void delete(ptr *h,ptr *tail, int n)
{
	ptr p1,p2;
	if((*h)==NULL)/*case - empty list*/
		return;
	p1=*h;
	while((p1)&&((p1->key)!=n))/* case - didnt find the key in the list */
	{
		p2=p1;
		p1=p1->next;
		if(p2->next==*h)
			return;
	}
	if(p1==(*h))/* case - the key is the head of the list */
	{
		(*h)=p1->next;
		(*tail)->next=(*h);
		free(p1);
	}
	else /* case - the key is the tail or between two nodes */
	{
		p2->next=p1->next;
		free(p1);
	}
}




