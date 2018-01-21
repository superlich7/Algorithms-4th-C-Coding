#include <iostream> 
using namespace std;

class WeightUF
{
	private:
		int *id;
		int *sz;//child num of each id 
		int num;//total id num
		
	public:
		WeightUF(int n);		
		~WeightUF();
		int root(int p);
		bool Connected(int p, int q);		
		void Union(int p, int q);	
};

WeightUF::WeightUF(int n)
{
	id = new int[n];
	sz = new int[n];
	for(int i=0;i<n;i++)
	{
		id[i] = i;
		sz[i] = 0;
	}
	num = n;
	
	cout << "New UF obj with elements " << num << endl;
}

WeightUF::~WeightUF()
{
	delete id;
	delete sz;
	num = 0;
}

int WeightUF::root(int p)
{
	while(id[p] != p)
	{
		id[p] = id[id[p]];
		p = id[p];
	}
	    
	return p;
}

bool WeightUF::Connected(int p, int q)
{
	if(root(p) == root(q))
	{
		cout << p << " and " << q << " are connected !" << endl; 
		return 1;
	}
	else
	{
		cout << p << " and " << q << " are NOT connected !" << endl; 
	    return 0;	
	}	
}

void WeightUF::Union(int p, int q)
{
	int proot = root(p);
	int qroot = root(q);
	
	if(proot == qroot) return;
	if(sz[proot] < sz[qroot])
	{
		id[proot] = qroot;
		sz[qroot] += sz[proot];
	}
	else
	{
		id[qroot] = proot;
		sz[proot] += sz[qroot];
	}

	cout << p << " and " << q << " union !" << endl;
	
	return ;
}	

int main()
{
	WeightUF oWeightUF(10);
	
	oWeightUF.Union(0,5);
	oWeightUF.Union(6,5);
	oWeightUF.Union(2,1);
	oWeightUF.Union(7,1);
	oWeightUF.Union(3,4);
	oWeightUF.Union(9,4);
	oWeightUF.Union(8,3);
	
	oWeightUF.Connected(0,6);	    
	oWeightUF.Connected(7,6);
	
	return 0;
}

