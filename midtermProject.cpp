#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

// struct movies {
//     // vectors to store data
//     std::vector<std::string> genres, originalTitle, overview, runtime,voteAverage;
// };

// struct credits {
//     // vectors to store data
//     std::vector<std::string> title;
//     std::vector<std::string> cast;
// };

// // check if the string is number, or not 
// bool isNumber(const std::string& str) {
//     bool numberCheck = false;
//     std::regex re("\\d+\\.\\d+");
//     // if a string is number, return true
//     if (std::regex_match(str, re)){
//         numberCheck = true;
//     }
//     return numberCheck;
// }

// void moviesDataSet() {
//     std::string openFilePath = "data/tmdb_5000_movies.csv";
//     std::ifstream dataSet(openFilePath);

//     movies data;
//     std::string line;
//     int index = 0;

//     std::string TempBudget, TempGenres, TempHomepage, TempID, TempKeywords, TempOriginalLanguage, TempOriginalTitle, TempOverview, TempPopularity;
//     std::string  TempProductionCompanies, TempProductionCountries, TempReleaseDate, TempRevenue, TempRuntime, TempSpokenLanguages, TempStatus, TempTagline, TempTitle, TempVoteAverage;

//     // read line by line
//     while (std::getline(dataSet, line))
//     {
//         // ignore header
//         if (index==0)
//         {
//             index++;
//             continue;
//         }
//         std::stringstream ss(line);

//         // get column by column                                 
//         std::getline(ss, TempBudget, ','); 
//         std::getline(ss, TempGenres, ']');

//         // chunk: series of genres
//         // e.g) "[{""id"": 28, ""name"": ""Action""}, {""id"": 12, ""name"": ""Adventure""}, {""id"": 14, ""name"": ""Fantasy""}, {""id"": 878, ""name"": ""Science Fiction""}
//         std::stringstream chunk(TempGenres);

//         // genreBlock: one part of genre block
//         // e.g) [{""id"": 28, ""name"": ""Action""}
//         std::string genreList="";
//         std::string genreBlock;
//         std::string dump;
//         // get one genre by genre
//         while(std::getline(chunk, genreBlock,','))
//         {
//             std::size_t found = genreBlock.find("name");
//             // check if there is genre at least one
//             if (found!=std::string::npos)
//             {
//                 // extract genre name
//                 std::string genreTail = genreBlock.substr(found+10);
//                 std::string genre = genreTail.substr(0, genreTail.length()-3);

//                 // create genre list
//                 genreList += genre;
//                 genreList += ",";
//             }
//         }
//         data.genres.push_back(genreList);
//         std::getline(ss, dump,',');
//         std::getline(ss, TempHomepage, ',');       
//         std::getline(ss, TempID, ',');          
//         std::getline(ss, TempKeywords, ']');          
//         std::getline(ss, dump,',');
//         std::getline(ss, TempOriginalLanguage, ',');    
//         std::getline(ss, TempOriginalTitle, ',');          
//         data.originalTitle.push_back(TempOriginalTitle);
        
//         // there is comma in overview, so read strings until the end of overview
//         std::string overviewSentence="";
//         std::getline(ss, TempOverview, ','); 
//         while(!isNumber(TempOverview)) {
//             overviewSentence += TempOverview;
//             std::getline(ss, TempOverview, ',');
//         }
//         data.overview.push_back(overviewSentence);  

//         std::getline(ss, TempPopularity, ',');           
//         std::getline(ss, TempProductionCompanies, ']');  
//         std::getline(ss, dump,',');
//         std::getline(ss, TempProductionCountries, ']');    
//         std::getline(ss, dump,',');
//         std::getline(ss, TempReleaseDate, ',');        
//         std::getline(ss, TempRevenue, ',');              
//         std::getline(ss, TempRuntime, ',');               
//         data.runtime.push_back(TempRuntime);
//         std::getline(ss, TempSpokenLanguages, ']');         
//         std::getline(ss, dump,',');
//         std::getline(ss, TempStatus, ',');               
//         std::getline(ss, TempTagline, ',');            
//         std::getline(ss, TempTitle, ',');                 
//         std::getline(ss, TempVoteAverage, ',');             
//         data.voteAverage.push_back(TempVoteAverage);
        

//         index++;
//     }

//     // check vector contents, delete later
//     std::cout << data.genres.at(0) << " " << data.originalTitle.at(0)  << " " <<  data.overview.at(0) << " " << data.runtime.at(0) << " " << data.voteAverage.at(0) << std::endl;

// }

// void creditsDataSet() {
//     std::string openFilePath = "data/tmdb_5000_credits.csv";
//     std::ifstream dataSet(openFilePath);

//     credits data;
//     std::string line;
//     std::string TempMovieID, TempTitle, TempCast;
//     int index = 0;

//     // read line by line
//     while (std::getline(dataSet, line))
//     {
//         // ignore header
//         if (index==0)
//         {
//             index++;
//             continue;
//         }
//         std::stringstream ss(line);

//         // get column by column                
//         std::getline(ss, TempMovieID, ',');    
//         std::getline(ss, TempTitle, ',');        
//         data.title.push_back(TempTitle);
//         std::getline(ss, TempCast, ']');   

//         // chunk: a series of casts
//         // e.g) [{"cast_id": 242, "character": "Jake Sully", "credit_id": "5602a8a7c3a3685532001c9a", "gender": 2, "id": 65731, "name": "Sam Worthington", "order": 0}, ...
//         std::stringstream chunk(TempCast);

//         // castBlock: one part of cast block
//         // e.g) [{"cast_id": 76, "character": "Tony Stark / Iron Man", "credit_id": "55e256d292514162cd000e40", "gender": 2, "id": 3223, "name": "Robert Downey Jr.", "order": 0}
//         std::string castList="";
//         std::string castBlock;
//         std::string dump;
//         // get one cast by cast
//         while(std::getline(chunk, castBlock,'}'))
//         {
//             std::size_t found = castBlock.find("name");
//             // check if there is cast at least one
//             if (found!=std::string::npos)
//             {
//                 std::string castTail = castBlock.substr(found+10);
//                 std::size_t order = castTail.find("order");
//                 std::string cast = castTail.substr(0, order-6);
//                 // create cast list
//                 castList += cast;
//                 castList += ",";
//             }
//         }
//         data.cast.push_back(castList);
        
//         index++;
//     }

//      // check vector contents, delete later
//     std::cout << " TITLE: " << data.title.at(0) << " CAST: " << data.cast.at(0) << std::endl;
// }

int main()
{
    std::string select;

    //Fix me, create a loop in case the user misspell the input

    std::cout << "Which dataset do you want to use?" << std::endl;
    std::cout << "Enter 'credits' or 'movies'" << std::endl;
    std::cin >> select;

    if (select == "movies") {
        // moviesDataSet();
    } else if (select == "credits") {
        // creditsDataSet();
    } else {
        std::cout << "choose a different option" << std::endl;
    }

    return 0;
}

