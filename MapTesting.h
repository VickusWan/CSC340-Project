//
//  MapTesting.h
//
//
//  Created by Brandon on 11/10/21.
//

#ifndef MapTesting_hpp
#define MapTesting_hpp

#include "ActorHashMap.h"
#include "Movie.h"
#include "MovieHashMap.h"

#include <iostream>
#include <string>
#include <vector>

namespace MapTesting_NS
{
  
  /* tests action movies hashing correctly
   * tests getMovies of multimap */
  inline
  bool testAction()
  {
    // the multimap
    MovieHashMap_NS::MovieHashMap* movieMap = new MovieHashMap_NS::MovieHashMap ();

    //action movie object creation
    Movie_NS::Movie avatar("Avatar", "action", 150.437577);
    Movie_NS::Movie spectre("Spectre", "action", 107.376788);
    Movie_NS::Movie theDarkKnightRises("The Dark Knight Rises", "action", 112.31295);
  
    //fantasy movie object creation
    Movie_NS::Movie piratesAtWorldsEnd{"Pirates of the Caribbean: At Worlds End", "fantasy", 139.082615};
    Movie_NS::Movie spiderman3("Spiderman 3", "fantasy", 115.699184);
    Movie_NS::Movie harryPotterHalf("Harry Potter and the Half Blood Prince", "fantasy", 98.8856367);
    Movie_NS::Movie harryPotterLady("Harry Potter and the Lady Gaga Conundrum", "fantasy", 88.8856367);
    Movie_NS::Movie harryPotterHeroin("Harry Potter and the Heroin Epidemic", "fantasy", 87.8856367);
    Movie_NS::Movie equus("Equus", "fantasy", 87.8856367);

    // add movies to map
    movieMap -> addMovie(avatar.getGenre(), avatar);
    movieMap -> addMovie(piratesAtWorldsEnd.getGenre(), piratesAtWorldsEnd);
    movieMap -> addMovie(spiderman3.getGenre(), spiderman3);
    movieMap -> addMovie(theDarkKnightRises.getGenre(), theDarkKnightRises);
    movieMap -> addMovie(spectre.getGenre(), spectre);
    movieMap -> addMovie(harryPotterHalf.getGenre(), harryPotterHalf);
    movieMap -> addMovie(harryPotterLady.getGenre(), harryPotterLady);
    movieMap -> addMovie(harryPotterHeroin.getGenre(), harryPotterHeroin);
    movieMap -> addMovie(equus.getGenre(), equus);

    // gets movies in action genre and puts in movie objects in vector
    std::vector<Movie_NS::Movie> actionMovies = movieMap -> getMovies("action");
    std::vector<std::string> actionTitles; // vector to push titles to
    
    // tester to print movies
    //for( Movie_NS::Movie movie : actionMovies)
    //  std::cout << "action: " << movie.getTitle() << std::endl;
    
    for(Movie_NS::Movie movie : actionMovies) // iterate through actionMovies
      actionTitles.push_back(movie.getTitle()); // push titles to title vectot
    
    // vector of how titles should appear in map
    std::vector<std::string> compareMovies {"Avatar", "The Dark Knight Rises", "Spectre"};
    
    return actionTitles == compareMovies; //returns comparison
  } // end testAction
  
