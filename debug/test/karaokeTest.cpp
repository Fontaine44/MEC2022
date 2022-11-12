#include <catch2/catch_test_macros.hpp>
#include <karaoke/Karaoke.h>
#include <song/GreatSong.h>
#include <song/BoringSong.h>

using namespace std;
using namespace Catch::Matchers;

SCENARIO("Karaoke") {

    GIVEN("An empty Karaoke") {

        Karaoke k;

        REQUIRE(k.getRequestedSongCount() == 0);
        REQUIRE(k.getNextSong() == nullptr);

        WHEN("A song is added") {

            GreatSong song("Roundabout", "I'll be the rouuuuunnnndabout. The words will make you out 'n' out. I spend the day your waaaaaaaaay");
            k.specialRequest(&song);

            THEN("The next song should be the one just added") {

                REQUIRE(k.getRequestedSongCount() == 1);
                REQUIRE(*k.getNextSong() == song);

                AND_THEN("No songs should be available after") {

                    REQUIRE(k.getRequestedSongCount() == 0);
                    REQUIRE(k.getNextSong() == nullptr);

                }
            }
        }

        WHEN("It is filled with songs") {

            BoringSong allStar("All star", "Well the years start coming. And they don't stop coming And they don't stop coming And they don't stop coming And they don't stop coming And they don't stop coming And they don't stop coming And they don't stop coming.");
            for (int i = 0; i < SONG_QUEUE_SIZE; ++i) {
                k.specialRequest(&allStar);
            }

            THEN("The song count should be equal to the max") {

                REQUIRE(k.getRequestedSongCount() == SONG_QUEUE_SIZE);

            }

            AND_WHEN("A new song is added") {

                GreatSong s("Tik Tok", "Now, the party don't start till I walk in");
                bool added = k.specialRequest(&s);

                THEN("The song should not be added") {

                    REQUIRE_FALSE(added);

                }

                THEN("The song count wasn't changed") {

                    REQUIRE(k.getRequestedSongCount() == SONG_QUEUE_SIZE);

                }

            }
        }
    }

    GIVEN("A karaoke with some songs") {
        Karaoke k;

        GreatSong s1("Elephant", "Well he feels like an elephant shakin' his big grey trunk for the hell of it");
        GreatSong s2("Breakfast in America", "Take a look at my girlfriend. She's the only one I got!");
        GreatSong s3("Africa", "I bless the raaaaainnnnn down in Aaaaaafricaaaaaaa");
        BoringSong s4("How To Save A Life", "And I would have stayed up with you all night. Had I known how to save a life");
    
        k.specialRequest(&s1);
        k.specialRequest(&s2);
        k.specialRequest(&s3);
        k.specialRequest(&s4);

        THEN("The size should be positive") {
            
            REQUIRE(k.getRequestedSongCount() > 0);
        }
        
        WHEN("The next song is queried") {

            const Song* nextSong = k.getNextSong();

            THEN("The first song should be returned") {

                REQUIRE(*nextSong == s1);

            }

            THEN("The number of request should have diminished") {

                REQUIRE(k.getRequestedSongCount() == 3);

            }

            AND_WHEN("A song is added") {

                GreatSong s5("Circle of Life (Lion King)",
                        "Naaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaants ingonyaaaaaaaaaaaaaaaaaaaaaaaaaaaama bagithi Baba");

                k.specialRequest(&s5);

                THEN("The number of requests should have been incremented") {

                    REQUIRE(k.getRequestedSongCount() == 4);
                    
                }
                
                THEN("The next song should not be one just added") {

                    const Song *const nextSong1 = k.getNextSong();

                    REQUIRE_FALSE(*nextSong1 == s5);
                }

            }
        }

        WHEN("All the songs are queried") {
            vector<const Song*> songs;
            
            while (k.getRequestedSongCount() != 0) {
                songs.push_back(k.getNextSong());
            }

            THEN("The number of requests should be 0") {

                REQUIRE(k.getRequestedSongCount() == 0);

            }

            THEN("The songs should follow the insertion order") {

                vector<const Song*> initialSongs;
                initialSongs.push_back(&s1);
                initialSongs.push_back(&s2);
                initialSongs.push_back(&s3);
                initialSongs.push_back(&s4);

                REQUIRE(songs == initialSongs);

            }
            
            AND_WHEN("A song is queried") {

                const Song* nextSong = k.getNextSong();

                THEN("A nullptr should be returned") {

                    REQUIRE(nextSong == nullptr);

                }
            }
        }
    }
}