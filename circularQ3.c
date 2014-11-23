#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL, *x, *y, *z;

void create();
void ins_at_beg();
void ins_at_pos();
void del_at_beg();
void del_at_pos();
void traverse();
void update();
void rev_traverse(struct node *p);

void main()
{
    int ch;

    printf("\n 1.Creation \n 2.Insertion at beginning \n 3.Insertion at remaining");
    printf("\n4.Deletion at beginning \n5.Deletion at remaining \n6.traverse");
    printf("\n7.update\n8.Exit\n");
    while (1)
    {
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            ins_at_beg();
            break;
        case 3:
            ins_at_pos();
            break;
        case 4:
            del_at_beg();
            break;
        case 5:
            del_at_pos();
            break;
        case 6:
            traverse();
            break;

        case 7:
            update();
            break;
        case 8:
            rev_traverse(head);
            break;
        default:
            exit(0);
        }
    }
}

/*Function to create a new circular linked list*/
void create()
{
    int c;

    x = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &x->data);
    x->link = x;
    head = x;
    printf("\n If you wish to continue press 1 otherwise 0:");
    scanf("%d", &c);
    while (c != 0)
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d", &y->data);
        x->link = y;
        y->link = head;
        x = y;
        printf("\n If you wish to continue press 1 otherwise 0:");
        scanf("%d", &c);
    }
}

void ins_at_beg()
{
    x = head;
    y = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    while (x->link != head)
    {
        x = x->link;
    }
    x->link = y;
    y->link = head;
    head = y;
}

void ins_at_pos()
{
    struct node *ptr;
    int c = 1, pos, count = 1;

    y = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("cannot enter an element at this place");
    }
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    while (ptr->link != head)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if (pos > count)
    {
        printf("OUT OF BOUND");
        return;
    }
    while (c < pos)
    {
        z = x;
        x = x->link;
        c++;
    }
    y->link = x;
    z->link = y;
}
void del_at_beg()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        y = head;
        while (x->link !=  head)
        {
            x = x->link;
        }
        head = y->link;
        x->link = head;
        free(y);
    }
}
void del_at_pos()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        int c = 1, pos;
        printf("\n Enter the position to be deleted:");
        scanf("%d", &pos);
        x = head;
        while (c < pos)
        {
            y = x;
            x = x->link;
            c++;
        }
        y->link = x->link;
        free(x);
    }
}
void traverse()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        while (x->link !=  head)
        {
            printf("%d->", x->data);
            x = x->link;
        }
        printf("%d", x->data);
    }
}
 void update()
{
    struct node *ptr;
    int search_val;
    int replace_val;
    int flag = 0;

    if (head == NULL)
    {
        printf("\n empty list");
    }
    else
    {
        printf("enter the value to be edited\n");
        scanf("%d", &search_val);
        fflush(stdin);
        printf("enter the value to be replace\n");
        scanf("%d", &replace_val);
        ptr = head;
        while (ptr->link !=  head)
        {
            if (ptr->data == search_val)
            {
                ptr->data = replace_val;
                flag = 1;
                break;
            }
            ptr = ptr->link;
        }
        if (ptr->data == search_val)
        {
            ptr->data = replace_val;
            flag = 1;
        }
        if (flag == 1)
        {
            printf("\nUPdate sucessful");
        }
        else
        {
            printf("\n update not successful");
        }
    }
}
void rev_traverse(struct node *p)
{
    int i = 0;

    if (head == NULL)
    {
        printf("empty linked list");
    }
    else
    {
        if (p->link !=  head)
        {
            i = p->data;
            rev_traverse(p->link);
            printf(" %d", i);
        }
        if (p->link == head)
        {
            printf(" %d", p->data);
        }
    }
}
