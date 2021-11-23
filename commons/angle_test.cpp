//
// Created by zhangyoufa on 2021/11/23.
//

#include <cmath>
#include <gtest/gtest.h>
#include "../commons/math/Angle_Conversion.h"

using namespace commons;
using namespace math;

TEST(positive_test,POSITIVE)
{
    ASSERT_DOUBLE_EQ(normal_range(2*M_PI),0);
    ASSERT_DOUBLE_EQ(normal_range(8*M_PI/3),2*M_PI/3);
    ASSERT_DOUBLE_EQ(normal_range(10*M_PI/3),-2*M_PI/3);
}


TEST(negative_test,NEGATIVE)
{
    ASSERT_DOUBLE_EQ(normal_range(-2*M_PI),0);
    ASSERT_DOUBLE_EQ(normal_range(-8*M_PI/3),-2*M_PI/3);
    ASSERT_DOUBLE_EQ(normal_range(-10*M_PI/3),2*M_PI/3);
}

TEST(zero_test,ZERO)
{
    ASSERT_DOUBLE_EQ(normal_range(0),0);
}
