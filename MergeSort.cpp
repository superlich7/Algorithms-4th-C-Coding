//MergeSort
//divide array into two halves, sort each half, merge two halves
//time: O(nlgn) compares, O(nlgn) exchanges
//but use O(n) memory

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

void  display(int *a,int num)
{	
	for(int i=0;i<num;i++)
	    cout << "sorted array [" << i << "] = " << a[i] << endl;
}

void MergeArray(int *a,int lo,int mid,int hi)
{
	int *tmp1 = new int[mid-lo+1];
	int *tmp2 = new int[hi-mid];
	
	for(int i=0;i<(mid-lo+1);i++)
	    tmp1[i] = a[lo+i];
	
	for(int j=0;j<(hi-mid);j++)
	    tmp2[j] = a[mid+1+j];
	
	for(int k=lo,i=0,j=0;k<=hi;k++)
	{
		if(i>(mid-lo))             a[k] = tmp2[j++];
		else if(j>(hi-mid-1))      a[k] = tmp1[i++];
		else if(tmp1[i] < tmp2[j]) a[k] = tmp1[i++];
		else                       a[k] = tmp2[j++];
	}
	
	delete []tmp1;
	delete []tmp2;
}

void MergeSort(int *a,int lo,int hi) //recursion call itself
{
    if(hi<=lo) return;
    
    int mid = lo+(hi-lo)/2;
    MergeSort(a,lo,mid);
    MergeSort(a,mid+1,hi);
    
    MergeArray(a,lo,mid,hi);
} 

int main()
{
	int lo  = 0;
	int hi  = SORT_NUM-1;
	int num = SORT_NUM;
	
	int a[num]= {0};
	srand((int)time(0));
	
	for(int i=0;i<num;i++)
	    a[i] = rand()%100;
	    
	//display(a,num);  
	//cout << "-----------------------------------------------"<<endl;
	MergeSort(a,lo,hi);
	display(a,num);
	
	return 0;
}
