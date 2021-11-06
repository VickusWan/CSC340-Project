//
//  ActorHashMap.hpp
//
//
//  Created by Brandon on 11/6/21.
//

#ifndef ActorHashMap_hpp
#define ActorHashMap_hpp

#include "Actor.hpp"
#include "Movie.hpp"

#include <map>
#include <string>
#include <vector>

namespace ActorHashMap_NS {

class ActorHashMap {
  public:
  ActorhashMap();
  vector<Movie> getMovies(string actorName);
  void addMovie(string actorName, Movie movie);
  
  private:
  multimap<string, Movie> actorMap;
  
}

} // end ActorHashMap_NS

#endif /* ActorHashMap_hpp */
