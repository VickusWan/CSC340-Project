//
//  HashMap.hpp
//  
//
//  Created by Brandon on 11/6/21.
//

#ifndef MovieHashMap_hpp
#define MovieHashMap_hpp

#include "Movie.h"

#include <string>
#include <vector>

namespace MovieHashMap_NS {
class MovieHashMap {
  public:
  vector<Movie> getMovies(string genre);
  
  private:
  multimap<string, Movie> movieMap;
  
  
} // end MovieHashMap

} // end MovieHashMapNS

#endif /* MovieHashMap_hpp */
