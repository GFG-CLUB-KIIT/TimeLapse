/*
-------------------------------------------------------------
@file       : driver.cpp
@author     : Aditya Das, Souvik
@date       : 29.06.2021
@brief      : Main driver code for timelapse video
-------------------------------------------------------------
*/
#pragma once
#include <vector>
#include "../color/color.hpp"
#include "./misc.hpp"

using namespace std;
using namespace cv;

// Progress bar
void progress_bar(int current_frame_index, int total_frames)
{
    std::string const mvleft = "\033[1000D";
    std::string const clearln = "\033[2K";
    std::cout << mvleft << clearln;
    std::cout << color::blue << "processing: " << color::green << ((current_frame_index + 1) / total_frames) * 100 << "%" << color::reset;
}

// driver code to convert images to timelapse
void make_timelapse(vector<cv::Mat> image_list, arguments args)
{
    int codec = VideoWriter::fourcc('H', '2', '6', '4');
    int h = 0, w = 0;
    Size S = image_list[0].size();
    VideoWriter outputVideo;
    outputVideo.open(args.output_file_name, codec, args.frames, S, true);

    if (!outputVideo.isOpened())
    {
        std::cout << "Could not open the output video for write " << std::endl;
        _Exit(0);
    }

    // frames to video
    int total = image_list.size();
    for (int i = 0; i < total; i++)
    {
        outputVideo << image_list[i];
        progress_bar(i, total);
    }
}
