//
// Created by Marco De Stefano on 05/07/21.
//
#include "gtest/gtest.h"
#include "../Utente.h"

TEST(Utente,DefaultCostructor){
    Utente utente("Paolo");
    EXPECT_EQ(utente.getNameOfUtente(),"Paolo");
    EXPECT_EQ(utente.getNumListe(),0);
    EXPECT_EQ(utente.getSubject(),nullptr);
    EXPECT_EQ(utente.getElencoListe().begin(),nullptr);
}


