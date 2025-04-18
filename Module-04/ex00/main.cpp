#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "<< Constructing animals in Zoo 🐾 >>" << std::endl;
    const Animal *annie = new Animal();
    const Animal *doggy = new Dog();
    const Animal *kitty = new Cat();
    std::cout << std::endl;

    std::cout<< "annie->getType() ➡️  " << annie->getType() << std::endl;
    std::cout << "doggy->getType() ➡️  " << doggy->getType() << std::endl;
    std::cout << "kitty->getType() ➡️  " << kitty->getType() << std::endl;
    std::cout << std::endl;

    std::cout << "annie->makeSound() ➡️  ";
    kitty->makeSound();
    std::cout << "doggy->makeSound() ➡️  ";
    doggy->makeSound();
    std::cout << "kitty->makeSound() ➡️  ";
    kitty->makeSound();
    std::cout << std::endl;

    std::cout << "⚠️ Wtf is going on ⚠️" << std::endl;
    const WrongAnimal *wrongDog = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << std::endl;
    
    std::cout << "wrongDog->getType() ➡️  " << wrongDog->getType() << std::endl;
    std::cout << "wrongCat->getType() ➡️  " << wrongCat->getType() << std::endl;
    std::cout << std::endl;
   
    std::cout << "wrongDog->makeSound() ➡️  ";
    wrongDog->makeSound();
    std::cout << "wrongCat->makeSound() ➡️  ";
    wrongCat->makeSound();
    std::cout << std::endl;

    std::cout << "<< Deconstructing animals in Zoo >>" << std::endl;
    delete annie;
    delete doggy;
    delete kitty;
    std::cout << std::endl;

    return 0;
}