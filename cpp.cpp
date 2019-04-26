//#define LINUX

//#1.��˺�̰߳�ȫ�ĵ���ģʽ
#ifdef LINUX
class Singlton
{
private://˽�У�����
    static pthread_mutex_t mtx;//��̬������
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

//TODO:2.���������ʽת����
//ʹ��explicit�ؼ��ֽ������� 

//TODO:3.���أ���д�����ص�����
//���أ����������� 
//��д�����ǡ����������麯��
//���أ�ֻҪ������ĺ������������ͬ�ͻ����� 

//TODO:volatile��ʾʲô����ʲô���ã�
//�ױ�ģ����ᱻ�����������Ż����ó���ȡ����ֱ��ȥ�ڴ��еġ�

//#C/C++��������ѡ��
//gcc/g++ �� clang/clang++ ���� Linux �³��õ� C/C++ ������, ���ȼ���clang++>g++>msvc�����и�ICC

//#static_cast<>, dynamic_cast<>, const_cast<>, reinterpret_cast<>�ĸ������ú�ʹ�û�����
//static_cast������ɴ󲿷�ת�����ܣ����ǲ���ȷ����ȫ
//const_cast���޷��Ӹ�����ת�����ͣ������const������������const, ֻ�����ԭ������const, ����ͨ����ת�����������ָ������ö��ԡ�
//dynamic_cast����Ի����������ָ�������ת���������������֮�����Ҫ�̳й�ϵ���ǰ�ȫ��
//reinterpret_cast�������κ�ָ������תΪ����ָ�����ͣ��ǰ�ȫ��

//malloc��new������
//malloc��
//�ڴ�������ʱ������NULL��������һ���⺯���������ڴ�ĵط�Ϊ�ѣ�ֻ�����ڴ�ռ䣻��Ҫָ����������ڴ棻
//new��
//�ڴ�������ʱ���׳�bad_alloc�쳣�����Զ���set_new_handler�������ڲ����쳣ʱ���д���������һ���������
//�����ڴ�ĵط�Ϊ���ɴ洢����Ϊһ�������������ڶ�����ԣ����������ڴ�ռ�Ȼ����ù��캯��������ָ����С��

//free��delete������
//delete��
//������һ�������
//free��
//������һ���⺯��


//TODO:freeһ������ʱ���֪��Ҫ�ͷŶ����ڴ��أ�
//һ��������ǰ�漸���ֽ��д���ĳһ���ṹ�������浱ǰ����������С��

//TODO:__stdcall��__cdecl������
//__stdcall��
//��������ѹջ����ջ���������ɺ������������һ����ͨ�����ָ��ret x, x��ʾ����x���ֽڣ�����������ȷ����
//����Ϊ��������֪�������Դ˹ؼ��ֲ��������пɱ����Ӧ�õĺ���������
//__cdecl��
//��������ѹջ���ɵ��������Զ�ջ���ݽ�����������裺���÷����ú��� - ������ִ�� - ������������� - �����÷������ջ��������Ҫ��Կɱ����
