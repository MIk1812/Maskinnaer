//
// Created by Mikkel Danielsen on 09/05/2020.
//

#ifndef PROJEKT2_STRUCTS_H
#define PROJEKT2_STRUCTS_H

#endif //PROJEKT2_STRUCTS_H

#pragma once

struct symbolTable{
    char** labels;
    int numberOfLabels;
    int* locations;
};
typedef struct symbolTable SymbolTable;

struct lineInfo{
    char* input;
    char* output;
    int firstIndex;
    SymbolTable symbolTable;
    int lineLength;
    int lineCount;
};
typedef struct lineInfo LineInfo;