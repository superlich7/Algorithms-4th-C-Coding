#include <iostream>
#include <string>

using namespace std;

template <class Type>
class LinkQueue
{
	private:
		struct Node
		{
			Type item;
			Node *next;
		};
		
		Node *first;
		Node *last;
	
	public:
		LinkQueue();
		~LinkQueue();
		bool IsEmpty();
		void Enqueue(Type item);
		Type Dequeue();
		Type GetFirst();
		Type GetLast();
		void Display();
		
 };
 
 template <class Type>
 LinkQueue<Type>::LinkQueue()
 {
 	first = NULL;
 	last  = NULL;
 }
 
 template<class Type>
 LinkQueue<Type>::~LinkQueue()
 {
 	Node *tmp;
 	while(first != NULL)
 	{
 		tmp   = first;
 		first = first->next;
 		delete tmp;
	 }
 }
 
 template<class Type>
 bool LinkQueue<Type>::IsEmpty()
 {
 	return ((first == NULL)&&(last == NULL));
 }
 
 template<class Type>
 void LinkQueue<Type>::Enqueue(Type item)
 {
 	Node *tmp = new Node;
 	if(IsEmpty())
 	{
 		first = tmp;
 		last  = tmp;
	}
	last->next = tmp;
	last       = tmp;  
    tmp->item  = item; 
	tmp->next  = NULL;  
 }
 
 template<class Type>
 Type LinkQueue<Type>::Dequeue()
 {
    Node *tmp = first;
    first = first->next;
    Type item = tmp->item;
    delete tmp;
    
    return item;
 }
 
 template<class Type>
 Type LinkQueue<Type>::GetFirst()
 {
 	return first->item;
 }
 
  template<class Type>
 Type LinkQueue<Type>::GetLast()
 {
 	return last->item;
 }
 
 template <class Type>
 void LinkQueue<Type>::Display()
 {
 	Node *tmp = first;
 	while(tmp != NULL)
 	{
 		cout << "current node is " << tmp->item << endl;
 		tmp = tmp->next;
	 }
 }
 
 int main()
 {
 	LinkQueue<int> oIntQueue;
 	oIntQueue.Enqueue(13);
 	oIntQueue.Enqueue(15);
 	oIntQueue.Enqueue(22);
 	oIntQueue.Dequeue();
 	oIntQueue.Display();
 	
 	LinkQueue<float> oFloatQueue;
 	oFloatQueue.Enqueue(2.3);
 	oFloatQueue.Enqueue(2.5);
 	oFloatQueue.Enqueue(4.1);
 	oFloatQueue.Dequeue();
 	oFloatQueue.Display();
 	
 	LinkQueue<string> oStringQueue;
 	oStringQueue.Enqueue("hello ");
 	oStringQueue.Enqueue("world ");
 	oStringQueue.Enqueue("newbee");
 	oStringQueue.GetFirst();
 	oStringQueue.Dequeue();
 	oStringQueue.Display();
 	
 	return 1;
 }
