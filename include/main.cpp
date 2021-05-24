#include <iostream>
#include "color/color.hpp"
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <opencv2/highgui.hpp>


int main(int argc, char **argv) {
   std::vector<std::string> image_path;
   std::cout << color::green << "test : 1"<< color::reset << std::endl;
   std::string path = argv[1];
   for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
      std::string img_path = entry.path();
      if((img_path.find(".jpg") != std::string::npos) or (img_path.find(".jpeg") != std::string::npos) or (img_path.find(".png") != std::string::npos)) {
         image_path.push_back(img_path);
      }
   }

   if(image_path.size() == 0) {
      std::cout << color::red << "No image files in the current directory" << color::reset <<std::endl;
   } 
   else {
   for(auto i : image_path) {
      cv::Mat image = cv::imread(i, CV_LOAD_IMAGE_COLOR);
      std::cout << i << std::endl;
      std::cout << "Width : " << image.size().width << std::endl;
      std::cout << "Height : " << image.size().height <<std::endl;
      }
   }
   return 0;
}

