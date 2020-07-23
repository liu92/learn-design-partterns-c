#include <iostream>

using namespace std;

class Visitor;

//使用这种方式 是不灵活的。应为这种模式下，Element中
// 如果需求的变化那么就要添加 其它方法。
class Element{

public:
    //第一次多态辨析
    virtual void accept(Visitor& visitor) = 0;

    virtual ~Element(){}  
};


//继承Element
class ElementA: public Element{

public:
   //重新accept函数 
   void accept(Visitor &visitor) override{
       visitor.visitElementA(*this);
   }
   
 
};

class ElementB: public Element{

public: 
   void accept(Visitor &visitor) override{
       //第二次多态辨析
       visitor.visitElementB(*this);
   }
    
};

//这个模式 前提条件，visitor的基类稳定的前提是 Element的所有子类都确定。 
// 也就是说Element 有多少个子类，那么 Visitor基类中就要有多个方法。
// 这是这个模式非常大一个缺点。
class Visitor{

public:
    virtual void visitElementA(ElementA& element) = 0;
    virtual void visitElementB(ElementB& element) = 0;
    virtual ~Visitor(){}
}

// 上面的当前的设计
// ====================================
// 将来的

class Visitor1: public Visitor{

public:
    void visitElementA(ElementA& element) override{
         cout<<"Visitor1 is processing ElementA" << endl;
    }   

    void visitElementB(ElementB& element) override{
         cout<<"Visitor1 is processing ElementB" << endl;
    }     
};


class Visitor2: public Visitor{

public:
    void visitElementA(ElementV& element) override{
         cout<<"Visitor2 is processing ElementA" << endl;
    }   

    void visitElementB(ElementB& element) override{
         cout<<"Visitor2 is processing ElementB" << endl;
    }     
};


int main{

    Visitor2 visitor;
    ElementB element;
    //1、因为element中是虚函数，所以要找Element运行时的真实类型
    // 运行时类型时ElementB。
    //2、进入到ElementB中调用 accept。这个方法中有Visitor参数
    //3、这个Visitor参数实际类型是 Visitor2
    //4、所以这个进入Visitor2中 执行 visitElementB方法 

    //执行两次 多态辨析(double dispatch)
    element.accept(Visitor); 

    return 0;
}