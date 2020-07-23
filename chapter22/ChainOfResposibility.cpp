#include <iostream>
#include <string>

using namespace std;

enum class RequestType{
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};

//具体负责请求的 
class Requset{
  string description;
  RequestType reqType;
public:
   Requset(const string  & desc, RequestType type): description(desc), reqType(type);
   RequestType getReqType() const {return reqType;}
   const string & getDescription() const{return description;}
 
};

//具体的处理者，或者接受者
class ChainHandler{
    ChainHandler *nextChain; //多态的指针，多态链表

    void sendReqestToNextHandler(const Request & req){
        //如果下一个节点不空，那么就把这个请求让下一个节点 处理
        if(nextChain != nullptr){
             nextChain ->handle(req);
        }
    }
protected:
    virtual bool canHandleRequest(const Request & req) = 0;
    virtual void processRequest(const Request & req) = 0;

public:
     ChainHandler() {nextChain = nullptr;}
     void setNextChain(ChainHandler *next){ nextChain = next;}

    //整体的一个处理逻辑
     void handle(const Requset & req){
         //如果当前的对象能够处理，那么就请求就去处理。
         if(canHandleRequest(req)){
             processRequest(req);
         }else
         {
              //如果处理不了，那么就下一个链表节点来处理
            sendReqestToNextHandler(req);
         }
         
     } 
};

class Handler1: public ChainHandler{
  protected:
     bool canHandleRequest(const Requset & req) override
     {
         return req.getReqType() == RequestType::REQ_HANDLER1;
     }  


     void processRequest(const Requset & req) override
     {
         cout << "Handler1 is hanlde request: " << req.getDescription << endl;
     }
};

class Handler2: public ChainHandler{
  protected:
     bool canHandleRequest(const Requset & req) override
     {
         return req.getReqType() == RequestType::REQ_HANDLER2;
     }  


     void processRequest(const Requset & req) override
     {
         cout << "Handler2 is hanlde request: " << req.getDescription << endl;
     }
};

class Handler3: public ChainHandler{
  protected:
     bool canHandleRequest(const Requset & req) override
     {
         return req.getReqType() == RequestType::REQ_HANDLER3;
     }  


     void processRequest(const Requset & req) override
     {
         cout << "Handler3 is hanlde request: " << req.getDescription << endl;
     }
};


int main{
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);

    Requset req("process task ...", RequestType:: REQ_HANDLER3);
    h1.handle(req);
    return 0;
}