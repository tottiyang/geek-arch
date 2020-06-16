#include "Component.h"

void Composite::add(Component* c) {
    m_leafs.push_back(c);
}

void Composite::operation() {
    print();

    vector<Component*>::iterator comIter = m_leafs.begin();
    for (; comIter != m_leafs.end(); comIter++) {
        fprintf(stderr, "----");
        (*comIter)->operation();
    }
}