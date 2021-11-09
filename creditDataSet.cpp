#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


#include "creditDataSet.h"

namespace NS_CREDIT_DATA_SET {

credits creditDataSet() {
    std::string openFilePath = "data/tmdb_5000_credits.csv";
    std::ifstream dataSet(openFilePath);

    credits data;
    std::string line;
    std::string TempMovieID, TempTitle, TempCast;
    int index = 0;
    

    // read line by line
    while (std::getline(dataSet, line))
    {
        // ignore header
        if (index==0)
        {
            index++;
            continue;
        }
        std::stringstream ss(line);

        // get column by column                
        std::getline(ss, TempMovieID, ',');    
        std::getline(ss, TempTitle, ',');        
        data.title.push_back(TempTitle);
        data.movieID.push_back(TempMovieID);
        std::getline(ss, TempCast, ']');   

        // chunk: a series of casts
        // e.g) [{"cast_id": 242, "character": "Jake Sully", "credit_id": "5602a8a7c3a3685532001c9a", "gender": 2, "id": 65731, "name": "Sam Worthington", "order": 0}, ...
        std::stringstream chunk(TempCast);

        // castBlock: one part of cast block
        // e.g) [{"cast_id": 76, "character": "Tony Stark / Iron Man", "credit_id": "55e256d292514162cd000e40", "gender": 2, "id": 3223, "name": "Robert Downey Jr.", "order": 0}
        std::string castList="";
        std::string castBlock;
        std::string dump;
        // get one cast by cast
        while(std::getline(chunk, castBlock,'}'))
        {
            std::size_t found = castBlock.find("name");
            // check if there is cast at least one
            if (found!=std::string::npos)
            {
                std::string castTail = castBlock.substr(found+10);
                std::size_t order = castTail.find("order");
                std::string cast = castTail.substr(0, order-6);
                // create cast list
                castList += cast;
                castList += ",";
            }
        }
        //std::cout << TempTitle << std::endl;

        //std::cout << castList << std::endl;
        data.cast.push_back(castList);
        
        index++;
    }

    
    
     // check vector contents, delete later
    // std::cout << " TITLE: " << data.title.at(0) << " CAST: " << data.cast.at(0) << std::endl;
    
    return data;
}

}
