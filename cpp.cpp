//#define LINUX
//1.手撕线程安全的单例模式
#ifdef LINUX
class Singlton
{
private:
    static pthread_mutex_t mtx;
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

    