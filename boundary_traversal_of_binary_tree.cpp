#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define forn for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void LeftTree(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    if (root->left)
    {
        ans.push_back(root->data);
        LeftTree(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        LeftTree(root->right, ans);
    }
}

void Leaf(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    Leaf(root->left, ans);

    if (!root->left and !root->right)
    {
        ans.push_back(root->data);
    }
    Leaf(root->right, ans);
}

void RightTree(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    if (root->right)
    {
        RightTree(root->right, ans);
        ans.push_back(root->data);
    }
    else if (root->left)
    {
        RightTree(root->left, ans);
        ans.push_back(root->data);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    if (!root->left and !root->right)
    {
        ans.push_back(root->data);
        return ans;
    }

    ans.push_back(root->data);
    LeftTree(root->left, ans);
    Leaf(root, ans);
    RightTree(root->right, ans);

    return ans;
}