#include <iostream>
#include <vector>
using namespace std;

class Sort
{
private:
    int size;
    vector<int> arr;
    int *arr_ptr; // merge_sort

public:
    void Display();
    void print_array();
    /* 선택 정렬 */
    void selection_sort();
    /* 삽입 정렬 */
    void insertion_sort();
    /* 버블 정렬 */
    void bubble_sort();
    /* Merge Sort (병합 정렬) */
    void merge(int l, int r);
    void merge_sort(int l, int r);
    /* Heap Sort (힙 정렬) */
    void heap_sort();
    void heapify(int i, int n) { max_heapify(i, n); }
    void max_heapify(int i, int n); // 오름차순
    void min_heapify(int i, int n); // 내림차순
    /* Quick Sort (퀵 정렬) */
    void quick_sort(int l, int r);
    int partition(int l, int r);
};

void Sort::Display()
{
    cout << "Enter the size of the array: ";
    cin >> size;
    arr.resize(size);
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Select the sorting algorithm: " << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Heap Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    print_array();
    switch (choice)
    {
    case 1:
        selection_sort();
        break;
    case 2:
        insertion_sort();
        break;
    case 3:
        bubble_sort();
        break;
    case 4:
        merge_sort(0, size - 1);
        break;
    case 5:
        heap_sort();
        break;
    case 6:
        quick_sort(0, size - 1);
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}
void Sort::print_array()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/* 선택 정렬 */
void Sort::selection_sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        print_array();
    }
}
/* 삽입 정렬 */
void Sort::insertion_sort()
{
    int key;
    cout << "(X) ";
    print_array();
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            cout << "(" << key << ") ";
            print_array();
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "(X) ";
    print_array();
}
/* 버블 정렬 */
void Sort::bubble_sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            print_array();
        }
    }
}
/* 합병 정렬 */
void Sort::merge_sort(int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, r);
    }
}
void Sort::merge(int l, int r)
{
    int mid = (l + r) / 2;

    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            arr_ptr[k++] = arr[i++];
        else
            arr_ptr[k++] = arr[j++];
    }

    int tmp = i > mid ? j : i;

    while (k <= r)
        arr_ptr[k++] = arr[tmp++];

    for (int i = l; i <= r; i++)
        arr[i] = arr_ptr[i];
    print_array();
}
/* 힙 정렬 */
void Sort::heap_sort()
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i, size);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(0, i);
    }
    print_array();
}
void Sort::max_heapify(int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        print_array();
        max_heapify(largest, n);
    }
}
void Sort::min_heapify(int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[largest])
        largest = l;
    if (r < n && arr[r] < arr[largest])
        largest = r;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        print_array();
        min_heapify(largest, n);
    }
}
/* 퀵 정렬 */
void Sort::quick_sort(int l, int r)
{
    if (l < r)
    {
        int pivot = partition(l, r);
        quick_sort(l, pivot - 1);
        quick_sort(pivot + 1, r);
    }
}
int Sort::partition(int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    print_array();
    return i + 1;
}

int main()
{
    Sort sort;
    sort.Display();
    return 0;
}