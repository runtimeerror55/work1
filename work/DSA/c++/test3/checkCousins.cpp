#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class helpingContainer
{
public:
    BinaryTreeNode<int> *parent1;
    int height1;
    bool found1;
    BinaryTreeNode<int> *parent2;
    int height2;
    bool found2;
    helpingContainer(BinaryTreeNode<int> *parent1, int height1, bool found1, BinaryTreeNode<int> *parent2, int height2, bool found2)
    {
        this->height1 = height1;
        this->parent1 = parent1;
        this->found1 = found1;
        this->height2 = height2;
        this->parent2 = parent2;
        this->found2 = found2;
    }
};

helpingContainer helper(BinaryTreeNode<int> *root, int n1, int n2)
{
    helpingContainer subAnswer(NULL, 0, false, NULL, 0, false);
    if (root == NULL)
    {
        return subAnswer;
    }

    if (root->data == n1)
    {
        subAnswer.height1 = 1;
        subAnswer.found1 = true;
        return subAnswer;
    }
    if (root->data == n2)
    {
        subAnswer.height2 = 1;
        subAnswer.found2 = true;
        return subAnswer;
    }

    helpingContainer left = helper(root->left, n1, n2);
    helpingContainer right = helper(root->right, n1, n2);

    if (left.found1 && left.parent1 == NULL || right.found1 && right.parent1 == NULL)
    {
        subAnswer.parent1 = root;
    }
    else
    {
        subAnswer.parent1 = left.parent1 == NULL ? right.parent1 : left.parent1;
    }
    if (left.found2 && left.parent2 == NULL || right.found2 && right.parent2 == NULL)
    {
        subAnswer.parent2 = root;
    }
    else
    {
        subAnswer.parent2 = left.parent2 == NULL ? right.parent2 : left.parent2;
    }

    subAnswer.found1 = left.found1 || right.found1;
    subAnswer.height1 = subAnswer.found1 == true ? (1 + (left.height1 || right.height1)) : 0;

    subAnswer.found2 = left.found2 || right.found2;
    subAnswer.height2 = subAnswer.found2 == true ? (1 + (left.height2 || right.height2)) : 0;

    return subAnswer;
}

bool isCousin(BinaryTreeNode<int> *root, int n1, int n2)
{
    helpingContainer subAnswer = helper(root, n1, n2);
    if (subAnswer.height1 == subAnswer.height2 && subAnswer.parent1 != subAnswer.parent2)
    {
        return true;
    }
    return false;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    // cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        // cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        // cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if (isCousin(root, n1, n2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
