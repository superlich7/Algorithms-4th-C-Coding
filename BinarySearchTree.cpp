//binary search tree
//a binary tree is a tree who has at most 2 children
//binary search tree: a binary tree whose left sub-tree key are smaller than the root key
//and whose right sub-tree keys are larger than the root key..  

#include <iostream>
#include <string>

using namespace std;

template <class TypeKey, class TypeVal>
class BinarySearchTree
{
	private:
	    struct Node
		{
			TypeKey key;
			TypeVal val;
			Node *left;
			Node *right;
			//int count;
		};
		Node *root;
		
	public:
		BinarySearchTree(TypeKey key,TypeVal val);
		BinarySearchTree();
		
		void  put(TypeKey key,TypeVal val);//insert a pair of key,val ,if key exist,then replace its val				
		TypeVal get(TypeKey key);//serch whether a key is in tree		
		void remove(TypeKey key);
		
		bool contains(TypeKey key);
		bool isEmpty();
		int  size();
		
		TypeKey min();
		TypeKey max();
		TypeKey floor(TypeKey key);   //return the largest key who less or equal to input key
		TypeKey ceiling(TypeKey key); //return the smallest key who larger or equal to input key
		int rank(TypeKey key);        //number of keys less than key
		TypeKey select(int k);        //key of rank k
		void deleteMin();
		void deleteMax();
		int size(TypeKey lo,TypeKey hi);//numbers of key between lo key nad hi key
		
		Node* put(Node *pNode,TypeKey key,TypeVal val)//help func for put() using a recursive
        {
            if(pNode == NULL) return  NewNode(key,val);
					
	        if(pNode->key > key)
	        	pNode->left  = put(pNode->left, key,val);	           
	        else if(pNode->key < key)
	        	pNode->right = put(pNode->right,key,val);	            
	        else
	        	pNode->val = val;
	        	
			return pNode;       			
        }
        
       	Node* NewNode(TypeKey key,TypeVal val)
        {
 	        Node *pNode = new Node;
 	
 	        pNode->key   = key;
 	        pNode->val   = val;
 	        pNode->left  = NULL;
 	        pNode->right = NULL;
 	
 	        cout << "new node, key = " << key << ", val = " << val <<endl;
 	        
 	        return pNode;
        }	
			
	    //iteration	function		
 };
 
 template <class TypeKey, class TypeVal>
 BinarySearchTree<TypeKey,TypeVal>::BinarySearchTree(TypeKey key,TypeVal val)
 {
 	root = new Node;
 	
	 root->key   = key;
	 root->val   = val;
	 root->left  = NULL;
	 root->right = NULL;
	 root->count = 1;
	 
	 cout << "new node, key = " << key << ", val = " << val <<endl;
 }
 
 template <class TypeKey, class TypeVal>
 BinarySearchTree<TypeKey,TypeVal>::BinarySearchTree()
 {
 	root = NULL;
 }

template <class TypeKey, class TypeVal>
void BinarySearchTree<TypeKey,TypeVal>::put(TypeKey key,TypeVal val)
{
    root = put(root,key,val); 			
}

template <class TypeKey, class TypeVal>
TypeVal BinarySearchTree<TypeKey,TypeVal>::get(TypeKey key)
{
	Node *node = root;
	
	while(node != NULL)
	{
		if(node->key > key) 
		    node = node->left;
		else if(node->key < key) 
		    node = node->right;
		else
		{
			cout << "found value of key " << key << " is " << node->val << endl;
			return node->val;
		}
	}
	cout << "NOT found value of key " << key << endl;
	return NULL;
}
 
 int main()
 {
 	//BinarySearchTree<string,int> oBST("abc",123);
 	BinarySearchTree<int,string> oBST;
 	oBST.put(50,"a");
 	oBST.put(10,"b");
 	oBST.put(15,"2c");
 	oBST.put(25,"cs");
 	oBST.put(45,"cd");
 	oBST.put(53,"ca");
 	oBST.put(75,"cd");
 	oBST.put(55,"cg");

 	oBST.get(50);
 	oBST.get(15);
 	//oBST.get(20);
 	
 	BinarySearchTree<string,int> oBST1;
 	oBST1.put("h",1);
 	oBST1.put("z",10);
 	oBST1.put("c",11);
 	oBST1.put("g",15);
 	oBST1.put("ga",125);
 	oBST1.put("fg",165);
 	
 	oBST1.get("c");
 	oBST1.get("d");
 	oBST1.get("ga");
	
 	return 0;
 }
