#include "consistent_hash.h"
#include "stdlib.h"
#include <iostream>

int main() {
    // 十台机器，共100个虚拟节点
    int server_count = 10;
    int virtual_node_count = 10;
    int key_count = 1000000; 
    int counter[10];
    char string_tmp[10];

    for (int i=0; i<server_count; i++) {
        counter[i] = 0;
    }

    ConsistentHash *ch = new ConsistentHash(server_count, virtual_node_count);
    ch->Initialize();
    for (int i=0; i<key_count; i++) {
        sprintf(string_tmp,"%d",i);
        // std::cout << string_tmp << std::endl;
        int index = ch->GetServerIndex(string_tmp);
        counter[index]++;
    }

    for (int i=0; i<server_count; i++) {
        std::cout << "server[" << i << "]:" << counter[i] << std::endl;
    }

    return 0;
}