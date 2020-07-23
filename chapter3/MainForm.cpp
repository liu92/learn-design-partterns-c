//C++ 中有多继承，
//但是推荐的是 一个是主的继承类，其它都是接口，或抽象基类
class MainForm: public Form, public IProgress
{
   TextBox* txtFilePath;
   TextBox* txtFileNumber;

   ProgressBar* progressBar;

public:
   void Button1_Click(){

       string filePath = txtFilePath->getText();
       int number = atoi(txtFileNumber->getText().c_str());

       //this 就是当前mainForm的指针， 这个对象也是实现了IProgress接口
       FileSplitter splitter(filePath, number, this);
       
       //多个观察者
      // FileSplitter splitter(filePath, number);
      // splitter.addIProgress(this);  定义通知
      // splitter.addIProgress(&cn);
        

       splitter.split();
   }

   virtual void DoProgress(float value){
       progressBar ->setValue(value);
   }
}
