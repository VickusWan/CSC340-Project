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
class MovieHashMap {
  public:
  MovieHashMap();
  vector<Movie> getMovies(string genre);
  void addMovie(string genre, Movie movie)
  
  private:
  multimap<string, Movie> movieMap;
  
  
} // end MovieHashMap

} // end MovieHashMapNS

#endif /* MovieHashMap_hpp */
