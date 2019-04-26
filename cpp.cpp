//#define LINUX

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

//TODO:2.如何消除隐式转换？
//使用explicit关键字进行修饰 

//TODO:3.重载，重写和隐藏的区别？
//重载：即函数重载 
//重写【覆盖】：即用于虚函数
//隐藏：只要派生类的函数名与基类相同就会隐藏 

//TODO:volatile表示什么？有什么作用？
//易变的，不会被编译器进行优化，让程序取数据直接去内存中的。

//#C/C++编译器的选择
//gcc/g++ 和 clang/clang++ 都是 Linux 下常用的 C/C++ 编译器, 优先级是clang++>g++>msvc。还有个ICC

//#static_cast<>, dynamic_cast<>, const_cast<>, reinterpret_cast<>的各自作用和使用环境？
//static_cast：能完成大部分转换功能，但是并不确保安全
//const_cast：无法从根本上转变类型，如果是const，它就依旧是const, 只是如果原对象不是const, 可以通过此转换来处理，针对指针和引用而言。
//dynamic_cast：针对基类和派生类指针和引用转换，基类和派生类之间必须要继承关系，是安全的
//reinterpret_cast：允许将任何指针类型转为其他指针类型，是安全的

//malloc和new的区别？
//malloc：
//内存分配错误时，返回NULL；本身是一个库函数；分配内存的地方为堆；只申请内存空间；需要指定申请多大的内存；
//new：
//内存分配错误时，抛出bad_alloc异常，可以定义set_new_handler函数来在产生异常时进行处理；本身是一个运算符；
//分配内存的地方为自由存储区【为一个抽象概念】；对于对象而言，会先申请内存空间然后调用构造函数；无需指定大小。

//free和delete的区别？
//delete：
//本身是一个运算符
//free：
//本身是一个库函数


//TODO:free一个数组时如何知道要释放多大的内存呢？
//一般在数组前面几个字节中存在某一个结构体来保存当前申请的数组大小。

//TODO:__stdcall和__cdecl的区别？
//__stdcall：
//从右往左压栈，堆栈参数数据由函数本身清除，一般是通过汇编指令ret x, x表示弹出x个字节，参数必须是确定，
//必须为函数本身知晓，所以此关键字不能用于有可变参数应用的函数声明。
//__cdecl：
//从右往左压栈，由调用者来对堆栈数据进行清除，步骤：调用方调用函数 - 》函数执行 - 》函数结果返回 - 》调用方清除堆栈参数，主要针对可变参数
