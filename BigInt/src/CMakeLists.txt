target_sources(big_int_lib
    PRIVATE
        bigint.cpp
    PUBLIC
        bigint.hpp
)
target_include_directories(big_int_lib PUBLIC
         "${PROJECT_SOURCE_DIR}/src"


)




