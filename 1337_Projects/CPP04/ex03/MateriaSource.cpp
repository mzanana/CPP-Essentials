#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
	while (i < 4)
	{
        materias[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    int i = 0;
	while (i < 4)
	{
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
		i++;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
		int i = 0;
        while (i < 4)
        {
            delete materias[i];
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
			i++;
		}
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
	int i = 0;
    while (i < 4)
	{
        delete materias[i];
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return;
    int i = 0; 
	while(i < 4)
    {
        if (materias[i] == NULL)
        {
            materias[i] = materia;
            return;
        }
		i++;
    }
    delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
	while (i < 4)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
		i++;
	}
    return NULL;
}