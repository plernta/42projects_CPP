#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base* generate(void){
	std::srand(std::time(0));
	int	random = rand() % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else if (random == 2)
		return new C;
	return (NULL);
}

void identify(Base* p){
	if(dynamic_cast<A*>(p))
		std::cout << "A [pointer]" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B [pointer]" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C [pointer]" << std::endl;
}

void identify(Base& p){
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A [reference]" << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B [reference]" << std::endl;
		return;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C [reference]" << std::endl;
		return;
	}
	catch (std::exception &e) {}
}

int	main(){
	Base* no_name = generate();
	identify(no_name);
	identify(*no_name);
	delete(no_name);
}