//#define LINUX
#include <string>
//#include "tool.cpp"
//////////////////////////////////////////////////////////////////////////
//#1.手撕线程安全的单例模式
#ifdef LINUX
class Singlton
{
private://私有，考点
    static pthread_mutex_t mtx;//静态，考点
    static Singlton* instance;
    Singlton() {}
    ~Singlton() {}
public:
    static Singlton* getInstance()
    {
        if (instance == NULL)
        {
            pthread_mutex_lock(mtx);
            if (instance == NULL)
                instance = new Singlton();
            pthread_mutex_unlock(mtx);
        }
        return instance;
    }
};
pthread_mutex_t Singlton::mtx = PTHREAD_MUTEX_INITIALIZER;//# define PTHREAD_MUTEX_INITIALIZER { { 0, 0, 0, 0, 0, 0, { 0, 0 } } }
Singlton* Singlton::instance = NULL;
#endif

//////////////////////////////////////////////////////////////////////////
//TODO:2.如何消除隐式转换？
//使用explicit关键字进行修饰 

//////////////////////////////////////////////////////////////////////////
//TODO:3.重载，重写和隐藏的区别？
//重载：即函数重载 
//重写【覆盖】：即用于虚函数
//隐藏：只要派生类的函数名与基类相同就会隐藏 

//////////////////////////////////////////////////////////////////////////
//TODO:volatile表示什么？有什么作用？
//易变的，不会被编译器进行优化，让程序取数据直接去内存中的。

//////////////////////////////////////////////////////////////////////////
//#C/C++编译器的选择
//gcc/g++ 和 clang/clang++ 都是 Linux 下常用的 C/C++ 编译器, 优先级是clang++>g++>msvc。还有个ICC

//////////////////////////////////////////////////////////////////////////
//#static_cast<>, dynamic_cast<>, const_cast<>, reinterpret_cast<>的各自作用和使用环境？
//static_cast：能完成大部分转换功能，但是并不确保安全
//const_cast：无法从根本上转变类型，如果是const，它就依旧是const, 只是如果原对象不是const, 可以通过此转换来处理，针对指针和引用而言。
//dynamic_cast：针对基类和派生类指针和引用转换，基类和派生类之间必须要继承关系，是安全的
//reinterpret_cast：允许将任何指针类型转为其他指针类型，是安全的

//////////////////////////////////////////////////////////////////////////
//malloc和new的区别？
//malloc：
//内存分配错误时，返回NULL；本身是一个库函数；分配内存的地方为堆；只申请内存空间；需要指定申请多大的内存；
//new：
//内存分配错误时，抛出bad_alloc异常，可以定义set_new_handler函数来在产生异常时进行处理；本身是一个运算符；
//分配内存的地方为自由存储区【为一个抽象概念】；对于对象而言，会先申请内存空间然后调用构造函数；无需指定大小。

//////////////////////////////////////////////////////////////////////////
//free和delete的区别？
//delete：
//本身是一个运算符
//free：
//本身是一个库函数

//////////////////////////////////////////////////////////////////////////
//TODO:free一个数组时如何知道要释放多大的内存呢？
//一般在数组前面几个字节中存在某一个结构体来保存当前申请的数组大小。

//////////////////////////////////////////////////////////////////////////
//TODO:__stdcall和__cdecl的区别？
//__stdcall：
//从右往左压栈，堆栈参数数据由函数本身清除，一般是通过汇编指令ret x, x表示弹出x个字节，参数必须是确定，
//必须为函数本身知晓，所以此关键字不能用于有可变参数应用的函数声明。
//__cdecl：
//从右往左压栈，由调用者来对堆栈数据进行清除，步骤：调用方调用函数 - 》函数执行 - 》函数结果返回 - 》调用方清除堆栈参数，主要针对可变参数

//////////////////////////////////////////////////////////////////////////
//linux内部提供了那些调试宏？
//__FILE__：表示在哪个文件
//__LINE__：表示在当前多少行
//__FUNCTION__：表示在执行在哪个函数

