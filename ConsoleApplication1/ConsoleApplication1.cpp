#include <iostream>

void openChest(int* gold, int* chest) {
    *gold += *chest;
    *chest = 0;
}

void trapDamage(int* hp, int damage) {
    *hp -= damage;
    if (*hp < 0) {
        *hp = 0;
    }
}

void swapChests(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void printArray(const int* arr, int size) {
    std::cout << "Chests: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int* findRichestChest(int* arr, int size) {
    if (size <= 0) {
        return nullptr;
    }

    int* richest = arr;

    for (int i = 1; i < size; i++) {
        if (arr[i] > *richest) {
            richest = &arr[i];
        }
    }

    return richest;
}

int main() {
    int hp = 100;
    int gold = 0;
    int chests[5] = { 10, 0, 25, 50, 5 };

    std::cout << "start HP:" << std::endl;
    std::cout << "HP: " << hp << ", Gold: " << gold << std::endl;
    printArray(chests, 5);
    std::cout << std::endl;

    openChest(&gold, &chests[0]);
    std::cout << "chest 10 gold:" << std::endl;
    std::cout << "HP: " << hp << ", Gold: " << gold << std::endl;
    printArray(chests, 5);
    std::cout << std::endl;

    trapDamage(&hp, 15);
    std::cout << "trap (-15 HP):" << std::endl;
    std::cout << "HP: " << hp << ", Gold: " << gold << std::endl;
    printArray(chests, 5);
    std::cout << std::endl;

    int* richest = findRichestChest(chests, 5);
    std::cout << "most expensive chest have : " << *richest << " gold" << std::endl;
    std::cout << std::endl;

    swapChests(&chests[1], &chests[3]);
    std::cout << "swap 2 and 4 chest:" << std::endl;
    printArray(chests, 5);
    std::cout << std::endl;

    richest = findRichestChest(chests, 5);
    openChest(&gold, richest);
    std::cout << "open most expensive chest:" << std::endl;
    std::cout << "HP: " << hp << ", Gold: " << gold << std::endl;
    printArray(chests, 5);
}