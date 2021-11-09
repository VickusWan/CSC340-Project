//
//  Movie.hpp
//  csc340
//
//  Created by Victor Uong on 2021-11-08.
//

#ifndef Movie_hpp
#define Movie_hpp

#include <vector>
#include <string>


#include <stdio.h>

namespace Movie_NS {

class Movie {
    
public:
    Movie(std::string ID, std::string t,
          std::string g, double vote);
    
    std::string movieID;
    std::string title;
    std::string genres;
    double voteAvg;
        
};

}

#endif /* Movie_hpp */
