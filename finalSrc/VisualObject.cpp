//
//  VisualObject.cpp
//  Scene_test
//
//  Created by Mike Allison on 10/11/14.
//
//

#include "VisualObject.h"

using namespace ci;

void VisualObject::draw(){
    
    gl::drawColorCube(vec3(0,0,0), vec3(1,1,1));

}