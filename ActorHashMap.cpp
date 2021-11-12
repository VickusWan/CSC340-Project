//
//  ActorHashMap.cpp
//
//
//  Created by Brandon on 11/6/21.
//

#include "ActorHashMap.h"
#include "Movie.h"

#include <map>
#include <string>
#include <vector>

namespace ActorHashMap_NS
{

using namespace std;



vector<Movie_NS::Movie> ActorHashMap::getMovies(string actorName)
{
  vector<Movie_NS::Movie> movies; // vector to hold movies to return
  
  int count = 0;
  /* iterator to begin at map start, iterate until map end, and increment
     iterator */
  for (auto itr = actorMap.begin(); itr != actorMap.end(); itr++)
  {
    if (itr -> first == actorName && count != 5) // if the itr -> first points to wanted actor
      movies.push_back(itr -> second); // push the movie to the vector
  } // end for
  return movies;
} // end getMovies

void ActorHashMap::addMovie(string actorName, Movie_NS::Movie movie)
{
  // adds key/value pair to multimap
  actorMap.insert(make_pair(actorName, movie));
} // end addMovie

} // End ActorHashMap_Ns
