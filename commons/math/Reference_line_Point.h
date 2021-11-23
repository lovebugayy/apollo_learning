//
// Created by zhangyoufa on 2021/11/23.
//

#ifndef LEARNING_APOLLO_REFERENCE_LINE_POINT_H
#define LEARNING_APOLLO_REFERENCE_LINE_POINT_H

#include "../../commons/math/Vec2d.h"
#include "../../commons/math/Angle_Conversion.h"

using namespace common::math;

namespace common
{
    namespace math
    {
        class Cartesian_Point
        {
        public:
            //Construction function
            Cartesian_Point(double x,double y,double theta)
                    :x_(x),y_(y),theta_(theta){;}

            //set theta value of Point
            //@param theta
            void setTheta(const double theta);

            //set velocity component in x-axis
            void setVelocityX(const double v_x);

            //set velocity component in y-axis
            void setVelocityY(const double v_y);

            //set acceleration component in x-axis
            void setAccelerationX(const double a_x);

            //set acceleration component in y-axis
            void setAccelerationY(const double a_y);

            //set unit tangent vector
            Vec2d get_unit_tangent() const;

            //set unit normal vector
            Vec2d get_unit_normal() const;

        protected:
            double x_;
            double y_;
            double theta_;
            double v_x_;
            double v_y_;
            double a_x_;
            double a_y_;
        };

        class Frenet_Point
        {
            Frenet_Point(double x,double y,double theta,double s)
                    :x_(x),y_(y),theta_(theta),s_(s){;
            }

            //set s coordinate value for Point
            void set_S(const double s);

            //set l coordinate value for Point
            void set_L(const double l);

            //set s_dot coordinate value for Point
            void set_S_Dot(const double s_dot);

            //set s_ddot coordinate value for Point
            void set_S_DDot(const double s_ddot);

            //set l_prime coordinate value for Point
            void set_L_prime(const double l_prime);

            //set l_pprime coordinate value for Point
            void set_L_pprime(const double l_pprime);

            //set theta coordinate value for Point
            void set_Theta(const double theta);

            //set kappa coordinate value for Point
            void set_Kappa(const double kappa);

            //set d_kappa coordinate value for Point
            void set_D_Kappa(const double d_kappa);

            //set d_kappa coordinate value for Point
            void set_DD_Kappa(const double dd_kappa);
        protected:
            //state in frenet coordinate
            double x_;
            double y_;
            double s_;
            double l_;
            double s_dot_;
            double s_ddot_;
            double l_prime_;
            double l_pprime_;
            double theta_;
            double kappa_;
            double dkappa_;
            double ddkappa_;

        };

    }
}

#endif //LEARNING_APOLLO_REFERENCE_LINE_POINT_H
