#pragma once

#include "menu.hpp"

namespace BM {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);
    const MenuItem* study(const MenuItem* current);

    const MenuItem* study_proglangs(const MenuItem* current);
    const MenuItem* study_algotithms(const MenuItem* current);
    const MenuItem* study_other(const MenuItem* current);
    const MenuItem* study_go_back(const MenuItem* current);

    const MenuItem* databases(const MenuItem* current);
    const MenuItem* multithreaded(const MenuItem* current);
    const MenuItem* net(const MenuItem* current);
    const MenuItem* other_go_back(const MenuItem* current);
}
