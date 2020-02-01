#include <opencv2/opencv.hpp>

//MAX
int low_H;
int low_S;
int low_V;

//MIN
int high_H;
int high_S;
int high_V;

//ed already has a thing that runs it in a loop
//rararar
using namespace cv;
using namespace std;
   
  Mat element = getStructuringElement(MORPH_ELIPSE, anchor=Point(10, 10));
  
  cvtColor(img, hsvimg, CV_BGR2HSV); //be carefull, opencv "H" value max is 180
  inRange(hsvimg, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), thresh);
  morphologyEx(thresh, close, 3, element); //fix later ahh
  morphologyEx(close, open, 2, element);
  
  //contours, hierarchy = cv2.findContours(opening, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
  findContours(opening, contours, CV_RETR_TREE, CHAIN_APPROX_NONE);
  
  