//////////////////////////////////////////////////////////////////////////
//引用和指针的区别？
//指针：是一个变量类型；指针可以不进行初始化；指针初始化后可以改变，在写代码时需要大量的检测
//引用：是一个别名；引用必须要初始化；引用初始化后不可改变，无需检测

//////////////////////////////////////////////////////////////////////////
//TODO:出现异常时，try和catch做了什么？
//Catch(Ep a)发生异常 - 》建立一个异常对象 - 》拷贝一个异常对象 - 》catch处理
//Catch(Ep &a)发生异常 - 》建立一个异常对象 - 》引用异常对象 - 》catch处理
//异常对象通常建立在全局或者堆中【需要在函数外进行捕捉】
//Catch捕捉异常的转换：异常处理时，如果用基类的处理派生类的对象会导致派生类完全当做基类来使用，即便有虚函数也没用，所以派生类必须放在基类前处理。

//////////////////////////////////////////////////////////////////////////
//C++如何处理多个异常的？
//多次catch处理

//////////////////////////////////////////////////////////////////////////
//TODO:常对象的成员变量一定不可以修改吗？为什么？
//可以修改，用mutable来修饰，可以突破const的限制。

//////////////////////////////////////////////////////////////////////////
//TODO:虚函数的调用过程？
//找到对象内存中vfptr所指向虚函数表的地址 - 》找到虚函数表相应的虚函数地址

//////////////////////////////////////////////////////////////////////////
//汇编层面：
//Mov ecx, dword ptr[ebp - 0ch]将this指针放进ecx
//Mov edx, dword ptr[ecx]将虚表的地址放进edx
//Call dword ptr[edx + 4]：调用虚表中函数
//虚函数放置顺序与声明顺序一样，成员变量也是
//虚表中放的不是函数的入口地址，而是一个jmp跳转指令的地址

//////////////////////////////////////////////////////////////////////////
//TODO:单继承，多继承，菱形继承，虚继承时，对象内存中的差异区别？如果存在虚函数呢？
//单继承：
class EmptyClass
{
    //virtual int f() 
    //{ 
    //    int a = 1;
    //    a += a;
    //    return a;
    //}
    /*virtual*/ int f2()
    {
        int a = 1;
        a += a;
        return a;
    }
    //int c;
    //char a;
    static int b;
};
int EmptyClass::b = 0;

class Base
{
public:
    int a;
    int f;
    int fr;
    ////int m;
    ////std::string l = "a";
    //long long a2;
    //int a1;
    //int a42;
    //int a3;
    //int m0;
    //virtual void f(){}
};
class Der1: public virtual Base
{
public:
    int b;
    int c;
    int d;
    //int mz;
    //void f() {}
};
class Der2: public /*virtual*/ Base
{
public:
    int c;
    //void f() {}
};
class Der3 : public Base
{
public:
    //int b;
    //void f() {}
};
class Der4 : public virtual EmptyClass
{
public:
    //int b;
    //void f() {}
};
class Der5 : public virtual Der2
{
public:
    int b;
    //void f() {}
};
//https://blog.csdn.net/xiejingfa/article/details/48028491
int main1()
{
    Der1 d1;
    Der2 d2;
    //Der3 d3;
    //d2.a = 1;
    //d2.b = 2;
    //d2.c = 3;
    int base = sizeof(Base);
    int der1 = sizeof(Der1);
    //int der2 = sizeof(Der2);
    //int p1 = 0;
    //int p2 = 0;
    //int *p1 = NULL;
    //int *p2 = NULL;
    //int *pp1 = &p1;
    //int *pp2 = &p2;
    //int s4 = sizeof(EmptyClass);
    //int s5 = sizeof(Der3);
    //int s6 = sizeof(d1);
    //int s7 = sizeof(d2);
    //int s8 = sizeof(d3);
    //int s9 = sizeof(Der4);
    //int s10 = sizeof(Der5);
    return 0;
}

