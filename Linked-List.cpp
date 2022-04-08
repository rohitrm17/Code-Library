#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    static int count;
    node(int d) : data(d), next(NULL)
    {
        count++;
    }
};

int node::count = 0;

class LinkedList
{
    node *head;
    node *tail;

public:
    LinkedList() : head(NULL), tail(NULL)
    {
    }
    void pushBack(int d)
    {
        node *temp = new node(d);
        if (head == NULL)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void assignTail()
    {
        node *ptr;
        for (ptr = head; ptr->next != NULL; ptr = ptr->next)
            ;
        tail = ptr;
    }
    void pushFront(int d)
    {
        node *temp = new node(d);
        if (head == NULL)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void deleteFront()
    {
        node *temp;
        if (head == NULL)
            cout << "Empty list !!" << endl;
        else if (head == tail)
        {
            temp = head;
            cout << "\nDeleted element: " << temp->data << endl;
            delete temp;
            head = tail = NULL;
            node::count--;
        }
        else
        {
            temp = head;
            head = head->next;
            cout << "\nDeleted element: " << temp->data << endl;
            node::count--;
            delete temp;
        }
    }
    void deleteBack()
    {
        node *temp, *ptr;
        if (head == NULL)
            cout << "Empty List !!" << endl;
        else if (head == tail)
        {
            temp = head;
            cout << "\nDeleted element: " << temp->data << endl;
            delete temp;
            head = tail = NULL;
            node::count--;
        }
        else
        {
            temp = tail;
            for (ptr = head; ptr->next != tail; ptr = ptr->next)
                ;
            ptr->next = NULL;
            tail = ptr;
            cout << "\nDeleted element: " << temp->data << endl;
            node::count--;
            delete temp;
        }
    }
    void size()
    {
        cout << "Size of Linked List : " << node::count << endl;
    }
    void display()
    {
        if (head == NULL)
            cout << "Empty List !!";
        cout << endl;
        for (node *ptr = head; ptr != NULL; ptr = ptr->next)
            cout << ptr->data << " ";
    }
    void reverse()
    {
        node *cur = head, *prev = NULL, *ptr = head;
        // tail = head;
        if (head == NULL)
            return;
        while (ptr != NULL)
        {
            cur = cur->next;
            ptr->next = prev;
            prev = ptr;
            ptr = cur;
        }
        head = prev;
        assignTail();
    }
    // node* reverse(node *head , int k)
    // {
    //     node *cur=head , *prev=NULL , *ptr=head;
    //     int c=0;
    //     while(ptr != NULL && c<k)
    //     {
    //         cur = cur->next;
    //         ptr->next = prev;
    //         prev = ptr;
    //         ptr = cur;
    //         c++;
    //     }
    //     if(ptr != NULL)
    //         head->next = reverse(ptr , k);
    //     return prev;
    // }
    ~LinkedList()
    {
        cout << "Linked List deleted" << endl;
    }
};

int main()
{
    LinkedList ll;
    int choice, d;
    while (1)
    {
        cout << "1.pushBack \n2.pushFront \n3.deleteFront \n4.deleteBack \n5.display " << endl;
        cout << "6.deleteList \n7.Size \n8.Reverse \n9.Reverse k \n0.Exit \nEnter choice:" << endl;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            cout << "Enter data" << endl;
            cin >> d;
            ll.pushBack(d);
            break;
        case 2:
            cout << "Enter data" << endl;
            cin >> d;
            ll.pushFront(d);
            break;
        case 3:
            ll.deleteFront();
            break;
        case 4:
            ll.deleteBack();
            break;
        case 5:
            ll.display();
            break;
        case 6:
            // free(ll);
            break;
        case 7:
            ll.size();
            break;
        case 8:
            ll.reverse();
            break;
        // case 9:
        //     {
        //         ll.head = ll.reverse(ll.head , 2);
        //     }
        //         break;
        case 0:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Wrong choice !!" << endl;
        }
    }
    return 0;
}
