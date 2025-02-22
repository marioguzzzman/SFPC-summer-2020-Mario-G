#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.listDevices();
    grabber.setDeviceID(1);
    
    grabber.setup(640, 480);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    //grabber.draw(grabber.getWidth(),0);
    
    cam.begin(); // camera need to be flipped
    cam.enableOrtho();// what was this for? you need to rotate tu see
    
    for (int y = 0; y < grabber.getHeight(); y+=15){
        ofPolyline line;
        for (int x = 0; x < grabber.getWidth(); x++){
            float brightness = grabber.getPixels().getColor(x,y).getBrightness();
            line.addVertex(x - grabber.getWidth()/2, (grabber.getHeight()-y-1) - grabber.getHeight()/2, ofMap(brightness, 0, 255, -mouseX, mouseX)); //restar grabber to change the center of the camera
            // too add distorcion we add the brigthnes to z
            // adding the -1 to y to flip the image
            // amunt of offset controlled by mouse
        }
        line = line.getSmoothed(10);
        line.draw();
    }
    cam.end();
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
