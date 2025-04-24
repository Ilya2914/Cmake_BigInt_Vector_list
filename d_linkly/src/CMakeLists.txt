target_sources(linkly_lib
    PRIVATE
        doubly_linked_list.cpp
    PUBLIC
        doubly_linked_list.hpp
)
target_include_directories(linkly_lib PUBLIC
         "${PROJECT_SOURCE_DIR}/src"


)




