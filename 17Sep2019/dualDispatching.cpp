#include <iostream>
using namespace std;

// -------- Lib ------
struct gameObject {
	virtual void collidesWith(gameObject &rhs) = 0;
	virtual void collide() = 0;
};
struct Asteroid : gameObject {
	void collidesWith(gameObject &rhs) { 
		cout << " Asteroid object collides with "; 
		rhs.collide();
	}
	void collide() {
		cout << " Asteroid object\n";
	}
};
struct Ship : gameObject {
	void collidesWith(gameObject &rhs) {
		cout << " Ship object collides with ";
		rhs.collide();
	}
	void collide() {
		cout << " Ship object\n";
	}
};
struct Satellite : gameObject {
	void collidesWith(gameObject &rhs) {
		cout << " Satellite object collides with ";
		rhs.collide();
	}
	void collide() {
		cout << " Satellite object\n";
	}
};

// -------- Middle -

void collided(gameObject & lhs, gameObject & rhs) { // LSP
	if (typeid(lhs) != typeid(rhs))
		lhs.collidesWith(rhs);
	else
		cout << typeid(lhs).name() <<" type Object cannot collide with "<< typeid(rhs).name()<<" object\n";
		//cout << " Same type Objects cannot collide\n";
	cout << "--------------------\n";
}
// ---------- App ----------
int main() {
	Asteroid aObj;
	Ship sObj;
	Satellite saObj;

	collided(aObj, sObj);
	collided(saObj, sObj);
	collided(aObj, saObj);
	collided(sObj, sObj);
}



