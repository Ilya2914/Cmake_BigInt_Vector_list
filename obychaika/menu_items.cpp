#include "menu_items.hpp"
#include <cstddef>
#include "menu_functions.hpp"

const BM::MenuItem BM::DATABASES = {
    "1 - Базы данных", BM::databases, &BM::STUDY_OTHER
};
const BM::MenuItem BM::MULTITHREADED = {
    "2 - Многопоточное программирование", BM::multithreaded, &BM::STUDY_OTHER
};
const BM::MenuItem BM::NET = {
    "3 - Сетевые технологии", BM::net, &BM::STUDY_OTHER
};
const BM::MenuItem BM::OTHER_GO_BACK = {
    "0 - Выйти в предидущее меню", BM::other_go_back, &BM::STUDY_OTHER
};

namespace {
    const BM::MenuItem* const other_children[] = {
        &BM::OTHER_GO_BACK,
        &BM::DATABASES,
        &BM::MULTITHREADED,
        &BM::NET
    };
    const int other_size = sizeof(other_children) / sizeof(other_children[0]);
}


const BM::MenuItem BM::STUDY_PROGLANGS = {
    "1 - Изучать языки программирования", BM::study_proglangs, &BM::STUDY
};
const BM::MenuItem BM::STUDY_ALGORITHMS = {
    "2 - Алгоритмы и структуры", BM::study_algotithms, &BM::STUDY
};
const BM::MenuItem BM::STUDY_OTHER = {
    "3 - Другие технологии", BM::show_menu, &BM::STUDY, other_children, other_size
};
const BM::MenuItem BM::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", BM::study_go_back, &BM::STUDY
};

namespace {
    const BM::MenuItem* const study_children[] = {
        &BM::STUDY_GO_BACK,
        &BM::STUDY_PROGLANGS,
        &BM::STUDY_ALGORITHMS,
        &BM::STUDY_OTHER
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const BM::MenuItem BM::STUDY = {
    "1 - Изучать программирование", BM::show_menu, &BM::MAIN, study_children, study_size
};
const BM::MenuItem BM::EXIT = {
    "0 - Пойти играть в футбол", BM::exit, &BM::MAIN
};

namespace {
    const BM::MenuItem* const main_children[] = {
        &BM::EXIT,
        &BM::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const BM::MenuItem BM::MAIN = {
    nullptr, BM::show_menu, nullptr, main_children, main_size
};
