//
//  MovieHashMap.cpp
//
//
//  Created by Brandon on 11/6/21.
//

#include "MovieHashMap.hpp"

#include <map>
#include <string>
#include <vector>

namespace MovieHashMap_NS
{

using namespace std;

MovieHashMap::MovieHashMap()
{
  multimap<string, Movie> movieMap = new multimap<>();
}

void MovieHashMap::addMovie(string genre, Movie movie)
{
  movieMap.insert(make_pair(genre, movie));
} // end addMovie

vector<Movie> MovieHashMap::getMovies(string genre)
{
  vector<Movie> movies; // vector to return movies
  
  // iterator start at map begin, go until map end, increment iterator
  for (auto itr = movieMap.begin(); itr != movieMap.end(); itr++)
  {
    if (itr -> first == genre) // if the itr -> first points to wanted genre
      movies.push_back(itr -> second); // push the movie to the vector
  }
  return movies;
} // end getMovie

} // end MovieHashMap_NS
