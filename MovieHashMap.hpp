//
//  HashMap.hpp
//  
//
//  Created by Brandon on 11/6/21.
//

#ifndef MovieHashMap_hpp
#define MovieHashMap_hpp

namespace MovieHashMap_NS {
class MovieHashMap {
  public:
  Vector<Movie> getMovies(String genre);
  
  private:
  multimap<String, Movie> movieMap;
  
  
} // end MovieHashMap

} // end MovieHashMapNS

#endif /* MovieHashMap_hpp */
