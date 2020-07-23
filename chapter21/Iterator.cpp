#include <iostream>
//使用面向对象的方式，在C++里面这种方式已经过时了。
template<typename T>
class Iterator{

public:
   virtual void first() = 0;
   virtual void next() =0;
   virtual bool isDone() const =0;
   virtual T& current() = 0;
};

template<typename T>
class MyCollection{

public:
   Iterator<T> GetIterator(){
       //....
   }    
};

template<typename T>
class CollectionIterator: public Iterator<T>{
    MyCollection<T> mc:
public:
   CollectionIterator(const MyCollection<T> & c ): mc(c){}  

   void first() override{
       
   }  

   void next() override{

   }

   bool isDone() const override{

   }

   T& current() override{

   }
};

void MyAlgorithm(){
    MyCollection<int> mc;

    Iterator<int> iter = mc.GetIterator();

      //面向对象， 多态
    for(iter.first(); !iter.isDone(); iter.next()){
        cout << iter.current() << endl;
    }
}
