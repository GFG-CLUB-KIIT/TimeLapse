/*
-------------------------------------------------------------
@file       : timelapse.cpp
@author     : Aditya Das
@date       : 28.06.2021
@brief      : Main operating file of the application
-------------------------------------------------------------
*/

#include <bits/stdc++.h>
#include <experimental/filesystem>
#include "color/color.hpp"
#include "utils/path_finder.hpp"
#include "utils/driver.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    if(argv[1] == "-h" or argv[1] == "--help")
    {
        // help function implementation
    }
    else if(argv[1] == "-v" or argv[1] == "--version") {
        // version implementation
    }
    else if(argv[1] == "--make" or argv[1] == "-m"){
        // makes timepse video
        /*
        pseudo implemetation : timelapse -m/--make <directory>
        */
        if(argc < 3){
            cout << color::red<< "ERR01: No Directory provided, please provide valid directory!" << color::reset<<endl;
            return 1;
        }
        if(argc == 3){
            // assuming directory must be provided.
            string path = argv[2];
            vector<string> img_path;
            // stores path in a vector
            get_path(path,img_path);
            if(img_path.size() == 0){
                cout << color::red << "ERR02: No images in the current directory !" << color::reset<< endl;
                return 1;
            } else {
                vector<cv::Mat> image_list;
                for(auto i : img_path){
                    cv::Mat image = cv::imread(i,cv::IMREAD_COLOR);
                    image_list.push_back(image);
                    cv::resize(image,image, image_list[0].size());
                }
                make_timelapse(image_list);
            }
        }
    }




    return 0;
}