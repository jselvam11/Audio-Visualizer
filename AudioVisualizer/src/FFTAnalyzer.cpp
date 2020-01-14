//
//  FFTAnalyzer.cpp
//  AudioVisualizer
//
//  Created by Jeeva Selvam on 4/27/19.
//

#include "FFTAnalyzer.hpp"


FFTAnalyzer::FFTAnalyzer() {
    rate = 44100;
    bands = 256;
    int channels = 2;
    audio.setup(rate, bands, channels);
}

void FFTAnalyzer::update(ofSoundBuffer inBuffer) {
    audio.analyze(inBuffer);
    spectrum = audio.getValues(SPECTRUM, 0);
}

void FFTAnalyzer::draw() {
    int length_of_frequency_bar_plot = ofGetWidth();
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofSetColor(color);
    float bar_width = (float) (length_of_frequency_bar_plot / spectrum.size());
    for (int i = 0; i < spectrum.size(); i++){
        float height_multiplier = ofMap(spectrum[i], DB_MIN, DB_MAX, 0.0, 1.0, true);
        float bar_height = (- 1.25) * (height_multiplier * ofGetHeight()/2);
        ofDrawRectangle(i * bar_width + 0.025 * ofGetWidth(), ofGetHeight()/2 + ofGetHeight()*0.25, bar_width, bar_height);
    }
}
