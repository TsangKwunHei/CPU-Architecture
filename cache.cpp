
/*
- simple logic direct map cahce, 
input access order, 
hit rate output
- LRU

*/
/*
Cache [
cache_blocks[
cache_entry [ 
TAG
Data_block
flag_bits
]
]
]
num_bytes per block * num_block


*/
struct cache_entry {
    int tag;
    int data_block;
    bool flag_bits;
}

// 1 fetch from from memory 
// flag_bits default to false
// direct

// 2 