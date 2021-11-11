//
//  DesignDoc.h
//  
//
//  Created by Brandon on 11/10/21.
//

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
    1. Movie Class
        a. movie title
        b. vote average
        c. genre
        d. need method to get title
        e. need method to get average
        f. need method to get genre
 
    2. ActorHashMap
        a. multimap (due to multiple entries with same key needed and quick searching based on key)
            i. note: multimaps use pointers for access rather than .methods
        b. key: actor name
        c. value: movie object that actor is in
        d. need add movie method with key and value
        e. need get movies method based on key search
            i. only return up to 5 movies to not be excessive
    
    3. MovieHashMap
        a. multimap (due to multiple entries with same key needed and quick searching based on key)
            i. note: multimaps use pointers for acess rather than .methods
        b. key: genre
        c. value: movie object that is in genre
        d. need add movie method with key and value
        e. need get movies method based on key search
            i. only return up to 5 movies to not be excessive
 
      
 */
