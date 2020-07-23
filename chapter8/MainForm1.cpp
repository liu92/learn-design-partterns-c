class MainForm:public From{
   TextBox* txtFilePath;
   TextBox* txtFileNumber;
   ProgressBar* progressBar;

public:
 void Button1_Clic(){

     string filePath = txtFilePath->getText();
     int number =atoi(txtFileNumber ->getText().c_str());

    //new BinarySplitter 是依赖具体类，导致了紧耦合
     ISplitter * splitter = new BinarySplitter(filePath, number);
     splitter->split();
 }   

}