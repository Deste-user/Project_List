//
// Created by Marco De Stefano on 02/07/21.
//

#include "gtest/gtest.h"

#include "../Lista.h"



TEST(Lista, DefaultCostructor){
    Lista lst("Things_To_Travel");
    EXPECT_EQ("Things_To_Travel",lst.getNameOfList());
    //EXPECT_TRUE(lst.getLst().begin() == nullptr);
}

TEST(Lista, add_to_list){
Lista lst("Things_to_travel");
CategoryProduct Item("Item");
shared_ptr<Product> prod(new Product("Brush",Item));
lst.add_to_list(prod,2);
//EXPECT_TRUE(lst.getLst().begin()prod);
Lista lst1("Things_to_travel");
EXPECT_THROW(lst1.add_to_list(prod,0),std::invalid_argument);
Lista lst2("Things_to_travel");
EXPECT_THROW(lst2.add_to_list(prod,-1),std::invalid_argument);

}

TEST(Lista,remove_to_list){
Lista list("ThanksGiving's lunch");
CategoryProduct Vegetables("Vegetables");
CategoryProduct Meat("Meat");
shared_ptr<Product> prod (new Product("Broccoli",Vegetables));
list.add_to_list(prod,3);
shared_ptr<Product> prod1 (new Product("Turkey",Meat));
list.rem_to_list(prod,2);
EXPECT_EQ((*list.getLst().begin())->getQuantity(),1);
EXPECT_THROW(list.rem_to_list(prod1,4),std::invalid_argument);
EXPECT_THROW(list.rem_to_list(prod,0),std::invalid_argument);
EXPECT_THROW(list.rem_to_list(prod,-3),std::invalid_argument);
}



TEST(Lista, search_into_list){
Lista list("To Repare The Wall");
CategoryProduct Tools("Tools");
shared_ptr<Product> prod1 (new Product("Drill",Tools));
list.add_to_list(prod1,1);
EXPECT_EQ(list.search_into_list(prod1),true);

}



