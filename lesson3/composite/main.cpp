#include "Component.h"

class picture: public Leaf {
public:
    picture() {}
    picture(string name) {}
};

class button: public Leaf {
public:
    button() {}
    button(string name) { m_name = name; }
};

class lable: public Leaf {
public:
    lable() {}
    lable(string name) { m_name = name; }
};

class checkbox: public Leaf {
public:
    checkbox() {}
    checkbox(string name) { m_name = name; }
};

class textbox: public Leaf {
public:
    textbox() {}
    textbox(string name) { m_name = name; }
};

class linklable: public Leaf {
public:
    linklable() {}
    linklable(string name) { m_name = name; }
};

class passwordbox: public Leaf {
public:
    passwordbox() {}
    passwordbox(string name) { m_name = name; }
};

int main() {

    Composite* winForm = new Composite(string("WINDONW窗口"));

    Component* p = new picture(string("LOGO图片"));
    winForm->add(p);

    Component* b1 = new button(string("登录"));
    winForm->add(b1);

    Component* b2 = new button(string("注册"));
    winForm->add(b2);

    Composite* frame = new Composite(string("FREAM1"));
    winForm->add(frame);

    Component* l1 = new lable(string("用户名"));
    frame->add(l1);

    Component* tb1 = new textbox(string("文本框"));
    frame->add(tb1);

    Component* l2 = new Lable(string("密码"));
    frame->add(l2);

    Component* pb = new passwordbox(string("密码框"));
    frame->add(pb);

    Component* cb = new checkbox(string("复选框"));
    frame->add(cb);

    Component* tb2 = new textbox(string("记住用户名"));
    frame->add(tb2);

    Component* ll = new linklable(string("忘记密码"));
    frame->add(ll);

    winForm->operation();
    return 0;
}
