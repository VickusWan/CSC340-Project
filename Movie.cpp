#include "Movie.h"

namespace Movie_NS{

    Movie::Movie(std::string newTitle, std::string newGenre, double newVoteAverage) {
        title = newTitle;
        genre = newGenre;
        voteAverage = newVoteAverage;
    }
    std::string Movie::GetGenre() { return genre; }
    std::string Movie::GetTitle() {return title; }
    double Movie::GetAverage() { return voteAverage; }

}