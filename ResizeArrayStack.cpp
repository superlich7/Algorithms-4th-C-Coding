#include <iostream>
#include <string>

using namespace std;

template <class Type>
class ResizeArrayStack
{
	private:
		Type *pItem;
		int  ArrayNum;
		int  ItemNum;
	
	public:
		ResizeArrayStack();
		~ResizeArrayStack();
		void ResizeArray(int size);
		bool IsEmpty();
		void Push(Type item);
		Type Pop();
		Type GetTop();
		void Display();
		
 };
 
 template <class Type>
 ResizeArrayStack<Type>::ResizeArrayStack()
 {
 	pItem = new Type[1];
    ArrayNum = 1;
    ItemNum  = 0;
 }
 
 template<class Type>
 ResizeArrayStack<Type>::~ResizeArrayStack()
 {
    delete[] pItem;
 }
 
 template<class Type>
 void ResizeArrayStack<Type>::ResizeArray(int size)
 {
 	Type *pCopyItem = new Type[size];
 	for(int i=0;i<ItemNum;i++)
        pCopyItem[i] = pItem[i];
    pItem = pCopyItem;
    ArrayNum = size;
 }
 
 template<class Type>
 bool ResizeArrayStack<Type>::IsEmpty()
 {
 	return (ItemNum == 0);
 }
 
 template<class Type>
 void ResizeArrayStack<Type>::Push(Type item)
 {
    if(ItemNum == ArrayNum)
        ResizeArray(ArrayNum*2);
    pItem[ItemNum++] = item;
 }
 
 template<class Type>
 Type ResizeArrayStack<Type>::Pop()
 {
    if((ItemNum > 0) && (ItemNum == ArrayNum/4))
        ResizeArray(ArrayNum/2);
    Type item = pItem[--ItemNum];
    //pItem[ItemNum] = NULL;
    
    return item;
 }
 
 template<class Type>
 Type ResizeArrayStack<Type>::GetTop()
 {
 	return pItem[ItemNum-1];
 }
 
 template <class Type>
 void ResizeArrayStack<Type>::Display()
 {
 	for(int i=0;i<ItemNum;i++)
 		cout << "current node is " << pItem[i] << endl;
 }
 
 int main()
 {
 	ResizeArrayStack<int> oResizeArrayStack;
 	oResizeArrayStack.Push(13);
 	oResizeArrayStack.Push(15);
 	oResizeArrayStack.Push(22);
 	oResizeArrayStack.Pop();
 	oResizeArrayStack.Display();
 	
 	ResizeArrayStack<float> oFloatStack;
 	oFloatStack.Push(2.3);
 	oFloatStack.Push(2.5);
 	oFloatStack.Pop();
 	oFloatStack.Display();
 	
 	ResizeArrayStack<string> oStringStack;
 	oStringStack.Push("hello ");
 	oStringStack.Push("world ");
 	oStringStack.Push("newbee");
 	oStringStack.GetTop();
 	oStringStack.Pop();
 	oStringStack.Display();
 	
 	return 1;
 }
