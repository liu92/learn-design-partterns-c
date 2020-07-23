class ISubject{
    public:
     virtual void process();
};

class RealSubject: public ISubject{
    public: 
      virtual void process(){

      }
};

class ClientApp{
    ISubject* subject;

public: 
   ClientApp(){
        //这里可能是因为性能的原因， 也可能是因为分布式的原因 拿不到这个对象, 
        // 那么这里应该怎么做呢？
       subject = new RealSubject();
   }

   void DoTask(){
       //...
       subject -> process();
       //...
   }

};