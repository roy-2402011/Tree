#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input()
{
    int val;
    cin >> val;

    Node* root;

    if(val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node*> q;

    if(root)
        q.push(root);

    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* myLeft;
        Node* myRight;

        if(l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if(r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if(myLeft)
            q.push(myLeft);

        if(myRight)
            q.push(myRight);
    }

    return root;
}

int height(Node* root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int countNode(Node* root)
{
    if(root == NULL)
        return 0;

    return 1 + countNode(root->left) + countNode(root->right);
}

bool isPerfect(Node* root)
{
    int h = height(root);
    int total = countNode(root);

    if(total == (pow(2, h) - 1))
        return true;

    return false;
}


int main()
{
    Node* root = input();
    if(isPerfect(root))
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

    return 0;
}
