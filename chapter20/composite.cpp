#include <iostream>
#include <list>
#include <string>
#include <algorithm>


using namespace std;

class Component{
  public:
    virtual void process() = 0;
    virtual ~Component(){}  
};

//树节点
class Composite:public Component{
   string name;
   list<Component*> elements;
 public:
    Composite(const string & s) : name(s){}

    void add(Component* element){
        elements.push_back(element);
    }  

    void remove(Component* element){
        elements.remove(elements);
    }

   // 重写父类
    void process(){
        //1. process current node
        
        //2. process leaf nodes

        //采用多态的方式 将树形结构的访问 封装在了树形结构的内部。而不是要不这个树形结构暴露出来。
        for (auto &e: elements)
        {
            // 递归
             //多态调用
             // 如果 这个e是 树节点那么就调用Composite
             // 如果 这个e是 叶子节点 那么就调用Leaf的 process方法
            e->process();
        }
        
    }
};

//叶子节点
class Leaf: public Component{
    string name;
  public: 
      Leaf(string s): name(s){}  

      void process(){
        //process current node
      }  
};

void Invoke(Component & c){
    //如果上面不使用多态的方式,那么这里就需要知道是Composite还是leaf
    c.process();
}

int main(){
    Composite root("root");
    Composite treeNode1("treeNode1");
    Composite treeNode2("treeNode2");
    Composite treeNode3("treeNode3");
    Composite treeNode4("treeNode4");
    Leaf leat1("left1");
    Leaf leat1("left2");

    root.add(&treeNode1);
    treeNode1.add(&treeNode2);
    treeNode2.add(&leat1);

    root.add(&treeNode3);
    treeNode3.add(&treeNode4);
    treeNode3.add(&leat2);

    process(root);
    
}