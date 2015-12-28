#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    enum AppMode {
        AppMode_Release,
        AppMode_Debug
    };
    
    AppMode mode = AppMode_Debug;
    ofxPanel gui;
    ofParameterGroup param_group0;
    ofParameter<float> param_group0_param0;
    ofParameter<int> param_group0_param1;
    ofParameter<int> param_group0_param2;
    
    ofParameterGroup param_group1;
    ofParameter<bool> param_group1_param0;
    ofParameter<string> param_group1_param1;
    ofxButton param_group1_param2;
    
    
    //--------------------------------------------------------------
    void setup(){
        ofBackground(0);
        ofSetFrameRate(60);
        ofSetVerticalSync(true);
        
        setupGUI();
    }
    
    void setupGUI() {
        gui.setDefaultWidth(240);
        gui.setup();
        gui.setName("Setting");
        param_group0.setName("Parameter Group 0");
        param_group0.add(param_group0_param0.set("Param 0", 0.3, 0.0, 1.0));
        param_group0.add(param_group0_param1.set("Param 1", 128, 0, 255));
        param_group0.add(param_group0_param2.set("Param 2", 0, 0, 255));
        gui.add(param_group0);
        param_group1.setName("Parameter Group 1");
        param_group1.add(param_group1_param0.set("toggle", false));
        param_group1.add(param_group1_param1.set("string", "test"));
        gui.add(param_group1);
        gui.add(param_group1_param2.setup("button"));
        
        
        param_group0_param0.addListener(this, &ofApp::updateFloatParam);
        param_group0_param1.addListener(this, &ofApp::updateIntParam);
        param_group0_param2.addListener(this, &ofApp::updateIntParam);
        
        gui.loadFromFile("settings.xml");
    }
    
    //--------------------------------------------------------------
    void update(){
        
    }
    
    //--------------------------------------------------------------
    void draw() {
        if(mode == AppMode_Debug) {
            drawDebug();
        }
    }
    
    void drawDebug() {
        ofSetColor(255);
        gui.draw();
    }
    
    void exit() {
        gui.saveToFile("settings.xml");
    }
    
    void switchDebug() {
        if (mode == AppMode_Debug) {
            mode = AppMode_Release;
        }else{
            mode = AppMode_Debug;
        }
    }
    
    void keyPressed(int key){
        if(key == 'f'){
            ofToggleFullscreen();
        }else if(key == 'd') {
            switchDebug();
        }
    }
    
    void updateFloatParam(float &value) {
        //do something.
        cout << "updateFloatParam : " << value << endl;
    }
    
    void updateIntParam(int &value) {
        //do something.
        cout << "updateIntParam : " << value << endl;
    }
};

//========================================================================
int main( ){
	ofSetupOpenGL(960,540, OF_WINDOW);
	ofRunApp( new ofApp());
}
