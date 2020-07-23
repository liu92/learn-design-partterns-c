class ISplitter1{

public:


   virtual void split)=0;
   virtual  ~ISplitter1(){}

};


class BinarySplitter: public ISplitter1{

};

class TxtSplitter: public ISplitter1{

};


class PictureSplitter: public ISplitter1{

};


