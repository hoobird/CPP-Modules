#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    static Singleton& getInstance();

    void doSomething();

private:
    Singleton();
    ~Singleton();

    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    static Singleton* instance;
};
Singleton* Singleton::instance = 0;


#endif