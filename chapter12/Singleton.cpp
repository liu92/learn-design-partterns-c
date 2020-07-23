class Singleton{
    private:
      Singleton();
      Singleton(const Singleton& other);
    public:
      static Singleton* getInstance();
      static Singleton* m_instance;  
};

Singleton* Singleton::m_instance = nullptr;

//非线程安全版本
Singleton* Singleton::getInstance(){
  if(m_instance == nullptr){
      m_instance = new Singleton();
  }

  return m_instance;
}

//线程安全版本

Singleton* Singleton::getInstance(){
    Lock lock;
    if(m_instance == nullptr){
        m_instance = new Singleton();
    }

    return m_instance;
}


//双检查锁，但由于内存读写reoder不安全
Singleton* Singleton::getInstance(){
    if(m_instance == nullptr){
        Lock lock;
        //这种方式会出现，
        // 1、先分配内存
        // 2、初始化构造器
        // 3、将上面做完的操作的返回值， 赋值给 m_instance
        // 上面三种的顺序会 出现错乱 ，在多线程情况下，如果一个线程执行到 这个判断时候
        // 以及分批了内存，但是另外一个线程执行到第一个 判断时候，m_instance不等于 nullptr。
        // 那么就会执行 return 操作。但是实际上这个构造器还没有初始化完。
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
    }
    return m_instance;
}


//c++ 11版本之后的跨平台实现(volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance(){
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
    if(tmp == nullptr){

        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if(tmp == nullptr){
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;

}