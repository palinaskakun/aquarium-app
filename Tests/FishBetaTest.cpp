/**
 * @file FishBetaTest.cpp
 * @author Palina Skakun
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <FishBeta.h>
#include <Aquarium.h>


TEST(FishBetaTest, Construct){
	Aquarium aquarium;
	FishBeta fishBeta(&aquarium);
}
