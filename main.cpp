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

				cout<<"InsertSort"<<endl;
        for (T i: a) {
            cout << i << " ";
        }
        cout << endl;
    }

		void SelectionSort()
		{
			auto a = myVector;
			int size = a.size();
			int min;
			int j;
			
			for(int i=0; i < size-1; i++)
			{
				min = i;

				for(j=i+1; j < size; j++)
					if(a[j] < a[min])
						min = j;

				swap(a[min],a[i]);	
			}

      cout<<"SelectionSort"<<endl;

			for(const auto& i: a){
				cout<<i<<" ";
      }

      cout<<endl;
		}
    
		void BubbleSort() {
        vector<T> a = myVector;
        for (unsigned int i = 0; i < a.size() - 1; i++) {
            for (unsigned int j = 0; j < a.size() - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    std::swap(a[j], a[j + 1]);
                }
            }
        }

				cout<<"BubbleSort"<<endl;
        for (T i: a) {
            cout << i << " ";
        }
        cout << endl;

    }

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
		}

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
      cout<<"HeapSort"<<endl;
			for(const auto& i: a)
			{
          cout<<i<<" ";
      }
      cout<<endl;

		}

    int partition (vector<T>& a, int low, int high)
    {
        int pivot = a[high];
				int i = (low - 1); 

        for (int j = low; j <= high - 1; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[high]);
        return (i + 1);
    }

    void quickSort(vector<T>& a, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(a,low, high);
            quickSort(a,low, pi - 1);
            quickSort(a, pi + 1, high);
        }
    }

    void QuickSort() {
        vector<T> a = myVector;
        quickSort(a, 0, a.size()-1);

				cout<<"QuickSort"<<endl;
        for (T i: a) {
            cout << i << " ";
        }
        cout << endl;
    }

    void BrickSort(){
			vector<T> a = myVector;
			bool sorted = false;

			while(!sorted){
				sorted = true;

				for(unsigned int i = 0; i<=a.size()-2;i+=2){
					if (a[i] > a[i + 1]) {
							std::swap(a[i], a[i + 1]);
							sorted = false;
					}
				}

				for(unsigned int i = 1; i<=a.size()-2;i+=2){
					if (a[i] > a[i + 1]) {
							std::swap(a[i], a[i + 1]);
							sorted = false;
					}
				}
		 }

			cout<<"BrickSort"<<endl;
			for(T i:a){
				cout<<i<<" ";
			}
			cout<<endl;

			}

		void merge(vector<T>& a, int l, int m, int r)
		{
			int i, j, k;
			int n1 = m - l + 1;
			int n2 =  r - m;

			int L[n1], R[n2];

			for (i = 0; i < n1; i++)
				L[i] = a[l + i];
			for (j = 0; j < n2; j++)
				R[j] = a[m + 1+ j];
			
			j = 0;
			i = 0;
			k = l;

			while (i < n1 && j < n2)
			{
				if (L[i] <= R[j])
				{
					a[k] = L[i];
					i++;
				}
				else
				{
					a[k] = R[j];
					j++;
				}
				k++;
			}

			while (i < n1)
			{
				a[k] = L[i];
				i++;
				k++;
			}

			while (j < n2)
			{
				a[k] = R[j];
				j++;
				k++;
			}
		}

		void mergeSort(vector<T>& a, int l, int r)
		{
			if (l < r)
			{
				int m = l+(r-l)/2;

				mergeSort(a, l, m);
				mergeSort(a, m+1, r);

				merge(a, l, m, r);
			}
		}

		void MergeSort(){
			auto a = myVector;
			mergeSort(a, 0, a.size() - 1);

			cout<<"MergeSort"<<endl;
			for(const auto& i: a){
				cout<<i<<" ";
			}
			cout<<endl;
		};

};


int main (int, char * []){

	Sorting<int> mySort;

    mySort.InsertSort();
    mySort.SelectionSort();
    mySort.BubbleSort();
    mySort.MergeSort();
    mySort.HeapSort();
    mySort.QuickSort();
    mySort.BrickSort();

	return 1;
}
