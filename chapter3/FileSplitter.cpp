// 用它来表示一种抽象的通知机制
class IProgress {
public:
  virtual void DoProgress(float value)=0;
  // 虚析构函数：
  // 析构函数是在对象不被使用之后释放它的资源,虚函数是为了实现多态, 那么为什么要把析构函数声明为
  // virtual呢？有什么作用呢？ 在C++里面 基类采用virtual 虚析构函数是为了防止内存泄漏。具体来说,
  // 如果派生类中申请了内存空间,并在其析构函数中对这些内存空间进行释放。
  // 假设基类采用的是非虚析构函数,当删除基类指针指向的派生类对象时就不会触发动态绑定,因而只会调用基类
  //的析构函数，而不会调用派生类的析构函数。在这种情况下，
  // 派生类中申请的空间就得不到释放从而产生内存泄漏。 所以，为了防止这种情况的发生，在C++中基类的析构
  //函数应该采用virtual 虚析构函数。
  virtual ~IProgress(){}

}


//这个 就不依赖 具体的ProgressBar, 而是一个抽象的接口
class FileSplitter
{

 string m_filePath;
 int m_fileNumber;

  //原来的写法, 这个表示上传文件的进度条。
  //ProgressBar* m_progressBar;//具体通知控件

  //现在写法
  IProgress* m_iprogress; //抽象通知机制 ，只能接受一个

  // List<IProgress*> m_iprogressList;//抽象通知机制，支持多个观察者

public:
    FileSplitter(const string& filePath, int fileNumber,
    IProgress* iprogress ):

    m_filePath(filePath),
    m_fileNumber(fileNumber),
    m_iprogress(iprogress){

    }

//稳定部分：复用性，这个可以支持多个平台，不用和其他绑定死
// 多个观察者的方式,就不建议上述写法了 =====================
  //  FileSplitter(const string& filePath, int fileNumber ):
  //   m_filePath(filePath),
  //   m_fileNumber(fileNumber){
  //   }
 //多个观察者
// void add_IProgress(IProgress* iprogress){
  //   m_iprogressList.add(iprogress);
  // }

  //  void remove_IProgress(IProgress* iprogress){
  //   m_iprogressList.remove(iprogress);
  // }
  

//======================



    void split(){

        //1.读取大文件

        //2.分批次向小文件中写入

        for(int i=0; i< m_fileNumber; i++){
             float progressValue = m_fileNumber;
             progressValue = (i + 1) / progressValue;
                //  m_iprogress->DoProgress(progressValue);
               onProgress(progressValue); // 发送通知，不知道谁是观察者，
                                          // 不需要去指定一个具体的观察者。
                                           //是对整个通知机制进行抽象的控制
            // if(m_iprogress! = nullptr){
            //     m_iprogress->DoProgress((i+1)/m_fileNumber);//更新进度条
            // }
        }
    }





//稳定部分：复用性，这个可以支持多个平台，不用和其他绑定死

protected:
 void onProgress(float value){
     if(m_iprogress !=nullptr){
       m_iprogress->DoProgress(value); //更新进度条
     }

     //多个观察者
    //  List<IProgress*>::Iterator itor = m_iprogressList.begin();
    //  while (itor!=m_iprogressList.end())
    //  (*itor)->DoProgress(value);//更新进度条
    //  itor++;
  }
 };