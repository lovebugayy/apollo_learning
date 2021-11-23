//
// Created by zhangyoufa on 2021/11/18.
//

#include "Vec2d.h"

using namespace std;
using namespace common;
using namespace math;

namespace common{
    namespace math{
            //get a vector by angle
            Vec2d Vec2d::CreateUnitByAngle(const double angle)
            {
                return Vec2d(std::cos(angle),std::sin(angle));
            }

            //get length of vector
            double common::math::Vec2d::Length() const
            {
                return std::hypot(x_,y_);
            }

            double Vec2d::SquareLength() const{
                return (x_ * x_ + y_ * y_);
            }

            double Vec2d::Angle() const{
                return std::atan2(y_,x_); //atan函数是atan2（y，x），可以在cmath库中找到
            }

            void Vec2d::Normalize(){
                const double l=Length();
                if(l>kMathEpsilon)
                {
                    this->x_=(this->x_)/l;
                    this->y_=(this->y_)/l;
                }
                return ;
            }

            //一定要注意，此处的other并不难直接取出其成员变量x_和y_,
            // 而需要通过访问变量的接口去获得它的值
            double Vec2d::DistanceTo(const Vec2d& other) const
            {
                return std::hypot(x_-other.x(),y_-other.y());
            }

            double Vec2d::SquareDistanceTo(const Vec2d& other) const
            {
                return std::pow((x_-other.x()),2)+std::pow((y_-other.y()),2);
            }

            //apollo源码此处返回的是一个double值，但事实上向量的叉乘应该是一个向量，而不是标量
            Vec2d Vec2d::CrossProd(const Vec2d& other) const
            {
                return Vec2d(x_*other.y(),-y_*other.x());
            }

            double Vec2d::InnerProd(const Vec2d& other) const
            {
                return (x_*other.x()+y_*other.y());
            }

            Vec2d Vec2d::rotate(double angle) const
            {
                return Vec2d(x_*std::cos(angle)-y_*std::sin(angle),x_*std::sin(angle)+y_*std::cos(angle));
            }

            void Vec2d::SelfRotate(double angle)
            {
                double temp_x=x_;
                x_=temp_x*std::cos(angle)-y_*std::sin(angle);
                y_=temp_x*std::sin(angle)+y_*std::cos(angle);
            }

            Vec2d Vec2d::operator + (const Vec2d& other) const
            {
                return Vec2d(x_+other.x_,y_+other.y_);
            }

            Vec2d Vec2d::operator - (const Vec2d& other) const
            {
                return Vec2d(x_-other.x_,y_-other.y_);
            }

            double Vec2d::operator * (const Vec2d& other) const
            {
                return this->InnerProd(other);
            }

            Vec2d Vec2d::operator * (const double ratio) const
            {
                return Vec2d(ratio*x_,ratio*y_);
            }

            Vec2d Vec2d::operator / (const double ratio) const
            {
                if(ratio>kMathEpsilon) //apollo 此处没有使用if，而是使用了CHECK_GT函数
                {
                    return Vec2d(x_/ratio,y_/ratio);
                }
            }

            Vec2d Vec2d::operator += (const Vec2d& other)
              {
                this->x_=this->x_+other.x_;
                this->y_=this->y_+other.y_;
                return *this;
                //不能直接返回this指针，否则会报错。所以，此处返回了×this
              }

            Vec2d Vec2d::operator -= (const Vec2d& other)
            {
                this->x_=this->x_-other.x_;
                this->y_=this->y_-other.y_;
                return *this;
            }

             Vec2d Vec2d::operator *= (const double ratio)
             {
                 this->x_=this->x_*ratio;
                 this->y_=this->y_*ratio;
                 return *this;
             }

             Vec2d Vec2d::operator /= (const double ratio)
             {
               if(ratio>kMathEpsilon)
               {
                   this->x_=this->x_/ratio;
                   this->y_=this->y_/ratio;
                   return *this;
               }
             }

             bool Vec2d::operator == (const Vec2d& other) const
             {
                return (this->x_==other.x_ && this->y_==other.y_);
             }

             std::string Vec2d::DebugString() const
             {
                //apollo 此处使用的自己写的库
                string res="Vec2d(x= "+to_string(x_)+",y="+ to_string(y_)+")";
                std::cout<<"Vec2d(x= "<<x_<<",y="<<y_<<")"<<std::endl;
                 return res;
             }
    }//end namespace math
}//end namespace common