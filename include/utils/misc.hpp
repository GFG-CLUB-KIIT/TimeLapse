#pragma once
#include <string>

// struct to store parsed commandline args
typedef struct
{
	std::string source_dir = "";
	std::string output_file_name = "./output.avi";
	int frames = 25;
	std::string filter_name = "";
	int filter_value = 0;
	float brightness_value = 0;
	float contrast_value = 1;
	float sharpness_value = 1;
	float blur_value = 1;
	float saturation_value = 1;

} arguments;

// banner for display
std::string const banner = "\     
      __             \n\
 ___ / /__ ____  ___ ___ \n\
/ -_) / _ `/ _ \\(_-</ _ \\ \n\
\\__/_/\\_,_/ .__/___/\\___/  V0.1.0\n\
         /_/              \n";