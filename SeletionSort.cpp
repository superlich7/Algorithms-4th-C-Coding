//Seletion Sort
//in iteration i, find(select) index min of smallest remaining entry.
//time: O(n^2) compares, O(n) exchanges

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SORT_NUM 50

void swap(int *a,int m,int n)
{
	int tmp = a[m];	
	a[m] = a[n];
	a[n] = tmp; 
}

void SeletionSort(int *a,int num)
{
	int min = 0;
	
	 for(int i=0;i<num;i++)
	 {
	     min = i;
	     for(int j=i+1;j<num;j++)
	     {	     	
	     	if(a[j]<a[min])
	     	    min = j;
		 }
		 swap(a,i,min);	 	
	 }	
} 

void  display(int *a,int num)
{	
	for(int i=0;i<num;i++)
	    cout << "sorted array [" << i << "] = " << a[i] << endl;
}

int main()
{
	int num = SORT_NUM;
	int a[num]= {0};
	srand((int)time(0));
	
	for(int i=0;i<num;i++)
	    a[i] = rand()%100;
	    
	SeletionSort(a,num);
	display(a,num);
	
	
	return 0;
}
