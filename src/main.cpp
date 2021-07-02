/*
-------------------------------------------------------------
@file       : Main.cpp
@author     : Aditya Das, Souvik Kar, Snehil
@date       : 19.05.2021
@brief      : Main operating file of the application
-------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "../include/color/color.hpp"
#include "../include/CLI11/CLI11.hpp"
#include "../include/utils/file_handler.hpp"

using namespace cv;

typedef struct
{
   std::string source_dir = "";
   std::string output_file_name = "./output.avi";
   int frames = 25;
   std::string filter_name = "";
   int filter_value = 0;
} arguments;

std::string const mvleft = "\033[1000D";
std::string const clearln = "\033[2K";

std::string const banner = "\     
      __             \n\
 ___ / /__ ____  ___ ___ \n\
/ -_) / _ `/ _ \\(_-</ _ \\ \n\
\\__/_/\\_,_/ .__/___/\\___/  V0.1.0\n\
         /_/              \n";

// Progress bar
void progress_bar(int current_frame_index, int total_frames)
{
   std::cout << mvleft << clearln;
   std::cout << color::blue << "processing: " << color::green << ((current_frame_index + 1) / total_frames) * 100 << "%" << color::reset;
}

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
   std::cout << color::blue << banner << color::reset;

   // application logic
   std::vector<std::string> image_path;
   std::vector<cv::Mat> image_list;

   int codec = VideoWriter::fourcc('H', '2', '6', '4');
   int h = 0, w = 0;

   read_images(args.source_dir, image_list);

   Size S = image_list[0].size();
   VideoWriter outputVideo;
   outputVideo.open(args.output_file_name, codec, args.frames, S, true);

   if (!outputVideo.isOpened())
   {
      std::cout << "Could not open the output video for write: " << endl;
      return 1;
   }

   // frames to video
   int total = image_list.size();
   for (int i = 0; i < total; i++)
   {
      outputVideo << image_list[i];
      progress_bar(i, total);
   }

   cout << color::green << "\nFinished!" << color::reset << endl;
   return 0;
}