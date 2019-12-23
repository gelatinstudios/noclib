
#include <unistd.h>
#include <xmmintrin.h>

#define stdin_fd 0
#define stdout_fd 1

typedef enum {false, true} bool;

static float square_root(const float x) {
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(x)));
}

static void newline(void) {
        write(stdout_fd, "\n", 2);
}

static void print_str(const char *str, const size_t length) {
        write(stdout_fd, str, length);
}

static float read_float(void) {
        char buffer[256] = {0};
        read(stdin_fd, buffer, 256);

        const char *c = buffer;
        bool is_negative = false;
        if (*c == '-') {
                is_negative = true;
                ++c;
        }

        float n = 0.0f;
        while (*c >= '0' && *c <= '9') {
                n *= 10.0f;
                n += *c - '0';
                ++c;
        }
        if (*c == '.') {
                ++c;
                float f = 0.1f;
                while (*c >= '0' && *c <= '9') {
                        n += (*c - '0') * f;
                        f *= 0.1f;
                        ++c;
                }
        }

        if (is_negative) n = -n;
        return n;
}

static char *print_float_converter(long n, char *c) {
        long denom = 1;
        long n1 = n;
        while (n1 >= 10) {
                n1 /= 10;
                denom *= 10;
        }

        while (denom) {
                *c = n / denom + '0';
                n %= denom;
                denom /= 10;
                ++c;
        }
        return c;
}

static void print_float(float f) {
        char buffer[256] = {0};
        char *c = buffer;

        bool is_negative = false;
        if (f < 0) {
                f = -f;
                is_negative = true;
                *c = '-';
                ++c;
        }
        long integer = f;
        long fraction = (f - integer) * 1000;

        c = print_float_converter(integer, c);

        if (fraction) {
                *c = '.';
                ++c;
                c = print_float_converter(fraction, c);
        }
        *c = 0;

        write(stdout_fd, buffer, 256);
}

int main(void) {
        print_str("y = ax^2 + bx + c\n", 19);
        print_str("a = ", 5);
        const float a = read_float();
        print_str("b = ", 5);
        const float b = read_float();
        print_str("c = ", 5);
        const float c = read_float();
        newline();

        float imag = b*b - 4*a*c;
        float denom = 2*a;
        const float real = -b / denom;

        if (imag < 0) {
                print_str("the roots are complex\n", 23);
                if (denom < 0) denom = -denom;
                imag = square_root(-imag) / denom;
                print_str("they are ", 10);
                print_float(real);
                print_str(" +/- ", 6);
                print_float(imag);
                print_str("i", 2);
        } else {
                print_str("the roots are real\n", 20);
                imag = square_root(imag) / denom;
                const float root1 = real + imag;
                const float root2 = real - imag;
                print_str("they are ", 10);
                print_float(root1);
                print_str(" and ", 6);
                print_float(root2);
        }

        newline();
}
