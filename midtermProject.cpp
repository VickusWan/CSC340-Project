#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

struct movies {
    //temp values
    // std::string TempBudget, TempGenres, TempHomepage, TempID, TempKeywords;
    // std::string TempOriginal_language, TempOriginal_title, TempOverview, TempPopularity;
    // std::string TempProduction_companies, TempProduction_countries, TempRelease_date, TempRevenue;
    // std::string TempRuntime, TempSpoken_languages, TempStatus, TempTagline, TempTitle, TempVote_average, TempVote_count;

    //vectors to store data
    // std::vector<std::string> budget, genres, homepage, id, keywords, original_Language, original_Title;
    // std::vector<std::string> overview, popularity, production_Companies, production_Countries;
    // std::vector<std::string> realese_date, revenue, runtime, spoken_Language, status, tagline;
    // std::vector<std::string> title, vote_Average, vote_Count;
    std::vector<std::string> genres, originalTitle, overview, runtime,voteAverage;
};

struct credits {
    //temp values
    std::string TempMovieID, TempName, TempCast, TempCrew;

    //vectors to store data
    std::vector<std::string> movieID;
    std::vector<std::string> title;
    std::vector<std::string> cast;
    std::vector<std::string> crew;
};

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

void moviesDataSet() {
    std::string openFilePath = "data/tmdb_5000_movies.csv";
    std::ifstream dataSet(openFilePath);

    movies data;
    std::string line;
    std::string genreBlock;
    std::string genre;
    std::string dump;
    int index = 0;

    std::string TempBudget, TempGenres, TempHomepage, TempID, TempKeywords, TempOriginalLanguage, TempOriginalTitle, TempOverview, TempPopularity;
    std::string  TempProductionCompanies, TempProductionCountries, TempReleaseDate, TempRevenue, TempRuntime, TempSpokenLanguages, TempStatus, TempTagline, TempTitle, TempVoteAverage;

    while (std::getline(dataSet, line))
    {
        // ignore header
        if (index==0)
        {
            index++;
            continue;
        }
        std::stringstream ss(line);

        //Fix me, we need to trim information before storing data to properly work

        //get lines to store                                     //storing data
        std::getline(ss, TempBudget, ',');                  // data.budget.push_back(data.TempBudget);
        std::getline(ss, TempGenres, ']');                  // data.genres.push_back(data.TempGenres);

        // chunk: series of genres
        // ex) "[{""id"": 28, ""name"": ""Action""}, {""id"": 12, ""name"": ""Adventure""}, {""id"": 14, ""name"": ""Fantasy""}, {""id"": 878, ""name"": ""Science Fiction""}
        std::stringstream chunk(TempGenres);

        // genreBlock: one part of genre block
        // ex) [{""id"": 28, ""name"": ""Action""}
        std::string genreList="";
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
        std::getline(ss, TempHomepage, ',');                // data.homepage.push_back(data.TempHomepage);
        std::getline(ss, TempID, ',');                      // data.id.push_back(data.TempID);
        std::getline(ss, TempKeywords, ']');                // data.keywords.push_back(data.TempKeywords);
        std::getline(ss, dump,',');
        std::getline(ss, TempOriginalLanguage, ',');       // data.original_Language.push_back(data.TempOriginal_language);
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

        std::getline(ss, TempPopularity, ',');              // data.popularity.push_back(data.TempPopularity);
        std::getline(ss, TempProductionCompanies, ']');     // data.production_Companies.push_back(data.TempProduction_companies);
        std::getline(ss, dump,',');
        std::getline(ss, TempProductionCountries, ']');     // data.production_Countries.push_back(data.TempProduction_countries);
        std::getline(ss, dump,',');
        std::getline(ss, TempReleaseDate, ',');             // data.realese_date.push_back(data.TempRelease_date);
        std::getline(ss, TempRevenue, ',');                 // data.revenue.push_back(data.TempRevenue);
        std::getline(ss, TempRuntime, ',');                 // data.runtime.push_back(data.TempRuntime);
        data.runtime.push_back(TempRuntime);
        std::getline(ss, TempSpokenLanguages, ']');         // data.spoken_Language.push_back(data.TempSpoken_languages);
        std::getline(ss, dump,',');
        std::getline(ss, TempStatus, ',');                  // data.status.push_back(data.TempStatus);
        std::getline(ss, TempTagline, ',');                 // data.tagline.push_back(data.TempTagline);
        std::getline(ss, TempTitle, ',');                   // data.title.push_back(data.TempTitle);
        std::getline(ss, TempVoteAverage, ',');             // data.vote_Average.push_back(data.TempVote_average);
        data.voteAverage.push_back(TempVoteAverage);
        // std::getline(ss, data.TempVote_count, '\n');             data.vote_Count.push_back(data.TempVote_count);

        index++;
    }

    // check vector contents, delete later
    std::cout << data.genres.at(0) << " " << data.originalTitle.at(0)  << " " <<  data.overview.at(0) << " " << data.runtime.at(0) << " " << data.voteAverage.at(0) << std::endl;

}

void creditsDataSet() {
    std::ifstream dataSet("data/tmdb_5000_credits.csv");

    credits data;
    std::string line;
    int index = 0;

    while (std::getline(dataSet, line))
    {
        std::stringstream ss(line);

        //Fix me, we need to trim extra characters before storing information to properly work

        //get lines to store                         //storing data
        std::getline(ss, data.TempMovieID, ',');     data.movieID.push_back(data.TempMovieID);
        std::getline(ss, data.TempName, ',');        data.title.push_back(data.TempName);
        std::getline(ss, data.TempCast, ',');        data.cast.push_back(data.TempCast);
        std::getline(ss, data.TempCrew, '\n');       data.crew.push_back(data.TempCrew);
        index = index + 1;
    }

    /*for (int i = 0; i < index; i++) {
        std::cout << "ID: " << data.movieID[i] << " TITLE: " << data.title[i] << " CAST: " << data.cast[i] << " CREW: " << data.crew[i] << std::endl;
    }*/
}

int main()
{
    std::string select;

    //Fix me, create a loop in case the user misspell the input

    std::cout << "Which dataset do you want to use?" << std::endl;
    std::cout << "Enter 'credits' or 'movies'" << std::endl;
    std::cin >> select;

    if (select == "movies") {
        moviesDataSet();
    }

    else if (select == "credits") {
        creditsDataSet();
    }

    else {
        std::cout << "choose a different option" << std::endl;
    }

    return 0;
}

