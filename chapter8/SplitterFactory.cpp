class ISplitter2{

public:

   virtual void split())=0;
   virtual  ~ISplitter2(){}

};



//工厂基类
class SplitterFactory{

public:
   // ISplitter CreateSplitter(){
   //    // 去new 要放具体类？ 那么如果去解决问题呢？
   //    return new 
   // }

   //使用虚函数，就延迟实现
   virtual ISplitter CreateSplitter()=0;
   virtual ~SplitterFactory(); 


};







