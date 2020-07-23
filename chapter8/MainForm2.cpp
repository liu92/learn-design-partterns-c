class MainForm2:public From{
  

   //3、将 工厂类放到这里
    SplitterFactory* factory; 

public:

   //构造器
   MainForm2(SplitterFactory* factory){
       this->factory = factory;
   }

 void Button1_Clic(){

 
    //1、
    // SplitterFactory* factory;
    //
    //  ISplitter * splitter = 
    //  factory.CreateSplitter();
    //  splitter->split();


    //2、 使用了虚函数的方式
    // SplitterFactory* factory; // 这里可以指定到具体工厂，但是不能直接写 因为直接写，那么就是具体依赖了
    //   ISplitter2 *splitter2 = 
    //  factory->CreateSplitter();
    //  splitter2->split();


   //4、在修改了之后，MainForm2没有对具体的类进行依赖，但是Factory在其他地方也会创建，那么也会产生依赖，
   // 不过这里 主要是MaForm 里面没有产生依赖 
     
      ISplitter2 *splitter2 = 
       factory->CreateSplitter(); //多态new ,使用虚函数
       splitter2->split();

    //5、MainForm只是依赖 ISplitter2和 SplitterFactory 。而不依赖具体类BinarySplitter   
 }   

}