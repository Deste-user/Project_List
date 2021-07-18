//
// Created by Marco De Stefano on 05/07/21.
//
#include "gtest/gtest.h"
#include "../Utente.h"

TEST(Utente,DefaultCostructor){
    Utente utente("Paolo");
    EXPECT_EQ(utente.getNameOfUtente(),"Paolo");
}

TEST(Utente,CreateList){
    Utente utente("Paolo");
    utente.create_list("Spesa");
    EXPECT_TRUE(utente.search_name_list("Spesa"));
}

TEST(Utente, AddList){
    Utente utente("Paolo");
    shared_ptr<Lista> list(new Lista("Nonna"));
    utente.add_a_list(list);
    EXPECT_TRUE(utente.search_name_list("Nonna"));
}

TEST(Utente, DeleteList){
    Utente utente("Paolo");
    shared_ptr<Lista> list(new Lista("Nonna"));
    ASSERT_ANY_THROW(utente.delete_list("Nonna"));
    utente.add_a_list(list);
    utente.delete_list("Nonna");
    EXPECT_TRUE(utente.search_name_list("Nonna")==nullptr);
}

TEST(Utente, SearchList){
    Utente utente("Paolo");
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_TRUE(utente.search_name_list("Spesa")==nullptr);
    utente.add_a_list(lst);
    EXPECT_TRUE(utente.search_name_list("Spesa"));
}

TEST(Utente, PrintAllList){
    Utente utente("Paolo");
    EXPECT_THROW(utente.print_all_list(),std::invalid_argument);
}

TEST(Utente, BuyProduct){
    Utente utente("Paolo");
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola",veg));
    EXPECT_THROW(utente.buy_a_product(prod,"Spesa"),std::invalid_argument);
    utente.create_list("Spesa");
    EXPECT_THROW(utente.buy_a_product(prod,"Spesa"),std::invalid_argument);
    utente.add_product_to_list(prod,"Spesa",1);
    EXPECT_FALSE(prod->isBought());
    utente.buy_a_product(prod,"Spesa");
    EXPECT_TRUE(prod->isBought());
}

TEST(Utente,AddProductToList ){
    Utente utente("Paolo");
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola",veg));
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_THROW(utente.add_product_to_list(prod,"Spesa",1), invalid_argument);
    utente.add_a_list(lst);
    EXPECT_THROW(utente.add_product_to_list(prod,"Spesa",0),invalid_argument);
    EXPECT_THROW(utente.add_product_to_list(prod,"Spesa",-1),invalid_argument);
    utente.add_product_to_list(prod,"Spesa",1);
    EXPECT_TRUE(lst->search_into_list(prod));
}

TEST(Utente, DeleteProductToList){
    Utente utente("Paolo");
    CategoryProduct veg("Vegetables");
    shared_ptr<Product> prod(new Product("Barbabietola",veg));
    shared_ptr<Lista> lst(new Lista("Spesa"));
    EXPECT_THROW(utente.remove_product_to_list(prod,"Spesa",1), invalid_argument);
    utente.add_a_list(lst);
    utente.add_product_to_list(prod,"Spesa",4);
    EXPECT_THROW(utente.remove_product_to_list(prod,"Spesa",0),invalid_argument);
    EXPECT_THROW(utente.remove_product_to_list(prod,"Spesa",-1),invalid_argument);
    utente.remove_product_to_list(prod,"Spesa",1);
    EXPECT_EQ(prod->getQuantity(),3);
    utente.remove_product_to_list(prod,"Spesa",3);
    EXPECT_FALSE(lst->search_into_list(prod));
}

