#include <catch2/catch_test_macros.hpp>
#include <song/Song.h>
#include <song/BoringSong.h>
#include <song/GreatSong.h>

using namespace std;

SCENARIO("Songs are sang correctly") {

    GIVEN("A boring song") {

        string rick = "Never gonna give you up! Never gonna let you down...";
        BoringSong boringSong("Never Gonna Give You Up", rick);

        WHEN("it is sung") {
            string s = boringSong.sing();

            THEN("It should be exactly as the lyrics") {

                REQUIRE(rick == s);

            }
        }
    }

    GIVEN("A great song") {

        GreatSong greatSong("Boys Blues Band", "La gaaaaaaang, s'en va chez Stan");


        WHEN("it is sung") {
            string s = greatSong.sing();

            THEN("The lyrics are shouted") {

                REQUIRE(s == "LA GAAAAAAANG, S'EN VA CHEZ STAN");

            }
        }
    }

    GIVEN("Two identical songs") {

        GreatSong shark1("Baby Shark", "Baby shark dou dou doudou doudou");
        GreatSong shark2("Baby Shark", "Baby shark dou dou doudou doudou");

        THEN("They should be equal") {

            REQUIRE(shark1 == shark2);

        }

    }

    GIVEN("Two songs with different lyrics") {

        GreatSong shark1("Baby Shark", "Baby shark dou dou doudou doudou");
        GreatSong shark2("Baby Shark", "Grandma shark dou dou doudou doudou");

        THEN("They should not be equal") {

            REQUIRE_FALSE(shark1 == shark2);

        }

    }

    GIVEN("Two songs with different titles") {

        GreatSong croco("Crocodile Rock", "nanananananananana");
        GreatSong batman("Batman Theme", "nanananananananana");

        THEN("They should not be equal") {

            REQUIRE_FALSE(croco == batman);

        }

    }
}
