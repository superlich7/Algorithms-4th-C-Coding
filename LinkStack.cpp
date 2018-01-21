#include <iostream>
#include <string>

using namespace std;

template <class Type>
class LinkStack
{
	private:
		struct Node
		{
			Type item;
			Node *next;
		};
		
		Node *first;
	
	public:
		LinkStack();
		~LinkStack();
		bool IsEmpty();
		void Push(Type item);
		Type Pop();
		Type GetTop();
		void Display();
		
 };
 
 template <class Type>
 LinkStack<Type>::LinkStack()
 {
 	first = NULL;
 }
 
 template<class Type>
 LinkStack<Type>::~LinkStack()
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
 bool LinkStack<Type>::IsEmpty()
 {
 	return (first == NULL);
 }
 
 template<class Type>
 void LinkStack<Type>::Push(Type item)
 {
 	Node *tmp  = new Node;
 	tmp->item  = item;
 	tmp->next = first;
 	first      = tmp;
 }
 
 template<class Type>
 Type LinkStack<Type>::Pop()
 {
 	Node *tmp = first;
 	Type item = tmp->item;
    first = first->next;
    delete tmp;
    return item;
 }
 
 template<class Type>
 Type LinkStack<Type>::GetTop()
 {
 	return first->item;
 }
 
 template <class Type>
 void LinkStack<Type>::Display()
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
 	LinkStack<int> oIntStack;
 	oIntStack.Push(13);
 	oIntStack.Push(15);
 	oIntStack.Push(22);
 	oIntStack.Pop();
 	oIntStack.Display();
 	
 	LinkStack<float> oFloatStack;
 	oFloatStack.Push(2.3);
 	oFloatStack.Push(2.5);
 	oFloatStack.Pop();
 	oFloatStack.Display();
 	
 	LinkStack<string> oStringStack;
 	oStringStack.Push("hello ");
 	oStringStack.Push("world ");
 	oStringStack.Push("newbee");
 	oStringStack.GetTop();
 	oStringStack.Pop();
 	oStringStack.Display();
 	
 	return 1;
 }
