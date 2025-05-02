#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "⚗️ MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    // std::cout << "⚗️ MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
    *this = other;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    // std::cout << "⚗️ MateriaSource assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (templates[i] != NULL)
                delete templates[i];
            templates[i] = NULL;
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
        }
    }
    return *this;
}
MateriaSource::~MateriaSource()
{
    // std::cout << "⚗️ MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i])
        {
            delete templates[i];
            templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    // std::cout << "⚗️ MateriaSource learnMateria called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] == NULL)
        {
            std::cout << "⚗️ MateriaSource learned " << m->getType() << std::endl;
            templates[i] = m;
            return;
        }
    }
    delete m; // delete the materia if not learned cuz leak
    std::cout << "⚗️ MateriaSource is full, cannot learn more materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // std::cout << "⚗️ MateriaSource createMateria called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] && templates[i]->getType() == type) {
            std::cout << "⚗️ Materia created: " << type << std::endl;
            return templates[i]->clone();
        }
    }
    std::cout << "⚗️ unknown type " << type << std::endl;
    return 0;
}