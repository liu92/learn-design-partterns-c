class TaxStrategy{

public:
  virtual double Calculate(const Context& context)=0;
  //虽然编译器会生成析构函数 ，但是还是要自己去写一个虚的析构函数
  //不然在 多条调用的时候 delete是会出问题。
  virtual  ~TaxStrategy(){}
};

class CNTax: public TaxStrategy{

public:
    virtual double Calculate(const Context& context){

    }
};


class USTax: public TaxStrategy{

public:
    virtual double Calculate(const Context& context){
        
    }
};


class DETax: public TaxStrategy{

public:
    virtual double Calculate(const Context& context){
        
    }
};


class  SalesOrder{
private:
   TaxStrategy* strategy; //一般来讲要实现多态的变量的时候，都要用指针

public:
  SalesOrder(StartegyFactory* startegyFactory){
      this->strategy = startegyFactory->NewStrategy();
  }

  ~SalesOrder(){
      delete this->strategy;
  }

  public double CalculateTax(){
      //...
      //所谓算法上下文的参数
      Context context();

      double val = 
         strategy->Calculate(context); //多态调用
  }
}
