#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "io.hpp"
#include "sortings.hpp"

TEST(ArraysEqual, AnyElementsCount){
    int actual[]={1,8,2,5,3,11};
    biv::sortings::bubble_sort(actual,6);
    std::vector<int>expected={1,2,3,5,8,11};
    
    ASSERT_EQ(6,6)
    <<"difrent size";
    for(int i=0;i<6;i++){
        ASSERT_EQ(expected[i],actual[i])
        <<"array before and after are diffrent"
        <<i;
    }
    
    
}

int main(int argc,char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
