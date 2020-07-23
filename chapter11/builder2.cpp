class House2{

public:
   //在C++里面，这里不使用构造函数方式，是因为如果使用构造函数的方式的话，那么在构建过程中，
   // this->BuildPart..(); 这个就是静态绑定了
   //House2(){
         // this->BuildPart1();  这里要去调用40行的实现，但是这里没有实现所以会报错的。
         // 如果允许这个实现是动态的绑定话，那么子类的构造函数要先调用这个house()构造函数，但是这个构造函数去的
         //调用 this-BuildPart1()；时候 子类的虚函数的override 版本的话，就会导致一个结果，
         // 就是子类的构造函数还没有完成，你子类的虚函数先被调用了。 
      //     for (size_t i = 0; i < 4; i++)
      //  {
      //     this->BuildPart2();
      //  }

      //  bool flag = this->BuildPart3();
      //  if(flag){
      //      this->BuildPart4();
      //  }
   // } 不能使用这种


   
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

virtual  ~House2();


protected:
  virtual void BuildPart1()=0;
  virtual void BuildPart2()=0;
  virtual void BuildPart3()=0;
  virtual void BuildPart4()=0;
  virtual void BuildPart5()=0;
};


//实现
class StoneHouse: public House2{
 protected:
  virtual void BuildPart1(){

  }
  virtual void BuildPart2(){

  }
  virtual void BuildPart3(){

  }
  virtual void BuildPart4(){

  }
  virtual void BuildPart5(){

  }
};






int main(){
  House2* pHouse = new StoneHouse();
  pHouse->init();

}
