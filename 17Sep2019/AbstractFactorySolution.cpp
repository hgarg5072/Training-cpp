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

// ---- Abstract Factory
struct IFactory {
	virtual ITaskBar * createTaskBar() = 0;
	virtual IStatusBar * createStatusBar() = 0;
	virtual IWindow * createWindow() = 0;
};
struct MSFactory : IFactory {
	virtual ITaskBar * createTaskBar() {		return new MSTaskBar();	}
	virtual IStatusBar * createStatusBar() { return new MSStatusBar(); }
	virtual IWindow * createWindow() { return new MSWindow(); }
};
struct LinuxFactory : IFactory {
	virtual ITaskBar * createTaskBar() { return new LinuxTaskBar(); }
	virtual IStatusBar * createStatusBar() { return new LinuxStatusBar(); }
	virtual IWindow * createWindow() { return new LinuxWindow(); }
};

// ------------ App --------------
int main() {
	IFactory *fp = new LinuxFactory(); // MSFactory();
	
	ITaskBar *tp = fp->createTaskBar();
	tp->draw();

	IStatusBar *sp = fp->createStatusBar();
	sp->draw();

	IWindow *wp = fp->createWindow();
	wp->draw();
}