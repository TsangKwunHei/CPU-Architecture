#include <iostream>
#include <vector>
#include <tuple>

int hit_count = 0;
struct cache_entry {
    int tag;
    int data;
    bool flagBits;
    int freq;
};

struct cache_entry cache_blocks[] = {
    {-1,0,false},
    {-1,0,false},
    {-1,0,false},
    {-1,0,false},
};

int accessRAM(int address) {
    return 1;
}
const int CACHE_SIZE = sizeof(cache_blocks) / sizeof(cache_blocks[0]);


void Direct_Map_cache(int address) {
    int data_fetch = accessRAM(address);
    int index = address % CACHE_SIZE;
    cache_entry& cache_now = cache_blocks[index];
    cache_now.tag = address >> 6 ;//tag 26 bits, drop 6 bits via shift
    cache_now.data = data_fetch;
    cache_now.flagBits = true;

}

void associative(int address) {
    int data_fetch = accessRAM(address);
    int lowest_freq = cache_blocks[0].freq;
    int index = 0;
    for (int i = 0; i < CACHE_SIZE; i++ ) {
        if (cache_blocks[i].freq < lowest_freq) {
            lowest_freq = cache_blocks[i].freq;
            index = i;
        }
   
      
    }
    cache_entry& cache_now = cache_blocks[index];
    cache_now.freq = 1;
    cache_now.tag = address >> 6 ;//tag 26 bits, drop 6 bits via shift
    cache_now.data = data_fetch;
    cache_now.flagBits = true;

}

void access_cache(int address) {
    bool hit = false;
    //index
    int index = address % CACHE_SIZE;
    cache_entry& cache_now = cache_blocks[index];
    int address_tag = address >> 6 ;//tag 26 bits, drop 6 bits via shift
        //if tag match
    if (cache_now.tag == address_tag) {
        if  (cache_now.flagBits == true) {
            //hit 
            std::cout << "hit" << "\n";
            hit_count ++;
            hit = true;
        }
    }
    if (!hit) {
        std::cout << "miss" << "\n";
        //Direct_Map_cache(address);
        associative(address);
    }
     cache_now.freq ++;
}

int main() {

    // address, data
    //vector<tuple<int,int>> memory;
   // memory.pushback(make_tuple(10,10));

    std::vector<int> look_address = {
        0,  
        2, 
        16,  
        32,   
        64,
        256,
        16,
        16,

        };
    for (int address : look_address) {
        access_cache(address);
    }

    std::cout << "\nhitRate =     " << hit_count*100.0/ look_address.size() << "%" ; 

}