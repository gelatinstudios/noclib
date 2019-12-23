
#include <unistd.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

#define nullptr ((void *) 0)
#define assert(x) {if(!(x)) *(char *)0 = 0;}

typedef enum {false, true} bool;

typedef struct {
        char *contents;
        size_t size;
} text_file;

text_file read_text_file(const char *filename) {
        text_file f;

        int fd = open(filename, O_RDONLY);
        f.size = lseek(fd, 0, SEEK_END);
        f.contents = mmap(nullptr, f.size, PROT_READ, MAP_PRIVATE, fd, 0);
        close(fd);

        return f;
}

long parse_long(char *c) {
        bool is_negative = false;
        if (*c == '-') {
                is_negative = true;
                ++c;
        }

        long n = 0;
        while (*c >= '0' && *c <= '9') {
                n *= 10;
                n += *c - '0';
                ++c;
        }
        if (is_negative) n = -n;
        return n;
}

void print_long(long n) {
        bool is_negative = false;
        if (n < 0) {
                n = -n;
                is_negative = true;
        }

        size_t digits = 0;
        long n1 = n;
        long denom = 1;
        while (n1 >= 10) {
                n1 /= 10;
                denom *= 10;
                ++digits;
        }

        size_t buffer_size = digits + 3;
        char buffer[buffer_size];
        char *c = buffer;

        if (is_negative) {
                *c = '-';
                ++c;
        }

        while (denom) {
                *c = n / denom + '0';
                n %= denom;
                denom /= 10;
                ++c;
        }

        *c = '\n';
        ++c;
        *c = 0;

        write(1, buffer, buffer_size);
}

int main(void) {
        text_file f1 = read_text_file("number1.txt");
        text_file f2 = read_text_file("number2.txt");

        long n1 = parse_long(f1.contents);
        long n2 = parse_long(f2.contents);

        print_long(n1 + n2);

        munmap(f1.contents, f1.size);
        munmap(f2.contents, f2.size);
}
