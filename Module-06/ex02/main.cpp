#include "main.hpp"

Base *generate(void)
{
    srand(time(0));
    int choice = rand() % 3;

    if (choice == 0) {
        std::cout << "Generating A type object." << std::endl;
        return new A();
    }
    else if (choice == 1) {
        std::cout << "Generating B type object." << std::endl;
        return new B();
    }
    else if (choice == 2) {
        std::cout << "Generating C type object." << std::endl;
        return new C();
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Identified type: A" << std::endl;
        return;
    } catch (const std::exception &) {}

    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Identified type: B" << std::endl;
        return;
    } catch (const std::exception &) {}

    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Identified type: C" << std::endl;
        return;
    } catch (const std::exception &) {}

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    Base *base = generate();
    // Base *base = new Base;
    if (base) {
        identify(base);
        identify(*base);
        delete base;
    } else {
        std::cout << "Failed to generate a Base type." << std::endl;
    }
    return 0;
}
