#include <iostream>

using namespace std;

void buildHeap(int arr[], int n)
{
    //keep replace with parent until parent is bigger than node 
    for (int i = 1; i < n; i++)
    {
        int nodeIndex = i;
        int parentIndex = i / 2;
        bool keepCheckParent = true;
        while (keepCheckParent)
        {
            if (parentIndex == 0)
            {
                keepCheckParent = false;
            }

            int node = arr[nodeIndex];
            int parent = arr[parentIndex];

            if (parent < node)
            {
                int temp = parent;
                arr[parentIndex] = node;
                arr[nodeIndex] = parent;

                nodeIndex = parentIndex;
                parentIndex = nodeIndex / 2;
            }
            else
            {
                keepCheckParent = false;
            }
        }
    }
}

void heapSort(int arr[], int n)
{
    //remove the top element from heap and append at the end
    for (int i = 0; i < n; i++)
    {
        buildHeap(arr, n - i);
        int temp = arr[n - 1 - i];
        arr[n - 1 - i] = arr[0];
        arr[0] = temp;
    }
}

int main()
{

    int n;
    cout << "Enter count of elements: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter Elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildHeap(arr, n);

    cout << "heaped array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);

    cout << "sorted array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}