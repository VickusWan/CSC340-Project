#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ifstream dataSet("tmdb_5000_credits.csv");

    std::vector<std::string> movieID;
    std::vector<std::string> title;
    std::vector<std::string> cast;
    std::vector<std::string> crew;
    std::string line;
    int index = 0;

    while (std::getline(dataSet, line))
    {
        std::stringstream ss(line);

        std::string TempMovieID, TempName, TempCast, TempCrew;
        std::getline(ss, TempMovieID, ',');
        std::getline(ss, TempName, ',');
        std::getline(ss, TempCast, ',');
        std::getline(ss, TempCrew, '\n');
        index = index + 1;

        movieID.push_back(TempMovieID);
        title.push_back(TempName);
        cast.push_back(TempCast);
        crew.push_back(TempCrew);

    }

    for (int i = 0; i < index; i++) {
        std::cout << "ID: " << movieID[i] << " TITLE: " << title[i] << " CAST: " << cast[i] << " CREW: " << crew[i] << std::endl;
    }
}

