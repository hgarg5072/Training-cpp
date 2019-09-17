#include <iostream>
using namespace std;

struct ITaskBar { virtual void draw() = 0; };
struct MSTaskBar : ITaskBar {
	virtual void draw() { cout << " MS TaskBar drawn\n"; }
};
struct LinuxTaskBar : ITaskBar {
	virtual void draw() { cout << " Linux TaskBar drawn\n"; }
};

struct IStatusBar { virtual void draw() = 0; };
struct MSStatusBar : IStatusBar {
	virtual void draw() { cout << " MS StatusBar drawn\n"; }
};
struct LinuxStatusBar : IStatusBar {
	virtual void draw() { cout << " Linux StatusBar drawn\n"; }
};

struct IWindow { virtual void draw() = 0; };
struct MSWindow : IWindow {
	virtual void draw() { cout << " MS Window drawn\n"; }
};
struct LinuxWindow : IWindow {
	virtual void draw() { cout << " Linux Window drawn\n"; }
};

// ------------ App --------------
int main() {
	//ITaskBar *tp = new MSTaskBar();  //new LinuxTaskBar();//
	ITaskBar *tp = new LinuxTaskBar();//
	tp->draw();

	IStatusBar *sp = new MSStatusBar();  //new LinuxStatusBar();//
	//IStatusBar *sp = new LinuxStatusBar();
	sp->draw();

	//IWindow *wp = new MSWindow();  //new LinuxWindow();//
	IWindow *wp = new LinuxWindow();
	wp->draw();
}