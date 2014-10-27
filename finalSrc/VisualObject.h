//
//  VisualObject.h
//  Scene_test
//
//  Created by Mike Allison on 10/11/14.
//
//

#pragma once
#include "Component.h"

using VisualObjectRef = std::shared_ptr<class VisualObject>;

class VisualObject : public ComponentBase {
public:
    
    static VisualObjectRef create(){ return VisualObjectRef( new VisualObject() ); }
    
    void update() override{ /* do something */ }
    void draw() override;
    
protected:
    
};