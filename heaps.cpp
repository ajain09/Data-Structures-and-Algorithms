#include <iostream>
using namespace std;
void MaxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        // Break if parent value is already greater than child value. if (temp > a[j])
        if (temp > a[j])
            break;
        // Switching value with the parent node if temp < a[j].
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void MinHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;

        // Break if parent value is already less than child value. if (temp < a[j])
        if (temp < a[j])
            break;

        // Switching value with the parent node if temp < a[j].
        else if (temp >= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void Max_HeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        // Storing maximum value at the end.
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        // Building max heap of remaining element.
        MaxHeapify(a, 1, i - 1);
    }
}
void Min_HeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        // Storing minimum value at the end.
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        // Building min heap of remaining element.
        MinHeapify(a, 1, i - 1);
    }
}
void Build_MaxHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}
void Build_MinHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MinHeapify(a, i, n);
}
void print(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
    return;
}
int main()
{
    int ch, size;
    do
    {
        cout << "1)Max Heap 2)Min Heap 3)Exit \n";
        cout << "enter your choice \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "enter no of elements for max heap \n";
            cin >> size;
            int arr[size + 1];
            for (int i = 1; i <= size; i++)
            {
                cout << "enter element" << i << " :\n";
                cin >> arr[i];
            }
            Build_MaxHeap(arr, size);
            cout << "before sorting \n";
            print(arr, size);
            Max_HeapSort(arr, size);
            cout << "after sorting \n";
            print(arr, size);
            break;
        }
        case 2:
        {
            cout << "enter no of elements for min heap\n";
            cin >> size;
            int arr1[size + 1];
            for (int i = 1; i <= size; i++)
            {
                cout << "enter element" << i << " :\n";
                cin >> arr1[i];
            }
            Build_MinHeap(arr1, size);
            cout << "before sorting \n";
            print(arr1, size);
            Min_HeapSort(arr1, size);
            cout << "after sorting \n";
            print(arr1, size);
            break;
        }
        case 3:
        default:
            cout << "enter valid choice \n";
        }
    } while (ch != 3);
    return 0;
}
