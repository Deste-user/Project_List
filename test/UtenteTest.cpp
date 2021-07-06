//
// Created by Marco De Stefano on 05/07/21.
//
#include "gtest.h"
#include "../Utente.h"

TEST(Utente,DefaultCostructor){
    Utente utente("Paolo");
    EXPECT_EQ(utente.getNameOfUtente(),"Paolo");

}

