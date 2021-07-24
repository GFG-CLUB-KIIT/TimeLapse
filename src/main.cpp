/*
-------------------------------------------------------------
@file       : Main.cpp
@author     : Aditya Das, Souvik, Snehil
@date       : 19.05.2021
@brief      : Main operating file of the application
-------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <vector>

#include "../include/color/color.hpp"
#include "../include/CLI11/CLI11.hpp"
#include "../include/utils/file_handler.hpp"
#include "../include/utils/driver.hpp"
#include "../include/utils/misc.hpp"

using namespace cv;

int main(int argc, char *argv[])
{
   // CLI logic
   arguments args;
   CLI::App app{"CLI to create timelapse video"};
   // CLI options
   app.add_option("-s,--source", args.source_dir, "source directory containing frames")->required();
   app.add_option("-o, --output", args.output_file_name, "output file name [default: output.avi]");
   app.add_option("-f,--frames", args.frames, "frames for making video [default: 25]");
   app.add_option("-z,--filter", args.filter_name, "Name to filter to be applied to each frame");
   app.add_option("-v,--value", args.filter_value, "Value of the filter provided in -z/--filter option");
   CLI11_PARSE(app, argc, argv);
   std::cout << banner << std::endl;

   // application logic
   std::vector<std::string> image_path;
   std::vector<cv::Mat> image_list;

   //read image in a vector
   read_images(args.source_dir, image_list);
   // convert collected image to video
   make_timelapse(image_list, args);

   cout << color::green << "\nFinished!" << color::reset << std::endl;

   return 0;
}