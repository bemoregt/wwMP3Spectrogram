#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	dog.load("/Users/mun/Desktop/woman.mp3");
    j=0;
    ofBackground(55);
}
//--------------------------------------------------------------
void ofApp::update(){
	// by taking maximums, as peaks and then smoothing downward
    float * val = ofSoundGetSpectrum(nBandsToGet);
	for (int i = 0;i < nBandsToGet; i++){
		// let the smoothed value sink to zero:
		fftSmoothed[i] *= 0.96f;
		
		// take the max, either the smoothed or the incoming:
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
	}
}
//--------------------------------------------------------------
void ofApp::draw(){
    float width = (float)(512) / nBandsToGet;
    //
    for (int i = 0;i < nBandsToGet; i++){
        col= fftSmoothed[i]*125000;
        if(col>255) col=255;
        ofSetColor(col);
        ofDrawRectangle(j*2, i, 2, 1);
    }
    j+=1;
    if(j > 512) j=0;
}
//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    // update the sound playing system:
    ofSoundUpdate();
    
    // (2) check for collision, and trigger sounds:
    dog.setVolume(1.9);
    dog.play();
    
    k +=1;
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

