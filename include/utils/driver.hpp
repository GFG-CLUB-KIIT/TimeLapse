/*
-------------------------------------------------------------
@file       : driver.cpp
@author     : Aditya Das
@date       : 29.06.2021
@brief      : Main driver code for timelapse video
-------------------------------------------------------------
*/


#include <bits/stdc++.h>
#include <experimental/filesystem>
#include "color/color.hpp"
#include "utils/path_finder.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"


using namespace std;
using namespace cv;


void make_timelapse(vector<cv::Mat> image_list, string output_name){
    Size S = image_list[0].size();
    string mvleft="\033[1000D";
   string clearln="\033[2K";
   int codec = VideoWriter::fourcc('H','2','6','4'); 
   int h=0,w=0;
    VideoWriter outputVideo;
    outputVideo.open(output_name, codec, 10.0 , S, true);

    if(!outputVideo.isOpened()) {
        cout  <<color::red<< "ERR03: Could not open the output video for write: "<<color::reset <<endl;
        return;
    }

    int total=image_list.size();
    for(int i=0; i<total; i++){
              outputVideo << image_list[i];
              //percentage/progress   
              cout<<mvleft<<clearln;
              cout<<"processing: "<<((i+1)/total)*100<<"%";
    }

    cout <<color::green<< "\nFinished"<<color::reset<<endl;
}