#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(0);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	
	int radius = 250;
	for (int z = -300; z <= 300; z += 20) {

		auto deg_start = ofMap(ofNoise((z + 300) * 0.0005 + ofGetFrameNum() * 0.01), 0, 1, -360, 360);

		for (int deg = deg_start; deg < deg_start + 360; deg += 120) {

			ofDrawLine(glm::vec3(radius * cos((deg + 2) * DEG_TO_RAD), radius * sin((deg + 2) * DEG_TO_RAD), z),
				glm::vec3(radius * cos((deg + 118) * DEG_TO_RAD), radius * sin((deg + 118) * DEG_TO_RAD), z));
		}
	}

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}