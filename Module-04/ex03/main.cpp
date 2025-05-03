#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void subjectPdfExample();
void materiasourcetest();
void materiatest();
void charactertest();

int main()
{
    // comment out the tests you don't want to run
    subjectPdfExample();
    materiasourcetest();
    materiatest();
    charactertest();

    return 0;
}

void charactertest()
{
    // Test Character
    std::cout << "== Character Test ==" << std::endl;
    Character *me = new Character("hoobird");
    IMateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    AMateria *tmp;
    tmp = source->createMateria("ice");

    me->equip(tmp);
    me->equip(tmp); // should not be able to equip the same materia
    tmp = source->createMateria("cure");
    me->equip(tmp);
    tmp = source->createMateria("ice");
    me->equip(tmp);
    tmp = source->createMateria("cure");
    me->equip(tmp);
    tmp = source->createMateria("cure");
    me->equip(tmp);

    delete me;
    delete source;
    delete tmp;
}

void materiatest()
{
    // Test Materia
    std::cout << "== Materia Test ==" << std::endl;
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();
    AMateria *ice2 = ice->clone();
    AMateria *cure2 = cure->clone();
    ICharacter *dummy = new Character("dummy");

    std::cout << "ice type: " << ice->getType() << std::endl;
    ice->use(*dummy);
    std::cout << "cure type: " << cure->getType() << std::endl;
    cure->use(*dummy);
    std::cout << "ice2 type: " << ice2->getType() << std::endl;
    ice2->use(*dummy);
    std::cout << "cure2 type: " << cure2->getType() << std::endl;
    cure2->use(*dummy);

    delete ice;
    delete cure;
    delete ice2;
    delete cure2;
    delete dummy;
    std::cout << std::endl;
}

void materiasourcetest()
{
    // Test MateriaSource
    std::cout << "== MateriaSource Test ==" << std::endl;
    IMateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    // last one should not be learned and no leaks

    IMateriaSource *frostysource = new MateriaSource();
    ICharacter *olaf = new Character("Olaf");
    ICharacter *falo = new Character("Falo");
    frostysource->learnMateria(new Ice());
    frostysource->learnMateria(new Ice());
    frostysource->learnMateria(new Ice());
    frostysource->learnMateria(new Ice());
    AMateria *tmp = frostysource->createMateria("ice");
    olaf->equip(tmp);
    AMateria *tmp2 = frostysource->createMateria("cure"); // no exist
    if (tmp2 == 0)
        std::cout << "Cure not found" << std::endl;

    *source = *frostysource;               // test assignment operator
    tmp2 = source->createMateria("cure"); // also cannot, same reason
    if (tmp2 == 0)
        std::cout << "Cure not found too too" << std::endl;

    // unequip
    AMateria *tmp3 = frostysource->createMateria("ice");
    olaf->equip(tmp3);
    olaf->use(1, *falo);
    olaf->unequip(1);

    // delete all
    delete source;
    delete frostysource;
    delete olaf;
    delete falo;
    delete tmp2;
    delete tmp3;
    std::cout << std::endl;
}

void subjectPdfExample()
{
    std::cout << "== Subject Example ==" << std::endl;

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    std::cout << "tmp getType: " << tmp->getType() << std::endl;
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;
}