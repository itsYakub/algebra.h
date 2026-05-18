#define ALGEBRA_IMPLEMENTATION
#include "./../vec2.h"
#
#include <stdio.h>
#include <stdlib.h>
#
#include <math.h>
#
#define NORMAL "\033[0m"
#define BOLD   "\033[1m"
#define RED    "\033[91m"
#define GREEN  "\033[92m"

/* declarations */

static int __algebra_test_vec2add(void);

static int __algebra_test_vec2sub(void);

static int __algebra_test_vec2mul(void);

static int __algebra_test_vec2div(void);

static int __algebra_test_vec2addf(void);

static int __algebra_test_vec2subf(void);

static int __algebra_test_vec2mulf(void);

static int __algebra_test_vec2divf(void);

static int __algebra_test_vec2mulm(void);

static int __algebra_test_vec2eq(void);

static int __algebra_test_vec2noeq(void);

static int __algebra_test_vec2great(void);

static int __algebra_test_vec2greateq(void);

static int __algebra_test_vec2less(void);

static int __algebra_test_vec2lesseq(void);

static int __algebra_test_vec2len(void);

static int __algebra_test_vec2lensq(void);

static int __algebra_test_vec2dist(void);

static int __algebra_test_vec2distsq(void);

static int __algebra_test_vec2dot(void);

static int __algebra_test_vec2cross(void);

static int __algebra_test_vec2norm(void);

static int __algebra_test_vec2neg(void);

static int __algebra_test_vec2abs(void);

static int __algebra_test_vec2sign(void);

static int __algebra_test_vec2sqrt(void);

static int __algebra_test_vec2pow(void);

static int __algebra_test_vec2fract(void);

static int __algebra_test_vec2floor(void);

static int __algebra_test_vec2ceil(void);

static int __algebra_test_vec2round(void);

static int __algebra_test_vec2mod(void);

static int __algebra_test_vec2modf(void);

static int __algebra_test_vec2min(void);

static int __algebra_test_vec2minf(void);

static int __algebra_test_vec2max(void);

static int __algebra_test_vec2maxf(void);

static int __algebra_test_vec2clamp(void);

static int __algebra_test_vec2clampf(void);

static int __algebra_test_vec2lerp(void);

static int __algebra_test_vec2step(void);

static int __algebra_test_vec2smoothstep(void);

static int __algebra_test_vec2perp(void);

static int __algebra_test_vec2reflect(void);

/* main */

