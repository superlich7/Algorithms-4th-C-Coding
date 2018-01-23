//Quick Sort
//partition:for some j, entry a[j] is in place, make no larger entry to the left of j,
//no smaller entry to the right of j
//sort each piece 
//time: O(nlgn) compares, O(nlgn) exchanges
//not stable 

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

int Partition(int *a,int lo,int hi) //recursion call itself
{   
    int i = lo;
    int j = hi+1;
    
    while(1)
    {
    	while(a[++i]<a[lo])
    	    if(i == hi) break;
    
        while(a[lo]<a[--j])
            if(j == lo) break;
    
    	if(j<=i) break;
    	
        swap(a,i,j);
	}
	swap(a,lo,j);  
	
	return j;
} 

void QuickSort(int *a,int lo,int hi)
{
	if(lo<hi)
	{
		int part = Partition(a,lo,hi);
		QuickSort(a,lo,part-1);
		QuickSort(a,part+1,hi);
	}
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
	QuickSort(a,lo,hi);
	display(a,num);
	
	return 0;
}
