#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <filesystem>
#include <wordexp.h>

namespace chf{
  /*
    Check for file existance
  */
  bool Fexists(std::string &filename);

  /*
    Expands environment variables in file path
  */
  void PathExpand(std::string &word);

  /*
    reads variables from config file
    only usefull inside other functions
  */
  std::vector<std::string> ReadConfig(std::vector<std::string> &key_list);

  std::string GetConfigLocation(std::vector<std::string> &expected_locations);

  std::string *Config(const std::string &config_location);

  /*
!!COMMAND LINE DISPLAYING!!

Displays content of paths returned by get_app_themes_location() in command line
  
void list_themes(std::string &appname,std::string &config_location);
  


cycles through themes paths, searches for specific app folder name
and when returns paths which contain app folder, for example:

Folders:

A/{memes,shemes}
B/{shemes}

if we ask for "memes" app when function will only return path to folder "B/"
but if we ask for "shemes" it will return both paths for A/ and B/

std::vector<std::string> get_app_themes_location(std::string &appname, std::string &config_location);



1) Function looks in <config path> and gets all base theme paths for current application via get_app_themes_location()
2) Function recursively searches for theme name match in all <base_path>/<application_name>
3) Now it should search for app theme apply function in <config_path>/apply_functions . Apply functions can be either shell script or binary
   but they should be named as <application name>_apply and accept at least one argument - path to theme file
4) Simply uses <app theme apply function> <path to theme> <optional implementation specific arguments>

void set_theme(std::string &appname, std::string &theme, std::string &config_location);

void get_apps(void);

void get_colors(std::string &appname, std::string &theme);

void display_help(void);

void dispatcher(std::string &command);
*/
}
