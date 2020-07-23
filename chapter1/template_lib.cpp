class Libaray{
public:
//稳定 template method 

  void Run(){
   
   Step1();

   if(Step2()){//支持变化==>虚函数的多条调用
     Step3();   
   } 

   for (int i = 0; i < 4; i++)
   {
      Step4(); //支持变化==>虚函数的多条调用
   }
   
   Step5();
  }

 //虚的 析构函数
 //在c++里面, 作为一个基类 有一个原则
 // 就是把 基类里面的 析构函数写成虚函数
 // 为什么写出虚函数,是因为 在main里面去 就调不到子类的析构函数
 //所以要求调用基类的时候，要将基类的析构函数写成虚构函数
  virtual ~Libaray(){}
}

protected:{
    void Step1(){ //稳定的
        //
    }

     void Step3(){ //稳定的
        //
    }
    
     void Step5(){ //稳定的
        //

        virtual bool Step2() = 0; // 变化
        virtual void Step4() = 0; //变化 
    }
}