class A
{
public:
    int a;
    virtual void f() {}
    //virtual void f2() {}
    //void f4() { printf("a"); }
};
class B: public /*virtual*/ A
{
public:
    int b;
    /*virtual*/ void f() {}
    //void f4() { printf("c"); }
};
class C: public virtual A
{
public:
    int c;
    /*virtual*/ void f() {}
    //virtual void f3() {}
    //void f4() { printf("c"); }
};
class D : public C
{
public:
    int d;
    /*virtual*/ void f() {}
};

int max1(int x, int y)
{
    return x > y ? x : y;
}
int main39()
{
    //D d;
    //A a;
    //B b;
    //C c;
    //int sa = sizeof(A);
    //int sb = sizeof(B);
    //int sc = sizeof(C);
    //int sd = sizeof(D);
    //int d1 = sizeof(d);
    //A *aa = new B;
    {
        char *str[] = { "wel","topyu","fortem","nanjing" };
        char **p = str + 1;
        str[0] = (*p++) + 2;
        str[1] = *(p + 1);
        str[2] = p[1] + 3;
        str[3] = p[0] + (str[2] - str[1]);
    }

    int(*p[2])(int,int);
    int max1(int,int);
    p[0] = max1;
    int ret = (p[0])(3,2);
    return 0;
}

char * getm()
{
    char p[] = "hello";
    return p;
}
char * getm2()
{
    char *p = "hello";
    return p;
}
int main22()
{
    int i = 0;
    int ii = 0;
    char * p = getm2();
    printf("%s,%s,%d,%d,%d,%d", getm(), p,getm2,&i,&ii,&p);
    return 0;
}
extern int ejj;
extern int sjj=8;
extern int sfun();
int main()
{
    int ss = sfun() + sjj;
    int i = 5.01;
    float f = 5;
    printf("%f\n", 5);
    printf("%1f\n", 5.01);
    printf("%f\n", f);
    printf("%d\n", 5.01);
    printf("%d\n", i);
    return 0;
}
//成为虚函数的条件：
//1.要能取地址
//2.依赖对象调用

//构造函数 不可以 系统调用 不依赖对象调用
//析构函数 可以
//内联函数 不可以 不能取地址 函数在调用点直接展开
//static函数 不可以 无this指针 不依赖对象调用

//虚函数表：
//第一行：RTTL（run time type information）运行时类型信息
//第二行：虚函数指针的偏移
//第三行：虚函数的入口地址
//虚表的写入时机 构造函数的执行之前

//////////////////////////////////////////////////////////////////////////
//空类型不包含任何信息，按理来说它的sizeof应该是0。但是，要考虑的是当我们声明该类型的实例的时候，
//它必须在内存中占有一定的空间，否则它就是不存在的而无法使用这些实例。
//因此，具体在内存中占用的空间大小是多少由编译器确定，在vs中一个空类型的实例占用1字节的空间。

//1、栈区（stack）:由编译器自动分配释放，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
//2、堆区（heap）:一般由程序员分配释放，若程序员不释放，程序结束时可能由OS回收。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表。
//3、全局区（静态区）（static）:全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。- 程序结束后由系统释放。
//4、文字常量区:常量字符串就是放在这里的。程序结束后由系统释放
//5、程序代码区:存放函数体的二进制代码。

//函数占的空间不在sizeof里，而在代码区里
//静态成员占的空间不在sizeof里，而在全局区里

//////////////////////////////////////////////////////////////////////////
//实现一个vector？是1.5还是2倍，各有什么优缺点？
//1.5倍优势：可以重用之前分配并且释放的内存
//2倍劣势：每次申请的内存都不可以重用
//1，2，4，8，16，32，...
//可以看到到第三次resize(4)的时候，前面释放的总和只有1 + 2 = 3，到第四次resize(8)的时候前面释放的总和只有1 + 2 + 4 = 7，
//每次需要申请的空间都无法用到前面释放的内存。
//////////////////////////////////////////////////////////////////////////
//https://www.nowcoder.com/discuss/57978
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////