#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <filesystem>
#include "functions.hpp"
#include <wordexp.h>

//Hardcoded config locations below:

std::vector<std::string> expected_locations =
{"$HOME/chtheme.conf",
 "$HOME/.config/chtheme.conf"};

int main(int argc, char ** argv)
{
  //Check for config availability, 
  if (argc == 0)
   {
    printf("Use 'chtheme help' for available commands");
    return 1;
   }  
  std::string config_location = chf::GetConfigLocation(expected_locations);
  printf("%s",config_location.c_str());
  return 0;
}



