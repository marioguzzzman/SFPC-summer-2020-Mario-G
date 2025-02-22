#include "ofApp.h"
//Biigthness to offset the image
//--------------------------------------------------------------
void ofApp::setup(){

    fbo.allocate(800,800);

    rock.load("rock.jpg");
    shader.load("", "shader.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetFrameNum() % 60 == 0){
        shader.load("", "shader.frag");
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    
    fbo.begin();
    ofClear(255,255,255,255);
    ofSetLineWidth(10);
    ofSetColor(0);
    
    ofDrawCircle(400,400,300);
    //line.draw();
    fbo.end(); // line or circle gets drawned into the fbo line
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    // increasing the count you can add more textures
    shader.setUniformTexture("rockImg", rock, 0);
    shader.setUniformTexture("lineImg", fbo, 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
    //fbo.draw(0,0); // jus to see the line
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    line.addVertex(x,y); // small drawing tool // dragging the mpouse creates a line
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    line.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
