//
// Created by zhangyoufa on 2021/11/19.
//

/*
 * this file is a test for Vector2d
 * we mainly test if it will operate normaly
 */

#include <gtest/gtest.h>
#include "math/Vec2d.h"

//std
using namespace std;

//our library
using namespace common;
using namespace math;

TEST(zero_vector,ZERO)
{
    Vec2d zero_vec;
    ASSERT_EQ(zero_vec.x(),0);
    ASSERT_EQ(zero_vec.y(),0);
}

TEST(non_Zero_vector,NON_ZERO)
{
    Vec2d non_Zero_vector(1,2);
    ASSERT_EQ(non_Zero_vector.x(),1);
    ASSERT_EQ(non_Zero_vector.y(),2);
}

TEST(length_test,LENGTH)
{
    Vec2d vec(1,1);
    ASSERT_DOUBLE_EQ(std::sqrt(2),vec.Length());
    Vec2d vec1(0,0);
    ASSERT_DOUBLE_EQ(0,vec1.Length());
    Vec2d vec2(10,1);
    ASSERT_DOUBLE_EQ(std::sqrt(101),vec2.Length());
}

TEST(square_test,SQUARE_TEST)
{
    Vec2d vec(1,1);
    ASSERT_DOUBLE_EQ(2,vec.SquareLength());
}

TEST(angle_test,ANGLE_TEST)
{
    Vec2d vec(1,1);
    ASSERT_DOUBLE_EQ(M_PI_4,vec.Angle());
}

TEST(Normalize_test,NORMALIZE)
{
    Vec2d vec(3,4);
    vec.Normalize();
    ASSERT_DOUBLE_EQ(vec.x(),0.6);
    ASSERT_DOUBLE_EQ(vec.y(),0.8);

    Vec2d vec1(1e-10,0);
    vec1.Normalize();
    ASSERT_DOUBLE_EQ(vec1.x(),1e-10);
    ASSERT_DOUBLE_EQ(vec1.y(),0);
}

TEST(Distance_TO_TEST,DISTANCE)
{
    Vec2d vec(1,2);
    Vec2d vec1(3,4);
    ASSERT_DOUBLE_EQ(std::sqrt(8),vec.DistanceTo(vec1));
    ASSERT_DOUBLE_EQ(0,vec.DistanceTo(vec));
}

TEST(square_distance_test,SQUARE_TEST)
{
    Vec2d vec(1,2);
    Vec2d vec1(3,4);
    ASSERT_DOUBLE_EQ(8,vec.SquareDistanceTo(vec1));
}

TEST(cross_product,CROSS_PRODUCT)
{
    Vec2d vec(1,2);
    Vec2d vec1(3,4);
    Vec2d vec2(4,-6);
    ASSERT_EQ(vec2,vec.CrossProd(vec1));
}

TEST(inner_product,INNER_PRODUCT)
{
    Vec2d vec(1,2);
    Vec2d vec1(3,4);
    ASSERT_EQ(11,vec.InnerProd(vec1));
}

