#include "Visiona.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
    visiona::MarkerDetectorConfig cfg;
    cfg.loadConfig("config/sample.cfg");

    cv::Mat raw = cv::imread("/home/gokberk/Downloads/imageedit_4_3294093214.jpg", cv::IMREAD_COLOR);
    cv::imshow("Display window", raw);
    cv::waitKey();

    visiona::MarkerDetector *detector = visiona::MarkerDetectorFactory::makeMarkerDetector(cfg);
    std::vector<std::shared_ptr<visiona::Target>> ret = detector->detect(raw);
    std::shared_ptr<visiona::Target> tg = ret[0];

    if (tg->detected) {
        std::cout << "A target detected" << std::endl;
        detector->evaluateExposure(raw, tg);
        detector->measureRough(raw, tg);
        detector->measure(raw, tg);
    }
    
    return 0;
}