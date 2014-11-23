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
void insert_front(int num)
{
    node *start;
    start=head;
    node *p;
    p=(node*)malloc(sizeof(node));
    p->value=num;
    p->next=head->next;
    head->next=p;

}
void insert_end(int num)
{

node *p,*start;
	p = (node *) malloc(sizeof(node));
	start = head;
	while(start->next != NULL)
	{
		start = start->next;
	}
    p->value=num;
    p->next=NULL;
    start->next=p;


}


void insert_any(int num,int key)
{
    node *p,*start;
	p = (node *) malloc(sizeof(node));

	start = head;
	while(start->next != NULL && start->value != key)
	{
		start = start->next;
	}
	if(start->value == key)
	{
		p->value = num;
		p->next = start->next;
		start->next =p;
	}
	else
	{
		printf("\nValue %d not found\n",key);
	}
}


void find()
{
    int a,i;
    node *p;
    p=head;
    printf("enter node number..");
    scanf("%d",&a);
    while(p->next!=NULL && p->value!=a)
    {
        p=p->next;
    }
    printf("%d",p->value);
}

void reverse_list()
{
    node *temp,*temp1,*var;

    temp=head;
    var=NULL;
    while(temp!=NULL)
    {
         temp1=var;
         var=temp;
         temp=temp->next;
         var->next=temp1;

    }
    head=var;

}


    void main()
{
	int choice;
	int cont = 1;
int n,key;

	head = (node *) malloc(sizeof(node));



	 create();
    display();
    printf("enter number to insert /n");
    scanf("%d",&n);


	while(cont == 1)
	{

		printf("\n1. Insert at front\n");
		printf("\n2. Insert at end\n");
		printf("\n3. Insert at any position\n");
		printf("\n4. Display linked list\n");
		printf("\n5. Reverse linked list \n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				insert_front(n);
				break;
			case 2:
				insert_end(n);
				break;
			case 3:
			    printf("enter key node /n");
                scanf("%d",&key);
				insert_any(n,key);
				break;
			case 4:
				display();
				break;
            case 5:
                reverse_list();
                break;
		}

		printf("\n\nDo you want to continue? (1 / 0): ");
		scanf("%d", &cont);
	}

	getch();
}



