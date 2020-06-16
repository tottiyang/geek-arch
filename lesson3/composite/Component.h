#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Component {
public:
    Component(){};
    virtual ~Component(){};

    virtual void operation() = 0;
};

class Leaf: public Component {
public:
    Leaf(){};
    ~Leaf(){};

    void operation() {  print(); }

private:
    void print() { printf(m_name.c_str()); }

    string m_name;
};

class Composite: public Component {
public:
    Composite(){};
    ~Composite(){};

    Composite(string name) { m_name = name;};
    void add(Component*);
    void operation();

private:
    void print() { printf(m_name.c_str()); }

    string m_name;
    vector<Component*> m_leafs;
};

#endif