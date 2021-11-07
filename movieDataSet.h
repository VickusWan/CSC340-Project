#ifndef movieDataSet_hpp
#define movieDataSet_hpp

#include <vector>
#include <string>


// declare namespace NS_MOVIE+DATA_SET
namespace NS_MOVIE_DATA_SET {
   struct movies {
        // vectors to store data
        std::vector<std::string> genres, originalTitle, overview, runtime,voteAverage;
    };
   
   // these are prototype of functions
   movies movieDataSet();
}

#endif