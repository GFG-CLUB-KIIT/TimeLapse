#include <string>
class Image {
   int width;
   int width;
   int channels;
   size_t size = 0;
   std::string path;
   
   Image(std::tring path);
   Image(int w, int h, int channels);
   ~Image();
   


   bool read(std::string path);

};
