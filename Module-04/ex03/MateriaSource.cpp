#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "📚 MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    // std::cout << "📚 MateriaSource copy constructor called" << std::endl;
    *this = other;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    // std::cout << "📚 MateriaSource assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
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
    // std::cout << "📚 MateriaSource destructor called" << std::endl;
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
    // std::cout << "📚 MateriaSource learnMateria called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] == NULL)
        {
            templates[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // std::cout << "📚 MateriaSource createMateria called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return NULL;
}