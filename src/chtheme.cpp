#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <filesystem>
#include "functions.hpp"
#include <iostream>
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
  //Just testing!
  
  std::string config_location  = chf::GetConfigLocation(expected_locations);
  std::string *config_pointer1 = chf::Config(config_location);
  std::string *config_pointer2 = chf::Config({});

  std::cout << "\n" << *config_pointer1 << "\n" << *config_pointer2;
  
  return(0);
}



