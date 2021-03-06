#include "functions.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <filesystem>
#include <wordexp.h>

namespace chf {
  bool Fexists(std::string &filename)
  {
    struct stat buffer;
    return(stat(filename.c_str(), &buffer) == 0);
  }

  void PathExpand(std::string &word)
  {
    char ** w;
    wordexp_t p;
    wordexp(word.c_str(), &p, 0);
    w=p.we_wordv;
    std::string new_word;
    for (size_t i=0;i<p.we_wordc;i++)
      new_word+=w[i];
    wordfree(&p);
    word=new_word;
  }

  std::string GetConfigLocation(std::vector<std::string> &expected_locations)
  {
    for (int i=0; i < expected_locations.size(); i++)
      {
	PathExpand(expected_locations[i]);
	if (Fexists(expected_locations[i]))
	  return(expected_locations[i]);
      }
  }
  
  /*
  std::vector<std::string> ReadConfig(const std::string &variable, std::string &config_location)
  {
  }

std::vector<std::string> get_app_themes_location(const std::string &appname, std::string &config_location)
{
  std::vector<std::string> all_paths = read_config("locations",config_location);
  std::vector<std::string> valid_paths;

  for (int i=0; i < all_paths.size(); i++)
    {
      std::string temp_path=all_paths[i] + appname;
      if (Fexists(temp_path))
	valid_paths.push_back(all_paths[i]);
    }
  return(valid_paths);
}

void list_themes(const std::string &appname, std::string &config_location)
{
  std::vector<std::string> themes;
  std::vector<std::string> paths=get_app_themes_location(appname,config_location);

  for (int i=0;i < paths.size(); i++)
    for(const auto & entry : std::filesystem::directory_iterator(paths[i]))
      themes.push_back(entry.path());
}

*/
}
