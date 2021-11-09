#ifndef Movie_h
#define Movie_h

#include <string>

namespace Movie_NS {
    class Movie{
        public:
        Movie::Movie(std::string newTitle, double newVoteAverage);
        std::string GetTitle();
        double GetAverage();
        
        private:
        std::string title;
        double voteAverage;
    }

}

#endif
