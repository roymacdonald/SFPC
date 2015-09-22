#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#define NUM_MESHES 2

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

    void  randRect(ofMesh& m, ofPoint center, float min, float max, ofColor color);

    ofMesh mesh [2];
    void addSquaresLayer(ofMesh& m, ofColor col1, ofColor col2);
    
    ofxPanel gui;
    ofParameter<float>minSize, maxSize, lineWidth, indMult;
    ofParameter<ofColor>color, color2;
    float size ;
    
    int num;
    
    void setSquares();
    void setSquaresF(float & f);
    void setSquaresCol(ofColor& c);
    
    bool bDrawGui;
};
