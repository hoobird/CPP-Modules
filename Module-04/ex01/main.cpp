#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void deleteAnimals(int n, const Animal *animals[]);
void shallowTest();
void populateZoo(int n, const Animal *animals[]);

int main()
{
    int n = 1000;

    std::cout << "<< Constructing animals and the Zoo >>" << std::endl;
    const Animal *zoo[n];

    populateZoo(n, zoo);
    std::cout << std::endl;

    // Test for shallow copy
    shallowTest();

    std::cout << std::endl;
    std::cout << "<< Deconstructing animals in Zoo >>" << std::endl;
    deleteAnimals(n, zoo);
    std::cout << std::endl;
    return 0;
}

void shallowTest()
{
    std::cout << "<< Shallow copy test >>" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    dog1.compareDog(dog2);
    std::cout << std::endl;

    Cat cat1;
    Cat cat2(cat1);
    cat1.compareCat(cat2);
    std::cout << std::endl;
}

void populateZoo(int n, const Animal *animals[])
{
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
}

void deleteAnimals(int n, const Animal *animals[])
{
    for (int i = 0; i < n; i++)
    {
        delete animals[i];
    }
}
