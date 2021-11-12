//adding files
#include "ActorHashMap.h"
#include "Movie.h"
#include "MovieHashMap.h"
#include "creditDataSet.h"
#include "movieDataSet.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

void menu(std::string select) {
   
        if (select == "genre") {
            std::string movie;
            MovieHashMap_NS::MovieHashMap* movieMap = new MovieHashMap_NS::MovieHashMap();
            int index = 0;
            std::vector<int> location;

            NS_MOVIE_DATA_SET::movies manageData = NS_MOVIE_DATA_SET::movieDataSet();

            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "What is the genre you like?" << std::endl;
            std::getline(std::cin, movie);

            for (long unsigned int i = 0; i < manageData.genres.size(); i++) {  //function to look for the genre in every
                std::stringstream ss(manageData.genres[i]);                     //genre of a movie, if the genre is found
                std::string temp;                                               //save location where found it
                                                                                //needs to be fixed
                while (ss >> temp) {

                    if (temp.compare(movie) == 0) {
                        location[index] = i;
                        index++;

                    }
                }
            }

            //printing movies with that genre

            std::cout << std::endl;
        }


        else if (select == "actor") {
            std::string actor;
            ActorHashMap_NS::ActorHashMap* actorMap = new ActorHashMap_NS::ActorHashMap();
            int index = 0;
            std::vector<int> location;

            NS_CREDIT_DATA_SET::credits manageData = NS_CREDIT_DATA_SET::creditDataSet();

            /*for (long unsigned int i = 0; i < manageData.cast.size(); i++) {
                std::cout << "actor "<< i << ": " << manageData.cast[i] << std::endl;    //printing cast vector
            }*/

            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "What is the name of your actor?" << std::endl;
            std::getline(std::cin, actor);

            for (long unsigned int i = 0; i < manageData.cast.size(); i++) {  //function to look for the actor in every
                std::stringstream ss(manageData.cast[i]);                     //cast movie, if the actor is found
                std::string temp;                                             //save location where found it
                                                                              //needs to be fixed
                while (ss >> temp) {

                    if (temp.compare(actor) == 0) {
                        location[index] = i;
                        index++;
                        
                    }
                }
            }    
            
            //I'm not sure how hashmaps work but I tried to add the movies where the actor was found to the hashmap
            //it will save the data from the location where the actor was found
            std::vector<Movie_NS::Movie> actorMovies;
            while (index < location.size()) {
                Movie_NS::Movie actorMovies{ NS_CREDIT_DATA_SET::creditDataSet().title[location[index]], NS_MOVIE_DATA_SET::movieDataSet().genres[location[index]], NS_MOVIE_DATA_SET::movieDataSet().voteAverage[location[index]], NS_CREDIT_DATA_SET::creditDataSet().cast[location[index]], NS_CREDIT_DATA_SET::creditDataSet().movieID[location[index]] };
                actorMap->addMovie(actor, actorMovies);
                index++;
            }
            
            //In this part I followed Brandon's code to print a recommendation
            std::vector<Movie_NS::Movie> movies = actorMap->getMovies(actor);

            for (Movie_NS::Movie movie : movies) {
                std::cout << std::endl;
                std::cout << "Some other movies " << actor << " appears in: " << movie.getTitle() << std::endl;
            }
            
            std::cout << std::endl;
        }
}


int main()
{
    std::string select;
    bool x = true;

    while (x == true) { //menu to ask the user for a preference
        std::cout << "Movies recommendation" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter 'genre' to recommend a genre || Enter 'actor' to recommend an actor" << std::endl;
        std::cout << "or enter 'quit' to stop" << std::endl;
        std::cin >> select;

        if (select == "genre" || select == "actor") {
            menu(select);
        }

        else if (select == "quit") {
            std::cout << std::endl;
            std::cout << "Closing program..." << std::endl;
            return 0;
        }

        else {
            std::cout << std::endl;
            std::cout << "Write a valid answer. Do NOT use capital letters!!" << std::endl;
            std::cout << std::endl;
        }
        
    }
}
