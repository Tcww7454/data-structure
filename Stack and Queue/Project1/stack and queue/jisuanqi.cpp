#include <cmath>
#include <string>
#include <iostream>
using namespace std;
template<class T> class Stack;
template<class T>
class Node {
private:
    T m_data;//数据域
    Node* m_next = nullptr;//指针域
public:
    Node(const T& val) {
        this->m_data = val;
    }	//有参构造
    Node& operator=(const Node& rhs) = delete;	//禁止赋值
    friend class Stack<T>;	//声明友元
};//创建结点

template<class T>
class Stack {
private:
    Node<T>* m_top = nullptr;//创建头结点
public:
    Stack() = default;//默认构造函数
    Stack(const Stack&) = delete;//抑制复制
    Stack& operator=(const Stack&) = delete;//抑制复制
    ~Stack() {
        clear();
        this->m_top = nullptr;
    }//析构函数

    void clear() {
        Node<T>* p = nullptr;
        while (this->m_top != nullptr) {
            p = this->m_top;
            this->m_top = this->m_top->m_next;
            delete p;
        }
    }//清栈函数

    void push(const T& val) {
        Node<T>* node = new Node<T>(val);
        node->m_next = this->m_top;
        this->m_top = node;
    }//入栈函数

    void pop() {
        if (empty()) { return; }
        Node<T>* p = this->m_top;
        this->m_top = this->m_top->m_next;
        delete p;
    }//出栈函数

    bool empty()const { return this->m_top == nullptr; }//判断是否为空

    const T& top() {
        return this->m_top->m_data;
    }//访问头指针数据

};//创建栈

class Calculator {
private:
    Stack<double> m_num;//用于存放数字
    Stack<char> m_opr;//用于存放运算符
    int precedence(const char& input)const;//判断优先级
    double readNum(string::const_iterator& it);//读出数字
    char readOpr(string::const_iterator& it);//读出运算符
    void calculate();//弹出数字和运算符计算
    bool isNum(string::const_iterator& c)const {
        return *c >= '0' && *c <= '9' || *c == '.';
    }    //判断是否为数字

public:
    ~Calculator() {
        this->m_num.clear();
        this->m_opr.clear();
    }    //析构函数
    Calculator() { this->m_opr.push('#'); }    //初始化
    double doIt(const string& exp);    //计算算式函数
};

int Calculator::precedence(const char& input)const {
    switch (input) {
    case'=':return 0;
    case'#':return 1;
    case'+':case'-':return 2;
    case'*':case'/':case'%':return 3;
    case's':case'c':case't':case'r':return 4;
    case'^':return 5;
    default: return 1;
    }
}    //判断优先级
double Calculator::readNum(string::const_iterator& it) {
    string t;
    if (*it == 'p' && *(it + 1) == 'i') {
        return atan(1.0) * 4;
    }    //判断是否为pi

    while (isNum(it) || *it == '.') {
        t += *it++;
    }
    while (isspace(*it)) {
        ++it;     // 跳过空格
    }
    return stod(t);    //将字符串转换为double存入
}/    /读出数字

char Calculator::readOpr(string::const_iterator & it) {
    string t1;
    string t2;
    t1 = *it;    //第一个字母
    t2 = *(it + 1);//第二个字母
    while (isspace(*it)) {
        ++it;     // 跳过空格
    }
    if (t1 == "s" && t2 == "i") {
        //cout << "获取sin";
        return 's';
    }    //sin
    else if (t1 == "c") {
        return 'c';
    }    //cos
    else if (t1 == "t") {
        return 't';
    }    //tan
    else if (t1 == "s" && t2 == "q") {
        return 'r';
    }//sqrt
}    //读出运算符


void Calculator::calculate() {
    if (this->m_num.empty()) {
        return;
    }
    double rightnum = this->m_num.top();    //取出右边的运算数
    this->m_num.pop();    //从栈中弹出取出的运算数
    switch (this->m_opr.top())
    {
    case's':
        this->m_num.push(sin(rightnum));
        break;
    case'c':
        this->m_num.push(cos(rightnum));
        break;
    case't':
        this->m_num.push(tan(rightnum));
        break;
    case'r':
        this->m_num.push(sqrt(rightnum));
        break;
    default://判断是否为一目运算不为则往下进行
        double leftnum = this->m_num.top();//取出左边的运算数
        //cout << "弹出二次数:" << this->m_num.top();
        this->m_num.pop();//从栈中弹出取出的运算数
        if (this->m_opr.top() == '+') {
            this->m_num.push(leftnum + rightnum);
        }
        else if (this->m_opr.top() == '-') {
            this->m_num.push(leftnum - rightnum);
        }
        else if (this->m_opr.top() == '*') {
            this->m_num.push(leftnum * rightnum);
        }
        else if (this->m_opr.top() == '/') {
            this->m_num.push(leftnum / rightnum);
        }
        else if (this->m_opr.top() == '%') {
            this->m_num.push(static_cast<int>(leftnum) % static_cast<int>(rightnum));
        }
        else if (this->m_opr.top() == '^') {
            this->m_num.push(pow(leftnum, rightnum));
        }
        break;
    }
    this->m_opr.pop();    //从栈中弹出取出的运算符
}    //运算函数

double Calculator::doIt(const string& exp) {
    this->m_num.clear();    //清除栈
    for (auto it = exp.begin(); it != exp.end();) {
        while (isspace(*it)) {
            ++it;     // 跳过空格
        }
        if (isNum(it) || *it == 'p') {
            this->m_num.push(readNum(it));
            if (*it == 'p') {
                ++it;
                ++it;
            }    //若为pi则跳过i的循环
        }//先判断是否为数字
        else if (*it == '(') {
            this->m_opr.push(*it);
            ++it;
        }//判断是否在括号里
        else if (*it == ')') {
            while (this->m_opr.top() != '(') {
                calculate();
            }
            this->m_opr.pop();//弹出"("结束括号内的运算
            ++it;
        }//若遇到")"则持续进行运算直到运算符栈顶为"("
        else {
            while (precedence(*it) <= precedence(this->m_opr.top())) {
                if (this->m_opr.top() == '#') {
                    break;
                }
                calculate();
            }//
            if (*it != '=' && *it != 's' && *it != 'c' && *it != 't') {
                this->m_opr.push(*it);//将普通运算符入栈
            }
            else {
                if (*it == 's' || *it == 'c' || *it == 't') {
                    this->m_opr.push(this->readOpr(it));
                    if (this->readOpr(it) == 'r') {
                        ++it;
                    }//若为sqrt则需要多跳一位
                    ++it;
                    ++it;
                }//入栈后跳出该字符的判断
            }//将特殊运算符入栈
            ++it;
        }
    }
    return this->m_num.top();//遍历后返回数据栈数据，得到结果
}

int main()
{
    string a = "3-2*4+(6-1)/2+5=";
    string b = "sin(pi/6)=";
    Calculator cal;
    double c = cal.doIt(a);
    double d = cal.doIt(b);
    cout << "第一个结果是:" << c << endl << "第二个结果是:" << d << endl;

}

​