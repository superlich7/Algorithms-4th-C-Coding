//BinaryHeap Sort
//use a binary heap structure to sort
//a complete tree is a perfectly full tree,except for the bottom level
//a binary heap is  a complete binary tree which meats the heap order:
//the parent is no smaller than its children
//parent of node at k is at k/2; children of node at k are at 2k and 2k+1
//time: O(nlgn) compares, O(nlgn) exchanges
//not stable 

//first to build a max-heap, get the max(root),then rebuild the max-heap, loop...
//note: a[0] is not used here

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

void swim(int *a,int k) //if the child k is bigger than its parent k/2,then swim up!
{   
    while((k>1) && (a[k/2]<a[k]))
    {
    	swap(a,k,k/2);
    	k/=2;
	}
} 

void sink(int *a,int k,int num)//if the parent k is smaller than its children(2k,or 2k+1 or both),then sink it dowm!
{	
	while(2*k <= num)
	{
		int j = 2*k;
		if(j<num && a[j]<a[j+1]) j++;
		if(a[k]>=a[j]) break;
		swap(a,k,j);
		k = j;
	}
}

void HeapSort(int *a,int num)
{
	//build the max-heap
    for(int i=num/2;i>=1;i--)
        sink(a,i,num);
    
    //swap the max(root) to the right end,then rebuild the max-heap
    int ntmp = num;
    while(ntmp>1)
    {
    	swap(a,1,ntmp);
    	sink(a,1,--ntmp);
	}    
}

int main()
{
	int num = SORT_NUM+1;//heap sort use no a[0]
	int a[num]= {0};
	srand((int)time(0));
	
	for(int i=1;i<num;i++)
	    a[i] = rand()%100;
	    
	//display(a,num);  
	//cout << "-----------------------------------------------"<<endl;
	HeapSort(a,num);
	display(a,num);
	
	return 0;
}
