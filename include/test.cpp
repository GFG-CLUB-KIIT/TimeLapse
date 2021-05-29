#include <iostream>
#include "color/color.hpp"
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
   std::vector<std::string> image_path;
   std::vector<cv::Mat> imagess;
   int ex = VideoWriter::fourcc('H','2','6','4');

   // req atleast two args
   if(argc!=2){
      std::cout<<color::red<<"No directory provided"<<std::endl;
      return 1;
   }
   std::string path = argv[1];

   std::cout << color::green << "test : 1"<< color::reset << std::endl;
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
   else {
   for(auto i : image_path) {
      cv::Mat image = cv::imread(i,cv::IMREAD_COLOR);
      imagess.push_back(image);            
      }
   }

   Size S = imagess[0].size();
   VideoWriter outputVideo;
   outputVideo.open("asa.avi", ex,30,S,true);
   
   if (!outputVideo.isOpened()){
              cout  << "Could not open the output video for write: "<< endl;
                      return -1;
                          
   }
   Mat res;
   for(int i=0; i<imagess.size(); i++){
              outputVideo << res;
                  
   }

   cout << "Finished"<<endl;
   return 0;
}