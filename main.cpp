#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

template<typename T>
class Sorting {
private:
    vector<T> myVector = {7, 3, 5, 9, 3, 14, 62, 4, 25, 4562, 36};
public:
    Sorting() = default;


    void InsertSort() {

        unsigned int j;

        vector<T> a = myVector;
        for (unsigned int i = 1; i < a.size(); i++) {
            j = i;
            while (j > 0 && a[j - 1] > a[j]) {
                swap(a[j], a[j - 1]);
                j--;
            }
        }

        for (T i: a) {
            cout << i << " ";
        }
        cout << endl;
    };

    void SelectionSort() {};

    void BubbleSort() {
        vector<T> a = myVector;
        for (unsigned int i = 0; i < a.size() - 1; i++) {
            for (unsigned int j = 0; j < a.size() - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    std::swap(a[j], a[j + 1]);
                }
            }
        }

        for (T i: a) {
            cout << i << " ";
        }
        cout << endl;

    };

    void MergeSort() {};

    void HeapSort() {};

    void swap2(int* a, int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }

    int partition ( int low, int high)
    {
        vector<T> arr = myVector;
        int pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap2(&arr[i], &arr[j]);
            }
        }
        swap2(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    void quickSort( int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            quickSort( low, pi - 1);
            quickSort( pi + 1, high);
        }
    }

    void QuickSort() {
        vector<T> a = myVector;
        quickSort( 0 , a.size()-1);

        for (T i: a) {
            cout << i << " ";
        }
        cout << "          quick sort           ";
        cout << endl;
    }

};

int main (int, char * []){

    Sorting<int> mySort;

    mySort.InsertSort();
    mySort.SelectionSort();
    mySort.BubbleSort();
    mySort.MergeSort();
    mySort.HeapSort();
    mySort.QuickSort();

    std::cout << "Hello World" << std::endl;
    return 1;
}
