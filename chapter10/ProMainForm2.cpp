class ProMainForm2:public From{

   //原型对象
    ISplitter* prototype; 

public:

   //构造器
   MainForm2(ISplitter* prototype){
       this->prototype = prototype;
   }

 void Button1_Clic(){
    ISplitter * splitter = prototype->clone();//克隆原型

   splitter->split();
 
 }   

}