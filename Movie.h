#ifndef Movie_h
#define Movie_h

#include <string>

namespace Movie_NS {
    class Movie{
        public:
        Movie::Movie(std::string newTitle, std::string newGenre, double newVoteAverage,);
        std::string GetTitle();
        double GetAverage();
        std::string GetGenre();

        private:
        std::string title;
        double voteAverage;
        std::string genre;
    }

}

#endif
