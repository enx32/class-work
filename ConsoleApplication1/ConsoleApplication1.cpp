#include <iostream>

void takeDamage(int* hp, int damage);
void heal(int* hp, int amount);
void printHp(const int* hp);
bool isAlive(const int* hp);

void takeDamage(int* hp, int damage) {
    if (*hp > 0) {
        *hp -= damage;
    }
}
void heal(int* hp, int amount) {
    if (*hp + amount <= 100) {
        *hp += amount;
    }
}
void printHp(const int* hp) {
    std::cout << "HP posle = " << *hp << std::endl;
}

bool isAlive(const int* hp) {
    if (*hp > 0) {
        std::cout << "player alive" << std::endl;
        return true;
    }
    else {
        std::cout << "player die, game over" << std::endl;
    }
    return false;
}


int main()
{
    std::cout << "player in dungeon" << std::endl;
    int hp = 100;
    std::cout << "HP = " << hp << std::endl;
    std::cout << "goblin attack = 30" << std::endl;
    takeDamage(&hp, 30);
    printHp(&hp);
    std::cout << "igrok piet zelie" << std::endl;
    heal(&hp, 20);
    printHp(&hp);
    isAlive(&hp);
}

