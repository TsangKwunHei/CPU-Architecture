#include <iostream>
#include <vector>
#include <tuple>

struct cache_entry {
    int tag;
    int data;
    bool flagBits;
}

struct cache_entry cache_blocks[] = {
    {12,123213213,false},
    {12,123213213,false},
    {12,123213213,false},
    {12,123213213,false},
};

access_cache(int address)
    bool hit
    //index
    int index = address % cache_blocks.size();
    cache_now = cache_blocks[index];
        //if tag match
    if (cache_now.tag == address.tag) {
        if  (cache_now.flagBits == true) {
            //hit 
            print(hit)
            hit_count ++;
        }
    }
    if (!hit) {
        print(miss)
        Direct_Map_cache(address);
    }

Direct_Map_cache(address) {
    accessRAM(address);
    int index = 1;
    cache_entry.line[index] = address;
}


int main() {

    // address, data
    vector<tuple<int,int>> memory;
    memory.pushback(make_tuple(10,10));

    list< look_address[5] = {1,2,3,4,5};
    for (addresss in look_address) {
        access_cache(address)
    }

    cout << "hitRate =" << hit_count/RAM_address.size *100 << "%" ; 

}