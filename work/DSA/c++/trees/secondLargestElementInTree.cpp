#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

pair<TreeNode<int> *, TreeNode<int> *> helper(TreeNode<int> *root)
{

    pair<TreeNode<int> *, TreeNode<int> *> subAnswer(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, TreeNode<int> *> childAnswer = helper(root->children[i]);
        if (subAnswer.first->data < childAnswer.first->data)
        {
            if (subAnswer.second == NULL && childAnswer.second != NULL)
            {
                if (subAnswer.first < childAnswer.second)
                {
                    subAnswer = childAnswer;
                }
                else
                {
                    subAnswer.second = subAnswer.first;
                    subAnswer.first = childAnswer.first;
                }
            }
            else if (subAnswer.second != NULL && childAnswer.second == NULL)
            {
                if (childAnswer.first < subAnswer.second)
                {
                    subAnswer.second = childAnswer.first;
                }
            }
            else if (subAnswer.second == NULL && childAnswer.second == NULL)
            {
                subAnswer.second = childAnswer.first;
            }
            else if (childAnswer.second->data > subAnswer.first->data)
            {
                subAnswer = childAnswer;
            }
            else
            {
                subAnswer.second = subAnswer.first;
                subAnswer.first = childAnswer.first;
            }
        }
        else if (subAnswer.second < childAnswer.first)
        {
            subAnswer.second = childAnswer.first;
        }
    }

    return subAnswer;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    return helper(root).second;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}