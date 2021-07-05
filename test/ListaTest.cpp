//
// Created by Marco De Stefano on 02/07/21.
//

#include "gtest.h"

#include "../Lista.h"



TEST(Lista, DefaultCostructor){
    Lista lst("Things_To_Travel");
    EXPECT_EQUAL("Things_To_Travel",lista.getNameOfList());
    EXPECT_EQUAL(0,lst.getNumOfElements());
    ASSERT_EQUAL(nullptr,lst.getObservers().begin());
    ASSERT_EQUAL(nullptr,lst.getLst().begin());
}

TEST(Lista, add_to_list){
Lista lst("Things_to_travel");
Product *prod(new Product("Brush","Item"));
lst.add_to_list(prod,2);
EXPECT_EQUAL(lst.getLst().begin(),prod);
Lista lst1("Things_to_travel");
EXPECT_THROW(lst1.add_to_list(prod,0),std::invalid_argument);
Lista lst2("Things_to_travel");
EXPECT_THROW(lst2.add_to_list(prod,-1),std::invalid_argument);

}

TEST(Lista,remove_to_list){
Lista list("ThanksGiving's lunch");
Product* prod (new Product("Broccoli","Vegetables"));
list.add_to_list(prod,3);
Product* prod1 (new Product("Turkey","Meat"));
list.rem_to_list(prod,2);
EXPECT_EQUAL((*list.getLst().begin())->getQuantity(),1);
EXPECT_THROW(list.rem_to_list(prod1,4),std::invalid_argument);
EXPECT_THROW(list.rem_to_list(prod,0),std::invalid_argument);
EXPECT_THROW(list.rem_to_list(prod,-3),std::invalid_argument);
}



TEST(Lista, search_into_list){
Lista list("To Repare The Wall");
Product* prod1 (new Product("Drill","Tools"));
list.add_to_list(prod1,1);
EXPECT_EQUAL(list.search(prod1),true);
EXPECT_THROW(list.search_into_list(nullptr),std::invalid_argument);
}



