#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat detectFaceInImage(Mat &image, string &cascade_file) {
  CascadeClassifier cascade;
  cascade.load(cascade_file);

  vector<Rect> faces;
  cascade.detectMultiScale(image, faces, 1.1, 3, 0, Size(20, 20));

  for(int i = 0; i < faces.size(); i++) {
    rectangle(image, 
        Point(faces[i].x, faces[i].y),
        Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
        Scalar(0, 200, 0),
        3,
        CV_AA
    );
    return image;
  }
}

int main() {
    Mat image = imread("./me.jpg");
    string filename = opencv/data/haarcascades/haarcascade_frontalface_default.xml";
    Mat detectFaceImage = detectFaceInImage(image, filename);
    cv::imshow("detect face", detectFaceImage);
    waitKey(0); 
}