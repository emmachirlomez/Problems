#include <bits/stdc++.h>
using namespace std;

int length = 0;

void insertEnd(int arr[], int n, int &length, int capacity)
{
    if (length < capacity)
    {
        arr[length] = n;
        length++;
    }
}

void removeEnd(int arr[], int &length)
{
    if (length > 0)
    {
        arr[length - 1] = 0;
        length--;
    }
}

void insertMiddle(int arr[], int i, int n, int &length, int capacity)
{
    if (length + 1 <= capacity)
        for (int index = length; index >= i; index--)
            arr[index + 1] = arr[index];
    length++;
    arr[i] = n;
}

void removeMiddle(int arr[], int i, int &length)
{
    for (int index = i + 1; index < length; index++)
        arr[index - 1] = arr[index];
    arr[length - 1] = 0;
    length--;
}

int main()
{
    int arr[10], capacity = 10;
    insertEnd(arr, 1, length, capacity);
    insertEnd(arr, 3, length, capacity);
    insertEnd(arr, 4, length, capacity);
    insertEnd(arr, 8, length, capacity);
    insertEnd(arr, 5, length, capacity);
    insertEnd(arr, 6, length, capacity);
    removeEnd(arr, length);
    insertMiddle(arr, 1, 2, length, capacity);
    removeMiddle(arr, 4, length);
    for (auto i : arr)
        cout << i << " ";
    cout << '\n';
}