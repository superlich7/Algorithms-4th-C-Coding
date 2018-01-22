//Insert Sort
//in iteration i, swap a[i] with each larger to its left.
//time: O(n^2) compares, O(n^2) exchanges
//it's good if the array is partilly sorted

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SORT_NUM 20

void swap(int *a,int m,int n)
{
	int tmp = a[m];	
	a[m] = a[n];
	a[n] = tmp; 
}

void  display(int *a,int num)
{	
	for(int i=0;i<num;i++)
	    cout << "sorted array [" << i << "] = " << a[i] << endl;
}

void InsertSort(int *a,int num)
{
    for(int i=0;i<num;i++)
	{
	    for(int j=i;j>0;j--)
		{
		    if(a[j]<a[j-1])
			    swap(a,j,j-1);
			else
			    break;	
		}	
	}	
} 

int main()
{
	int num = SORT_NUM;
	int a[num]= {0};
	srand((int)time(0));
	
	for(int i=0;i<num;i++)
	    a[i] = rand()%100;
	    
	InsertSort(a,num);
	display(a,num);
	
	
	return 0;
}
