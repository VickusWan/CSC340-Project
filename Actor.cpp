//
//  Actor.cpp
//  CSC340-Project
//
//  Created by Brandon on 11/5/21.
//

#include "Actor.hpp"

namespace ActorClass_NS {

  Actor::Actor(String name, Vector<Movie> movies) {
    this.name = name;
    this.movies = movies;
  }

  Vector<Movie> Actor::getMovies() {
    return movies;
  }

} // end ActorClass_NS
