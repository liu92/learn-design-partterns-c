#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Expression{

public: 
    virtual int interpreter(map<char, int> var) = 0;
    virtual ~Expression(){}    
};

//变量表达式
class VarExpression: public Expression{
    char key;
public:
    VarExpression(const char& key){
        this->key = key;
    }  

    int interpreter(map<char, int> var) override{
        //如果是变量表达式 就取key的值就可以了
        //如果下面 中a、b。
        return var[key];
    }
};


//符号表达式
//如果下面的 + 、- 符合
class SymbolExpression:public Expression{
   //运算符左右两个参数
protected:
    Expression* left;
    Expression* right;
public:
    //   +
    // a   b
    // 其中的a表示左子树，b表示右子树
    SymbolExpression(Expression* left, Expression* right):
      left(left), right(right){

      }    

};

//加法运算
class  AddExpression: public SymbolExpression{

public:
    AddExpression(Expression* left, Expression* right):
        SymbolExpression(left, right){
        }

    int interpreter(map<char, int> var){
        return left->interpreter(var) + right->interpreter(var);
    }    
};


//减法运算
class  SubExpression: public SymbolExpression{

public:
    SubExpression(Expression* left, Expression* right):
        SymbolExpression(left, right){
        }

    int interpreter(map<char, int> var){
        return left->interpreter(var) + right->interpreter(var);
    }    
};

//针对一个字符串 解析得到一个表达式
Expression* analyse(string expStr){

    stack<Expression*> expStack;
    Expression* left = nullptr;
    Expression* right = nullptr;
    for (size_t i = 0; i < expStr.size(); i++)
    {   
        //当i=0,第一个元素进来时，是a 那么就调用default 
        //将这元素加入 push到栈中去。
        // 当i=1是，那么就进入到 第一个case操作中，
       
        switch (expStr[i])
        {
        case '+':
             //加法运算
             //进入到这个"+" 表达式中，首先从这个栈中拿出元素 a。
             // 取处理之后 再 ++i， 因为i=1。然后++i =2。 那么取2的元素
             //  就会取到b这个元素。所以right =b ,left =a;
             //  再将 这个结构 加入到栈中去。
             left = expStack.top();
             right = new VarExpression(expStr[++i]);
             expStack.push(new AddExpression(left, right));
            break;
        case '-':
             //减法运算
             //当继续操作时，首先将栈中结构 取处理 ，这个结构是"a+b"它是整个 left

             // 再 ++i ,取出来c 
             left = expStack.top();
             right = new VarExpression(expStr[++i]);
             //然后push一个 减法的表达式 
             expStack.push(new SubExpression(left, right));
            break;
        default:
            //变量表达式
            expStack.push(new VarExpression(expStr[i]));
        }
    }

    Expression* expression = expStack.top();

    return expression;
    
}

void release(Expression* expression){
    //释放表达式树的节点内存。。。
}


int main(int argc, const char * argv[]){
    // a+b 构成一般表达式
    //整个构成一个树表达式。
    string expStr = "a+b-c+d";
    map<char, int> var;
    var.insert(make_pair('a',5));
    var.insert(make_pair('b',2));
    var.insert(make_pair('c',1));
    var.insert(make_pair('d',6));

    Expression* expression = analyse(expStr);

    int result = expression->interpreter(var);

    cout<<result<<endl;
    release(expression);

    return 0;
}
