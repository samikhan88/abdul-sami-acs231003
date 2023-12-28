#include <iostream>

// Abstract base class Animal
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function
};

// Concrete derived classes
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

class Bird : public Animal {
public:
    void makeSound() override {
        std::cout << "Chirp!" << std::endl;
    }
};

int main() {
    Animal* animals[] = {new Dog(), new Cat(), new Bird()};

    for (Animal* animal :animals) {
        animal->makeSound(); // Polymorphic call to makeSound()
    }

    // Properly deallocate memory
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
