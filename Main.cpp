//adding files
#include "Movie.h"
#include "MovieHashMap.h"
#include "creditDataSet.h"
#include "movieDataSet.h"
#include "ActorHashMap.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

void menu(std::string select, MovieHashMap_NS::MovieHashMap* movieMap, MovieHashMap_NS::MovieHashMap* actorMap) {

    if (select == "genre") {

        std::string genre;

        std::cin.ignore();
        std::cout << std::endl;
        std::cout << "What genre would you like recommendations?" << std::endl;
        std::getline(std::cin, genre);

        std::vector<Movie_NS::Movie> listMovies = movieMap->getMovies(genre);

        std::cout << "Top 5 " << genre << " movies: " << std::endl;
        int count = 0;
        for (int i = 0; i < listMovies.size(); i++) {

            std::cout << "Title: " << listMovies.at(i).GetTitle() << std::endl;
            count++;
            if (count == 5)
                break;
        }
        std::cout << std::endl << std::endl;
    }

    else if (select == "actor") {

        std::string actor;

        std::cin.ignore();
        std::cout << std::endl;
        std::cout << "What is the actor you want?" << std::endl;
        std::getline(std::cin, actor);

        std::vector<Movie_NS::Movie> listMovies;
        listMovies = actorMap->getMovies(actor);

        std::cout << "Top 5 movies " << actor << " appears in: " << std::endl;
        int count = 0;
        for (int i = 0; i < listMovies.size(); i++) {

            std::cout << "Title: " << listMovies.at(i).GetTitle();
            std::cout << "\t\tgenre: " << listMovies.at(i).GetGenre() << std::endl;
            count++;
            if (count == 5)
                break;
        }

        std::cout << std::endl << std::endl;

    }
    
    else if (select == "random") {
        srand(time(0));
        int total = rand() % 10000 - rand() % 1000;

        NS_MOVIE_DATA_SET::movies movieTitle = NS_MOVIE_DATA_SET::movieDataSet();

        if (total > 4804) {
            total = total - 4804;
        }

        if (total < 0) {
            total = (total * -2);
        }
        std::cout << std::endl;
        std::cout << "Random movie recommendation: " << movieTitle.originalTitle.at(total) << std::endl;
        std::cout << std::endl;
    }
}


int main()
{

    MovieHashMap_NS::MovieHashMap* movieMap = new MovieHashMap_NS::MovieHashMap();
    NS_MOVIE_DATA_SET::movies movieData = NS_MOVIE_DATA_SET::movieDataSet();

    MovieHashMap_NS::MovieHashMap* actorMap = new MovieHashMap_NS::MovieHashMap();
    NS_CREDIT_DATA_SET::credits creditData = NS_CREDIT_DATA_SET::creditDataSet();


    for (long unsigned int i = 0; i < movieData.originalTitle.size(); i++) {

        std::string title = movieData.originalTitle.at(i);
        std::string genre = movieData.genres.at(i);
        double vote = 0;
        Movie_NS::Movie m(title, genre, vote);

        movieMap->addMovie(genre, m);

    }

    for (long unsigned int i = 0; i < creditData.cast.size(); i++) {

        if (movieData.movieID.at(i) == creditData.movieID.at(i)) {
            std::string title = movieData.originalTitle.at(i);
            std::string genre = movieData.genres.at(i);
            std::string actor = creditData.cast.at(i);
            double vote = 0;
            Movie_NS::Movie m(title, genre, vote);

            actorMap->addMovie(actor, m);
        }
    }

    std::string select;
    bool x = true;

    while (x == true) { //menu to ask the user for a preference
        std::cout << "Movies Recommendation" << std::endl << std::endl;
        std::cout << "Enter 'genre' for recommendations in that genre" << std::endl;
        std::cout << "Enter 'actor' recommendations with that actor" << std::endl;
        std::cout << "Enter 'random' for a random movie" << std::endl;
        std::cout << "Enter 'quit' to stop" << std::endl;
        std::cin >> select;

        if (select == "genre" || select == "actor" || select == "random") {
            menu(select, movieMap, actorMap);
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
