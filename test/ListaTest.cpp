//
// Created by Marco De Stefano on 02/07/21.
//

#include "gtest/gtest.h"

#include "../Lista.h"


TEST(Lista, DefaultCostructor) {
    Lista lst("Things_To_Travel");
    EXPECT_EQ("Things_To_Travel", lst.getNameOfList());
    EXPECT_EQ(lst.num_product_in_list(), 0);
}

TEST(Lista, add_to_list) {
    Lista lst("Things_to_travel");
    CategoryProduct Item("Item");
    shared_ptr<Product> prod(new Product("Brush", Item));
    lst.add_to_list(prod, 2);
    EXPECT_EQ(lst.num_product_in_list(), 1);
    Lista lst1("Things_to_travel");
    EXPECT_THROW(lst1.add_to_list(prod, 0), std::invalid_argument);
    Lista lst2("Things_to_travel");
    EXPECT_THROW(lst2.add_to_list(prod, -1), std::invalid_argument);
}

TEST(Lista, remove_to_list) {
    Lista list("ThanksGiving's lunch");
    CategoryProduct Vegetables("Vegetables");
    CategoryProduct Meat("Meat");
    shared_ptr<Product> prod(new Product("Broccoli", Vegetables));
    list.add_to_list(prod, 3);
    EXPECT_EQ(list.num_product_in_list(), 1);
    shared_ptr<Product> prod1(new Product("Turkey", Meat));
    list.rem_to_list(prod, 2);
    EXPECT_EQ(list.num_product_in_list(), 1);
    list.rem_to_list(prod, 3);
    EXPECT_EQ(list.num_product_in_list(), 0);
    EXPECT_THROW(list.rem_to_list(prod1, 4), std::invalid_argument);
    EXPECT_THROW(list.rem_to_list(prod, 0), std::invalid_argument);
    EXPECT_THROW(list.rem_to_list(prod, -3), std::invalid_argument);
}

TEST(Lista, search_into_list) {
    Lista list("To Repare The Wall");
    CategoryProduct Tools("Tools");
    shared_ptr<Product> prod1(new Product("Drill", Tools));
    list.add_to_list(prod1, 1);
    EXPECT_EQ(list.num_product_in_list(), 1);
    EXPECT_TRUE(list.search_into_list(prod1));
}

TEST(Lista, num_product_in_list) {
    Lista list("ThanksGiving's lunch");
    CategoryProduct Vegetables("Vegetables");
    CategoryProduct Meat("Meat");
    EXPECT_EQ(list.num_product_in_list(), 0);
    shared_ptr<Product> prod(new Product("Broccoli", Vegetables));
    list.add_to_list(prod, 1);
    EXPECT_EQ(list.num_product_in_list(), 1);
}

TEST(Lista, num_product_in_list_bought) {
    Lista list("ThanksGiving's lunch");
    CategoryProduct Vegetables("Vegetables");
    CategoryProduct Meat("Meat");
    shared_ptr<Product> prod(new Product("Broccoli", Vegetables));
    list.add_to_list(prod, 2);
    EXPECT_EQ(list.num_product_in_list_bought(), 0);
    prod->setBought(true);
    EXPECT_EQ(list.num_product_in_list_bought(), 1);
}



