#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    num = 6;
    size = MIN(ofGetHeight(), ofGetWidth())/(num + 1.0);
    
    randomize();
    
    gui.setup();
    for (int i = 0; i < NUM_MESHES; i++) {
        layer[i].setName("Layer " + ofToString(i));
        layer[i].add(color[i].set("color " + ofToString(i), ofColor::red, ofColor(0,0), ofColor(255,255)));
        layer[i].add(minSize[i].set("minSize " + ofToString(i), size-10 , 0, size ));
        layer[i].add(maxSize[i].set("maxSize " + ofToString(i), size +10, 0, size*2 ));
        maxSize[i].addListener(this, &ofApp::setSquaresF);
        minSize[i].addListener(this, &ofApp::setSquaresF);
        color[i].addListener(this, &ofApp::setSquaresCol);
        gui.add(layer[i]);
    }

    gui.add(numIter.set("Num Iterations", 10, 1, 200));
    gui.add(lineWidth.set("lineWidth", 1, 0, 5));
    gui.add(dotSize.set("dot size", 1, 0, 20));
 
    
    
    blurParams.setName("blur params");
    blurScale.setup("Constartep,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,");
    blurRotation,
    blurBrightness,
    blurShape;
    blurRadius;

    
    gui.loadFromFile("settings.xml");
    setSquares();
    
    blur.setup(ofGetWidth(), ofGetHeight());
    bDrawGui =true;
}
//--------------------------------------------------------------
void ofApp::setSquares(){
    
    for (int i = 0; i < NUM_MESHES; i++){
        mesh[i].clear();
        dotMesh[i].clear();
    }
    int rows = num;
    int cols = num;
    int total = rows * cols;
    for (int i = 0; i < NUM_MESHES; i++){
        mesh[i].setMode(OF_PRIMITIVE_LINES);
        dotMesh[i].setMode(OF_PRIMITIVE_POINTS);
        
        for (int y = 0 ; y < rows; y++) {
            for (int x  =0 ; x < cols; x++) {
                if (i == indColor[y][x]) {
                    for (int j = 0; j < numIter; j++) {
                        randRect(i,ofPoint((x+1)*size, (y+1)*size), MIN(minSize[i],maxSize[i]), MAX(minSize[i],maxSize[i]), color[i]);
                    }
                }
            }
        }
        dotMesh[i].addVertices(mesh[i].getVertices());
        dotMesh[i].addColors(mesh[i].getColors());

    
    }
    
}
//--------------------------------------------------------------
void ofApp::randomize(){

   // for (int i = 0; i < indColor.size();i++) {
     //   indColor[i].clear();
    //}
    if(indColor.size()){
        indColor.clear();
    }
    int rows = num;
    int cols = num;
    for (int y = 0 ; y < rows; y++) {
        vector<int> v;
        for (int x  =0 ; x < cols; x++) {
            int r = (int)floor(ofRandom(0, NUM_MESHES));
            if(r >= NUM_MESHES){
                r = NUM_MESHES - 1;
            }
            v.push_back(r);
        }
        indColor.push_back(v);
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
void ofApp::randRect(int meshIndex, ofPoint center, float min, float max, ofColor color){
    ofRectangle rmx, rmn;
    rmx.setFromCenter(center, max, max);
    rmn.setFromCenter(center, min, min);
    unsigned int i = mesh[meshIndex].getVertices().size();
    ofMesh & m = mesh[meshIndex];
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
    for (int i =0; i < 4; i++){
        m.addColor(color);
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofEnableSmoothing();
    ofDisableDepthTest();
    ofSetLineWidth(lineWidth);
    for (int i = 0; i < NUM_MESHES; i++){
        mesh[i].draw();
        glPointSize(dotSize);
        dotMesh[i].draw();
    }
    if (bDrawGui) {
        gui.draw();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        bDrawGui ^=true;
    }else if(key == 'r'){
        randomize();
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