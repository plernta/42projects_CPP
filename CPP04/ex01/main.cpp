#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    int numberOfAnimals = 4;
    int i = 0;

    Animal* animals[numberOfAnimals];
    while (i < numberOfAnimals)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        i++;
    }
    i = 0;
    while (i < numberOfAnimals)
    {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
        i++;
    }
    i = 0;
    while (i < numberOfAnimals)
    {
        delete animals[i];
        i++;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << BLUE << "Showing Deep copy of Dog." << RESET << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want to play");
    std::cout << "dog1: " << dog1.getBrain()->getIdea(0) << std::endl;

    Dog dog2(dog1);
    dog2.getBrain()->setIdea(0, "I want to sleep");
    std::cout << "dog2: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << BLUE << "Checking dog1's original idea." << RESET << std::endl;
    std::cout << "dog1: " << dog1.getBrain()->getIdea(0) << std::endl;

    std::cout << "dog1 brain address: " << dog1.getBrain() << std::endl;
    std::cout << "dog2 brain address: " << dog2.getBrain() << std::endl; // different
    std::cout << "----------------------------------------" << std::endl;
    // std::cout << BLUE << "Showing Shallow copy of Cat. ***This causes leak because brain is never deleted***" << RESET << std::endl;
    // Cat cat1;
    // cat1.getBrain()->setIdea(0, "I want to play");
    // std::cout << "cat1: " << cat1.getBrain()->getIdea(0) << std::endl;
    // Cat cat2(cat1);
    // cat2.getBrain()->setIdea(0, "I want to sleep");
    // std::cout << "cat2: " << cat2.getBrain()->getIdea(0) << std::endl;
    // std::cout << BLUE << "Checking cat1's original idea" << RESET << std::endl;
    // std::cout << "cat1: " << cat1.getBrain()->getIdea(0) << std::endl;

    // std::cout << "cat1 brain address: " << cat1.getBrain() << std::endl;
    // std::cout << "cat2 brain address: " << cat2.getBrain() << std::endl; // same
    // std::cout << "----------------------------------------" << std::endl;
    return 0;
}
