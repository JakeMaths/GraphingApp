#include "test_funcs.h"

float funcA(float x) {
    return x;
}

float funcB(float x) {
    return x * x;
}

float funcC(float x) {
    return x * x * x;
}

float funcD(float x) {
    return std::abs(x);
}

float funcE(float x) {
    return std::sin(x);
}

float funcF(float x) {
    return std::cos(x);
}

float funcG(float x) {
    return std::tan(x);
}
