#include <iostream>
using namespace std;

// ---- Library ----
struct Shape {
	virtual void draw() = 0; // Pure virtual functions
	//{ cout << "Shape drawn\n"; }
};

struct Triangle : Shape {
	void draw() { cout << " Triangle drawn\n"; }
};

struct Rectangle :Shape{
	void draw() { cout << " Rectangle drawn\n"; }
};
// ----- middle - layer
//template <typename T>
//void render( T &sObj){
void render(Shape &sObj) {
	cout << " --- Allocate the resources ---\n";
	sObj.draw();
	// doJob of rendering
	cout << " --- De-Allocate  resources ---\n";
	cout << " ------------------- \n";
}

// --------------- App --------
int main() {
//	Shape sObj;
	Triangle tObj;
	Rectangle rObj;

	//render(sObj);
	render(tObj);
	render(rObj);
}