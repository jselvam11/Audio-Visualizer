//
//  FFTAnalyzer.hpp
//  AudioVisualizer
//
//  Created by Jeeva Selvam on 4/27/19.
//

#ifndef FFTAnalyzer_hpp
#define FFTAnalyzer_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAudioAnalyzer.h"
#include "ofSoundPlayerExtended.h"

class FFTAnalyzer {
    ofxAudioAnalyzer audio;
    vector<float> spectrum;
    int rate;
    int bands;
    
public:
    
    FFTAnalyzer();
    void update(ofSoundBuffer buffer);
    void draw();
    int getBands() {
        return bands;
    }
    
};

#endif /* FFTAnalyzer_hpp */
