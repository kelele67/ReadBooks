/* 用原型实例指定对象的种类
 * 通过拷贝这些原型创建新的对象
 */


// 普通的实现

// #include <iostream>
// using namespace std;

// // 丑角
// class Stooge { // 还是换回自己的埃及习惯吧~
// public:
// 	virtual void slapStick() = 0;
// };

// class Larry : public Stooge {
// public:
// 	void slapStick() {
// 		cout << "Larry: poke eyes" << endl;
// 	}
// };
// class Moe : public Stooge {
// public:
// 	void slapStick() {
// 		cout << "Moe: slap head" << endl;
// 	}
// };
// class Curly : public Stooge {
// public:
// 	void slapStick() {
// 		cout << "Curly: suffer abuse" << endl;
// 	}
// };

// int main(void) {
// 	Stooge* roles[10];
// 	int in, j, i = 0; // 注意初始化顺序，小心segmentation fault

// 	cout << "L(1) M(2) C(3) Go(0): ";
// 	cin >> in;
// 	while (in) {
// 		if (in == 1) {
// 			roles[i++] = new Larry;
// 		}
// 		else if (in == 2) {
// 			roles[i++] = new Moe;
// 		}
// 		else {
// 			roles[i++] = new Curly;
// 		}
// 		cout << "L(1) M(2) C(3) Go(0): ";
// 		cin >> in;
// 	}

// 	for (j = 0; j < i; j++) {
// 		roles[j]->slapStick();
// 	}

// 	for (j = 0; j < i; j++) {
// 		delete roles[j];
// 	}

// 	return 0;
// }

// L(1) M(2) C(3) Go(0): 1
// L(1) M(2) C(3) Go(0): 2
// L(1) M(2) C(3) Go(0): 3
// L(1) M(2) C(3) Go(0): 1
// L(1) M(2) C(3) Go(0): 0
// Larry: poke eyes
// Moe: slap head
// Curly: suffer abuse
// Larry: poke eyes

// 原型模式
// #include <iostream>
// using namespace std;

// class Stooge {
// public:
// 	virtual Stooge* clone() = 0;
// 	virtual void slapStick() = 0;
// };

// class Factory {
// public:
// 	static Stooge* create(int i);
// private:
// 	static Stooge* prototypes_[4];
// };

// class Larry : public Stooge {
// public:
// 	Stooge* clone() { return new Larry; }
// 	void slapStick() {
// 		cout << "Larry: poke eyes" << endl;
// 	}
// };
// class Moe : public Stooge {
// public:
// 	Stooge* clone() { return new Moe; }
// 	void slapStick() {
// 		cout << "Moe: slap head" << endl;
// 	}
// };
// class Curly : public Stooge {
// public:
// 	Stooge* clone() { return new Curly; }
// 	void slapStick() {
// 		cout << "Curly: suffer abuse" << endl;
// 	}
// };

// Stooge* Factory::prototypes_[] = { 0, new Larry, new Moe, new Curly };
// Stooge* Factory::create(int i) { return prototypes_[i]->clone(); }

// int main() {
// 	Stooge* roles[10];
// 	int in, j, i = 0;

// 	cout << "vlh L(1) M(2) C(3) Go(0): ";
// 	cin >> in;
// 	while (in) {
// 		roles[i++] = Factory::create(in);
// 		cout << "L(1) M(2) C(3) Go(0): ";
// 		cin >> in;
// 	}

// 	for (j = 0; j < i; j++) {
// 		roles[j]->slapStick();
// 	}
	
// 	for (j = 0; j < i; j++) {
// 		delete roles[j];
// 	}

// 	return 0;
// }

// 原型模式的demo
#include <iostream>
using namespace std;

enum imageType { LSAT, SPOT };

class Image {
public:
	virtual void draw() = 0;
	static Image* findAndClone(imageType);
protected:
	virtual imageType returnType() = 0;
	virtual Image* clone() = 0;
	// 注册它的原型作为图像的每个子类的声明
	static void addPrototype(Image* image) {
		_prototypes[_nextSlot++] = image;
	}
private:
	static Image* _prototypes[10];
	static int _nextSlot;
};

Image* Image::_prototypes[];
int Image::_nextSlot;

// client 调用这个公共静态成员函数时,它需要一个图像的子类实例
Image* Image::findAndClone(imageType type) {
	for (int i = 0; i < _nextSlot; i++) {
		if (_prototypes[i]->returnType() == type) {
			return _prototypes[i]->clone();
		}
	}
}

class LandSatImage : public Image {
public:
	imageType returnType() { return LSAT; }
	void draw() { cout << "LandSatImage::draw " << _id << endl; }
	Image* clone() { return new LandSatImage(1); }
protected:
	LandSatImage(int dummy) { _id = _count++; }
private:
	// 初始化机制——这将调用注册一个图像子类原型的的默认构造函数
	static LandSatImage _landSatImage;
	// 当静态 私有成员被初始化时才调用
	LandSatImage() {addPrototype(this); }

	//每个实例名义上的“状态”机制
	int _id;
	static int _count;
};

// 注册子类原型
LandSatImage LandSatImage::_landSatImage;
// 初始化 每个实例名义上的“状态”机制
int LandSatImage::_count = 1;

class SpotImage : public Image {
public:
	imageType returnType() { return SPOT; }
	void      draw()       { cout << "SpotImage::draw " << _id << endl; }
	Image*    clone()      { return new SpotImage( 1 ); }
protected:
	SpotImage( int dummy ) { _id = _count++; }
private:
	SpotImage() { addPrototype( this ); }
	static SpotImage _spotImage;
	int        _id;
	static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

// 模拟创建请求流
const int NUM_IMAGES = 8;
imageType input[NUM_IMAGES] = { LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT };

int main() {
	Image* images[NUM_IMAGES];

	// 提供一个特定的图像类型,找到合适的原型,并返回一个克隆
	for (int i = 0; i < NUM_IMAGES; i++) {
		images[i] = Image::findAndClone(input[i]);
	}

	// 证明图像对象已经被正确克隆
	for (int i = 0; i < NUM_IMAGES; i++) {
		images[i]->draw();
	}

	for (int i = 0; i < NUM_IMAGES; i++) {
			delete images[i];
	}
	return 0;

}
