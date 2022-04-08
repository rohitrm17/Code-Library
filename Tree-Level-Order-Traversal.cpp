#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void levelOrder(Node *root)
    {
        Node *temp;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            cout << q.front()->data << " ";
            if (q.front()->left != NULL || q.front()->right != NULL)
            {
                if (q.front()->left != NULL)
                {
                    temp = q.front();
                    q.push(temp->left);
                }
                if (q.front()->right != NULL)
                {
                    temp = q.front();
                    q.push(temp->right);
                }
                q.pop();
            }
            else
            {
                q.pop();
            }
        }
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.levelOrder(root);

    return 0;
}
