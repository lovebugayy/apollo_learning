//
// Created by youfa on 2021/11/23.
//

#include "../../commons/math/Angle_Conversion.h"

namespace commons
{
    namespace math
    {
        double normal_range(const double angle)
        {
            double current_angle=angle;
            if(angle>M_PI)
            {
                current_angle-=2*M_PI;
            }else if (angle<-M_PI)
            {
                current_angle+=2*M_PI;
            }else
            {
                return current_angle;
            }
            return normal_range(current_angle);
        }
    }
}