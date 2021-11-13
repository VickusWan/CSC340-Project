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
            std::string genre;
            MovieHashMap_NS::MovieHashMap* movieMap = new MovieHashMap_NS::MovieHashMap();

            NS_MOVIE_DATA_SET::movies manageData = NS_MOVIE_DATA_SET::movieDataSet();

            /*for (long unsigned int i = 0; i < manageData.genres.size(); i++) {
                std::cout << "genre " << i << ": " << manageData.genres[i] << std::endl;    //printing genres vector
            }*/

            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "What is the genre you like?" << std::endl;
            std::getline(std::cin, genre);

            for (long unsigned int i = 0; i < manageData.originalTitle.size(); i++) {

                std::string title = manageData.originalTitle.at(i);
                std::string genre = manageData.genres.at(i);
                double vote = manageData.voteAverage.at(i);
                std::string runtime = manageData.runtime.at(i);
                std::string overview = manageData.overview.at(i);
                Movie_NS::Movie movie(title, genre, vote, runtime, overview);

                movieMap->addMovie(genre, movie);

            }

            std::vector<Movie_NS::Movie> movies = movieMap->getMovies(genre);

            for (Movie_NS::Movie movie : movies) {
                std::cout << std::endl;
                std::cout << "Some other movies with " << genre << " genre: " << movie.getTitle() << std::endl;
            }

            std::cout << std::endl;
        }


        else if (select == "actor") {
            std::string actor;
            ActorHashMap_NS::ActorHashMap* actorMap = new ActorHashMap_NS::ActorHashMap();
            int index = 0;
            std::vector<int> location;

            NS_CREDIT_DATA_SET::credits manageData = NS_CREDIT_DATA_SET::creditDataSet();
            NS_MOVIE_DATA_SET::movies manageMoviesData = NS_MOVIE_DATA_SET::movieDataSet();

            /*for (long unsigned int i = 0; i < manageData.cast.size(); i++) {
                std::cout << "actor "<< i << ": " << manageData.cast[i] << std::endl;    //printing cast vector
            }*/

            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "What is the name of your actor?" << std::endl;
            std::getline(std::cin, actor);  
            
            for (long unsigned int i = 0; i < manageData.cast.size(); i++) {

                //credits data set
                std::string title = manageData.title.at(i);
                std::string cast = manageData.cast.at(i);

                //movies data set //not needed
                double vote = manageMoviesData.voteAverage.at(i);
                std::string runtime = manageMoviesData.runtime.at(i);
                std::string overview = manageMoviesData.overview.at(i);
                Movie_NS::Movie movie(title, cast, vote, runtime, overview);

                actorMap->addMovie(actor, movie);

            }

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
