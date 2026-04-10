#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

static const std::string CASCADE_PATH = "data/haarcascade_frontalface_default.xml";
static const std::string IMAGE_PATH = "images/profile pic.jpg";
//static const std::string IMAGE_PATH = "images/test.jpg";

bool loadFaceCascade(cv::CascadeClassifier& faceCascade) {
    if (!faceCascade.load(CASCADE_PATH)) {
        std::cerr << "Error: Failed to load Haar cascade from: " << CASCADE_PATH << std::endl;
        return false;
    }
    return true;
}

std::vector<cv::Rect> detectFaces(cv::Mat& frame, cv::CascadeClassifier& faceCascade) {
    std::vector<cv::Rect> faces;
    cv::Mat gray;

    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    faceCascade.detectMultiScale(
        gray,
        faces,
        1.1,              // scaleFactor
        5,                // minNeighbors
        0,
        cv::Size(30, 30)  // minSize
    );

    return faces;
}

void drawFacesAndCount(cv::Mat& frame, const std::vector<cv::Rect>& faces) {
    for (const auto& face : faces) {
        cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
    }

    std::string label = "Faces: " + std::to_string(faces.size());
    cv::putText(
        frame,
        label,
        cv::Point(20, 40),
        cv::FONT_HERSHEY_SIMPLEX,
        1.0,
        cv::Scalar(0, 255, 0),
        2
    );
}

void runImageMode(cv::CascadeClassifier& faceCascade) {
    cv::Mat image = cv::imread(IMAGE_PATH);

    if (image.empty()) {
        std::cerr << "Error: Failed to load image from: " << IMAGE_PATH << std::endl;
        return;
    }

    std::vector<cv::Rect> faces = detectFaces(image, faceCascade);
    drawFacesAndCount(image, faces);

    std::cout << "Detected " << faces.size() << " face(s) in image." << std::endl;
    std::cout << "Press any key to close image window." << std::endl;

    cv::imshow("Face Detection - Image", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

std::string generateSnapshotName() {
    fs::create_directories("snapshots");

    auto now = std::time(nullptr);
    std::tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif

    char buffer[64];
    std::strftime(buffer, sizeof(buffer), "snapshots/snapshot_%Y%m%d_%H%M%S.jpg", &localTime);
    return std::string(buffer);
}

void runWebcamMode(cv::CascadeClassifier& faceCascade) {
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open webcam." << std::endl;
        return;
    }

    std::cout << "Webcam started.\n";
    std::cout << "Press 's' to save snapshot.\n";
    std::cout << "Press 'q' or ESC to quit.\n";

    cv::Mat frame;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Error: Empty frame captured from webcam." << std::endl;
            break;
        }

        std::vector<cv::Rect> faces = detectFaces(frame, faceCascade);
        drawFacesAndCount(frame, faces);

        cv::imshow("Face Detection - Webcam", frame);

        char key = static_cast<char>(cv::waitKey(1));

        if (key == 'q' || key == 27) {
            break;
        }

        if (key == 's') {
            std::string filename = generateSnapshotName();
            if (cv::imwrite(filename, frame)) {
                std::cout << "Snapshot saved: " << filename << std::endl;
            } else {
                std::cerr << "Error: Failed to save snapshot." << std::endl;
            }
        }
    }

    cap.release();
    cv::destroyAllWindows();
}

int main() {
    cv::CascadeClassifier faceCascade;

    if (!loadFaceCascade(faceCascade)) {
        return -1;
    }

    int choice = 0;
    std::cout << "=============================\n";
    std::cout << " OpenCV Face Detection App\n";
    std::cout << "=============================\n";
    std::cout << "1. Detect faces in image\n";
    std::cout << "2. Detect faces from webcam\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        runImageMode(faceCascade);
    } else if (choice == 2) {
        runWebcamMode(faceCascade);
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}