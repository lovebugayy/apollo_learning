//
// Created by zhangyoufa on 2021/11/23.
//
#include <cmath>

#include "../../commons/math/Reference_line_Point.h"

using namespace common;
using namespace common::math;

namespace common
{
    namespace math
    {
        //definition for Class Point_Cartesian
       void Cartesian_Point::setTheta(const double theta)
       {
           this->theta_= commons::math::normal_range(theta);
       }

       void Cartesian_Point::setVelocityX(const double v_x)
        {
            this->v_x_=v_x;
        }

       void Cartesian_Point::setVelocityY(const double v_y)
       {
           this->v_y_=v_y;
       }

        void Cartesian_Point::setAccelerationX(const double a_x)
        {
           this->a_x_=a_x;
        }

        void Cartesian_Point::setAccelerationY(const double a_y)
        {
           this->a_y_=a_y;
        }

        Vec2d Cartesian_Point::get_unit_tangent() const
        {
           return Vec2d(std::cos(theta_),std::sin(theta_));
        }

        Vec2d Cartesian_Point::get_unit_normal() const
        {
           return Vec2d(-std::sin(theta_),std::cos(theta_));
        }


        //Definition for Class Frenet_Point_Point
        //set s coordinate value for Point
        void Frenet_Point::set_S(const double s)
        {
           this->s_=s;
        }

        //set l coordinate value for Point
        void Frenet_Point::set_L(const double l)
        {
           this->l_=l;
        }

        //set s_dot coordinate value for Point
        void Frenet_Point::set_S_Dot(const double s_dot)
        {
           this->s_dot_=s_dot;
        }

        //set s_ddot coordinate value for Point
        void Frenet_Point::set_S_DDot(const double s_ddot)
        {
           this->s_ddot_=s_ddot;
        }

        //set l_prime coordinate value for Point
        void Frenet_Point::set_L_prime(const double l_prime)
        {
           this->l_prime_=l_prime;
        }

        //set l_pprime coordinate value for Point
        void Frenet_Point::set_L_pprime(const double l_pprime)
        {
           this->l_pprime_=l_pprime;
        }

        //set theta coordinate value for Point
        void Frenet_Point::set_Theta(const double theta)
        {
           this->theta_=theta;
        }

        //set kappa coordinate value for Point
        void Frenet_Point::set_Kappa(const double kappa)
        {
           this->kappa_=kappa;
        }

        //set d_kappa coordinate value for Point
        void Frenet_Point::set_D_Kappa(const double d_kappa)
        {
           this->dkappa_=d_kappa;
        }

        //set d_kappa coordinate value for Point
        void common::math::Frenet_Point::set_DD_Kappa(const double dd_kappa)
        {
           this->ddkappa_=dd_kappa;
        }

    }
}