  /* tests fantasy movies hashing correctly
   * tests getMovies of multimap, including only producing 5 movies */
  inline
  bool testFantasy()
  {
    // the multimap
      MovieHashMap_NS::MovieHashMap* movieMap = new MovieHashMap_NS::MovieHashMap ();

    // action movie object creation
    Movie_NS::Movie avatar{"Avatar", "action", 150.437577};
    Movie_NS::Movie spectre("Spectre", "action", 107.376788);
    Movie_NS::Movie theDarkKnightRises("The Dark Knight Rises", "action", 112.31295);
  
    // fantasy movie object creation
    Movie_NS::Movie piratesAtWorldsEnd{"Pirates of the Caribbean: At Worlds End", "fantasy", 139.082615};
    Movie_NS::Movie spiderman3("Spiderman 3", "fantasy", 115.699184);
    Movie_NS::Movie harryPotterHalf("Harry Potter and the Half Blood Prince", "fantasy", 98.8856367);
    Movie_NS::Movie harryPotterLady("Harry Potter and the Lady Gaga Conundrum", "fantasy", 88.8856367);
    Movie_NS::Movie harryPotterHeroin("Harry Potter and the Heroin Epidemic", "fantasy", 87.8856367);
    Movie_NS::Movie equus("Equus", "fantasy", 87.8856367);

    // add movies to the map
    movieMap -> addMovie(avatar.getGenre(), avatar);
    movieMap -> addMovie(piratesAtWorldsEnd.getGenre(), piratesAtWorldsEnd);
    movieMap -> addMovie(spiderman3.getGenre(), spiderman3);
    movieMap -> addMovie(theDarkKnightRises.getGenre(), theDarkKnightRises);
    movieMap -> addMovie(spectre.getGenre(), spectre);
    movieMap -> addMovie(harryPotterHalf.getGenre(), harryPotterHalf);
    movieMap -> addMovie(harryPotterLady.getGenre(), harryPotterLady);
    movieMap -> addMovie(harryPotterHeroin.getGenre(), harryPotterHeroin);
    movieMap -> addMovie(equus.getGenre(), equus);

    // gets fantasy movies from map and puts movie objects in vector
    std::vector<Movie_NS::Movie> fantasyMovies = movieMap -> getMovies("fantasy");
    std::vector<std::string> fantasyTitles; // vector to push hold titles
   
    for(Movie_NS::Movie movie : fantasyMovies) // iterate through fantasy movies
      fantasyTitles.push_back(movie.getTitle()); // push titles to title vector
    
    //tester to print fantasy movies
    //for( Movie_NS::Movie movie : fantasyMovies)
    //  std::cout << "fantasy: " << movie.getTitle() << std::endl;
    
    // vector how should look
    std::vector<std::string> compareMovies {"Pirates of the Caribbean: At Worlds End",
                                            "Spiderman 3", "Harry Potter and the Half Blood Prince",
                                            "Harry Potter and the Lady Gaga Conundrum",
                                            "Harry Potter and the Heroin Epidemic"};
    
    return fantasyTitles == compareMovies; // return comparison
  }

  inline
  bool testDanielCraig()
  {
    // multimap
    ActorHashMap_NS::ActorHashMap* actorMap = new ActorHashMap_NS::ActorHashMap();

    Movie_NS::Movie avatar("Avatar", "action", 150.437577);
    Movie_NS::Movie spectre("Spectre", "action", 107.376788);
    Movie_NS::Movie theDarkKnightRises("The Dark Knight Rises", "action", 112.31295);
  
    // fantasy movie object creation
    Movie_NS::Movie piratesAtWorldsEnd{"Pirates of the Caribbean: At Worlds End", "fantasy", 139.082615};
    Movie_NS::Movie spiderman3("Spiderman 3", "fantasy", 115.699184);
    Movie_NS::Movie harryPotterHalf("Harry Potter and the Half Blood Prince", "fantasy", 98.8856367);
    Movie_NS::Movie harryPotterLady("Harry Potter and the Lady Gaga Conundrum", "fantasy", 88.8856367);
    Movie_NS::Movie harryPotterHeroin("Harry Potter and the Heroin Epidemic", "fantasy", 87.8856367);
    Movie_NS::Movie equus("Equus", "fantasy", 87.8856367);

   // Daniel Craig movie object creation
    Movie_NS::Movie goldenCompass{"The Golden Compass", "adventure", 42.990986};
    Movie_NS::Movie layercake{"Layer Cake", "drama", 24.0034};

    // Daniel Radcliffe movie object creation
    Movie_NS::Movie victorFrankenstein{"Victor Frankenstein", "science fiction", 24.821138};
    Movie_NS::Movie harryPotterGoblet{"Harry Potter and the Goblet of Fire", "fantasy", 101.250416};

    

    // add Danel Craig movies to map
    actorMap -> addMovie("Daniel Craig", spectre);
    actorMap -> addMovie("Daniel Craig", goldenCompass);
    actorMap -> addMovie("Daniel Craig", layercake);
    
    // add Daniel Radcliffe movies to map
    actorMap -> addMovie("Daniel Radcliffe", harryPotterGoblet);
    actorMap -> addMovie("Daniel Radcliffe", harryPotterHalf);
    actorMap -> addMovie("Daniel Radcliffe", victorFrankenstein);
    actorMap -> addMovie("Daniel Radcliffe", harryPotterLady);
    actorMap -> addMovie("Daniel Radcliffe", harryPotterHeroin);
    actorMap -> addMovie("Daniel Radcliffe", equus);
    
    // get Daniel Craig movies
    std::vector<Movie_NS::Movie> danielCraigmovies = actorMap -> getMovies("Daniel Craig");
  
    // tester to print out movies
    //for(Movie_NS::Movie movie : danielCraigmovies)
    //  std::cout << "Daniel Craig stars in " << movie.getTitle() << std::endl;
    
    std::vector<std::string> craigTitles; // vector to hold titles
    
    for(Movie_NS::Movie movie : danielCraigmovies) // iterate through vector of movie objs
      craigTitles.push_back(movie.getTitle()); // push back titles to string vector
    
    std::vector<std::string> compareMovies{"Spectre", "The Golden Compass", "Layer Cake"};
    
    return craigTitles == compareMovies;
  }; // end testDanielCraig

