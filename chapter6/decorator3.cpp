//第三版本就是有 中间类DecoatorStream。
class Stream
{
public:
  virtual char Read(int number) =0;
  virtual void Seek(int position) = 0;
  virtual void Write(char data)=0;

  virtual ~Stream(){}
};


//主体类，这些始终没有变化，他们时单独实行行为的。
//就是可以单独使用的，
//但是加密 必须传入一个流的对象
//  CryptoStream* c2 = new  CryptoStream(fs);
class FileStream: public Stream{
public: 
    virtual char Read(int number){

    }

    virtual void Seek(int position){

    }

    virtual void Write(char data){
      
    }
 
};



class NetWorkStream: public Stream{
public: 
    virtual char Read(int number){

    }

    virtual void Seek(int position){

    }

    virtual void Write(char data){
      
    }
 
};



class MemoryStream: public Stream{
public: 
    virtual char Read(int number){

    }

    virtual void Seek(int position){

    }

    virtual void Write(char data){
      
    }
 
};

//装饰着模式是附着在其他的操作上面的
// 扩展操作
class DecoatorStream: public Stream{
  //继承stream, 然后再组合stream
  protected:
  Stream* stream; //组合stream
  //构造器
 CryptoStream(Stream* stm):stream(stm){

 }
}




class CryptoStream:public DecoatorStream{
 //1、使用继承的方式，但是代码有很多重复的代码 

 //2、使用子类组合，这种方式是静态绑定的。
//  FileStream* stream;
 //当一个变量的类型都是其, 某个类型的子类的时候 那么就应该声明成 某个类型, 所以这里声明称其基类
// 3、 使用基类声明， 这种声明就是动态的去绑定, 也就是运行时去绑定不是编译的时候就帮定
//  Stream* stream; // =new FileStream

//4、当使用动态的绑定时，那么就可以减少很多重复代码


// 如果某个类它有多个子类都有同样的字段的时候，应该将这个网上提出来。这里如果在Stream类中在放入
//   Stream* stream;  但是像FileStream这种 它实现的时候，时不需要这个字段的。
// 所以：要设计一个中间类
//5、可以将  Stream* stream;  提取出来,一种是放到基类中去，但是放在基类中 它的子类不需要这给字段
// 所以应该设计一个中间类，来存放这个字段
// 这个就是Decoator(装饰者)


 public:

   //构造方法,然后成员初始化列表的方式
   CryptoStream(Stream* stm):stream(stm){

  }

  
   virtual char Read(int number){
     stream->Read(number);
   }

  
    virtual void Seek(int position){
       stream->Seek(position);
    }

    virtual void Write(char data){
      stream->Write(data);
    }  


};



class BufferedStream:public Stream{
   Stream* stream; //.....这个动态变化

public:

   //构造方法,然后成员初始化列表的方式
   BufferedStream(Stream* stm):stream(stm){

  }

}










void proccess(){

  //运行时装配
  FileStream* fs = new FileStream();
  CryptoStream* c2 = new  CryptoStream(fs);

}


//这里再写一个类来继承 这个基类，其实就是 为了接口规范
// 因为 下面的方法时 虚函数,那么为什么是虚函数
// 加上基类 是为了完善 下面  虚函数的接口规范
// 也就是 这个stream 为  CryptoFileStream1定义了 接口规范
// class CryptoFileStream1:public Stream{

//  Stream* stream; // =new FileStream

//  public:
//    virtual char Read(int number){
//      stream->Read(number);
//    }


// };






// class CryptoNetWorkStream{
//  NetWorkStream * stream;

// public:
//    virtual char Read(int number){
//      stream->Read(number);
//    }


// };

