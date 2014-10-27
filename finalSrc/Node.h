//
//  Node.h
//  Node_test
//
//  Created by Mike Allison on 10/11/14.
//
//

#pragma once

using NodeRef = std::shared_ptr< class Node >;

class Node {
public:
        
    void addChild( const std::string& name, NodeRef child ){
        child->setParent(this);
        mChildren.insert( std::make_pair( name, child ) );
    }
    
    NodeRef getChild( const std::string& name ){
        
      return mChildren.find(name)->second;
        
    }
    
    void setParent( Node* parent ){
        mParent = parent;
    }
    
    void setPosition( const ci::vec3& postion );
    void setRotation( const ci::vec3& axis, const float& degree );
    void setScale( const ci::vec3& scale );
    void lookAt( const ci::vec3& position, const ci::vec3& center_of_interest );

    virtual void draw();
    virtual void update() = 0;
    virtual ~Node(){}
    
    Node( Node* parent ):mParent(parent), mLookDirection(ci::vec3( 0,0,1 )), mModelMatrix(ci::mat4(1.)){
    
    
    }
    
    Node* mParent;
    std::map<std::string, NodeRef> mChildren;
    
    ci::mat4 mModelMatrix;
    ci::vec3 mLookDirection;
    
};

