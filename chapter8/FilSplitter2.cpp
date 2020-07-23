


//具体类，
class BinarySplitter: public ISplitter1{

};

class TxtSplitter: public ISplitter1{

};


class PictureSplitter: public ISplitter1{

};


//具体工厂


class BinarySplitterFactory: public SplitterFactory{
public:
   virtual ISplitter2* CreateSplitter(){
      return new BinarySplitter();
   }

};

class TxtSplitterFactory: public SplitterFactory{
public:
   virtual ISplitter2* CreateSplitter(){
      return new TxtSplitter();
   }
};


class PictureSplitterFactory: public SplitterFactory{
public:
   virtual ISplitter2* CreateSplitter(){
      return new PictureSplitter();
   }
};