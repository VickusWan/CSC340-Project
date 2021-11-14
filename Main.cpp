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

void menu(std::string select, MovieHashMap_NS::MovieHashMap* movieMap, MovieHashMap_NS::MovieHashMap* actorMap) {
        
        if (select == "genre") {
            
            std::string genre;
            
            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "What is the genre you like?" << std::endl;
            std::getline(std::cin, genre);
            
            std::vector<Movie_NS::Movie> listMovies;
            listMovies = movieMap -> getMovies(genre);
            
            int count = 0;
            for (int i = 0; i< listMovies.size(); i++) {
                
                std::cout << listMovies.at(i).GetTitle() << std::endl;
                count++;
                if (count == 5)
                    break;
            }
        }

        else if (select == "actor") {
            
            std::string actor;
            
            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "What is the actor you want?" << std::endl;
            std::getline(std::cin, actor);
            
            std::vector<Movie_NS::Movie> listMovies;
            listMovies = actorMap -> getMovies(actor);
            
            int count = 0;
            for (int i = 0; i< listMovies.size(); i++) {
                
                std::cout << listMovies.at(i).GetTitle() << std::endl;
                count++;
                if (count == 5)
                    break;
            }
            
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
        
        movieMap -> addMovie(genre, m);
        
    }
    
    for (long unsigned int i = 0; i < creditData.cast.size(); i++) {
        
        if (movieData.movieID.at(i) == creditData.movieID.at(i)) {
            std::string title = movieData.originalTitle.at(i);
            std::string genre = movieData.genres.at(i);
            std::string actor = creditData.cast.at(i);
            double vote = 0;
            Movie_NS::Movie m(title, genre, vote);
            
            actorMap -> addMovie(actor, m);
        }
    }
    
    std::string select;
    bool x = true;

    while (x == true) { //menu to ask the user for a preference
        std::cout << "Movies recommendation" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter 'genre' to recommend a genre || Enter 'actor' to recommend an actor" << std::endl;
        std::cout << "or enter 'quit' to stop" << std::endl;
        std::cin >> select;

        if (select == "genre" || select == "actor") {
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
