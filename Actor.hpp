//
//  Actor.hpp
//  CSC340-Project
//
//  Created by Brandon on 11/5/21.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <string>
#include <vector>

#include "Movie.h"

namespace ActorClass_NS {

class Actor {
  public:
  Actor(String name; Vector<Movie> movies);
  Vector<Movie> getMovies();
  
  private:
  String name = "";
  Vector<Movie> movies;
  
} // end Actor

} // end ActorClass_NS

#endif /* Actor_hpp */
