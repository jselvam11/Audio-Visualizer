#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beat.load("MusicSoundsBetterWithYou.mp3");
    extended_sound_player_.load("MusicSoundsBetterWithYou.mp3");
    extended_sound_player_.setLoop(true);
    extended_sound_player_.setVolume(0.0);
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }
    bands = 256;
    beat.setLoop(true);
    beat.setVolume(0.2);
    fftAnalyzer = FFTAnalyzer();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    ofSoundBuffer current_sound_buffer = extended_sound_player_.getCurrentSoundBuffer(fftAnalyzer.getBands());
    fftAnalyzer.update(current_sound_buffer);
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.9f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofSetColor(color);
    ofSetBackgroundColor(0);
    for (int i = 0; i < bands; i++) {
        ofCircle(ofGetWidth(), ofGetHeight(), -(fftSmooth[i]*250));
        ofCircle(0, ofGetHeight(), -(fftSmooth[i]*250));
        ofCircle(0, 0, -(fftSmooth[i]*250));
        ofCircle(ofGetWidth(), 0, -(fftSmooth[i]*250));
    }
    fftAnalyzer.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '5':
            beat.play();
            extended_sound_player_.play();
            break;
        case '6':
            beat.stop();
            extended_sound_player_.stop();
        break;
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
