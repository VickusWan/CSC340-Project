#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

struct movies {
    //temp values
    std::string TempBudget, TempGenres, TempHomepage, TempID, TempKeywords;
    std::string TempOriginal_language, TempOriginal_title, TempOverview, TempPopularity;
    std::string TempProduction_companies, TempProduction_countries, TempRelease_date, TempRevenue;
    std::string TempRuntime, TempSpoken_languages, TempStatus, TempTagline, TempTitle, TempVote_average, TempVote_count;

    //vectors to store data
    std::vector<std::string> budget, genres, homepage, id, keywords, original_Language, original_Title;
    std::vector<std::string> overview, popularity, production_Companies, production_Countries;
    std::vector<std::string> realese_date, revenue, runtime, spoken_Language, status, tagline;
    std::vector<std::string> title, vote_Average, vote_Count;
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

void moviesDataSet() {
    std::string openFilePath = "data/tmdb_5000_movies.csv";
    std::ifstream dataSet(openFilePath);

    std::string saveFilePath = "data/movie_genre.csv";
    std::ofstream extractDataSet(saveFilePath);

    movies data;
    std::string line;
    std::string genreBlock;
    std::string genre;
    std::string dump;
    int index = 0;

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
        std::getline(ss, data.TempBudget, ',');                  data.budget.push_back(data.TempBudget);
        std::getline(ss, data.TempGenres, ']');                  data.genres.push_back(data.TempGenres);

        // chunk: series of genres
        // ex) "[{""id"": 28, ""name"": ""Action""}, {""id"": 12, ""name"": ""Adventure""}, {""id"": 14, ""name"": ""Fantasy""}, {""id"": 878, ""name"": ""Science Fiction""}
        std::stringstream chunk(data.TempGenres);

        // genreBlock: one part of genre block
        // ex) [{""id"": 28, ""name"": ""Action""}
        while(std::getline(chunk, genreBlock,','))
        {
            std::size_t found = genreBlock.find("name");
            // check if there is genre at least one
            if (found!=std::string::npos)
            {
                // extract genre name
                std::string genreTail = genreBlock.substr(found+10);
                std::string genre = genreTail.substr(0, genreTail.length()-3);

                // save genre name in csv file
                extractDataSet << genre << ' ';
            }
        }
        extractDataSet << ',';
        std::getline(ss, dump,',');
        std::getline(ss, data.TempHomepage, ',');                data.homepage.push_back(data.TempHomepage);
        std::getline(ss, data.TempID, ',');                      data.id.push_back(data.TempID);
        std::getline(ss, data.TempKeywords, ']');                data.keywords.push_back(data.TempKeywords);
        std::getline(ss, dump,',');
        std::getline(ss, data.TempOriginal_language, ',');       data.original_Language.push_back(data.TempOriginal_language);
        std::getline(ss, data.TempOriginal_title, ',');          data.original_Title.push_back(data.TempOriginal_title);
        extractDataSet << data.TempOriginal_title << std::endl;
        std::getline(ss, data.TempOverview, ',');                data.overview.push_back(data.TempOverview);
        std::getline(ss, data.TempPopularity, ',');              data.popularity.push_back(data.TempPopularity);
        std::getline(ss, data.TempProduction_companies, ']');    data.production_Companies.push_back(data.TempProduction_companies);
        std::getline(ss, dump,',');
        std::getline(ss, data.TempProduction_countries, ']');    data.production_Countries.push_back(data.TempProduction_countries);
        std::getline(ss, dump,',');
        std::getline(ss, data.TempRelease_date, ',');            data.realese_date.push_back(data.TempRelease_date);
        std::getline(ss, data.TempRevenue, ',');                 data.revenue.push_back(data.TempRevenue);
        std::getline(ss, data.TempRuntime, ',');                 data.runtime.push_back(data.TempRuntime);
        std::getline(ss, data.TempSpoken_languages, ']');        data.spoken_Language.push_back(data.TempSpoken_languages);
        std::getline(ss, dump,',');
        std::getline(ss, data.TempStatus, ',');                  data.status.push_back(data.TempStatus);
        std::getline(ss, data.TempTagline, ',');                 data.tagline.push_back(data.TempTagline);
        std::getline(ss, data.TempTitle, ',');                   data.title.push_back(data.TempTitle);
        std::getline(ss, data.TempVote_average, ',');            data.vote_Average.push_back(data.TempVote_average);
        std::getline(ss, data.TempVote_count, '\n');             data.vote_Count.push_back(data.TempVote_count);

        index++;
    }
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

