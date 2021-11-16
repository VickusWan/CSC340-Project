//
//  ActorHashMap.hpp
//
//
//  Created by Brandon on 11/6/21.
//

#ifndef ActorHashMap_hpp
#define ActorHashMap_hpp


#include "Movie.h"

#include <map>
#include <string>
#include <vector>

namespace ActorHashMap_NS {

using namespace std;

class ActorHashMap {
  public:
 
  vector<Movie_NS::Movie> getMovies(string actorName);
  void addMovie(string actorName, Movie_NS::Movie movie);
  
  private:
  multimap<string, Movie_NS::Movie> actorMap;
  
};

} // end ActorHashMap_NS

#endif /* ActorHashMap_hpp */
