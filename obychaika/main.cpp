#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

int main() {
    std::setlocale(LC_ALL, "");

    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;

    const BM::MenuItem* current = &BM::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}
