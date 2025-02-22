#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    original.load("test.png");
    original.resize(ofGetWindowWidth(), ofGetWindowHeight());
    original.setImageType(OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // save the image
    ofBuffer buffer; // space in memory ram
    ofSaveImage(original.getPixels(), buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
    
    
    ofSeedRandom(0);
    
    //mouseX where to skip
    int whereToSkip = ofMap(mouseX, 0, ofGetWidth(), 0, buffer.size(), true);
    int left = buffer.size() - whereToSkip;
    
    //mouseY where to skip
    int howMuchToSkip = ofMap(mouseY, 0, ofGetHeight(), 0, left*0.5, true);
    
    ofBuffer buffer2;
    
    //sends data from one buffer to anotherone
    
    // if i am in between the place I want to skip to
    for (int i = 0; i < buffer.size(); i++){
        if (i < whereToSkip ||
            i > (whereToSkip+howMuchToSkip)){
            buffer2.append(buffer.getData() + i, 1);
        } else { // or append  random data
             char * data = new char[1];
            data[0] = ofRandom(0,255);
            buffer2.append(data, 1);
            delete data;
            
        }
    }
    
    
    newImage.load(buffer2);
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    newImage.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    original.load("test.png");
//    original.setImageType(OF_IMAGE_COLOR);
    
    if (key == ' '){
        ofSaveScreen(ofGetTimestampString() + ".png");
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
