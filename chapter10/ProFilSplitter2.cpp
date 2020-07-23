


//具体类，
class BinarySplitter: public ISplitter{
public:
   virtual ISplitter* clone(){
      //注意这个this。
      return new BinarySplitter(*this);
   }
};

class TxtSplitter: public ISplitter{
public:
   virtual ISplitter* clone(){
      return new TxtSplitter(*this);
   }
};


class PictureSplitter: public ISplitter{
public:
   virtual ISplitter* clone(){
      return new PictureSplitter(*this);
   }
};


