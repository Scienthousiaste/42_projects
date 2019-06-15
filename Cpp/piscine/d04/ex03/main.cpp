#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	Character* zaz = new Character("zaz");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	ICharacter* bob = new Character("bob");
	zaz->use(0, *bob);
	zaz->use(1, *bob);

	std::cout << "XP for materia cure in bob's purse after one use: "
		<< zaz->getMateriaIndex(1)->getXP() << std::endl;
	zaz->unequip(1);
	zaz->use(1, *bob); //do nothing because 
	zaz->equip(tmp);
	zaz->use(1, *bob); //cure again
	std::cout << "XP for materia cure in bob's purse after 2 uses: "
		<< zaz->getMateriaIndex(1)->getXP() << std::endl;


	AMateria* tmp2 = src->createMateria("cure");
	AMateria* tmp3 = src->createMateria("ice");
	AMateria* tmp4 = src->createMateria("ice");
	zaz->equip(tmp2);
	zaz->equip(tmp3);
	zaz->equip(tmp4);


	delete bob;
	delete zaz;
	delete src;
	return 0;
}
