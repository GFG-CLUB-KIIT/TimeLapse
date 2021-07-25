/*
-------------------------------------------------------------
@file       : filter.cpp
@author     : Rupanshi Chawda, Aditya Das
@date       : 02.06.2021
@brief      : Parameter for manipulating Brightness and contrast of the images 
-------------------------------------------------------------
*/

#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "../utils/misc.hpp"
#include "../color/color.hpp"

using namespace cv;
using namespace std;

//**************** F I L T E R S ******************

//----------------BRIGHTNESS-----------------
void apply_brightness(std::vector<cv::Mat> &image_list, float br_val) {
   std::cout << "Changing Brightness : " ;
   float contrast = 1;
   for(auto &img : image_list){
      img.convertTo(img, -1, contrast, br_val);
   }
   std::cout << color::green << "Done" <<color::reset<<std::endl;
}
//---------------CONTRAST-------------------
void apply_contrast(std::vector<cv::Mat> &image_list, float con_val) {
   std::cout << "Changing Contrast : " ;
   float brightness = 0;
   for(auto &img : image_list){
      img.convertTo(img, -1, con_val, brightness);
   }
   std::cout << color::green << "Done" <<color::reset<<std::endl;
}


//---------SATURATION-----------
void apply_saturation(std::vector<cv::Mat> &image_list, float saturation_val) {
   std::cout << "Changing Saturation : " ;
   for(auto &img : image_list) {
      Mat hsv;
      cvtColor(img, hsv, COLOR_BGR2HSV);
      float factor = saturation_val;
      hsv = hsv * factor;
      cvtColor(hsv, img, COLOR_HSV2BGR);
   }
   std::cout << color::green << "Done" <<color::reset<<std::endl;
}



//----------------SHARPNESS ----------------
void apply_sharpen(std::vector<cv::Mat> &image_list, float sharpness_val) {
   Mat sharpeningKernel = (Mat_<double>(3,3) << 0, 0, 0, 0, sharpness_val, 0, 0, 0, 0);
   if(sharpness_val != 1)
   {
      sharpeningKernel = (Mat_<double>(3,3) << -1, -1, -1, -1, sharpness_val, -1, -1, -1, -1);
   }
   std::cout << "Changing Sharpness : " ;
   for(auto &img: image_list) {
      filter2D(img, img, -1, sharpeningKernel);
   }
   std::cout << color::green << "Done" <<color::reset<<std::endl;
}



//------------------ BLUR--------------------
void apply_blur(std::vector<cv::Mat> &image_list, float blurness) {
   
   std::cout << "Adjusting Blur : " ;
   for(auto &img: image_list) {
      blur(img, img, Size(blurness, blurness));
   }
   std::cout << color::green << "Done" <<color::reset<<std::endl;
}



void apply_filter(std::vector<cv::Mat> &image_list, arguments args, char *argv[], int argc) {
   std::cout << "Optimizing Parameters :" <<std::endl;
   
   apply_brightness(image_list, args.brightness_value);
   apply_contrast(image_list, args.contrast_value);
   apply_saturation(image_list, args.saturation_value);
   apply_sharpen(image_list, args.sharpness_value);
   apply_blur(image_list, args.blur_value);
}


