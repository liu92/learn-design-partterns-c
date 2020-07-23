//对象的表示
class House3{

};

//对象的构建
class HouseBuilder{
   
public:
  
  House3* GetResult(){
     return pHouse;
  }
   

virtual  ~HouseBuilder();

protected:
  House3* pHouse3;
  virtual void BuildPart1()=0;
  virtual void BuildPart2()=0;
  virtual void BuildPart3()=0;
  virtual void BuildPart4()=0;
  virtual void BuildPart5()=0;
};


//实现
class StoneHouse: public House3{
 
};

class StoneHoseBuilder: public HouseBuilder{
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
}


//稳定部分
class HouseDirector{
public:
   HouseBuilder* pHouseBuilder;

   HouseDirector(HouseBuilder* pHouseBuilder){
      this->pHouseBuilder = pHouseBuilder;
   }

   House3* Construct(){
       pHouseBuilder->BuildPart1();
   } 

     for (size_t i = 0; i < 4; i++)
       {
          pHouseBuilder->BuildPart2();
       }

       bool flag = pHouseBuilder->BuildPart3();
       if(flag){
           pHouseBuilder->BuildPart4();
       }
       
       pHouseBuilder->BuildPart5(); 
       return pHouseBuilder->GetResult();
};







int main(){
  House2* pHouse = new StoneHouse();
  pHouse->init();

}
