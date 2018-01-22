//Shell Sort
//move more than one position at a time by h-sorting the array.
//time: O(n^2) compares, O(n^2) exchanges

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

void ShellSort(int *a,int num)
{
    int h = 1;
	while(h<num/3)
	  h	= h*3+1;
	  
	while(h>=1)
	{
		for(int i=h;i<num;i++)
		{
			for(int j=i;j>=h && a[j]<a[j-h];j-=h)
			    swap(a,j,j-h);
		}
		h/=3;
	}
} 

int main()
{
	int num = SORT_NUM;
	int a[num]= {0};
	srand((int)time(0));
	
	for(int i=0;i<num;i++)
	    a[i] = rand()%100;
	    
	ShellSort(a,num);
	display(a,num);
	
	
	return 0;
}