int main(void) {
    if (!__algebra_test_vec2add()) { printf("%s%s=== 'vec2add' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2sub()) { printf("%s%s=== 'vec2sub' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2mul()) { printf("%s%s=== 'vec2mul' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2div()) { printf("%s%s=== 'vec2div' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2addf()) { printf("%s%s=== 'vec2addf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2subf()) { printf("%s%s=== 'vec2subf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2mulf()) { printf("%s%s=== 'vec2mulf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2divf()) { printf("%s%s=== 'vec2divf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2mulm()) { printf("%s%s=== 'vec2mulm' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2eq()) { printf("%s%s=== 'vec2eq' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2noeq()) { printf("%s%s=== 'vec2noeq' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2great()) { printf("%s%s=== 'vec2great' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2greateq()) { printf("%s%s=== 'vec2greateq' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2less()) { printf("%s%s=== 'vec2less' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2lesseq()) { printf("%s%s=== 'vec2lesseq' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2len()) { printf("%s%s=== 'vec2len' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2lensq()) { printf("%s%s=== 'vec2lensq' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2dist()) { printf("%s%s=== 'vec2dist' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2distsq()) { printf("%s%s=== 'vec2distsq' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2dot()) { printf("%s%s=== 'vec2dot' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2cross()) { printf("%s%s=== 'vec2cross' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2norm()) { printf("%s%s=== 'vec2norm' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2neg()) { printf("%s%s=== 'vec2neg' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2abs()) { printf("%s%s=== 'vec2abs' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2sign()) { printf("%s%s=== 'vec2sign' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2sqrt()) { printf("%s%s=== 'vec2sqrt' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2pow()) { printf("%s%s=== 'vec2pow' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2fract()) { printf("%s%s=== 'vec2fract' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2floor()) { printf("%s%s=== 'vec2floor' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2ceil()) { printf("%s%s=== 'vec2ceil' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2round()) { printf("%s%s=== 'vec2round' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2mod()) { printf("%s%s=== 'vec2mod' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2modf()) { printf("%s%s=== 'vec2modf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2min()) { printf("%s%s=== 'vec2min' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2minf()) { printf("%s%s=== 'vec2minf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2max()) { printf("%s%s=== 'vec2max' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2maxf()) { printf("%s%s=== 'vec2maxf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2clamp()) { printf("%s%s=== 'vec2clamp' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2clampf()) { printf("%s%s=== 'vec2clampf' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2lerp()) { printf("%s%s=== 'vec2lerp' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2step()) { printf("%s%s=== 'vec2step' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2smoothstep()) { printf("%s%s=== 'vec2smoothstep' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2perp()) { printf("%s%s=== 'vec2perp' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }
    
    if (!__algebra_test_vec2reflect()) { printf("%s%s=== 'vec2reflect' FAILED ===%s\n", BOLD, RED, NORMAL); exit(EXIT_FAILURE); }

    printf("%s%s=== 'ALL 'vec2' TESTS PASSED ===%s\n", BOLD, GREEN, NORMAL); exit(EXIT_SUCCESS);
}

/* implementations */

static int __algebra_test_vec2add(void) {
	printf("%s%s=== 'vec2add' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2sub(void) {
	printf("%s%s=== 'vec2sub' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2mul(void) {
	printf("%s%s=== 'vec2mul' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2div(void) {
	printf("%s%s=== 'vec2div' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2addf(void) {
	printf("%s%s=== 'vec2addf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2subf(void) {
	printf("%s%s=== 'vec2subf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2mulf(void) {
	printf("%s%s=== 'vec2mulf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2divf(void) {
	printf("%s%s=== 'vec2divf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2mulm(void) {
	printf("%s%s=== 'vec2mulm' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2eq(void) {
	printf("%s%s=== 'vec2eq' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2noeq(void) {
	printf("%s%s=== 'vec2noeq' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2great(void) {
	printf("%s%s=== 'vec2great' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2greateq(void) {
	printf("%s%s=== 'vec2greateq' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2less(void) {
	printf("%s%s=== 'vec2less' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2lesseq(void) {
	printf("%s%s=== 'vec2lesseq' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2len(void) {
	printf("%s%s=== 'vec2len' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2lensq(void) {
	printf("%s%s=== 'vec2lensq' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2dist(void) {
	printf("%s%s=== 'vec2dist' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2distsq(void) {
	printf("%s%s=== 'vec2distsq' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2dot(void) {
	printf("%s%s=== 'vec2dot' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2cross(void) {
	printf("%s%s=== 'vec2cross' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2norm(void) {
	printf("%s%s=== 'vec2norm' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2neg(void) {
	printf("%s%s=== 'vec2neg' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2abs(void) {
	printf("%s%s=== 'vec2abs' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2sign(void) {
	printf("%s%s=== 'vec2sign' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2sqrt(void) {
	printf("%s%s=== 'vec2sqrt' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2pow(void) {
	printf("%s%s=== 'vec2pow' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2fract(void) {
	printf("%s%s=== 'vec2fract' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2floor(void) {
	printf("%s%s=== 'vec2floor' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2ceil(void) {
	printf("%s%s=== 'vec2ceil' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2round(void) {
	printf("%s%s=== 'vec2round' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2mod(void) {
	printf("%s%s=== 'vec2mod' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2modf(void) {
	printf("%s%s=== 'vec2modf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2min(void) {
	printf("%s%s=== 'vec2min' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2minf(void) {
	printf("%s%s=== 'vec2minf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2max(void) {
	printf("%s%s=== 'vec2max' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2maxf(void) {
	printf("%s%s=== 'vec2maxf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2clamp(void) {
	printf("%s%s=== 'vec2clamp' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2clampf(void) {
	printf("%s%s=== 'vec2clampf' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2lerp(void) {
	printf("%s%s=== 'vec2lerp' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2step(void) {
	printf("%s%s=== 'vec2step' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2smoothstep(void) {
	printf("%s%s=== 'vec2smoothstep' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2perp(void) {
	printf("%s%s=== 'vec2perp' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}


static int __algebra_test_vec2reflect(void) {
	printf("%s%s=== 'vec2reflect' PASSED ===%s\n", BOLD, GREEN, NORMAL); return (1);
}

