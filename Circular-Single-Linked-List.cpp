#include <bits/stdc++.h>

using namespace std;

int count = 0;

typedef struct NODE
{
    int data;
    struct NODE *link;
}*node;

node create()
{
    node temp = (node)malloc(sizeof(node));
    printf("\n\nEnter data ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    count++;
return temp;
}

node c_insert_front(node head)
{
    node temp = create(),cur = head;

    if(head == NULL)
    {
        head = temp;
        temp->link = head;
    }
    else
    {
        while(cur->link != head)
            cur = cur->link;

        temp->link = head;
        cur->link = temp;
        head = temp;
    }

return head;
}

node c_insert_end(node head)
{
    node temp = create(),cur = head;

    if(head == NULL)
    {
        head = temp;
        temp->link = head;
    }
    else
    {
        while(cur->link != head)
            cur = cur->link;

        cur->link = temp;
        temp->link = head;
    }

return head;
}

node c_delete_front(node head)
{
    node cur = head , ptr = head;
    if(head == NULL)
        printf("\nEmpty list !!!");
    else
    if(head->link == head)
    {
        printf("\nDeleted data : %d",head->data);
        free(head);
        head = NULL;
        count--;
    }
    else
    {
        while(cur->link != head)
            cur = cur->link;

        head = head->link;
        cur->link = head;
        //ptr->link = NULL;
        printf("\nDeleted data : %d",ptr->data);
        free(ptr);
        count--;
    }

return head;
}

node c_delete_end(node head)
{
    node cur = head , prev = head;
    if(head == NULL)
        printf("\nEmpty list !!!");
    else
    if(head->link == head)
    {
        printf("\nDeleted data : %d",head->data);
        free(head);
        head = NULL;
        count--;
    }
    else
    {
       while(cur->link != head)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = head;
        //cur->link = NULL;
        printf("\nDeleted data : %d",cur->data);
        free(cur);
        count--;
    }

return head;
}

node insert_pos(node head)
{
    int pos;
    node cur = head;
    printf("\nEnter position : ");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1)
    {
        if(pos == 1)
        {
            head = c_insert_front(head);
        }
        else
        if(pos == count+1)
        {
            head = c_insert_end(head);
        }
        else
        {
            node temp = create();
            for(int i=1;i<pos-1;i++)
                cur = cur->link;
            temp->link = cur->link;
            cur->link = temp;
        }
    }
    else
        printf("\nWrong position !!!");

return head;
}

node delete_pos(node head)
{
    int pos;
    node cur = head,temp;
    printf("\nEnter position : ");
    scanf("%d",&pos);
    if(pos>0 && pos<=count)
    {
        if(pos == 1)
        {
            head = c_delete_front(head);
        }
        else
        if(pos == count)
        {
            head = c_delete_end(head);
        }
        else
        {
            for(int i=1;i<pos-1;i++)
                cur = cur->link;
            temp = cur->link;
            cur->link = temp->link;
            printf("\nDeleted data = %d",temp->data);
            free(temp);
            count--;
        }
    }
    else
        printf("\nWrong position !!!");

return head;
}

void display(node head)
{
    node cur = head;
    if(head == NULL)
        printf("\nEmpty list !!!");
    else
    {
        while(cur->link != head)
        {
            printf("%d -> ",cur->data);
            cur = cur->link;
        }
        printf("%d",cur->data);
    }
    printf("\n");
    for(int i=1;i<=count;i++)
    {
        if(i == 1)
            printf("^  ");
        else if(i == count)
            printf("     |");
        else printf("      ");
    }
    printf("\n");
    for(int i=1;i<=count;i++)
    {
        if(i == 1)
            printf("|");
        else if(i == count)
            printf("_______|");
        else
            printf("______");
    }
printf("\n\nCount = %d \n",count);
}

int main()
{
    int choice;
    node head = NULL;
    while(1)
    {
        printf("\n\t~ Circular singly linked list ~\n");
        printf("\n0. Exit \n1. Insert front \n2. Insert end \n3. Delete front \n4. Delete end \n5. Display \n6. Insert at position \n7. Delete at position \n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        system("CLS");
        switch(choice)
        {
            case 1: printf("\n~ Insert Front ~");
                    head = c_insert_front(head);
                    break;
            case 2: printf("\n~ Insert End ~");
                    head = c_insert_end(head);
                    break;
            case 3: printf("\n~ Delete front ~");
                    head = c_delete_front(head);
                    break;
            case 4: printf("\n~ Delete End ~");
                    head = c_delete_end(head);
                    break;
            case 5: printf("\n~ Circular list contains ~\n");
                    display(head);
                    break;
            case 6: printf("\n~ Insert at position ~");
                    head = insert_pos(head);
                    break;
            case 7: printf("\n~ Delete at position ~");
                    head = delete_pos(head);
                    break;
            case 0: exit(0);
            default : printf("\nWrong choice !!!");
        }
    }
    return 0;
}
