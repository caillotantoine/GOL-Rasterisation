#include <iostream>
#include <cstdio>
#include <algorithm> 
#include "pgm_out.hpp"


int write_pgm(char *filename, Map map)
{
    if(map.data.size() != (map.width * map.height))
        return -1;

    FILE* f = NULL;
    f = fopen(filename, "w");

    if(f == NULL)
        return -2;

    unsigned char biggest = *std::max_element(map.data.begin(), map.data.end());
    
    fprintf(f, "P2\n# map.pgm\n%d %d\n%d\n", map.width, map.height, biggest);
    for(int i = 0; i<map.height; i++)
    {
        for(int j = 0; j<map.width; j++)
        {
            fprintf(f, "%d ", map.data.at(i*map.width+j));
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return 0;
}