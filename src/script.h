#ifndef SCRIPT_H
#define SCRIPT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define OPS 14
#define MEM 8

void execute(char*);
void populate(char*);
int isop(char*);
void doop(int);
void stackinfo();
static char stack[512][16];
static int stacksize = 0;
static int opindex = 0;
static bool failed = false;
static int memory[MEM] = {0};
static int labels[512] = {-1};
static int labelsize = 0;
static char* ops[OPS] = {"MDS", "IFE", "SET", "ADD", "ENF", "PRN", "ELS", "STP", "MEM", "DEF", "JMP", "IFL", "IFG", "MDX"};
static int mds = 0;
static int mdx = 0;
enum {
    OP_NON=-1, // not an operation
    OP_MDS,    // memory location
    OP_IFE,    // if equal to
    OP_SET,    // set mds
    OP_ADD,    // add
    OP_ENF,    // end if
    OP_PRN,    // print
    OP_ELS,    // else
    OP_STP,    // end of program
    OP_MEM,    // print memory (debug)
    OP_DEF,    // define label
    OP_JMP,    // jump to label
    OP_IFL,    // if less than
    OP_IFG,    // if greater than
    OP_MDX     // second memory location
};

#endif
