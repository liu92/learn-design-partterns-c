class Application: public Libaray{
    protected:
    virtual bool Step2(){
        //...子类重写实现
    }

    virtual void Step4(){
     //...子类重写实现
    }

};


int main(){

    Libaray* pLib = new Application();
    pLib->Run();
    delete pLib;
}