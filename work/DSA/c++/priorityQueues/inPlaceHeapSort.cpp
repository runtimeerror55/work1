#include <bits/stdc++.h>
using namespace std;
void insert(int input[], int index)
{
    int currentIndex = index;
    int parentIndex = (currentIndex - 1) / 2;
    while (currentIndex > 0)
    {
        if (input[currentIndex] < input[parentIndex])
        {
            int temp = input[currentIndex];
            input[currentIndex] = input[parentIndex];
            input[parentIndex] = temp;
        }
        currentIndex--;
        parentIndex = (currentIndex - 1) / 2;
    }
}

void remove(int input[], int end)
{
    int temp = input[0];
    input[0] = input[end];
    int parentIndex = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < end)
    {
        int temp = input[parentIndex];
        int minIndex = parentIndex;
        if (input[minIndex] > input[leftChildIndex])
        {

            minIndex = leftChildIndex;
        }

        if (input[minIndex] > input[rightChildIndex])
        {
            minIndex = rightChildIndex;
        }
        if (parentIndex == minIndex)
        {
            break;
        }

        input[parentIndex] = input[minIndex];
        input[minIndex] = temp;
        parentIndex = minIndex;
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = leftChildIndex + 1;
    }
    input[end] = temp;
}

void heapSort(int input[], int size)
{
    for (int i = 1; i < size; i++)
    {
        insert(input, i);
    }

    for (int i = 0; i < size; i++)
    {
        remove(input, size - i - 1);
    }
}
int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}