  inline
  bool testDanielRadcliffe()
  {
    // create multiamp
    ActorHashMap_NS::ActorHashMap* actorMap = new ActorHashMap_NS::ActorHashMap();
  
    // action movie object creation
    Movie_NS::Movie avatar("Avatar", "action", 150.437577);
    Movie_NS::Movie spectre("Spectre", "action", 107.376788);
    Movie_NS::Movie theDarkKnightRises("The Dark Knight Rises", "action", 112.31295);
  
    // fantasy movie object creation
    Movie_NS::Movie piratesAtWorldsEnd{"Pirates of the Caribbean: At Worlds End", "fantasy", 139.082615};
    Movie_NS::Movie spiderman3("Spiderman 3", "fantasy", 115.699184);
    Movie_NS::Movie harryPotterHalf("Harry Potter and the Half Blood Prince", "fantasy", 98.8856367);
    Movie_NS::Movie harryPotterLady("Harry Potter and the Lady Gaga Conundrum", "fantasy", 88.8856367);
    Movie_NS::Movie harryPotterHeroin("Harry Potter and the Heroin Epidemic", "fantasy", 87.8856367);
    Movie_NS::Movie equus("Equus", "fantasy", 87.8856367);

   // daniel creaig movie objects
    Movie_NS::Movie goldenCompass{"The Golden Compass", "adventure", 42.990986};
    Movie_NS::Movie layercake{"Layer Cake", "drama", 24.0034};

    // Daniel Radcliffe movie objects
    Movie_NS::Movie victorFrankenstein{"Victor Frankenstein", "science fiction", 24.821138};
    Movie_NS::Movie harryPotterGoblet{"Harry Potter and the Goblet of Fire", "fantasy", 101.250416};

     // add Daniel Craig movies to map
    actorMap -> addMovie("Daniel Craig", spectre);
    actorMap -> addMovie("Daniel Craig", goldenCompass);
    actorMap -> addMovie("Daniel Craig", layercake);
    
    // add Daniel Radcliffe movies to map
    actorMap -> addMovie("Daniel Radcliffe", harryPotterGoblet);
    actorMap -> addMovie("Daniel Radcliffe", harryPotterHalf);
    actorMap -> addMovie("Daniel Radcliffe", victorFrankenstein);
    actorMap -> addMovie("Daniel Radcliffe", harryPotterLady);
    actorMap -> addMovie("Daniel Radcliffe", harryPotterHeroin);
    actorMap -> addMovie("Daniel Radcliffe", equus);
    std::vector<Movie_NS::Movie> danielRadcliffemovies = actorMap -> getMovies("Daniel Radcliffe");

    // tester to print movies
    //for(Movie_NS::Movie movie : danielRadcliffemovies)
    //  std::cout << "Daniel Radcliffe stars in " << movie.getTitle() << std::endl;
    
    std::vector<std::string> radcliffeTitles; // vector to hold titles
    
    for(Movie_NS::Movie movie : danielRadcliffemovies) // iterate through vector of movie objs
      radcliffeTitles.push_back(movie.getTitle()); // push back titles to string vector
  
    std::vector<std::string> compareMovies{"Harry Potter and the Goblet of Fire",
                                           "Harry Potter and the Half Blood Prince",
                                           "Victor Frankenstein",
                                           "Harry Potter and the Lady Gaga Conundrum",
                                           "Harry Potter and the Heroin Epidemic"};
    
    return radcliffeTitles == compareMovies;
  }; // end testDanielRadcliffe
} // end MapTesting_NS

#endif // end MapTesting_h
