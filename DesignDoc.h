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
 
 --------------Problem Analysis and algorith design ----------------
 Problem: input: 2 different csv files
          output: movie recommendations based on user input
 
 ******************************
 *     program design         *
 ******************************
    1. read in csv data source files
    2. clean up files for what we need
    3. put data into hashmaps
    4. main menu querying if user wants to search by genre or actor
    5. user input of genre/actor based on choice
    6. return movie recommendations
 
 
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
