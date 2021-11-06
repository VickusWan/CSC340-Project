//
//  ActorHashMap.cpp
//
//
//  Created by Brandon on 11/6/21.
//

#include "ActorHashMap.hpp"
#include "Movie.hpp"

#include <map>
#include <string>
#include <vector>

namespace ActorHashMap_NS
{

using namespace std;

ActorHashMap::ActorHashMap()
{
  multimap<string, Movie> = new multimap<>();
}

vector<Movie> ActorHashMap::getMovies(string actorName)
{
  vector<Movie> movies; // vector to hold movies to return
  
  /* iterator to begin at map start, iterate until map end, and increment
     iterator */
  for (auto itr = actorMap.begin(); itr != actorMap.end(); itr++)
  {
    if (itr -> first == actorName) // if the itr -> first points to wanted actor
      movies.push_back(itr -> second); // push the movie to the vector
  } // end for
  return movies;
} // end getMovies

void ActorHashMap::addMovie(string actorName, Movie movie)
{
  // adds key/value pair to multimap
  actorMap.insert(make_pair(actorName, movie));
} // end addMovie

} // End ActorHashMap_Ns