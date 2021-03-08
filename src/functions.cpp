#include "functions.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <filesystem>
#include <wordexp.h>
#include <fstream>

namespace chf {

  static std::string config_path;
  
  bool Fexists(std::string filename)
  {
    struct stat buffer;
    return(stat(filename.c_str(), &buffer) == 0);
  }

  std::string PathExpand(const std::string &word)
  {
    char ** w;
    wordexp_t p;
    wordexp(word.c_str(), &p, 0);
    w=p.we_wordv;
    std::string new_word;
    for (size_t i=0;i<p.we_wordc;i++)
      new_word+=w[i];
    wordfree(&p);
    return(new_word);
  }

  std::string GetConfigLocation(std::vector<std::string> &expected_locations)
  {
    for (int i=0; i < expected_locations.size(); i++)
      {
	if (Fexists(PathExpand(expected_locations[i]))==true)
	  return(expected_locations[i]);
      }
  }


  //you can access "config" value after first initialization (function usage)
  //*Config() always should be called without any parameters except the first call
 
  std::string *Config(const std::string &config_location)
  {
    static std::string config;
    static bool config_loaded;

    if (config_loaded!=true)
      {
	config=config_location;
	config_loaded=true;
	printf("%s","[LOG] Config loaded for the first time!\n");
      }
    return(&config); 
  }

  //Now we are ready to write functions which will use Config() instead of passing as variable every time!
  
  
  std::vector<std::string> ReadConfig(std::vector<std::string> &key_list)
  {
    //should split code into functions into another and explain it for my future self, this is a mess in current state 
    std::vector<std::string> value_list;   
    std::string config_location=*Config({});
    std::ifstream config_istream(config_location);
    
    for (std::string line; getline(config_istream, line);)
      {
	std::istringstream is_line(line);
	for (int i=0; i < key_list.size(); i++)
	  {
	    if (std::getline(is_line,key_list[i],'='))
	      {
		std::string value;
		if (std::getline(is_line, value))
		    value_list.push_back(value);
	      }
	  }
      }
    return(value_list);
  }

  
  
std::vector<std::string> AppThemesLocation(const std::string &appname)
{
  std::string config_location = *Config({});
  std::vector<std::string> keys = {"location"}; 
  
  std::vector<std::string> all_paths = ReadConfig(keys);
  std::vector<std::string> valid_paths;

  for (int i=0; i < all_paths.size(); i++)
    {
      std::string temp_path=PathExpand(all_paths[i]) + "/" + appname;
      if (Fexists(temp_path)==true)
	valid_paths.push_back(all_paths[i]);
    }
  return(valid_paths);
}

  /*
  
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
