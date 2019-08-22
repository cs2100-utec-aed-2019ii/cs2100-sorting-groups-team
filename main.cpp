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
    void SelectionSort()
		{
			vector<T> a = myVector;
			auto size = a.size();
			int min;
			for(int i=0; i < size-1; i++)
			{
				min = i;
				for(int j=0; j < size; j++)
				{
					if(a[j] < a[min])
						min = a[j];

					T temp = a[min];
					a[min] = a[i];
					a[i] = temp;
				}	
			}
		};
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
