#include <catch2/catch_test_macros.hpp>
#include <singer/Singer.h>
#include <song/BoringSong.h>
#include <singer/FrenchSinger.h>

using namespace std;

SCENARIO("Singer") {

    GIVEN("A singer") {

        Singer singer;

        WHEN("No song was proposed") {

            THEN("It should return NO_SONG_MESSAGE") {

                REQUIRE(singer.sing() == NO_SONG_MESSAGE);
            }
        }

        WHEN("A song was proposed") {

            const string darude = "DUDUDUDUDU DUDUDUDUDU DU DUDUDUDUDU DUDUDUDUDU DU DUDUDUDUDU";
            BoringSong song("Darude - Sandtorm", darude);

            singer.setProposedSong(&song);
            
            THEN("The singer should sing the song") {
                REQUIRE(singer.sing() == darude);
            }

            THEN("The singer should recognize its song") {
                REQUIRE(singer.omgItsMySooooong(&song));
            }
        }
    }

    GIVEN("A French singer") {

        FrenchSinger singer;

        WHEN("A song was proposed") {

            const string sousLeVent = "J'ai trouvé mon étoile. Je l'ai suivie un instant. Sous le vent";
            BoringSong song("Sous le vent", sousLeVent);

            singer.setProposedSong(&song);

            THEN("The singer should sing the song") {
                REQUIRE(singer.sing() == "Du coup, " + sousLeVent);
            }
        }
    }
}