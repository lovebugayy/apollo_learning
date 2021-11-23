//
// Created by zhangyoufa on 2021/11/18.
//

#ifndef LEARNING_APOLLO_VEC2D_H
#define LEARNING_APOLLO_VEC2D_H

/*
 * @namespace common::math
 * @brief common::math
*/
#include <iostream>
#include <cmath>
#include <string>

namespace common{
    namespace math{
        /*
         * @class Vec2d
         *
         * @brief Implementation of a 2-dimensional vector point
         *
         */
        //declare a const expr for math epsilon
        constexpr double kMathEpsilon=1e-10;

         class Vec2d
         {
         public:
             // constructor which take x_ and y_ coordinates
             //设置为constexpr是为了可以使该类生成常量
             constexpr Vec2d(double x,double y) noexcept: x_(x),y_(y) {}

             //constructor for a zero const vector
             constexpr Vec2d() noexcept: x_(0),y_(0) {}

             //Create a unit-vector with a given angle
             //static成员函数是类内一个特殊的函数
             //static成员函数只能访问静态成员函数和静态成员变量
             //static成员函数属于整个类，并没有this指针
             static Vec2d CreateUnitByAngle(const double angle);

             //get x component
             //类的成员函数后面加const后，表示这个函数不会对类内的成员作出任何的改变
             double x() const {return x_;}

             //get y componeny
             double y() const {return y_;}

             //set x component
             void set_x(const double x) {x_=x;}

             //set y component
             void set_y(const double y) {y_=y;}

             //get length of vector
             double Length() const;

             //get square length of vector
             double SquareLength() const;

             //get Angle between the vector and positive semi x-axis
             double Angle() const;

             //get unit vector which along with the vector
             void Normalize();

             //calculate  distance to a vector
             double DistanceTo(const Vec2d& other) const;

             //calculate square distance to a vector
             double SquareDistanceTo(const Vec2d& other) const;

             //calculate "cross" product of two vector, 叉乘
             Vec2d CrossProd(const Vec2d& other) const;

             //calculate inner product of two vector, 点乘
             double InnerProd(const Vec2d& other) const;

             //rotate the vector by an angle
             Vec2d rotate(double angle) const;

             //self rotate by an angle
             void SelfRotate(double angle);

             //operator + reload
             Vec2d operator + (const Vec2d& other) const;

             //operator - reload
             Vec2d operator - (const Vec2d& other) const;

             //operator * reload
             double operator * (const Vec2d& other) const;

             //operator * reload
             Vec2d operator * (const double ratio) const;

             //operator / reload
             Vec2d operator / (const double ratio) const;

             //operator += reload
             Vec2d operator += (const Vec2d& other);

             //operator -= reload
             Vec2d operator -= (const Vec2d& other);

             //operator *= reload
             Vec2d operator *= (const double ratio);

             //operator /= reload
             Vec2d operator /= (const double ratio);

             //operator == reload
             bool operator == (const Vec2d& other) const;

             //operator * reload
             //Vec2d operator * (double ratio,Vec2d& other) const;

             //Debug string, it will return a human-readable string
             std::string DebugString() const;

         protected: //设置为protected是因为后面还有很多数据结构需要继承该类
             double x_=0.0;
             double y_=0.0;
         };//end Class Vec2d
    }//math
}//common

#endif //LEARNING_APOLLO_VEC2D_H
