#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> v;

void inorder(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
}

bool checkBST(Node *root)
{
    inorder(root);
    for (int i = 0; i < v.size() - 1; i++)
        if (v[i] >= v[i + 1])
            return false;
    return true;
}

int main()
{
    return 0;
}