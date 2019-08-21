#include <iostream>
#include<vector>

using namespace std;

template<typename T>
class Sorting{
private:
    vector<T> myVector = {7,3,5,9,3,14,62,4,25,4562,36};
public:
    Sorting()= default;

    void InsertSort(){};
    void SelectionSort(){};
    void BubbleSort(){};
    void MergeSort(){};
    void HeapSort(){};
    void QuickSort(){};

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