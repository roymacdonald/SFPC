#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxBlur.h"
#define NUM_MESHES 4

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    void  randRect(int meshIndex, ofPoint center, float min, float max, ofColor color);

    ofMesh mesh [NUM_MESHES];
    ofMesh dotMesh [NUM_MESHES];
    
    ofxPanel gui;
    ofParameter<float> lineWidth,dotSize;
    ofParameter<int>numIter;
    ofParameter<float> minSize [NUM_MESHES];
    ofParameter<float> maxSize[NUM_MESHES];
    ofParameterGroup layer [NUM_MESHES];
    ofParameter<ofColor> color[NUM_MESHES];
    
    ofParameterGroup blurParams;
    ofParameter<float> blurScale, blurRotation, blurBrightness, blurShape;
    ofParameter<int> blurRadius;
    
    
    vector<vector<int> > indColor;

    float size ;
    int num;
    
    void setSquares();
    void setSquaresF(float & f);
    void setSquaresCol(ofColor& c);

    void randomize();
    
    bool bDrawGui;

    ofxBlur blur;
};
