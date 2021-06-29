/*
-------------------------------------------------------------
@file       : path_finder.hpp
@author     : Aditya Das
@date       : 28.06.2021
@brief      : utility functions for storing path of the images
-------------------------------------------------------------
*/




#include <bits/stdc++.h>
#include "color/color.hpp"
#include <experimental/filesystem>



using namespace std;


// sort images
bool comp(string img1, string img2){
    // sorting
   if(img1.length()==img2.length()){
      return img1<img2;
   }
   return img1.length()<img2.length();
}


// gets paths of the image in current directory
void get_path(string path,vector<string> &img_path){
    for(const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
        string img_p = entry.path();
        if((img_p.find(".jpg") != std::string::npos) or (img_p.find(".jpeg") != std::string::npos) or (img_p.find(".png") != std::string::npos)) {
            img_path.push_back(img_p);
        }
    }

    sort(img_path.begin(), img_path.end(), comp);
}

