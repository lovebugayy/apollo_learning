//
// Created by zhangyoufa on 2021/11/23.
//

#ifndef LEARNING_APOLLO_CARTESIAN_FRENET_CONVERSION_H
#define LEARNING_APOLLO_CARTESIAN_FRENET_CONVERSION_H

#include "../../commons/math/Vec2d.h"
#include "../../commons/math/Reference_line_Point.h"

using namespace common;
using namespace math;

namespace common
{
    namespace math
    {
        //Notations:
        /* s_condition=[s,s_dot,s_ddot]
         * s: longitudinal coordinate in reference line in frenet coordinate
         * s_dot: ds/dt
         * s_ddot: d(s_dot)/dt
         * d_condition=[d,d_prime,d_pprime]
         * d: lateral coordinate in refrence line in frenet coordinate
         * d_prime: d(d)/ds
         * d_pprime: d(d_prime)/ds
         * l is the same as d
         * */
        class CartesianFrenetConverter{
        public:
            //Construction function of CartesianFrenetConverter
            //C++ 11 可以让程序员显式地禁用某些函数，加上delete便可以禁用函数
            //delete还可以显示的禁止某些类型转换的构造函数
            CartesianFrenetConverter()=delete;
            // this function is to transform the state from Cartesian coordinate to Frenet Coordinate
//            Frenet_Point Cartesian_to_Frenet(const Cartesian_Point cartesianPoint,const Frenet_Point matched_point);
//            //this function is to transform the state from Frenet coordinate to Cartesian coordinate
//            Cartesian_Point Frenet_to_Cartesian(const Frenet_Point frenetPoint);
//            //calculate theta
//            static double calculateTheta();
//
//            //calculate kappa
//            static double calculateKappa();
        private:
        protected:
        };//end class CartesianFrenetConversion
    }//end namespcae math
}//end namespace common

#endif //LEARNING_APOLLO_CARTESIAN_FRENET_CONVERSION_H
