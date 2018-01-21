#include <iostream> 
using namespace std;

class QuickUnionUF
{
	private:
		int *id;
		int num;
		
	public:
		QuickUnionUF(int n)
		{
			id = new int[n];
			for(int i=0;i<n;i++)
			    id[i] = i;
			num = n;
			
			cout << "New UF obj with elements " << num << endl;
		}
		
		~QuickUnionUF()
		{
			delete id;
			num = 0;
		}
		
		int root(int p)
		{
			while(id[p] != p)
			    p = id[p];
			return p;
		}
		
		bool Connected(int p, int q)
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
		
		void Union(int p, int q)
		{
			int proot = root(p);
			int qroot = root(q);
			
			id[proot] = qroot;

			cout << p << " and " << q << " union !" << endl;
			
			return ;
		}	
};

int main()
{
	QuickUnionUF oQuickUnionUF(10);
	
	oQuickUnionUF.Union(0,5);
	oQuickUnionUF.Union(6,5);
	oQuickUnionUF.Union(2,1);
	oQuickUnionUF.Union(7,1);
	oQuickUnionUF.Union(3,4);
	oQuickUnionUF.Union(9,4);
	oQuickUnionUF.Union(8,3);
	
	oQuickUnionUF.Connected(0,6);	    
	oQuickUnionUF.Connected(7,6);
	
	return 0;
}

