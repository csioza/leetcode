//#define LINUX
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////////
const int * a = 0;
//const * int b = 0;    //err
int const * c = 0;
int * const d = 0;
const int * const e = 0;
//////////////////////////////////////////////////////////////////////////
//如何消除隐式转换？
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
//#C/C++编译器的选择
//gcc/g++ 和 clang/clang++ 都是 Linux 下常用的 C/C++ 编译器, 优先级是clang++>g++>msvc。还有个ICC

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
    virtual void f(){}
};
class Base2
{
public:
    int a2;
    virtual void f3() {}
};
class Der1: public virtual Base
{
public:
    int b;
    void virtual f() {}
    //void virtual f2() {}
};
class Der2: public virtual Base, public Base2
{
public:
    int c;
    void f() {}
    void virtual f2() {}
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
int main()
{
    Base d0;
    Der1 d1;
    Der2 d2;
    //Der3 d3;
    //d2.a = 1;
    //d2.b = 2;
    //d2.c = 3;
    int base = sizeof(Base);
    int der1 = sizeof(Der1);
    int der2 = sizeof(Der2);
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
class AA
{
public:
    //AA(int a):aa(a) {
    //    printf("\n11111111,%d",this);
    //}
    AA() /*:aa(2)*/ {
        //printf("\n22222222,%d,%d", aa, this);
    }
    ~AA() {
        //printf("\n44444444,%d,%d", aa,this);
    }
    //AA(AA &a) {
    //    aa = a.aa;
    //    printf("\n33333333,%d", this);
    //}
    void fun() {};
    void *operator new(size_t size, char caint)
    {
        void *tmp = malloc(size);
        memset(tmp, caint, size);
        printf("\noperator,%c", *(char *)tmp);
        return tmp;
    }
public:
    //int aa;
};
AA play(AA a)
{
    printf("\n66666666,%d", &a);
    return a;
}
int main66()
{
    AA *aaa = new('s') AA;
    printf("\n66666666,%c", *(char* )aaa);
    ///*AA bb =*/ play(2);
    //printf("\n55555555,%d", &bb);

    //aa.fun();
    //aab.fun();
    //aab.a;
    //int ss = sfun() + sjj;
    //int i = 5.01;
    //float f = 5;
    //printf("%1f\n", 5.01);
    //printf("%f\n", f);
    //printf("%d\n", 5.01);
    //printf("%d\n", i);
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
//实现一个vector？是1.5还是2倍，各有什么优缺点？
//1.5倍优势：可以重用之前分配并且释放的内存
//2倍劣势：每次申请的内存都不可以重用
//1，2，4，8，16，32，...
//可以看到到第三次resize(4)的时候，前面释放的总和只有1 + 2 = 3，到第四次resize(8)的时候前面释放的总和只有1 + 2 + 4 = 7，
//每次需要申请的空间都无法用到前面释放的内存。

//////////////////////////////////////////////////////////////////////////
//map底层用了什么？
//红黑树

////////////////////////////////////////////////////////////////////////////
//如果用map删除了一个元素，迭代器还能用吗？为什么？怎样做可以接着用？
//能用，a.erase(it++)；因为是直接申请的内存，所以可以直接通过获取后续节点来处理

//////////////////////////////////////////////////////////////////////////
//红黑树的特征是什么？
//（1）根节点为黑色
//（2）一个节点为红色，子节点必定为黑色
//（3）从任意一点触发到达每一个叶子节点的黑色节点个数相同
//（4）每一个节点不是红色就是黑色
//（5）每一个叶子节点都是黑色

//////////////////////////////////////////////////////////////////////////
//红黑树如何插入和删除的？
//插入：
//（1）如果父节点为黑色，直接插入不处理
//（2）如果父节点为红色，叔叔节点为红色，则父节点和叔叔节点变为黑色，祖先节点变为红色，将节点操作转换为祖先节点
//（3）如果当前节点为父亲节点的右节点，则以父亲结点为中心左旋操作
//（4）如果当前节点为父亲节点的左节点，则父亲节点变为黑色，祖先节点变为红色，以祖先节点为中心右旋操作
//删除：
//（1）先按照排序二叉树的方法，删除当前节点，如果需要转移即转移到下一个节点
//（2）当前节点，必定为这样的情况：没有左子树。
//（3）删除为红色节点，不需要处理，直接按照删除二叉树节点一样
//（4）如果兄弟节点为黑色，兄弟节点的两个子节点为黑色，则将兄弟节点变为红色，将着色转移到父亲节点
//（5）如果兄弟节点为红色，将兄弟节点设为黑色，父亲结点设为红色节点，对父亲结点进行左旋操作
//（6）如果兄弟节点为黑色，左孩子为红色，右孩子为黑色，对兄弟节点进行右旋操作
//（7）如果兄弟节点为黑色，右孩子为红色，则将父亲节点的颜色赋值给兄弟节点，将父亲节点设置为黑色，将兄弟节点的右孩子设为黑色，对父亲节点进行左旋

//////////////////////////////////////////////////////////////////////////
//红黑树和B + , B - 的区别？
//红黑树的深度比较大，而B + 和B - 的深度则相对要小一些，而B + 较B - 则将数据都保存在叶子节点，同时通过链表的形式将他们连接在一起。

//////////////////////////////////////////////////////////////////////////
//手写strcpy, memcpy, memmove函数？
//需要注意内存重叠问题

//////////////////////////////////////////////////////////////////////////
//Do{}while (0)的用法有哪些？
//（1）可以将语句当做一个独立的域
//（2）对于多语句可以正常的运行
//（3）可以有效的消除goto语句，达到跳转语句的效果

//////////////////////////////////////////////////////////////////////////
//手写快排？时间复杂度？空间复杂度？能进行优化吗？还有吗？能进行尾递归优化吗？
//最优时间复杂度：nlogn
//最差时间复杂度：n ^ 2
//平均时间复杂度：nlogn
//空间复杂度：logn->n
//优化：
//（1）随机
//（2）三数取中
//（3）当排序达到一定长度时用插入排序
//（4）分隔一次后，将相同数据不处理
//（5）使用并行或者多线程
//（6）进行尾递归优化【即将logn降解为更低的复杂度】

//////////////////////////////////////////////////////////////////////////
//C++分为内存分为哪几部分？
//堆；栈；静态全局；常量；自由存储区

//////////////////////////////////////////////////////////////////////////
//如果new申请内存失败了，如何去解决？如果让你实现一个new，你会怎么实现？
//如果申请失败可以通过set_new_handler来进行处理。
//实现：需要注意申请失败，如果相应的处理函数则调用，否则抛出bad_alloc异常

//////////////////////////////////////////////////////////////////////////
//如何得到一个结构体内成员的偏移量？
#define offsetof(type, number) ((size_t)&((type *)0)->number)

//手写如何通过一个结构体的成员变量得到一个结构体的地址？
#define container_of(ptr, type, number) ({ \
                                            const typeof(((type*)0)->number) * __mptr = (ptr);\
                                            (type*)((char*) __mptr - offsetof(type, number));\
                                         })
//////////////////////////////////////////////////////////////////////////
//构造函数能不能虚函数？为什么？那拷贝构造函数能不能为虚函数？为什么？
//不可以为虚函数，因为在调用构造函数时，虚表指针并没有在对象的内存空间中，必须要构造函数调用完成后才会形成虚表指针。
//拷贝构造函数是构造函数所以理由同上。

//////////////////////////////////////////////////////////////////////////
//析构函数能不能虚函数？为什么？
//可以为析构函数，没有为什么

//////////////////////////////////////////////////////////////////////////
//模板和实现可不可以不写在一个文件里面？为什么？
//只能写在一个一个头文件中。
//原因：多文件处理变为一个文件其实是通过链接器来实现的，所以如果用源文件来处理模板实现，会导致链接失效，
//最主要的原因还是在编译，编译器会暂时不处理模板类只有在实例化对象时才去处理，但是这就需要实现的代码了，
//如果放在其他文件的话，就会无法形成相应的类。

//////////////////////////////////////////////////////////////////////////
//为什么要字节对齐？
//（1）有些特殊的CPU只能处理4倍开始的内存地址
//（2）如果不是整倍数读取会导致读取多次
//（3）数据总线为读取数据提供了基础

//////////////////////////////////////////////////////////////////////////
//在成员函数中调用delete this会出现什么问题？对象还可以使用吗？
//如果当前内存空间真正被释放了再次调用成员函数会报错，调用成员变量好像没有问题。

//////////////////////////////////////////////////////////////////////////
//如果在构造函数中调用memset(this, 0, sizeof(*this))来初始化内存空间，有什么问题吗？
//对于有虚函数和虚表存在的类，在进行memset后不能调用虚函数和虚基表继承而来的数据和函数

//////////////////////////////////////////////////////////////////////////
//对一个数组而言，delete a和delete[] a有什么区别？为什么？
//对于基础数据类型没有什么区别，对于对象delete值调用一次析构函数，delete[]才会析构所有的东西。

//////////////////////////////////////////////////////////////////////////
//Dynamic_cast是如何实现运行时类型转换的？
//如果有些虚函数的话，会到对应的虚表中的RTTI去查找对应的类型来判断可不可以进行相应的转换。

//////////////////////////////////////////////////////////////////////////
//C语言调用C++语法函数怎么做？那C++调用C语法的函数怎么做？
//使用extern “C”来产生C语言环境编译的程序供外部使用。

//////////////////////////////////////////////////////////////////////////
//Extern “C”是什么意思？他有什么作用？
//表示当前声明需要用C语言环境进行编译。

//////////////////////////////////////////////////////////////////////////
//Struct{ char a[0]; }的作用？有什么好处？
//充当可变缓冲区的作用，同时char a[0]不占用内存空间。

//////////////////////////////////////////////////////////////////////////
//如何判断两个浮点数相等？
//需要考虑浮点误差

//////////////////////////////////////////////////////////////////////////
//浮点数为什么会有误差？
//因为二进制无法精准的表示十进制小数，0.3和0.2都无法完整的用二进制表示。
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
//https://www.nowcoder.com/discuss/57978
//////////////////////////////////////////////////////////////////////////
//栈上分配内存和堆上分配内存有什么区别？
//栈上：分配简单，只需要移动栈顶指针，不需要其他的处理
//堆上：分配复杂，需要进行一定程度清理工作，同时是调用函数处理的。

//////////////////////////////////////////////////////////////////////////
//变量的存储方式有哪些？
//auto，extern，register，static

//////////////////////////////////////////////////////////////////////////
//什么是类型安全？能举例吗？
//两个类型直接进行转换，必须是显式的，string和STL模板是类型安全的

//////////////////////////////////////////////////////////////////////////
//虚函数表是在什么时候确定的？那虚表指针呢？
//编译时确定虚函数表，虚表指针则是运行时

//////////////////////////////////////////////////////////////////////////
//如何检查内存泄露？如果不通过printf, debug等调试方式和编译器报错提示呢？
//使用GDB调试器

//////////////////////////////////////////////////////////////////////////
//int(*f(int, void(*)()))(int, int)是什么意思？
//一个函数，参数为int和指向返回值为void的无参数的函数指针，返回值为一个指向返回值为int，参数为int和int的函数指针

//////////////////////////////////////////////////////////////////////////
//STL空间配置器如何处理内存的？能说一下它的大概实现方案吗？为什么是8bytes的倍数？
//分为两部分：大于128bytes用malloc直接申请，小于128bytes则使用一个8bytes倍数的数组来进行申请。
//为8bytes的原因是为了提高效率，同时对于64位的机器而言，地址大小为8bytes

//////////////////////////////////////////////////////////////////////////
//静态函数能定义为虚函数吗？为什么？
//不可以，因为虚函数属于对象，不属于类

//////////////////////////////////////////////////////////////////////////
//静态函数能定义为常函数吗？为什么？
//不可以，因为常函数是操作成员变量的，而静态函数没有成员变量可说

//////////////////////////////////////////////////////////////////////////
//C++中有哪些机制可以取代宏？
//inline，typedef, const

//////////////////////////////////////////////////////////////////////////
//对于默认处理的结构体，能用memcmp来进行比较吗？为什么？如果不能，该如何比较？
//不能，因为字节对齐多出来的内存是随机的，必须要一个个成员比较

//////////////////////////////////////////////////////////////////////////
//手写一个有可变参数的函数？
//使用va_list，va_start，va_arg，va_end。
//也可以用宏定义##__VA_ARGS__，可以针对空参数消除逗号

//////////////////////////////////////////////////////////////////////////
//系统调用与函数调用的区别？
//（1）一个在用户地址空间执行；一个在内核空间执行
//（2）一个是过程调用，开销小；一个需要切换用户空间和内核上下文，开销大
//（3）一般相同；不同系统不同
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//this指针调用成员变量时，堆栈会发生什么变化？
//将相应的参数从右往左压栈，然后将this指针放到寄存器中

//////////////////////////////////////////////////////////////////////////
//实现一个shared_ptr类和auto_ptr类？
//Shared_ptr则是引用计数处理，auto_ptr则是权限转移机制

//////////////////////////////////////////////////////////////////////////
//下面这两个函数在执行过程中有什么区别？
//int f(string&a); f("abc");//报错
//int f(const string&a); f("abc");//正常

//////////////////////////////////////////////////////////////////////////
//C++中可以继承string类吗？为什么？
//不可以，因为string不是类

//////////////////////////////////////////////////////////////////////////
//char * const *(*next)()是什么？
//next是一个指针，指向一个函数，这个函数返回一个指针，这个指针指向char类型的常量指针

//////////////////////////////////////////////////////////////////////////
//如何判断const所修饰的对象？
//const只修饰其后的【变量】，至于const放在类型前还是类型后并没有区别

//////////////////////////////////////////////////////////////////////////
//vector<vector<int> > dp(n, vector<int>(m));
//int* *dp = new int*[n];
//for (int i = 0; i < n; i++)
//    dp[i] = new int[m];
//////////////////////////////////////////////////////////////////////////
//extern
static int sjj = 8;
extern int ejj = 9;
int sfun()
{
    return 0;
}
//////////////////////////////////////////////////////////////////////////
//    cout << A::aa << a.aa << A::bb() << a.bb() << a.aa << endl;
//    printf("\n%d,%d,%d,%d,%d", A::aa, a.aa, A::bb(), a.bb(), a.aa);