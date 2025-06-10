#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    std::cout << "------------------------" << std::endl;
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* wj = new WrongCat();
    meta2->makeSound();
    wj->makeSound();
    delete wj;
    delete meta2;
    std::cout << "------------------------" << std::endl;
    return 0;
}