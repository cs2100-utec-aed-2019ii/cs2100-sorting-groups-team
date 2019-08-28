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

	void InsertSort(){};

	void SelectionSort(){};

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

		i = 0;
		j = 0;
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

		for(const auto& i: a){
			cout<<i<<" ";
		}
		cout<<endl;

	};
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
