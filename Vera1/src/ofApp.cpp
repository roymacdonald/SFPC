#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i < NUM_MESHES; i++) mesh[i].setMode(OF_PRIMITIVE_LINES);
    num = 6;
    size = MIN(ofGetHeight(), ofGetWidth())/(num + 1.0);

    gui.setup();
    gui.add(minSize.set("minSize", size-10 , 0, size ));
    gui.add(maxSize.set("maxSize", size +10, 0, size*2 ));
    gui.add(color.set("color", ofColor::red, ofColor(0,0), ofColor(255,255)));
    gui.add(color2.set("color2", ofColor::red, ofColor(0,0), ofColor(255,255)));
    gui.add(indMult.set("index mult", 1, 1, 2));
    gui.add(lineWidth.set("lineWidth", 1, 0, 5));
    gui.loadFromFile("settings.xml");
    setSquares();
    indMult.addListener(this, &ofApp::setSquaresF);
    color.addListener(this, &ofApp::setSquaresCol);
    color2.addListener(this, &ofApp::setSquaresCol);
    maxSize.addListener(this, &ofApp::setSquaresF);
    minSize.addListener(this, &ofApp::setSquaresF);
    
    bDrawGui =true;
}
//--------------------------------------------------------------
void ofApp::setSquares(){

    for (int i = 0; i < NUM_MESHES; i++) mesh[i].clear();
    addSquaresLayer(mesh[0], color, color);
    addSquaresLayer(mesh[1], color, color2);
}
//--------------------------------------------------------------
void ofApp::addSquaresLayer(ofMesh& m, ofColor col1, ofColor col2){
    int rows = num;
    int cols = num;
    int total = rows * cols;
    for (int y = 0 ; y < rows; y++) {
        for (int x  =0 ; x < cols; x++) {
            int ind = y*cols + x;
            bool bSecondHalf = ind >= total/2 ;
            if (bSecondHalf) {
                ind -= (ind%(total/2))*2 +1;
            }
            for (int j = 0; j < (int)floor(ind* indMult + 1); j++) {
                if (bSecondHalf) {
                    randRect(m,ofPoint((x+1)*size, (y+1)*size), MIN(minSize,maxSize), MAX(minSize,maxSize), col2);
                }else{
                    randRect(m, ofPoint((x+1)*size, (y+1)*size), MIN(minSize,maxSize), MAX(minSize,maxSize), col1);
                }
            }
        }
    }
    
}
//--------------------------------------------------------------
void ofApp::setSquaresCol(ofColor& c){
    setSquares();
}
//--------------------------------------------------------------
void ofApp::setSquaresF(float & f){
    setSquares();
}

//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::randRect(ofMesh& m, ofPoint center, float min, float max, ofColor color){
    ofRectangle rmx, rmn;
    rmx.setFromCenter(center, max, max);
    rmn.setFromCenter(center, min, min);
    unsigned int i = m.getVertices().size();
    
    m.addVertex(ofVec3f(ofRandom(rmn.getX(), rmx.getX()), ofRandom(rmn.getY(), rmx.getY())));
    m.addVertex(ofVec3f(ofRandom(rmn.getMaxX(), rmx.getMaxX()), ofRandom(rmn.getY(), rmx.getY())));
    m.addVertex(ofVec3f(ofRandom(rmn.getMaxX(), rmx.getMaxX()), ofRandom(rmn.getMaxY(), rmx.getMaxY())));
    m.addVertex(ofVec3f(ofRandom(rmn.getX(), rmx.getX()), ofRandom(rmn.getMaxY(), rmx.getMaxY())));

    m.addIndex(i);
    m.addIndex(i+1);
    
    m.addIndex(i+1);
    m.addIndex(i+2);
    
    m.addIndex(i+2);
    m.addIndex(i+3);
   
    m.addIndex(i+3);
    m.addIndex(i);
    for (int i =0; i < 4; i++) m.addColor(color);
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofEnableSmoothing();
    ofDisableDepthTest();
    ofSetLineWidth(lineWidth);
    for (int i = 0; i < NUM_MESHES; i++) mesh[i].draw();
    if (bDrawGui) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        bDrawGui ^=true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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