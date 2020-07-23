//把枚举类转换成一个抽象基类

class NetworkState2{
  public:  
     NetworkState2* pNext;
     //所有跟状态有关的都变成 状态对象的行为。
     virtual void Operation1()=0;
     virtual void Operation2()=0;
     virtual void Operation3()=0;

     virtual ~NetworkState2(){}
};

class OpenState: public NetworkState2{
    static NetworkState2* m_instance;
public:
// 在状态模式中，倾向于singleton模式。因为这个对象没不要有多个
    static NetworkState2* getInstance(){
        if(m_instance == nullptr){
            m_instance = new OpenState();
        }
        return m_instance;
    }    

    void Operation1(){
        pNext =  CloseState::getInstance();
    }

    void Operation2(){
        pNext =  ConnectState::getInstance();
    }
};


//这是扩展方式，只需要增加子类，不需要修改
class CloseState:public NetworkState2{

};

class ConnectState:public NetworkState2{

};



//稳定部分 
class NetworkProcessor{
    //抽象指针
   NetworkState2* pState;
public:

   NetworkProcessor(NetworkState2* pState){
       this->pState =pState;
   }
   void Operation1(){
       pState->Operation1();
       pState = pState->pNext;
   }  


    void Operation2(){
       pState->Operation2();
       pState = pState->pNext;
   }  
};
