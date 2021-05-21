#include <iostream>
#include "color/color.hpp"
#include <experimental/filesystem>
#include <string>
#include <vector>


int main(int argc, char **argv) {
   std::vector<std::string> image;
   std::cout << color::green << "test : 1"<< color::reset << std::endl;
   std::string path = argv[1];
   for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
      std::string img = entry.path();
      if((img.find(".jpg") != std::string::npos) or (img.find(".jpeg") != std::string::npos) or (img.find(".png") != std::string::npos)) {
         image.push_back(img);
      }
   }

   if(image.size() == 0) {
      std::cout << color::red << "No image files in the current directory" << color::reset <<std::endl;
   } 
   else {
   for(auto i : image) {
      std::cout << i << std::endl;
   }
   }
   return 0;
}

