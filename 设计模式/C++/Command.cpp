/* 命令模式将“请求”封装成对象，
 * 以便使用不同的请求、队列或者日志来参数化其他对象。
 * 命令模式也支持可撤销的操作。
 * 命令对象将动作和接受者包进对象中，这个对象只暴露一个execute()方法。
 * 当需要将发出请求的对象和执行请求的对象解耦的时候，使用命令模式。
 */




/* 遥控器上有一个插槽，可以放上不同的装置，
 * 然后用按钮控制。我们这里放置电灯，
 * 并有开和关按钮。
 * 可以命令模式实现
 */


#include <iostream>

using namespace std;

// 电灯类
class Light {
public:
	void on() {
		cout << "Light on !" << endl;
	}
	void off() {
		cout << "Light off !" << endl;
	}
};

// 命令类
class Command {
public:
	virtual void execute() {}
};

// 具体命令类
class LightOnCommand : public Command {
public:
	LightOnCommand(Light* lig) : light(lig) {}
	// execute 方法
	void execute() {
		light->on();
	}
private:
	Light* light;
};

class LightOffCommand : public Command {
public:
	LightOffCommand(Light* lig) : light(lig) {}
	void execute() {
		light->off();
	}
private:
	Light* light;
};

// 遥控器类
class RemoteControl {
public:
	void setCommand(Command* command) {
		slot = command;
	}
	void buttonOn() {
		slot->execute();
	}
private:
	Command* slot;
};

int main() {
	RemoteControl lightOnControl;
	RemoteControl lightOffControl;

	Command* onCommand = new LightOnCommand(new Light());
	Command* offCommand = new LightOffCommand(new Light());

	lightOnControl.setCommand(onCommand);
	lightOffControl.setCommand(offCommand);

	lightOnControl.buttonOn();
	lightOffControl.buttonOn();

	return 0;
}