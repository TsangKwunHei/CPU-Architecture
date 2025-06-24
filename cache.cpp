#include <iostream>
#include <vector>
#include <tuple>

int hit_count = 0;
struct cache_entry {
    int tag;
    int data;
    bool flagBits;
};

struct cache_entry cache_blocks[] = {
    {12,123213213,false},
    {12,123213213,false},
    {12,123213213,false},
    {12,123213213,false},
};

int accessRAM(int address) {
    return 1;
}

void Direct_Map_cache(int address) {
    int data_fetch = accessRAM(address);
    int index = address % cache_blocks.size();
    cache_entry cache_now = cache_blocks[index];
    cache_now.tag = address[0-26]; //tag 26 bits
    cache_now.data = data_fetch;

}

void access_cache(int address) {
    bool hit = false;
    //index
    int index = address % sizeof(cache_blocks);
    cache_entry cache_now = cache_blocks[index];
    int address_tag = address >> 6 ;//tag 26 bits, drop 6 bits via shift
        //if tag match
    if (cache_now.tag == address_tag) {
        if  (cache_now.flagBits == true) {
            //hit 
            std::cout << "miss";
            hit_count ++;
        }
    }
    if (!hit) {
        std::cout << "miss";
        Direct_Map_cache(address);
    }
}




int main() {

    // address, data
    vector<tuple<int,int>> memory;
    memory.pushback(make_tuple(10,10));

    std::vector<int> look_address = {
        0x00000000,   
        0x00000010,  
        0x00000040,   
        0x00000001,  
        0x00000101   
        };
    for (addresss : look_address) {
        access_cache(address);
    }

    cout << "hitRate =" << hit_count/RAM_address.size *100 << "%" ; 

}