class House{

public:
   //这里不使用构造器方式，是因为如果使用构造器的方式的话，那么在构建过程中，
   // this->BuildPart..(); 这个就是静态绑定了
   
   //构建过程
    void init(){
       this->BuildPart1();

       for (size_t i = 0; i < 4; i++)
       {
          this->BuildPart2();
       }

       bool flag = this->BuildPart3();
       if(flag){
           this->BuildPart4();
       }
       
       this->BuildPart5();
    }
virtual  ~House();

protected:
  virtual void BuildPart1()=0;
  virtual void BuildPart2()=0;
  virtual void BuildPart3()=0;
  virtual void BuildPart4()=0;
  virtual void BuildPart5()=0;
};




