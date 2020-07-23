//目标接口(新接口)
class ITarget{
 public:
   virtual void process1()=0;
   
};

//遗留接口(老接口)
class IAdaptee{
    public:
     virtual void foo(int data) =0 ;
     virtual int bar() = 0;
};

class OldClass:public IAdaptee{
    // .....
}

//对象适配器
class Adapter:public ITarget{//继承
protected:
   //灵活性
    IAdaptee* pAdaptee; //组合
public:
   Adapter(IAdaptee* pAdaptee;){
      this->pAdaptee = pAdaptee;
   }
   
    virtual void process1(){
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};

//类适配器，却是了灵活性，这个和OldClass类就绑定死了
// class Adapter:public ITarget,
//          protected OldClass{//多继承

// }



int main(){
    IAdaptee* pAdaptee = new OldClass();
    
    ITarget* pTarget = new Adapter(pAdaptee);
    pTarget ->process1();
}