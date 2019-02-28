#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void QuickSort(int *array, int low, int high);
void SelectSort(int *array, int max);
void BubbleSort(int *array, int max);
void MergeSort(int *array, int n);
void *NewArray(int n, int size);
void Merge(int *a, int *a1, int n1, int *a2, int n2);
int  BitarySearch(int *a, int n, int item);

int main(int argc, char const *argv[])
{
	int a[MAX], b[MAX];
	int i;
	srand(time(0));
	for (i = 0; i < MAX; ++i)
		a[i] = rand()%100;
	for (i = 0; i < MAX; ++i)
		b[i] = a[i];
	SelectSort(a, MAX-1);
	for (i = 0; i < MAX; ++i){
		printf("%d ", a[i]);
		a[i] = b[i];
	}
	printf("\n");
	BubbleSort(a, MAX-1);
	for (i = 0; i < MAX; ++i){
		printf("%d ", a[i]);
		a[i] = b[i];
	}
	printf("\n");
	for (i = 0; i < MAX; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	MergeSort(a, MAX-1);
	for (i = 0; i < MAX; ++i){
		printf("%d ", a[i]);
		a[i] = b[i];
	}
	printf("\n");
	QuickSort(a,0,MAX-1);
	for (i = 0; i < MAX; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	int result = BitarySearch(a,MAX-1,77);
	if(result != -1)
		printf("The position is:%d\n", result);
	else
		printf("Not Found!");
	return 0;   
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectSort(int *a ,int max)
{
	int i, k, index;
	for(k = 0; k < max; ++k){
		index = k;
		for(i = k+1; i<max+1; ++i){
			if(a[i] < a[index])
				index = i;
		}
		Swap(&a[k], &a[index]);
	}
}

void BubbleSort(int *a, int max)
{
	int i, k;
	for(i = 0; i < max; ++i)
		for(k = 0; k < max-i; ++k){
			if(a[k] > a[k+1])
				Swap(&a[k], &a[k+1]);
		}
}

void QuickSort(int *a, int low, int high)
{
	int pivot = a[low];
	int s = low;
	int t = high;
	if(low >= high)
		return;
	while(s < t){
		for(; t > s && a[t] > pivot; t--);
			a[s] = a[t];
		for(; s < t && a[s] <= pivot; ++s);
			a[t] = a[s];
	}
	a[s] = pivot;
	QuickSort(a, low, s-1);
	QuickSort(a, s+1, high);
}

void MergeSort(int *a, int n)
{

	int n1,n2;
	int i;
	n1 = n/2;
	n2 = n - n1;
	int size = sizeof(int);
	int *array1;
	int *array2;
	if(n < 2)
		return;
	array1 = (int*)NewArray(n1, size);
	array2 = (int*)NewArray(n2, size);
	for(i = 0; i < n1; i++)
		array1[i] = a[i];
	for(i = 0; i < n2; i++)
		array2[i] = a[n1 + i]; 
	MergeSort(array1, n1);
	MergeSort(array2, n2);
	Merge(a, array1 ,n1 , array2 , n2);
	free(array1);
	free(array2);
	for (i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void* NewArray(int n, int size)
{
	void *p;
	p = malloc(size*n);
	return p;
}

void Merge(int *a, int *a1, int n1, int *a2, int n2)
{
	int i, j, k;
	i = j = k = 0;
	while(i < n1 && j < n2)
	{
		while(a1[i] <= a2[j] && i < n1)
			a[k++] = a1[i++];
		while(a2[j] <= a1[i] && j < n2)
			a[k++] = a2[j++];
	} 
	if(i < n1)
		while(i < n1)
			a[k++] = a1[i++];
	else
		while(j < n2)
			a[k++] = a2[j++];	
}

int BinarySearch(int *a, int n, int item)
{
	int low = 0;
	int high = n;
	int middle = (low + high)/2;
	while(low <= high){
		if(a[middle] == item)
			return middle;
		else if(a[middle] < item)
			low = middle + 1;
		else 
			high = middle - 1;
		middle = (low + high)/2;
	}
	return -1;
}
