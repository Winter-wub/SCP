#include<stdio.h>
#define n 21
void print ( int A[] , int size){
	if(size != 0){
		print(A,size-1);
		printf("%d ",A[size-1]);
	}
}
int partition(int A[],int first,int last){
	int pivot = A[last];
	int i=first,j,temp;
	for(j=first;j<last;j++){
		if(A[j] <= pivot){
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
	}
	temp = A[i];
	A[i] = A[last];
	A[last] = temp;
	return i;
}

void quicksort(int A[],int first,int last){
	if(first < last){
		int p = partition(A,first,last);
		quicksort(A,first,p-1);
		quicksort(A,p+1,last);
	}
}

void merge(int A[],int first,int last){
	int P1 = first, P1E = (first+last)/2, P2 = P1E+1, P2E = last;
	int temp[last+1];
	int count = first;
	
	while(P1<=P1E && P2<=P2E){
		if(A[P1] <= A[P2]){
			temp[count++] = A[P1++];
		}
		else{
			temp[count++] = A[P2++];
		}
	}
	
	while(P1<=P1E){
		temp[count++] = A[P1++];
	}
	while(P2<=P2E){
		temp[count++] = A[P2++];
	}
	
	int i;
	for(i=first; i<=last; i++){
		A[i] = temp[i];
	}
}

void mergesort(int A[],int first,int last){
	if(first < last){
		int mid = (first+last)/2;
		mergesort(A,first,mid);
		mergesort(A,mid+1,last);
		merge(A,first,last);
	}

}

int main(){
	int a[n];
	int i;
	for(i=0;i<n;i++){
		a[i] = 1+rand()%100;
		printf("%d ",a[i]);
	}

	printf("\n");
	mergesort(a,0,n-1);
//	quicksort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
