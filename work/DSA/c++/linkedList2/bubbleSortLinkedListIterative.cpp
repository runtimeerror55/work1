#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *swapNodes(Node *x, Node *y, Node *left)
{

    Node *currentNode1 = x;
    Node *leftNode1 = left;
    Node *currentNode2 = y;
    Node *rightNode2 = currentNode2->next;

    if (leftNode1 != NULL)
    {
        leftNode1->next = currentNode2;
    }
    currentNode2->next = currentNode1;
    currentNode1->next = rightNode2;
    return currentNode2;
}

Node *bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp1 = head;
    Node *newHead = NULL;

    while (true)
    {
        Node *leftNode1 = NULL;
        bool areSwapped = false;
        while (temp1 != NULL)
        {
            if (temp1->data > temp1->next->data)
            {
                newHead = swapNodes(temp1, temp1->next, leftNode1);
                leftNode1=newHead;
                areSwapped = true;
            }
            else
            {

                leftNode1 = temp1;
                temp1 = temp1->next;
            }
        }
        if (!areSwapped)
        {
            return newHead;
        }
    }
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}