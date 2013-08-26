#include <cstdio>
#include <xmmintrin.h>
 
void vectorAdd(float* a, float* b, float* c, size_t n) {
        __m128 A, B, C;
        for(size_t i = 0; i < n; i += 4) {
                A = _mm_load_ps(&a[i]);
                B = _mm_load_ps(&b[i]);
                C = _mm_add_ps(A, B);
                _mm_store_ps(&c[i], C);
        }
}
 
void vectorSub(float* a, float* b, float* c, size_t n) {
        __m128 A, B, C;
        for(size_t i = 0; i < n; i += 4) {
                A = _mm_load_ps(&a[i]);
                B = _mm_load_ps(&b[i]);
                C = _mm_sub_ps(A, B);
                _mm_store_ps(&c[i], C);
        }
}
 
void vectorMultiply(float* a, float* b, float* c, size_t n) {
        __m128 A, B, C;
        for(size_t i = 0; i < n; i += 4) {
                A = _mm_load_ps(&a[i]);
                B = _mm_load_ps(&b[i]);
                C = _mm_mul_ps(A, B);
                _mm_store_ps(&c[i], C);
        }
}
 
void vectorDiv(float* a, float* b, float* c, size_t n) {
        __m128 A, B, C;
        for(size_t i = 0; i < n; i += 4) {
                A = _mm_load_ps(&a[i]);
                B = _mm_load_ps(&b[i]);
                C = _mm_div_ps(A, B);
                _mm_store_ps(&c[i], C);
        }
}
 
int main() {
        const size_t num = 7;
        float a[num] = {1, 2, 3, 4, 5, 6, 7};
        float b[num] = {1, -1, -2, 1, -3, -2, 5};
        float c[num];
        vectorAdd(a, b, c, num);
        for(int i = 0; i < num; ++i) {
                printf("%f ", c[i]);
        }
        printf("\n");
        vectorSub(a, b, c, num);
        for(int i = 0; i < num; ++i) {
                printf("%f ", c[i]);
        }
        printf("\n");
        vectorMultiply(a, b, c, num);
        for(int i = 0; i < num; ++i) {
                printf("%f ", c[i]);
        }
        printf("\n");
        vectorDiv(a, b, c, num);
        for(int i = 0; i < num; ++i) {
                printf("%f ", c[i]);
        }
        printf("\n");
 
        return 0;
}
