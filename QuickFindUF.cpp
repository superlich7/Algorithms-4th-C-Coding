#include <iostream> 
using namespace std;

class QuickFindUF
{
	private:
		int *id;
		int num;
		
	public:
		QuickFindUF(int n)
		{
			id = new int[n];
			for(int i=0;i<n;i++)
			    id[i] = i;
			num = n;
			
			cout << "New UF obj with elements " << num << endl;
		}
		
		~QuickFindUF()
		{
			delete id;
			num = 0;
		}
		
		bool Connected(int p, int q)
		{
			if(id[p] == id[q])
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
			int pid = id[p];
			int qid = id[q];
			
			for(int i=0;i<num;i++)
			{
				if(id[i] == pid)
				    id[i] = qid;
			}
			cout << p << " and " << q << " union !" << endl;
			
			return ;
		}	
};

int main()
{
	QuickFindUF oQuickFindUF(10);
	
	oQuickFindUF.Union(0,5);
	oQuickFindUF.Union(6,5);
	oQuickFindUF.Union(2,1);
	oQuickFindUF.Union(7,1);
	oQuickFindUF.Union(3,4);
	oQuickFindUF.Union(9,4);
	oQuickFindUF.Union(8,3);
	
	oQuickFindUF.Connected(0,6);	    
	oQuickFindUF.Connected(7,6);
	
	return 0;
}

