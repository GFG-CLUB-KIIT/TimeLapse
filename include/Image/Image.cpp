#include "Image.h"
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <opencv2/highgui.hpp>
#include "color/color.hpp"
Image::Image(std::string path) {
   if(read(path)) {
      std::cout<< color::green<< "Read : "<<color::reset<<path;
      

   }
   else {
      std::cout<< color::red << "Unable to read" <<color::reset<<std::endl;
   }
}

Image::Image(int width, int height, int channels) {

}


bool Image::read(std::string path) {
   cv::Mat image = cv::imread(path, CV_LOAD_IMAGE_COLOR);
   width = image.size().width;
   height = image.size().height;
   size = image.size();

   return size!=0;

}

