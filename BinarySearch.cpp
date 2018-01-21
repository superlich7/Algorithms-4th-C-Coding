#include <iostream>
using namespace std;

int BinarySearch(int a[],int num,int key)
{
	int low  = 0;
	int mid  = 0;
	int high = num - 1;	
	
	while(low <= high)
	{
		mid = low + (high - low)/2;
		
		if(key > a[mid])
		    low = mid + 1;
		else if(key < a[mid])
		    high = mid - 1;
		else
		{
			cout << "Sucessful search for " << key << endl;
			return mid; 
		}
		     
	}
	
	cout << key << " is not found in array!" << endl;
	return -1;
}

int main()
{
	int a[] = {6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
	int num = sizeof(a)/sizeof(int);
	
	BinarySearch(a,num,33);
	BinarySearch(a,num,34);
	BinarySearch(a,num,70);
	BinarySearch(a,num,96);
	
	return 1;
}
