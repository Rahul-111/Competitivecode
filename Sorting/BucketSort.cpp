#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

void display(int arr[], int size) {
	int i;
	for(i = 0; i < size; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int getMax(int arr[], int size) {
	int i, m = arr[0];
	for(i = 1; i < size; i++) {
		if(arr[i] > m) {
			m = arr[i];
		}
	}
	return m;
}

void bucketSort(int arr[], int size) {
	//variables
	int max, bucket = 10, divider, i, j, k;
	
	//10 buckets
	vector<int> B[bucket];

	//find max and min
	max = getMax(arr, size);

	divider = ceil(float(max + 1) / bucket);	//ceil(x) : Returns the smallest integer that is greater than or equal to x (i.e : rounds up the nearest integer).
	
	//insert element into bucket
	for(i = 0; i < size; i++) {
		j = floor( arr[i] / divider );	//returns the largest possible integer value  eg  9.2->9
		B[j].push_back(arr[i]);			//floor(x) : Returns the largest integer that is smaller than or equal to x (i.e : rounds downs the nearest integer).
	}
	
	//sort elements in the buckets
	for(i = 0; i < bucket; i++) {
		sort(B[i].begin(), B[i].end());
	}

	//append back the elements from the buckets
	k = 0;
	for(i = 0; i < bucket; i++) {
		for(j = 0; j < B[i].size(); j++) {
			arr[k++] = B[i][j];
		}
	}
}

int main(void) {
	//unsorted elements
	int arr[] = {22,45,12,8,10,6,72,81,33,18,50,14};

	//size of the array
	int n = sizeof(arr)/sizeof(arr[0]);

	//output unsorted elements
	display(arr, n);

	//sort the elements
	bucketSort(arr, n);

	//display sorted elements
	display(arr, n);

	return 0;
}
