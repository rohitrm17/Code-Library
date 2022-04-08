#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int no;
    struct NODE *right;
    struct NODE *left;
}*node;

node create(int d)
{
    node temp = malloc(sizeof(struct NODE));
    temp->left = temp->right = NULL;
    temp->no = d;
    return temp;
}

node insert(node root , int d)
{
    if(root == NULL)
        return create(d);
    else
    {
        if(root->no > d)
            root->left = insert(root->left , d);
        else
        if(root->no < d)
            root->right = insert(root->right , d);
        else
            printf("\nElement already exist !!");
    }
    return root;
}

int height(node root)
{
    if(root == NULL)
        return 0;
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);

        if(lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
}

void inorder(node root)
{
    if(root == NULL)
        return ;
    inorder(root->left);
    printf("%d " , root->no);
    inorder(root->right);
}

void search(node root , int d)
{
    if(root == NULL)
    {
        printf("\nElement NOT found !!");
        return ;
    }
    else
    {
        if(root->no > d)
            search(root->left , d);
        else
        if(root->no < d)
            search(root->right , d);
        else
            printf("\nElement found !!");

    }
}

node findMin(node root)
{
    node ptr = root;
    while(ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

node Delete(node root , int d)
{
    if(root == NULL)
        return root;
    else
    {
        if(root->no > d)
            root->left = Delete(root->left , d);
        else
        if(root->no < d)
            root->right = Delete(root->right , d);
        else
        {
            if(root->left == NULL)
            {
                node temp = root->right;
                free(root);
                return temp;
            }
            else
            if(root->right == NULL)
            {
                node temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                node temp = findMin(root->right);
                root->no = temp->no;
                root->right = Delete(root->right , temp->no);
            }
        }
    }
    return root;
}

int main()
{
    node root = NULL;
    int s;
    int d , choice;
    FILE *f;
    f = fopen("Tree.txt" , "r");
    if(f == NULL)
    {
        printf("\nFile not found !!");
        exit(0);
    }
    while(!feof(f))
    {
        fscanf(f , "%d " , &s);
        root = insert(root , s);
    }

    while(1)
    {
        printf("\n\n1.Inorder \n2.Search \n3.Delete \n4.Height \n6.Exit");
        printf("\nEnter choice : ");
        scanf("%d" , &choice);
        switch(choice)
        {
            case 1:
                    printf("\nInorder \n");
                    if(root == NULL)
                        printf("\nEmpty tree !!");
                    else
                        inorder(root);
                    break;
            case 2:
                    printf("\nEnter number to be searched : ");
                    scanf("%d" , &d);
                    search(root , d);
                    break;
            case 3:
                    if(root == NULL)
                        printf("\nEmpty tree !!");
                    else
                    {
                        printf("\nEnter number to be delete : ");
                        scanf("%d" , &d);
                        root = Delete(root , d);
                    }
                    break;
            case 4:
                    printf("\nHeight : %d" , height(root));
                    break;
            case 6:
                    fclose(f);
                    exit(0);
            default: printf("\nWrong Choice !!\n");
        }

    }

    return 0;
}
