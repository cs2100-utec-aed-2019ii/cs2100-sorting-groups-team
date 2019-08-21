#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

template<typename T>
class Sorting{
private:
    vector<T> myVector = {7,3,5,9,3,14,62,4,25,4562,36};
public:
    Sorting()= default;

    void InsertSort(){

        unsigned int j;

        vector<T> a = {7,3,5,9,3,14,62,4,25,4562,36};
        for(unsigned int i = 1; i < a.size();i++){
            j = i;
            while(j>0 && a[j-1]>a[j]){
                swap(a[j],a[j-1]);
                j--;
            }
        }

        for(T i: a){
            cout<<i<<" ";
        }
        cout<<endl;
    };
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