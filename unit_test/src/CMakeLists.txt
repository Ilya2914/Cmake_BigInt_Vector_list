target_sources(bubble_sort_lib
    PRIVATE
        main.cpp
        io.cpp
        sortings.cpp
    PUBLIC
        io.hpp
        sortings.hpp
)
target_include_directories(bubble_sort_lib PUBLIC
         "${PROJECT_SOURCE_DIR}/src"


)


