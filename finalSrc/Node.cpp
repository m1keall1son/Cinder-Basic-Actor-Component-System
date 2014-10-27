//
//  Node.cpp
//  Node_test
//
//  Created by Mike Allison on 10/11/14.
//
//

#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Node::setPosition( const ci::vec3& position ){
    
    mModelMatrix = mat4( translate(position) );
}
void Node::setRotation( const ci::vec3& axis, const float& degree ){
    
    mModelMatrix = mat4( rotate( degree, axis ) );
    
}
void Node::setScale( const ci::vec3& scale ){
    
    mModelMatrix = mat4( glm::scale( scale ) );
}

void Node::lookAt( const ci::vec3& position, const ci::vec3& center_of_interest ){
    
    vec3 diff = position - center_of_interest;
    mLookDirection = normalize(diff);
    
    mModelMatrix = mat4( translate(position) );
}
void Node::draw(){

    gl::ScopedModelMatrix push;
    
    if(mParent)
        gl::multModelMatrix(mModelMatrix * mParent->mModelMatrix);
    else
        gl::multModelMatrix(mModelMatrix);
        
    gl::drawColorCube(vec3(0,0,0), vec3(1,1,1));
    
    auto it = mChildren.begin();
    auto end = mChildren.end();
    
    while (it != end) {
        it->second->draw();
        it++;
    }
    
    
}