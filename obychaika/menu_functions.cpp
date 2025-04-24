#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const BM::MenuItem* BM::show_menu(const MenuItem* current) {
    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];
}

const BM::MenuItem* BM::exit(const MenuItem* current) {
    std::exit(0);
}

const BM::MenuItem* BM::study(const MenuItem* current) {
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::study_proglangs(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::study_algotithms(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::study_other(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::study_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}




const BM::MenuItem* BM::databases(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::multithreaded(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::net(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const BM::MenuItem* BM::other_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}