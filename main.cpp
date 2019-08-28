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

        vector<T> a = myVector;
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


    void BubbleSort(){
      vector<T> a = myVector;
      for(unsigned int i = 0; i < a.size() - 1; i++){
          for(unsigned int j = 0; j < a.size() - 1 - i; j++){
              if(a[j]>a[j+1]){
                  std::swap(a[j], a[j+1]);
              }
          }
      }

      for(T i: a){
          cout<<i<<" ";
      }
      cout<<endl;

    };

		void MergeSort(){};
		
		void Heapify(vector<T>& a, int size, int root)
		{
		  auto biggest = root;
			auto left = 2*root + 1;
			auto right = 2*root + 2;

			if(left < size && a[left] > a[biggest])
				biggest = left;

			if(right < size && a[right] > a[biggest])
				biggest = right;
			
			if(biggest != root)
			{
				std::swap(a[root], a[biggest]);
				Heapify(a, size, biggest);
			}
		};
			
    void HeapSort()
		{
			auto a = myVector;
			int size = a.size();

			for(int i = size/2-1; i >= 0; i--)
				Heapify(a, size, i);
			
			for(int i = size-1; i >= 0; i--)
			{
				swap(a[0],a[i]);
				Heapify(a, i, 0);
			}
			
			//imprimir vector 'a'
			for(const auto& i: a)
			{
          cout<<i<<" ";
      }
      cout<<endl;

		};

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
