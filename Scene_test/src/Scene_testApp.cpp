#include "cinder/app/AppNative.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Scene.h"
#include "VisualObject.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Scene_testApp : public AppNative {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    CameraPersp mCamera;
    
    SceneRef mScene;
    
};

void Scene_testApp::setup()
{
    
    mCamera.setPerspective(60, getWindowAspectRatio(), .1, 10000);
    mCamera.lookAt(vec3(0,0,5), vec3(0,0,0));
    
    mScene = Scene::create();
    
    ActorRef tCube = Actor::create("cube");

    tCube->addComponent( VisualObject::create() );
    
    tCube->setPosition( vec3(2,0,1) );
    
    mScene->addChild( tCube->getName(), tCube );
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
}

void Scene_testApp::mouseDown( MouseEvent event )
{
}

void Scene_testApp::update()
{
    
    mScene->getChild("cube")->setPosition(vec3( 3*cos(getElapsedSeconds()),0,3*sin(getElapsedSeconds()) ));
    mScene->update();
}

void Scene_testApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::setMatrices(mCamera);
    
    mScene->draw();
}

CINDER_APP_NATIVE( Scene_testApp, RendererGl )
