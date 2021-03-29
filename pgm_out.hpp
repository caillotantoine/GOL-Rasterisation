#include <vector>

typedef struct {
    std::vector<unsigned char> data;
    int width;
    int height;
    float cpm; // cells per meter
} Map;

int write_pgm(char *filename, Map map);