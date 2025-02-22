#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //cout << ofGetFrameNum() % 5 << endl;
    
    for (int y = 0; y < 20; y++){
        
        int offset = y; 

        //this creates a ZIGZAG. it counts 0-3 one direction and then 4-6 goes another direction
//        int offset = y%8;
//        if (offset > 4){
//            offset = 8 - offset;
//        }
        
        for (int x = 0; x < 20; x++){
            
            // if( x % MAX(mouseX, 1) == 0){ //can not divide by cero
            //this creates a DIAGONAL
            if ( (x+offset) % 4 < 2){ // in here we are adding the row

            //This creates STRIPES
//          if (x % 2 == 0){ // |0|0|0|

                ofSetColor(255);
            } else {
                // if ( (x+offset) % 4 < 2){ // in here we are adding the row
                ofSetColor(0);
            }
            ofDrawCircle(x*40 + 100, y*40 + 100, 20);
        }
    }
    
    
    

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
