//
//  Movie.cpp
//  csc340
//
//  Created by Victor Uong on 2021-11-08.
//

#include <vector>
#include <string>

#include "Movie.hpp"


namespace Movie_NS {

    Movie::Movie(std::string ID, std::string t,std::string g, double vote) {
    
    movieID = ID;
    title = t;
    genres = g;
    voteAvg = vote;
    
 }
    
};




