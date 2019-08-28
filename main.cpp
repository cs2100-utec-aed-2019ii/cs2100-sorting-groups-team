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

	void merge(vector<T> arr, int l, int m, int r)
	{
		int i, j, k;
		int n1 = m - l + 1;
		int n2 =  r - m;

		/* create temp arrays */
		int L[n1], R[n2];

		/* Copy data to temp arrays L[] and R[] */
		for (i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1+ j];

		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // Initial index of first subarray
		j = 0; // Initial index of second subarray
		k = l; // Initial index of merged subarray
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		/* Copy the remaining elements of L[], if there
           are any */
		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		/* Copy the remaining elements of R[], if there
           are any */
		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}

	void mergeSort(vector<T> arr, int l, int r)
	{
		if (l < r)
		{
			// Same as (l+r)/2, but avoids overflow for
			// large l and h
			int m = l+(r-l)/2;

			// Sort first and second halves
			mergeSort(arr, l, m);
			mergeSort(arr, m+1, r);

			merge(arr, l, m, r);
		}
	}




	void MergeSort(){
		vector<T> a = myVector;
		mergeSort(a, 0, a.size() - 1);


		for(T i: a){
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
