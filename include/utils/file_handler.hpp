/*
-------------------------------------------------------------
@file       : path_finder.hpp
@author     : Aditya Das, Souvik
@date       : 28.06.2021
@brief      : utility functions for storing path of the images
-------------------------------------------------------------
*/

#pragma once
#include <vector>
#include <experimental/filesystem>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "../color/color.hpp"

using namespace std;

// sort images
bool comp(string img1, string img2)
{
    // sorting
    if (img1.length() == img2.length())
    {
        return img1 < img2;
    }
    return img1.length() < img2.length();
}

// gets paths of the image in current directory
void get_files(string source_dir, vector<string> &image_path)
{

    
    for (const auto &entry : experimental::filesystem::directory_iterator(source_dir))
    {
        string img_p = entry.path();
        if ((img_p.find(".jpg") != std::string::npos) or (img_p.find(".jpeg") != std::string::npos) or (img_p.find(".png") != std::string::npos))
        {
            image_path.push_back(img_p);
        }
    }
    sort(image_path.begin(), image_path.end(), comp);
    cout << "done"<<endl;
}

void read_images(string source_dir, std::vector<cv::Mat> &image_list)
{
    cout << color::red<<">>Reading files"<<color::reset <<endl;
    vector<string> image_path;
    // list images from the source directory
    get_files(source_dir, image_path);
    if (image_path.size() == 0)
    {
        std::cout << color::red << "No image files in the current directory" << color::reset << std::endl;
        _Exit(1);
    }

    int x =1;
    // read images from collected path
    for (auto i : image_path)
    {
        cout <<color::yellow <<"Reading file :"<<color::reset<< x++ <<endl;
        
        cv::Mat image = cv::imread(i, cv::IMREAD_COLOR);
        image_list.push_back(image);
        cv::resize(image, image, image_list[0].size());
    }

    cout << color::green<<"Reading Done" <<color::reset<<endl;
}
