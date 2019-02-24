#include <iostream>
#include <string>
#include "CSVdata.h"


std::string getFileName(const std::string& s) 
{

   char sep = '/';

#ifdef _WIN32
   sep = '\\';
#endif

   size_t i = s.rfind(sep, s.length());
   if (i != std::string::npos) 
   {
      return(s.substr(i+1, s.length() - i));
   }

   return("");
}



int main(int argc, char **argv) {
    //std::cout << "Hello, world!" << std::endl;
    //std::cout << argv[0] << std::endl;
    //std::cout << argv[1] << std::endl;
    std::string filePath = argv[1];
    
    CSVdata::CSVDataReader testRun = CSVdata::CSVDataReader(filePath, getFileName(filePath));
    
    testRun.RunProgram();

    return 0;
}
