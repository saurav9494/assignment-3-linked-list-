#include<malloc.h>
#include<stdio.h>

struct Node
{
    int value;
    struct Node *next;
};
typedef struct Node node;
node *head;
node *create()
{
     node *p;
    int k,n;
    printf("enter number of nodes");
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        if(k==0)
        {
            head=(node*)malloc(sizeof(node));
            p=head;
        }
            else
            {
         p->next=(node *)malloc(sizeof(node));
         p=p->next;
            }
            scanf("%d",&p->value);
    }
    p->next=NULL;
        return(head);
}
void display(){
node *start;
start=head;
while(start!=NULL)
{
    printf("%d->",start->value);
    start=start->next;
}
}


void NthNode(node * node1, int n){
	node* pointer1 = node1;
	node* pointer2 = node1;

	while(pointer1 != NULL && n > 0){
		pointer1 = pointer1->next;
		n--;
	}
	//List does not have n nodes, so return null
	if(n > 0)
        printf("invalid node number..");
		return ;
	//traverse till pointer1 becomes null
	while(pointer1 != NULL){
		pointer1 = pointer1->next;
		pointer2 = pointer2->next;
	}
	printf("%d",pointer2->value);
}
int  main()
{
    int num;
    create();
    display();
    printf("enter node no. from end.. \n");
    scanf("%d",&num);
    NthNode(head,num);

}
