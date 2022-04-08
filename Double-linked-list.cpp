#include <bits/stdc++.h>

using namespace std;

int count = 0;

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}*NODE;

NODE create()
{
    NODE temp = (NODE*)malloc(sizeof(struct node));
    printf("\nEnter data : ") ;
    scanf("%d",&temp->data);
    temp->llink = NULL;
    temp->rlink = NULL;
    count++;
return temp;
}

NODE insert_front(NODE head)
{
    NODE temp = create();
    if(head == NULL)
        head = temp;
    else
    {
        temp->rlink = head;
        head->llink = temp;
        head = temp;
    }
return head;
}

NODE insert_end(NODE head)
{
    NODE temp = create() ,cur = head;
    if(head == NULL)
        head = temp;
    else
    {
        while(cur->rlink != NULL)
            cur = cur->rlink;
        cur->rlink = temp;
        temp->llink = cur;
    }
return head;
}

NODE delete_front(NODE head)
{
    NODE ptr = head;
    if(head == NULL)
        printf("\nEmpty List !!!");
    else if(head->rlink == NULL)
    {
       printf("Deleted element : %d ",head->data);
       free(head);
       head = NULL;
       count--;
    }
    else
    {
        head = head->rlink;
        head->llink = NULL;
        printf("\nDeleted element : %d ",ptr->data);
        free(ptr);
        count--;
    }
return head;
}

NODE delete_end(NODE head)
{
    NODE cur = head;
    if(head == NULL)
        printf("Empty list !!!");
    else
    if(head->rlink == NULL)
    {
        printf("\nDeleted element : %d ",head->data);
        free(head);
        head = NULL;
        count--;
    }
    else
    {
        while(cur->rlink != NULL)
            cur = cur->rlink;
        printf("\nDeleted element : %d ",cur->data);
        (cur->llink)->rlink = NULL;
        free(cur);
        count--;
    }
return head;
}

void display(NODE head)
{
    NODE cur = head;
    if(head == NULL)
        printf("\nEmpty list !!!");
    else
    {
        while(cur != NULL)
        {
            printf("%d -> ",cur->data);
            cur = cur->rlink;
        }
    }
    printf("\nCount = %d\n",count);
}

NODE insert_pos(NODE head)
{
    int pos;
    printf("\nEnter position : ");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1)
    {
        if(pos == 1)
            head = insert_front(head);
        else
        if(pos == count+1)
            head = insert_end(head);
        else
        {
            NODE temp = create(),cur = head,prev;
            for(int i=1;i<pos;i++)
                cur = cur->rlink;
            prev = cur->llink;
            temp->rlink = cur;
            temp->llink = prev;
            prev->rlink = temp;
            cur->llink = temp;
        }
    }
    else
        printf("\nWrong position !!!");
return head;
}

void rev_display(NODE head)
{
    NODE cur = head;
    while(cur->rlink != NULL)
        cur = cur->rlink;
    while(cur != NULL)
    {
        printf("%d -> ",cur->data);
        cur = cur->llink;
    }
}

int main()
{
    int choice;
    NODE head = NULL;
    while(1)
    {
        printf("\n\n~ Double Linked List ~\n");
        printf("\n0. Exit \n1. Insert front \n2. Insert end \n3. Delete front \n4. Delete end \n5. Display \n6. Insert position \n7.Reverse display\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        system("CLS");
        switch(choice)
        {
            case 1: printf("\n~ Insert front ~\n");
                    head = insert_front(head);
                    break;
            case 2: printf("\n~ Insert end ~\n");
                    head = insert_end(head);
                    break;
            case 3: printf("\n~ Delete front ~\n");
                    head = delete_front(head);
                    break;
            case 4: printf("\n~ Delete end ~\n");
                    head = delete_end(head);
                    break;
            case 5: printf("\n~ Link contains ~\n");
                    display(head);
                    break;
            case 6: printf("\n~ Insert at position ~\n");
                    head = insert_pos(head);
                    break;
            case 7: printf("\n~ Reverse display ~\n");
                    rev_display(head);
                    break;
            case 0: exit(0);
            default : printf("\nWrong choice !!!");
        }
    }
    return 0;
}
