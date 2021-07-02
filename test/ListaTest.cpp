//
// Created by Marco De Stefano on 02/07/21.
//

#include "gtest.h"

#include "../Lista.h"

TEST(Lista, DefaultCostructor){
    Lista lst("Things_To_Travel");
    ASSERT_EQUAL("Things_To_Travel",lista.getNameOfList());
    ASSERT_EQUAL(0,lst.getNumOfElements());
    ASSERT_EQUAL(nullptr,lst.getObservers().begin());
    ASSERT_EQUAL(nullptr,lst.getLst().begin());
}

TEST(Lista, add_to_list){

}