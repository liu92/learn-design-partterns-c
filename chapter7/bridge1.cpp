//在这个类里中存在很多重复的代码，并且

class Messager
{

public:
   virtual void login(string userName, string password)=0;
   virtual void SendMessage(string message)=0;
   virtual void SendPicture(Image image)=0;
   
   virtual void PlaySound()=0;
   virtual void DrawShape()=0;
   virtual void WriteText()=0;
   virtual void Connect()=0;

   virtual ~Messager(){}
};

//平台实现 ：假设平台实现这里列为n
class PCMessagerBase : public Messager{
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

class MobileMessagerBase : public Messager{
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

//业务抽象：假设这里列为m
// 那么类的个数：1+n+ m*n , 这里表示的意思是基类又1给，
// 而平台实现有n个，业务抽象有m个，那么n个平台类 业务抽象m,就有n*m。
class PCMessagerLite : public PCMessagerBase{
    public:
    virtual void login(string userName, string password){
        PCMessagerBase::Connect();
        //.......
    }
   virtual void SendMessage(string message){
       PCMessagerBase::WriteText();
        //.......
   }
   virtual void SendPicture(){
        PCMessagerBase::DrawShape();
   }
   
};

class PCMessagerPerfect: public PCMessagerBase{
    public:
    virtual void login(string userName, string password){
        PCMessagerBase::PlaySound();
        //******
        PCMessagerBase::Connect();
        //.......
    }
   virtual void SendMessage(string message){
       PCMessagerBase::PlaySound();
       //******
       PCMessagerBase::WriteText();
        //.......
   }
   virtual void SendPicture(){
       PCMessagerBase::PlaySound();
       //******
       PCMessagerBase::DrawShape();
        //.......
   }
   
};


//业务实现，不同平台上
class MobileMessagerLite : public MobileMessagerBase{
    public:
    virtual void login(string userName, string password){
        MobileMessagerBase::Connect();
        //.......
    }
   virtual void SendMessage(string message){
       MobileMessagerBase::WriteText();
        //.......
   }
   virtual void SendPicture(){
        MobileMessagerBase::DrawShape();
   }
   
};

class MobileMessagerPerfect: public MobileMessagerBase{
    public:
    virtual void login(string userName, string password){
        MobileMessagerBase::PlaySound();
        //******
        MobileMessagerBase::Connect();
        //.......
    }
   virtual void SendMessage(string message){
       MobileMessagerBase::PlaySound();
       //******
       MobileMessagerBase::WriteText();
        //.......
   }
   virtual void SendPicture(){
       MobileMessagerBase::PlaySound();
       //******
       MobileMessagerBase::DrawShape();
        //.......
   }
   
};

void Process(){
    //编译时装配
    Messager *m = new MobileMessagerPerfect();
}