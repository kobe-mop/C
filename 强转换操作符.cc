dynamic_cast主要用于“安全地向下转型”

dynamic_cast用于类继承层次间的指针或引用转换。主要还是用于执行“安全的向下转型（safe downcasting）”，
也即是基类对象的指针或引用转换为同一继承层次的其他指针或引用。至于“先上转型”（即派生类指针或引用类型转换为其基类类型），本身就是安全的，
尽管可以使用dynamic_cast进行转换，但这是没必要的， 普通的转换已经可以达到目的，毕竟使用dynamic_cast是需要开销的。

#include <iostream>
using namespace std;
class Base
{
public:
    Base(){};
    virtual void Show(){cout<<"This is Base calss";}
};
class Derived:public Base
{
public:
    Derived(){};
    void Show(){cout<<"This is Derived class";}
};
int main()
{    
    Base *base ;
    Derived *der = new Derived;
    //base = dynamic_cast<Base*>(der); //正确，但不必要。
    base = der; //先上转换总是安全的
    base->Show(); 
    system("pause");
}

对于“向下转型”有两种情况。
一种是基类指针所指对象是派生类类型的，这种转换是安全的；  //等同于java中的多态 Base b = new Derived()
另一种是基类指针所指对象为基类类型，在这种情况下dynamic_cast在运行时做检查，转换失败，返回结果为0；

#include<iostream>
using namespace std;

class Base
{
public:
    Base(){};
    virtual void Show(){cout<<"This is Base calss";}
};
class Derived:public Base
{
public:
    Derived(){};
    void Show(){cout<<"This is Derived class";}
};
int main()
{    
    //这是第一种情况
    Base* base = new Derived;
    if(Derived *der= dynamic_cast<Derived*>(base))
    {
        cout<<"第一种情况转换成功"<<endl;
        der->Show();
        cout<<endl;
    }
    //这是第二种情况
    Base * base1 = new Base;
    if(Derived *der1 = dynamic_cast<Derived*>(base1))
    {
        cout<<"第二种情况转换成功"<<endl;
        der1->Show();
    }
    else 
    {
        cout<<"第二种情况转换失败"<<endl;
    }

    delete(base);
    delete(base1);
    system("pause");
}


3.1派生类指针到基类指针用隐式类型转换(直接赋值)或者用 static_cast. 显然不应该也没必要用 reinterpret_cast.
3.2基类指针到派生类指针用 dynamic_cast (运行期检查)或者 static_cast (运行期不检查,由程序员保证正确性). 考虑到C++对象模型的内存分布可能引起的指针偏移问题,绝对不能用 reinterpret_cast.
3.3static_cast 运算符完成*相关类型*之间的转换. 而 reinterpret_cast 处理*互不相关的类型*之间的转换.
3.4 void* 到任意类型指针, 用 static_cast 和 reinterpret_cast 都可以,这是由 void* 是通用指针这个语义决定的.我个人倾向用 reinterpret_cast,表达要"重新解释"指针的语义.

3.5 不同类型指针间的相互转换用 reinterpret_cast.

3.6 int 型和指针类型间的相互转换用 reinterpret_cast.
struct car
{
    int doors;
    int height;
    int length;
    float weight; 
};

int create_car()
{
    car *c = new car;
    return reinterpret_cast<int>(c);
}

int get_car_doors(int car_id)
{
    car *c = reinterpret_cast<car*>(car_id);
    return c->doors;
}

void destroy_car(int car_id)
{
    car *c = reinterpret_cast<car*>(car_id);
    delete c;
}

如上,外部函数不需要知道 struct car 的具体定义,只需要调用 create_car() 得到一个 car id,然后用此 car_id 调用其他相关函数即可,至于 car_id 是什么,根本没必要关心.
