#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    ofDirectory dir;
    dir.listDir("kittens");
    for (int i = 0; i < dir.size(); i++){
        imageWithData img;
        images.push_back(img);
        images.back().img.load(dir.getPath(i)); // almost the same, but here we are going to accsess the image with data. Need to change this in all he code 
        cout << "loaded " << i << " of " << dir.size() << endl;
        
        ofRectangle targetDim(0,0,640,480);
        ofRectangle imageDim(0,0,images.back().img.getWidth(),
                             images.back().img.getHeight());
        
        targetDim.scaleTo(imageDim);
        
        images.back().img.crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
        images.back().img.resize(640,480);
    }
    
    // this calculates the average brightness
    for (int i = 0; i < images.size(); i++){
        float brightness = 0;
        for (int j = 0; j < 640; j++){
            for (int k = 0; k < 480; k++){
                brightness += images[i].img.getColor(j,k).getBrightness(); // we can add the hue here
            }
        }
        brightness /= 640*480.;
        images[i].brightness = brightness;
    }
    
    //snippet to sort with lambda
    sort(images.begin(), images.end(),
        [](const imageWithData & a, const imageWithData & b) -> bool
    {
        return a.brightness > b.brightness; // the < > changes th way we sort
    });
    
    
   
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    images[ ofMap(mouseX, 0, ofGetWidth(),0, images.size()-1, true)].img.draw(0,0); // Zach adds the max to not pass negatives numbers into the array
    
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
