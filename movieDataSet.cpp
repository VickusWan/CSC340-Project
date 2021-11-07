#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include "movieDataSet.h"

namespace NS_MOVIE_DATA_SET {

// check if the string is number, or not 
bool isNumber(const std::string& str) {
    bool numberCheck = false;
    std::regex re("\\d+\\.\\d+");
    // if a string is number, return true
    if (std::regex_match(str, re)){
        numberCheck = true;
    }
    return numberCheck;
}

movies movieDataSet() {
    std::string openFilePath = "data/tmdb_5000_movies.csv";
    std::ifstream dataSet(openFilePath);

    movies data;
    std::string line;
    int index = 0;

    std::string TempBudget, TempGenres, TempHomepage, TempID, TempKeywords, TempOriginalLanguage, TempOriginalTitle, TempOverview, TempPopularity;
    std::string  TempProductionCompanies, TempProductionCountries, TempReleaseDate, TempRevenue, TempRuntime, TempSpokenLanguages, TempStatus, TempTagline, TempTitle, TempVoteAverage;

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
        std::getline(ss, TempBudget, ','); 
        std::getline(ss, TempGenres, ']');

        // chunk: series of genres
        // e.g) "[{""id"": 28, ""name"": ""Action""}, {""id"": 12, ""name"": ""Adventure""}, {""id"": 14, ""name"": ""Fantasy""}, {""id"": 878, ""name"": ""Science Fiction""}
        std::stringstream chunk(TempGenres);

        // genreBlock: one part of genre block
        // e.g) [{""id"": 28, ""name"": ""Action""}
        std::string genreList="";
        std::string genreBlock;
        std::string dump;
        // get one genre by genre
        while(std::getline(chunk, genreBlock,','))
        {
            std::size_t found = genreBlock.find("name");
            // check if there is genre at least one
            if (found!=std::string::npos)
            {
                // extract genre name
                std::string genreTail = genreBlock.substr(found+10);
                std::string genre = genreTail.substr(0, genreTail.length()-3);

                // create genre list
                genreList += genre;
                genreList += ",";
            }
        }
        data.genres.push_back(genreList);
        std::getline(ss, dump,',');
        std::getline(ss, TempHomepage, ',');       
        std::getline(ss, TempID, ',');          
        std::getline(ss, TempKeywords, ']');          
        std::getline(ss, dump,',');
        std::getline(ss, TempOriginalLanguage, ',');    
        std::getline(ss, TempOriginalTitle, ',');          
        data.originalTitle.push_back(TempOriginalTitle);
        
        // there is comma in overview, so read strings until the end of overview
        std::string overviewSentence="";
        std::getline(ss, TempOverview, ','); 
        while(!isNumber(TempOverview)) {
            overviewSentence += TempOverview;
            std::getline(ss, TempOverview, ',');
        }
        data.overview.push_back(overviewSentence);  

        std::getline(ss, TempPopularity, ',');           
        std::getline(ss, TempProductionCompanies, ']');  
        std::getline(ss, dump,',');
        std::getline(ss, TempProductionCountries, ']');    
        std::getline(ss, dump,',');
        std::getline(ss, TempReleaseDate, ',');        
        std::getline(ss, TempRevenue, ',');              
        std::getline(ss, TempRuntime, ',');               
        data.runtime.push_back(TempRuntime);
        std::getline(ss, TempSpokenLanguages, ']');         
        std::getline(ss, dump,',');
        std::getline(ss, TempStatus, ',');               
        std::getline(ss, TempTagline, ',');            
        std::getline(ss, TempTitle, ',');                 
        std::getline(ss, TempVoteAverage, ',');             
        data.voteAverage.push_back(TempVoteAverage);
        

        index++;
    }

    // check vector contents, delete later
    // std::cout << data.genres.at(0) << " " << data.originalTitle.at(0)  << " " <<  data.overview.at(0) << " " << data.runtime.at(0) << " " << data.voteAverage.at(0) << std::endl;

    return data;
}

}