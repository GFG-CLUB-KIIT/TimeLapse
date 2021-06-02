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
    Mat contrast;

    if (img.empty()) {
        cout << "Can not open or image is not present" << endl;
        cin.get();
        return -1;
    }

    img.convertTo(contrast, -1, 5, 0);

    bool check = imwrite(i, contrast);

    if (check == false) {
        cout << "Mission - Saving the image, FAILED" << endl;
        cin.get();
        return -1;
    }
  }

    cout << "\n Successful. " << endl;

   return 0;
}

