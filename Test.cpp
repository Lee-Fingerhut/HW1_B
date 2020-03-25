//
//  Test.cpp
//  phonetic-search-a
//
//  Created by Lee Fingerhut on 21/03/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//

#include "PhoneticFinder.hpp"
#include "doctest.h"
#include <string>
using namespace phonetic;
using namespace std;

TEST_CASE("v,w  and W,V") {
    string text = "victorys basket worth";
    CHECK(find(text, "Worth") == string("worth"));
    CHECK(find(text, "vorth") == string("worth"));
    CHECK(find(text, "Vorth") == string("worth"));
    CHECK(find(text, "Victorys") == string("victorys"));
    CHECK(find(text, "victorys") == string("victorys"));
    CHECK(find(text, "wictorys") == string("victorys"));
    CHECK(find(text, "Wictorys") == string("victorys"));
}

TEST_CASE("b,f,p and B,F,P") {
    string text = "Elsa and Anna are forever princess";
    CHECK(find(text, "borever") == string("forever"));
    CHECK(find(text, "Forever") == string("forever"));
    CHECK(find(text, "BORever") == string("forever"));
    CHECK(find(text, "porever") == string("forever"));
    CHECK(find(text, "Porever") == string("forever"));
    CHECK(find(text, "forever") == string("forever"));
    CHECK(find(text, "Princess") == string("princess"));
    CHECK(find(text, "Brincess") == string("princess"));
    CHECK(find(text, "Frincess") == string("princess"));
    CHECK(find(text, "PRINCESS") == string("princess"));
    CHECK(find(text, "brincess") == string("princess"));
    CHECK(find(text, "frincess") == string("princess"));
    CHECK(find(text, "princess") == string("princess"));
}

TEST_CASE(" g,j and G,J") {
    string text = "Welcome to the jungle";
    CHECK(find(text, "jungle") == string("jungle"));
    CHECK(find(text, "gunjle") == string("jungle"));
    CHECK(find(text, "Gunjle") == string("jungle"));
    CHECK(find(text, "Jungle") == string("jungle"));
    CHECK(find(text, "junGle") == string("jungle"));
    CHECK(find(text, "JunGle") == string("jungle"));
    CHECK(find(text, "junjle") == string("jungle"));
    CHECK(find(text, "gungle") == string("jungle"));
    CHECK(find(text, "JUNGLE") == string("jungle"));
}

TEST_CASE("c,k,q and C,K,Q") {
    string text = "bake a cake quickly";
    CHECK(find(text, "baKe") == string("bake"));
    CHECK(find(text, "baqe") == string("bake"));
    CHECK(find(text, "bace") == string("bake"));
    CHECK(find(text, "cake") == string("cake"));
    CHECK(find(text, "qake") == string("cake"));
    CHECK(find(text, "Qake") == string("cake"));
    CHECK(find(text, "qaQe") == string("cake"));
    CHECK(find(text, "cuickly") == string("quickly"));
    CHECK(find(text, "cuikqly") == string("quickly"));
    CHECK(find(text, "quiccly") == string("quickly"));
    CHECK(find(text, "kuikkly") == string("quickly"));
    CHECK(find(text, "kuicqly") == string("quickly"));
}

TEST_CASE("s,z and S,Z") {
    string text = "surprise for Zoe";
    CHECK(find(text, "surprise") == string("surprise"));
    CHECK(find(text, "Surprise") == string("surprise"));
    CHECK(find(text, "Zurprise") == string("surprise"));
    CHECK(find(text, "zurprize") == string("surprise"));
    CHECK(find(text, "surprize") == string("surprise"));
    CHECK(find(text, "Surprise") == string("surprise"));
    CHECK(find(text, "zoe") == string("Zoe"));
    CHECK(find(text, "soe") == string("Zoe"));
    CHECK(find(text, "ZOe") == string("Zoe"));
    CHECK(find(text, "Soe") == string("Zoe"));
    CHECK(find(text, "soe") == string("Zoe"));
}

TEST_CASE("d,t and D,T") {
    string text = "dont see dhe dime";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "Dont") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "DONd") == string("dont"));
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "Tond") == string("dont"));
    CHECK(find(text, "tond") == string("dont"));
    CHECK(find(text, "the") == string("dhe"));
    CHECK(find(text, "dhe") == string("dhe"));
    CHECK(find(text, "The") == string("dhe"));
    CHECK(find(text, "THE") == string("dhe"));
    CHECK(find(text, "time") == string("dime"));
 //   CHECK(find(text, "tim") == string("dime"));
    CHECK(find(text, "Time") == string("dime"));
}

TEST_CASE("o,u and O,U") {
    string text = "hello yossi";
    CHECK(find(text, "hello") == string("hello"));
    CHECK(find(text, "hellu") == string("hello"));
    CHECK(find(text, "hellU") == string("hello"));
    CHECK(find(text, "hEllo") == string("hello"));
    CHECK(find(text, "HELLO") == string("hello"));
    CHECK(find(text, "HELLO") == string("hello"));
    CHECK(find(text, "yussi") == string("yossi"));
    CHECK(find(text, "yUssi") == string("yossi"));
    CHECK(find(text, "yossi") == string("yossi"));
    CHECK(find(text, "YOssi") == string("yossi"));
    CHECK(find(text, "Yussi") == string("yossi"));
    CHECK(find(text, "YOSSI") == string("yossi"));
}

TEST_CASE( "i,y and I,Y") {
    string text = "inbar love newyork";
    CHECK(find(text, "inbar") == string("inbar"));
    CHECK(find(text, "ynbar") == string("inbar"));
    CHECK(find(text, "Inbar") == string("inbar"));
    CHECK(find(text, "INBAR") == string("inbar"));
    CHECK(find(text, "YnBar") == string("inbar"));
    CHECK(find(text, "YNBAR") == string("inbar"));
    CHECK(find(text, "newyork") == string("newyork"));
    CHECK(find(text, "newiork") == string("newyork"));
    CHECK(find(text, "NEWyork") == string("newyork"));
    CHECK(find(text, "newIork") == string("newyork"));
    CHECK(find(text, "newYork") == string("newyork"));
    CHECK(find(text, "NEWyork") == string("newyork"));
}

TEST_CASE("word was not found"){
     string text = "how are you";
     CHECK_THROWS_AS(find(text, "ll"),  std::exception);
     CHECK_THROWS_AS(find(text, "sha"),  std::exception);
     CHECK_THROWS_AS(find(text, "she"),  std::exception);
     CHECK_THROWS_AS(find(text, "yyU"),  std::exception);
     CHECK_THROWS_AS(find(text, "ABcd"),  std::exception);
     CHECK_THROWS_AS(find(text, "Bacd"),  std::exception);
     CHECK_THROWS_AS(find(text, "lili"),  std::exception);
     CHECK_THROWS_AS(find(text, "tomy"),  std::exception);
     CHECK_THROWS_AS(find(text, "ava"),  std::exception);
     CHECK_THROWS_AS(find(text, "yaya"),  std::exception);
    CHECK_THROWS_AS(find(text, "lee"),  std::exception);
    CHECK_THROWS_AS(find(text, "yaya"),  std::exception);
}

TEST_CASE("empty word")
{
    string text = " ";
    string text1 = "";

    CHECK_THROWS_AS(find(text, "le"), std::exception);
    CHECK_THROWS_AS(find(text1, "bibi"), std::exception);
}

TEST_CASE("illegale word"){
     string text = "how are you";
     CHECK_THROWS_AS(find(text, "how are"),  std::exception);
     CHECK_THROWS_AS(find(text, "are you"),  std::exception);
}


