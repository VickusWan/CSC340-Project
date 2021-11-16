//
//  DesignDoc.h
//  
//
//  Created by Brandon on 11/10/21.
//  Movie Recommendation Engine
//  Group 3:
//  Brandon Cruz-Youll
//  Adrian Paul Enriquez
//  Trinity Godwin
//  Yoshimasa Iwano
//  Armando Partida Dela O
//  Victor Uong

/*
 
 --------------Problem Analysis and algorithm design ----------------
 Problem: input: 2 different csv files
          output: movie recommendations based on user input
 
 ******************************
 *     program design         *
 ******************************
    1. read in csv data source files
    2. clean up files for what we need
        These steps are done in Credit and Movie data set
    3. put data into hashmaps
    4. main menu querying if user wants to search by genre or actor
    5. user input of genre/actor based on choice
    6. return movie recommendations
        This is accomplished by using the user input to
        query the different HashMaps 
 
 ******************************
 *   algortihm analysis       *
 ******************************
 main.cpp
 1. void main(std::string select, MovieHashMap_NS::MovieHashMap movieMap, MovieHashMap_NS::MovieHashMap actorMap)
  a. input  string select, and a movie multimap and an actor multimap
  b. output nothing, function is void
  c. sample input:
     the string is 'genre', 'actor' or 'random' while the multimaps are always the same
  d. pseudocode
  if select is 'genre'
    string to hold genre
    ignore whatever is in cout buffer
    printout "What genre would you like recommendations?"
    get users genre
    initialize vector of movies using movieMap -> getMovies(genre)
    for top 5 movies
      print out "Title: "  and movie title
  if select is 'actor'
   string to hold actor
   ignore whatever is in cout buffer
   printout "What actore would you like recommendations?"
   get users actor
   initialize vector of movies using movieMap -> getMovies(actor)
   for top 5 movies
     print out "Title: "  and movie title with genre 
  if selected random movie
    select random movie based on random number generator and the total number of movies
 
  e. given the use of multimaps, this should be logorithmic complexity.
 
 2. int main()
    a. input none
    b. output 0 if all goes well
    c. sample input: n/a
    d. pseudocode
       create new movieMap
       get the genre dataset
       create new actorMap
       get the credits dataset
      
      iterate through dataset
        get title
        get genre
        get rating
        put into Movie object
        put Movie object into movieMap with key genre
 
      iterate through dataset
        get title
        get genre
        get cast
        create movie object
        for each cast member
          put movie object into moviemap with key actor
      
        while loop for menu
          print out Movie Recommendations
          print out instructions for selecting genre, actor, random or quit
          ask user for entry
          validate entry
          if valid, call void menu with selection
      e. the complexity is O(n)
          
 ******************************
 *   built-in data types      *
 ******************************
    1. string
    2. vector
    3. map/multimap
    
 ******************************
 *  user-defined data types   *
 ******************************
   1. CreditDataSet
       A. struct
          I. constructor does the heavy lifting
             open file
             while loop to read line by line
               ignore header, increment index
               throw line into stringstream
               get column by column (movieID, title) and push to vectors
               cast dissect the cast block in while loop
                 find "name" field
                 check if at least 1 cast
                 create cast list
               push cast list
               increment index
             return data
       B. vector of movieID
       C. vector of title
       D. vector of cast

    2. MovieDataSet
       A. struct
           I. constructor does the heavy lifting
              open file
              while loop to read line by line
                if header, ignore it, increment index
                grab budget
                grab genres
                dissect genre block in while loop
                grab homepage
                grab movieID
                grab keywords
                grab original language
                grab temporary title
                grab overview block in while loop
                grab popularity
                grab production companies
                grab release date
                grab revenue
                grab runtime
                grab spoken languages
                grab status
                grab title
                grab vote average
                push the lot to vectors
              return data
       B. vector of movieID
       C. vector of genre
       D. vector of title
       E. vector of overview
       F. vector of runtime
       G. vector of vote average
 
    3. Movie Class
        A. movie title
        B. vote average
        C. genre
        D. need method to get title
        E. need method to get average
        F. need method to get genre
 
    4. ActorHashMap
        A. multimap (due to multiple entries with same key needed and quick searching based on key)
            I. note: multimaps use pointers for access rather than .methods
        B. key: actor name
        C. value: movie object that actor is in
        D. need add movie method with key and value
        E. need get movies method based on key search
            I. only return up to 5 movies to not be excessive
    
    5. MovieHashMap
        A. multimap (due to multiple entries with same key needed and quick searching based on key)
            I. note: multimaps use pointers for acess rather than .methods
        B. key: genre
        C. value: movie object that is in genre
        D. need add movie method with key and value
        E. need get movies method based on key search
            I. only return up to 5 movies to not be excessive
 

 
      
 */
