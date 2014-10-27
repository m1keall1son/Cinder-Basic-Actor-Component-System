#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Node_testApp : public AppNative {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    NodeRef mRoot;
    
    CameraPersp mCamera;

};

void Node_testApp::setup()
{
    mRoot = Node::create();
    
    mRoot->addChild( "cube", Node::create() );
    
    mRoot->getChild("cube")->setPosition( vec3(3,0,0) );
    mRoot->getChild("cube")->setRotation( vec3(1,0,0), 45 );
    
    mCamera.setPerspective(50, getWindowAspectRatio(), .1, 1000);
    mCamera.lookAt(vec3(0,0,5), vec3(0,0,0));
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
}

void Node_testApp::mouseDown( MouseEvent event )
{
}

void Node_testApp::update()
{
}


void Node_testApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::setMatrices(mCamera);
    mRoot->draw();
    
}

CINDER_APP_NATIVE( Node_testApp, RendererGl )
