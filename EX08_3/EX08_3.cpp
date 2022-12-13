#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Package.h"
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
    virtual double GetSize() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetWidth() {
        return this->width;
    }
    double GetHeight() {
        return this->height;
    }
    double GetDepth() {
        return this->depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }
    double GetSize() {
        return width + height + depth;
    }
};

class Cylinder :Solid {
private:
    double radius;
    double height;

public:
    Cylinder(
        double radius,
        double height) {
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return this->radius;
    }
    double GetHeight() {
        return this->height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height;
    }
    double GetSurface() {
        return (radius * 2 * M_PI * height) + ((radius * radius * M_PI) * 2);
    }
    double GetSize() {
        return radius * 4 + height;
    }
};

class Cone :Solid {
private:
    double radius;
    double height;

public:
    Cone(
        double radius,
        double height) {
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return this->radius;
    }
    double GetHeight() {
        return this->height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height / 3;
    }
    double GetSurface() {
        return radius * radius * M_PI + (radius * M_PI * (radius + sqrt(radius * 2 + height * 2)));
    }
    double GetSize() {
        return radius * 4 + height;
    }
};

class Sphere :Solid {
private:
    double radius;

public:
    Sphere(
        double radius) {
        this->radius = radius;
    }
    double GetRadius() {
        return this->radius;
    }
    double GetVolume() {
        return radius * radius * radius * M_PI * 4 / 3;
    }
    double GetSurface() {
        return radius * radius * M_PI * 4;
    }
    double GetSize() {
        return radius * 6;
    }
};

int main()
{
    Box box{ 3,5,2.5 };
    Cylinder cylinder{ 3,5 };
    Cone cone{ 20,9 };
    Sphere sphere{ 7 };
    cout << "どの宅急便を利用しますか" << endl << "１ : ヤマト運輸" << endl << "２ : ゆうパック" << endl;
    int type;
    cin >> type;
    Package* package = new Package(type);
    int size[4] = { package->SizeCheck(box.GetSize()),package->SizeCheck(cylinder.GetSize()), package->SizeCheck(cone.GetSize()), package->SizeCheck(sphere.GetSize()) };
    for (int i = 0; i < 4; i++) {
        if (size[i] != 0) {
            cout << size[i] << "サイズで送ることができます" << endl;
        }
        else {
            cout << "送ることができません。" << endl;
        }
    }

}