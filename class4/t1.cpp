#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    cv::Mat src =imread("D:\\2.jpg",0);
    Mat dst;
    threshold(src,dst,100,255,THRESH_BINARY);

    Mat structureElement = getStructuringElement(MORPH_ELLIPSE, Size(5, 5), Point(-1, -1));

    erode(dst, dst, structureElement, Point(-1, -1), 2, 0, 0);  //腐蚀
    dilate(dst, dst, structureElement, Point(-1, -1), 2, 0, 0);  //膨胀    ==开运算

    //dilate(dst, dst, structureElement, Point(-1, -1), 2, 0, 0);  //膨胀
    //erode(dst, dst, structureElement, Point(-1, -1), 2, 0, 0);  //腐蚀     ==闭运算   /练习1

    Mat stats, centroids,res;
    int Imglabelnum=connectedComponentsWithStats(dst, res, stats, centroids);   //   /练习2
    printf("%d",Imglabelnum);
    cv::imshow("2c",dst);
    waitKey(0);
    return 0;
}