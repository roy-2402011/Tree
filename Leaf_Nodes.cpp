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

void printLeafDescending(Node* root)
{
    if(root == NULL) return;

    vector<int> leaf;
    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

       
        if(curr->left == NULL && curr->right == NULL)
        {
            leaf.push_back(curr->val);
        }

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }

    sort(leaf.rbegin(), leaf.rend());

    for(int x : leaf)
        cout << x << " ";
}


int main()
{
    Node* root = input();
    printLeafDescending(root);
    

    return 0;
}
