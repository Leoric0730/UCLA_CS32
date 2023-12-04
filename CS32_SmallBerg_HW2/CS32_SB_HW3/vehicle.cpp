//
//  main.cpp
//  CS32_SB_HW3P1
//
//  Created by HaoYu Luo on 2023/2/14.
//

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    Vehicle(string s);
    virtual ~Vehicle();
    string id() const;
    virtual string description() const = 0;
    virtual bool canHover() const;
private:
    string m_name;
};
Vehicle::Vehicle(string s):m_name(s){}

Vehicle::~Vehicle(){}

string Vehicle::id() const{
    return m_name;
}
bool Vehicle::canHover() const {
    return true;
}

//================================ Drone implementation
class Drone :public Vehicle
{
public:
    Drone(string s);
    ~Drone();
    virtual string description() const;
};

Drone::Drone(string s):Vehicle(s){}

Drone::~Drone(){
    cout << "Destroying " << id() << ", " << description() << endl;
}
string Drone::description() const{
    return "a drone";
    }

//================================= Balloon implementation
class Balloon : public Vehicle
{
public:
    Balloon(string s, double d);
    ~Balloon();
    virtual string description() const;
private:
    double m_dia;
};

Balloon::Balloon(string s, double d):Vehicle(s),m_dia(d){}
Balloon::~Balloon(){
    cout << "Destroying the balloon " << id() << endl;
}
string Balloon::description() const {
    if (m_dia < 8) return "a small balloon";
else
    return "a large balloon";
}

//=================================== Satellite implementation


class Satellite :public Vehicle
{
public:
    Satellite(string s);
    ~Satellite();
    virtual string description() const;
    virtual bool canHover() const;
};

Satellite::Satellite(string s):Vehicle(s){}
Satellite::~Satellite(){
    cout << "Destroying the satellite " << id() << endl;
}
string Satellite::description() const {
    return "a satellite";
}

bool Satellite::canHover() const{
    return false;
}


