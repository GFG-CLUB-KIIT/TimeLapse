/*
-------------------------------------------------------------
@file       : filter.cpp
@author     : Rupanshi Chawda
@date       : 02.06.2021
@brief      : Parameter for manipulating Brightness and contrast of the images 
-------------------------------------------------------------
*/

#include <iostream>
#include "color.hpp"
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv) {
   

   std::vector<std::string> image_path;
   std::vector<cv::Mat> image_list;
   int codec = VideoWriter::fourcc('H','2','6','4'); 
   int h=0,w=0;
   // req atleast two args
   if(argc!=2){
      std::cout<<color::red<<"No directory provided"<<std::endl;
      return 1;
   }
   std::string path = argv[1];

   std::cout << color::green << "check : 1"<< color::reset << std::endl;

 for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
      std::string img_path = entry.path();
      if((img_path.find(".jpg") != std::string::npos) or (img_path.find(".jpeg") != std::string::npos) or (img_path.find(".png") != std::string::npos)) {
         image_path.push_back(img_path);
      }
   }

   if(image_path.size() == 0) {
      std::cout << color::red << "No image files in the current directory" << color::reset <<std::endl;
      return 1;
   } 
  

    std::cout << color::green << "check : 2"<< color::reset << std::endl;


   for(auto i : image_path){

    Mat img = imread(i);
    Mat change;

    if (img.empty()) {
        cout << "Can not open or image is not present" << endl;
        cin.get();
        return -1;
    }
//**************** F I L T E R S ******************

   //-----BRIGHTNESS & CONTRAST-----

   float contrast = 1.2, brightness = 0;
   img.convertTo(change, -1, contrast, brightness);
   
   //---------SATURATION-----------

   Mat hsv;
   cvtColor(change, hsv, COLOR_BGR2HSV);
   float factor = 1.2;
   hsv = hsv * factor;
   cvtColor(hsv, change, COLOR_HSV2BGR);
   
   //-------SHARPNESS & BLUR--------
   
   float sharp = 9, blurness = 3;
   Mat sharpeningKernel = (Mat_<double>(3,3) << -1, -1, -1, -1, sharp, -1, -1, -1, -1);
   filter2D(change, change, -1, sharpeningKernel);
   blur(change, change, Size(blurness, blurness)); 

 
   // Writing the image 
   bool check = imwrite(i, change);

    if (check == false) {
        cout << "Mission - Saving the image, FAILED" << endl;
        cin.get();
        return -1;
    }
  }

    cout << "\n Successful. " << endl;

   return 0;
}

