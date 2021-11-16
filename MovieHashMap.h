//
//  HashMap.hpp
//
//
//  Created by Brandon on 11/6/21.
//

#ifndef MovieHashMap_hpp
#define MovieHashMap_hpp

#include "Movie.h"

#include <map>
#include <string>
#include <vector>

namespace MovieHashMap_NS {

using namespace std;
class MovieHashMap {
  public:
  vector<Movie_NS::Movie> getMovies(string genre); // returns movies in vector
  void addMovie(string genre, Movie_NS::Movie movie); // add movie to map
  
  private:
  multimap<string, Movie_NS::Movie> movieMap; // creates multimap
  
  
  
}; // end MovieHashMap

} // end MovieHashMapNS

#endif /* MovieHashMap_hpp */
