/* 观察者模式定义了对象之间的一对多依赖，
 * 这样一来，当一个对象改变状态时，
 * 它的所有依赖者都会收到通知并自动更新。
 */

/* 气象系统有三个部分分别是
 * 气象站（获取实际气象数据的物理装置），
 * WeatherData对象（用来追踪来自气象站的数据，并更新布告板）
 * 和布告板（显示目前天气状况给用户看）。
 * WeatherData对象知道如何根物理气象站联系，以取得更新信息。
 * WeatherData对象会随机更新三个布告板的显示：
 * 目前状况（温度，湿度，气压）、气象统计和天气预报。
 * 我们的工作是建立一个 应用，
 * 利用WeatherData对象取得数据，
 * 并更新三个布告板：目前状况、气象统计和天气预报。
 */

#include <iostream>
#include <list>

using namespace std;

//以下是观察者和主题的基类，其中DisplayElement是一个抽象类,用来
//使子类实现显示功能 
class Observer {
public:
	virtual ~Observer() {};
	virtual void update(float temp, float humidity, float pressure) {}; // humidity 湿度
};

class DisplayElement {
public:
	virtual ~DisplayElement() {};
	virtual void display() = 0;
};

class Subject {
public:
	virtual ~Subject() {};
	virtual void regsiterObserver(Observer* o) {};
	virtual void removeObserver(Observer* o) {};
	virtual void notifyObserver() {};
};

// WeatherData类，实现了注册，删除和通知观察者的功能
class WeatherData : public Subject {
public:
	void regsiterObserver(Observer *o) {
		observers.push_back(o);
	}
	void removeObserver(Observer *o) {
		observers.remove(o);
	}
	void notifyObservers() {
		list<Observer*>::iterator iter = observers.begin();
		for (; iter != observers.end(); iter++) {
			Observer* observer = *iter;
			observer->update(tempreature, humidity, pressure);
		}
	}

	void measurementsChanged() {
		notifyObservers();
	}

	void setMeasurements(float temp, float humid, float pres) {
		tempreature = temp;
		humidity = humid;
		pressure = pres;
		measurementsChanged();
	}

private:
	list<Observer*> observers;
	float tempreature;
	float humidity;
	float pressure;
};

//以下是CurrentConditionsDisplay布告板的实现，主要功能为申请注册，实时更新和显示。
class CurrentConditionDisplay : public Observer, public DisplayElement {
public:
	CurrentConditionDisplay(Subject *weather_Data) {
		weatherData = weather_Data;
		weatherData->regsiterObserver(this);
	}

	void update(float temp, float humid, float pres) {
		tempreature = temp;
		humidity = humid;
		// pressure = pres;
		display();
	}

	void display() {
		cout << "Current conditions: " << tempreature << "F degree and " << humidity << "% humidity" << endl;
	}

private:
	float tempreature;
	float humidity;
	Subject *weatherData;
};

int main() {
	WeatherData *weatherData = new WeatherData();
	CurrentConditionDisplay *currentConditionDisplay = new CurrentConditionDisplay(weatherData);

	weatherData->setMeasurements(80, 65, 30.4f);
	weatherData->setMeasurements(82, 70, 29.2f);
	weatherData->setMeasurements(78, 90, 29.2f);
	return 0;
}
