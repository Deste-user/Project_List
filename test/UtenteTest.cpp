//
// Created by Marco De Stefano on 05/07/21.
//
#include "gtest/gtest.h"
#include "../Utente.h"

TEST(Utente, DefaultCostructor) {
    Utente utente("Paolo");
    EXPECT_EQ(utente.getNameOfUtente(), "Paolo");
    EXPECT_EQ(utente.num_of_list(), 0);
}

TEST(Utente, CreateList) {
    Utente utente("Paolo");
    utente.create_list("Spesa");
    EXPECT_TRUE(utente.search_name_list("Spesa"));
    EXPECT_EQ(utente.num_of_list(), 1);
}

TEST(Utente, AddList) {
    Utente utente("Paolo");
    shared_ptr<Lista> list(new Lista("Nonna"));
    utente.add_a_list(list);
    EXPECT_TRUE(utente.search_name_list("Nonna"));
    EXPECT_EQ(utente.num_of_list(), 1);
}

TEST(Utente, DeleteList) {
    Utente utente("Paolo");
    shared_ptr<Lista> list(new Lista("Nonna"));
    ASSERT_ANY_THROW(utente.delete_list("Nonna"));
    utente.add_a_list(list);
    EXPECT_EQ(utente.num_of_list(), 1);
    utente.delete_list("Nonna");
    EXPECT_EQ(utente.num_of_list(), 0);
    EXPECT_FALSE(utente.search_name_list("Nonna"));
}

TEST(Utente, SearchList) {
    Utente utente("Paolo");
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_TRUE(utente.search_name_list("Spesa") == nullptr);
    utente.add_a_list(lst);
    EXPECT_EQ(utente.num_of_list(), 1);
    EXPECT_TRUE(utente.search_name_list("Spesa"));
}

TEST(Utente, PrintAllList) {
    Utente utente("Paolo");
    EXPECT_THROW(utente.print_all_list(), std::invalid_argument);
}

TEST(Utente, BuyProduct) {
    Utente utente("Paolo");
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola", veg));
    EXPECT_THROW(utente.buy_a_product(prod, "Spesa"), std::invalid_argument);
    utente.create_list("Spesa");
    EXPECT_EQ(utente.num_of_list(), 1);
    EXPECT_THROW(utente.buy_a_product(prod, "Spesa"), std::invalid_argument);
    utente.add_product_to_list(prod, "Spesa", 1);
    EXPECT_EQ(utente.search_name_list("Spesa")->num_product_in_list(), 1);
    EXPECT_FALSE(prod->isBought());
    utente.buy_a_product(prod, "Spesa");
    EXPECT_TRUE(prod->isBought());
}

TEST(Utente, AddProductToList) {
    Utente utente("Paolo");
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola", veg));
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_THROW(utente.add_product_to_list(prod, "Spesa", 1), invalid_argument);
    utente.add_a_list(lst);
    EXPECT_EQ(utente.num_of_list(), 1);
    EXPECT_THROW(utente.add_product_to_list(prod, "Spesa", 0), invalid_argument);
    EXPECT_THROW(utente.add_product_to_list(prod, "Spesa", -1), invalid_argument);
    utente.add_product_to_list(prod, "Spesa", 1);
    EXPECT_TRUE(lst->search_into_list(prod));
}

TEST(Utente, DeleteProductToList) {
    Utente utente("Paolo");
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola", veg));
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_THROW(utente.remove_product_to_list(prod, "Spesa", 1), invalid_argument);
    utente.add_a_list(lst);
    EXPECT_EQ(utente.num_of_list(), 1);
    utente.add_product_to_list(prod, "Spesa", 4);
    EXPECT_THROW(utente.remove_product_to_list(prod, "Spesa", 0), invalid_argument);
    EXPECT_THROW(utente.remove_product_to_list(prod, "Spesa", -1), invalid_argument);
    utente.remove_product_to_list(prod, "Spesa", 1);
    EXPECT_EQ(prod->getQuantity(), 3);
    utente.remove_product_to_list(prod, "Spesa", 3);
    EXPECT_FALSE(lst->search_into_list(prod));
}

TEST(Utente, NumOfList) {
    Utente utente("Paolo");
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_EQ(utente.num_of_list(), 0);
    utente.add_a_list(lst);
    EXPECT_EQ(utente.num_of_list(), 1);
    utente.create_list("Cena di Natale");
    EXPECT_EQ(utente.num_of_list(), 2);
}

TEST(Utente, SelectQuantityProd) {
    Utente utente("Paolo");
    shared_ptr<Lista> lst(new Lista("Spesa"));
    utente.add_a_list(lst);
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola", veg));
    utente.add_product_to_list(prod, lst->getNameOfList(), 0);
    EXPECT_EQ(prod->getQuantity(), 0);
    utente.select_quantity_prod("Spesa", prod, 3);
    EXPECT_EQ(prod->getQuantity(), 3);
}

