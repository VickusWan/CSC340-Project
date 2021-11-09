#ifndef creditDataSet_hpp
#define creditDataSet_hpp

#include <vector>
#include <string>


// declare namespace NS_MOVIE+DATA_SET
namespace NS_CREDIT_DATA_SET {
   struct credits {
        // vectors to store data
       std::vector<std::string> movieID;
        std::vector<std::string> title;
        std::vector<std::string> cast;
    };

   
   // these are prototype of functions
   credits creditDataSet();
}

#endif
