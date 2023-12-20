#include "ofApp.h"
#include "ofAppNoWindow.h"
#include "ofMain.h"

int main() {
  auto window = make_shared<ofAppNoWindow>();

  ofRunApp(window, make_shared<ofApp>());
  ofRunMainLoop();
}
