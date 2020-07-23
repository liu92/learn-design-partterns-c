
//原来版本
// class Messager
// {

// public:
//    virtual void login(string userName, string password)=0;
//    virtual void SendMessage(string message)=0;
//    virtual void SendPicture(Image image)=0;
   
//    virtual void PlaySound()=0;
//    virtual void DrawShape()=0;
//    virtual void WriteText()=0;
//    virtual void Connect()=0;

//    virtual ~Messager(){}
// };

//拆分后
class Messager{
   protected:
     MessagerImpl* MessagerImpl
public:
   virtual void login(string userName, string password)=0;
   virtual void SendMessage(string message)=0;
   virtual void SendPicture(Image image)=0;
   
   
};

//这个是平台实现, 那么这个时候平台实现就继承这个类
class MessagerImpl{

   virtual void PlaySound()=0;
   virtual void DrawShape()=0;
   virtual void WriteText()=0;
   virtual void Connect()=0;

   virtual ~MessagerImpl(){}
};




// //平台实现
// class PCMessagerBase : public Messager{
//     public:
//     virtual void PlaySound(){
//         //**********
//     }
//    virtual void DrawShape(){
//        //********
//    }
//    virtual void WriteText(){
//         //********
//    }
//    virtual void Connect(){
//         //********
//    }
// };

// class MobileMessagerBase : public Messager{
//     public:
//     virtual void PlaySound(){
//         //**********
//     }
//    virtual void DrawShape(){
//        //********
//    }
//    virtual void WriteText(){
//         //********
//    }
//    virtual void Connect(){
//         //********
//    }
// };


//平台实现，这里就是实现了
class PCMessagerImpl : public MessagerImpl{
    public:
    virtual void PlaySound(){
        //**********
    }
   virtual void DrawShape(){
       //********
   }
   virtual void WriteText(){
        //********
   }
   virtual void Connect(){
        //********
   }
};

class MobileMessagerImpl : public MessagerImpl{
    public:
    virtual void PlaySound(){
        //**********
    }
   virtual void DrawShape(){
       //********
   }
   virtual void WriteText(){
        //********
   }
   virtual void Connect(){
        //********
   }
};



//业务实现 原来实现
// class MessagerLite {

//     //使用指针才能实现多态
//     Messager* messager; //new PCMessagerBase()这个是不成立的，
//                         // 为什么？ 因为这个PCMessagerBase 是一个抽象类
//                         //在C++里面叫做纯虚基类， 因为你只override了部分虚函数，
//                         // 另外一部分没有override。 该如何解决呢？
//                         // 应该将Messager里面的 虚函数拆分成两个类

//     public:
//     virtual void login(string userName, string password){
//         messager->Connect();
//         //.......
//     }
//    virtual void SendMessage(string message){
//        messager->WriteText();
//         //.......
//    }
//    virtual void SendPicture(){
//         messager->DrawShape();
//    }
   
// };

// 
// class MessagerPerfect{
//       //使用指针才能实现多态
//     Messager* messager;
//     public:
//     virtual void login(string userName, string password){
//         messager->PlaySound();
//         //******
//         messager->Connect();
//         //.......
//     }
//    virtual void SendMessage(string message){
//        messager->PlaySound();
//        //******
//        messager->WriteText();
//         //.......
//    }
//    virtual void SendPicture(){
//        messager->PlaySound();
//        //******
//        messager->DrawShape();
//         //.......
//    }
   
// };


//类的数目：2+n+m 
//业务实现 ，现在实现方式，组合MessagerImpl，并且继承Messager
class MessagerLite :public Messager{

    //使用指针才能实现多态
    //MessagerImpl* MessagerImpl;//指针，多态变化。。。灵活变化
    // 如果同样的类，的子类里面有相同的字段，那么就往基类里面 提上去
    // 所以将 MessagerImpl* MessagerImpl 放到 基类中取

    public:
    virtual void login(string userName, string password){
        MessagerImpl->Connect();
        //.......
    }
   virtual void SendMessage(string message){
       MessagerImpl->WriteText();
        //.......
   }
   virtual void SendPicture(){
        MessagerImpl->DrawShape();
   }
   
};


class MessagerPerfect:public Messager{
      //使用指针才能实现多态
    //   MessagerImpl* MessagerImpl;
    public:
    virtual void login(string userName, string password){
        messager->PlaySound();
        //******
        messager->Connect();
        //.......
    }
   virtual void SendMessage(string message){
       messager->PlaySound();
       //******
       messager->WriteText();
        //.......
   }
   virtual void SendPicture(){
       messager->PlaySound();
       //******
       messager->DrawShape();
        //.......
   }
   
};



//业务实现，不同平台上
//将平台的去掉，然后就可以看到PC的和Mobile的是一样的所以，就注释掉重复代码
// class MObileMessagerLite {
//     //使用指针才能实现多态
//     Messager* messager;

//     public:
//     virtual void login(string userName, string password){
//         messager::Connect();
//         //.......
//     }
//    virtual void SendMessage(string message){
//        messager::WriteText();
//         //.......
//    }
//    virtual void SendPicture(){
//         messager::DrawShape();
//    }
   
// };

// class MobileMessagerPerfect: public MobileMessagerBase{
//     public:
//     virtual void login(string userName, string password){
//         MobileMessagerBase::PlaySound();
//         //******
//         MobileMessagerBase::Connect();
//         //.......
//     }
//    virtual void SendMessage(string message){
//        MobileMessagerBase::PlaySound();
//        //******
//        MobileMessagerBase::WriteText();
//         //.......
//    }
//    virtual void SendPicture(){
//        MobileMessagerBase::PlaySound();
//        //******
//        MobileMessagerBase::DrawShape();
//         //.......
//    }
   
// };


//原来的方式
// void Process(){
//     //编译时装配
//     Messager *m = new MobileMessagerPerfect();
// }


void Process(){
    //动态装配
    MessagerImpl* mIpml = new PCMessagerImpl();
    Messager *m = new Messager(mIpml);
}