// Quadratic Running Time - Selection Sort & Insertion Sort & Bubble Sort
// Ascending Sorting
#include<stdio.h>
#include<stdlib.h>
#define N 100000

void selectionSort(int B[], int size){
	int i,j,temp,minind;
	for(i=0; i<size-1; i++){
		minind = i;
		for(j=i+1; j<size; j++){
			if(B[minind] > B[j]){
				minind = j;
			}
		}
		temp = B[i];
		B[i] = B[minind];
		B[minind] = temp;
	}
}	// always O(n^2)

// *************************** //

void insertionSort(int B[], int size){
	int i,j,temp;
	for(i=1; i<size; i++){
		for(j=i-1; j>=0; j--){
			if(B[j+1] < B[j]){
				temp = B[j+1];
				B[j+1] = B[j];
				B[j] = temp;
			}
			else{
				break;
			}
		}
	}
}	// Best case: O(n)	Worst case: O(n^2)

// *************************** //

void bubbleSort(int B[], int size){
	int i,temp;
	while(size>1){
		for(i=1; i<size; i++){
			if(B[i] < B[i-1]){
				temp = B[i];
				B[i] = B[i-1];
				B[i-1] = temp;
			}
		}
		size--;
	}
}	// O(n^2)

// *************************** //

int main(){
//	srand(time(0));
	int A[N];
	int i;
	for(i=0; i<N; i++){
		A[i] = rand()%100;
		printf("%d ", A[i]);
	}
	printf("\n");
	
//	selectionSort(A,N);
//	insertionSort(A,N);
	bubbleSort(A,N);
	
	for(i=0; i<N; i++){
		printf("%d ", A[i]);
	}
	
	return 0;
}
