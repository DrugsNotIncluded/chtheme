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

  //first init of config:
  
  std::string config_location  = chf::GetConfigLocation(expected_locations);
  chf::Config(config_location);
  /*
    Example usage:
  std::string config_pointer1 = *chf::Config({});
  std::string config_pointer2 = *chf::Config({});

  std::cout << "\n" << config_pointer1 << "\n" << config_pointer2;
  */

  //Test setup
  
  std::vector<std::string> keys_test=
    {"location",
     "override_apply"};
  
  std::vector<std::string> values_list = chf::ReadConfig(keys_test);

  for (int i=0;i< values_list.size();i++)
    printf("[%d]%s\n",i,values_list[i].c_str());
  
  return(0);
}



