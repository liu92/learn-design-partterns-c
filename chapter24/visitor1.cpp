#include <iostream>

using namespace std;

class Visitor;

//使用这种方式 是不灵活的。应为这种模式下，Element中
// 如果需求的变化那么就要添加 其它方法。
class Element{

public:
    virtual void Func1() =0;
    //比如这里添加了Func2和Fun3方法，那么其Element的所有子类就要重写
    //方法。所以这种方式违背了开闭原则
    virtual void Func2() =0; 
    virtual void Func3() =0;
     

    virtual ~Element(){}  
};

class ElementA: public Element{

public: 
    void Func1() override{
        //....
    }    

    virtual ~Element(){}
};

class ElementB: public Element{

public: 
    void Func1() override{
        //....
    }    
};