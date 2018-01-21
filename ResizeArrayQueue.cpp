#include <iostream>
#include <string>

using namespace std;

template <class Type>
class ResizeArrayQueue
{
	private:
		Type *pItem;
		int  ArrayNum;
		int  ItemNum;
	
	public:
		ResizeArrayQueue();
		~ResizeArrayQueue();
		void ResizeArray(int size);
		bool IsEmpty();
		void Enqueue(Type item);
		Type Dequeue();
		Type GetFirst();
		Type GetLast();
		void Display();
		
 };
 
 template <class Type>
 ResizeArrayQueue<Type>::ResizeArrayQueue()
 {
 	pItem = new Type[1];
    ArrayNum = 1;
    ItemNum  = 0;
 }
 
 template<class Type>
 ResizeArrayQueue<Type>::~ResizeArrayQueue()
 {
    delete[] pItem;
 }
 
 template<class Type>
 void ResizeArrayQueue<Type>::ResizeArray(int size)
 {
 	Type *pCopyItem = new Type[size];
 	for(int i=0;i<ItemNum;i++)
        pCopyItem[i] = pItem[i];
    pItem = pCopyItem;
    ArrayNum = size;
 }
 
 template<class Type>
 bool ResizeArrayQueue<Type>::IsEmpty()
 {
 	return (ItemNum == 0);
 }
 
 template<class Type>
 void ResizeArrayQueue<Type>::Enqueue(Type item)
 {
    if(ItemNum == ArrayNum)
        ResizeArray(ArrayNum*2);
    pItem[ItemNum++] = item;
 }
 
 template<class Type>
 Type ResizeArrayQueue<Type>::Dequeue()
 {
    if((ItemNum > 0) && (ItemNum == ArrayNum/4))
        ResizeArray(ArrayNum/2);
    Type item = pItem[0];
    ItemNum--;
    for(int i=0;i<ItemNum;i++)
        pItem[i] = pItem[i+1];
    
    return item;
 }
 
 template<class Type>
 Type ResizeArrayQueue<Type>::GetFirst()
 {
 	return pItem[0];
 }
 
 template<class Type>
 Type ResizeArrayQueue<Type>::GetLast()
 {
 	return pItem[ItemNum-1];
 }
 
 template <class Type>
 void ResizeArrayQueue<Type>::Display()
 {
 	for(int i=0;i<ItemNum;i++)
 		cout << "current node is " << pItem[i] << endl;
 }
 
 int main()
 {
 	ResizeArrayQueue<int> oResizeArrayQueue;
 	oResizeArrayQueue.Enqueue(13);
 	oResizeArrayQueue.Enqueue(15);
 	oResizeArrayQueue.Enqueue(22);
 	oResizeArrayQueue.Dequeue();
 	oResizeArrayQueue.Display();
 	
 	ResizeArrayQueue<float> oFloatQueue;
 	oFloatQueue.Enqueue(2.3);
 	oFloatQueue.Enqueue(2.5);
 	oFloatQueue.Dequeue();
 	oFloatQueue.Display();
 	
 	ResizeArrayQueue<string> oStringQueue;
 	oStringQueue.Enqueue("hello ");
 	oStringQueue.Enqueue("world ");
 	oStringQueue.Enqueue("newbee");
 	oStringQueue.Dequeue();
 	oStringQueue.Display();
 	
 	return 1;
 }
