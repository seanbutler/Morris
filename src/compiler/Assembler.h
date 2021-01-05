//
// Created by sean on 04/01/2021.
//

#ifndef MORRIS_ASSEMBLER_H
#define MORRIS_ASSEMBLER_H



#include <vector>
#include <map>

#include <filesystem>
#include <iostream>
#include <fstream>

#include "Instructions.h"

class Assembler {

public:
//    Assembler(std::string AS) : assemblyStr(AS) {}
    Assembler(){}
    virtual ~Assembler() {}

    INSTR ScanInstruction();

    void Scan(std::string AS) {
        assemblyStr = AS;
        INSTR result;
        do {
            result = ScanInstruction();
        } while (result != INSTR::END_OF_FILE && result != INSTR::ERROR);

        std::cout << std::endl << "Dump Labels Map" << std::endl;
        DumpLabelsMap();

        std::cout << std::endl << "Dump Jumps Map" << std::endl;
        DumpJumpsMap();

        std::cout << std::endl << "Dump Data Map" << std::endl;
        DumpDataMap();

        PatchUpJumps();

    }

    void PatchUpJumps() {
        // go through the jump locations a patch in the correct addresses

        //std::cout << "Patching Jumps " << std::endl;
        for(auto J : jumps) {
            //std::cout << "Patch " << J.first << " " << J.second ;
            //std::cout << " to " << labels[J.second] << std::endl;

            instructions[J.first] = labels[J.second];
        }
        //std::cout << std::endl;
    }

    std::vector<int> GetInstructions() {
        return this->instructions;
    }

    void OutputInstructionList(std::string F) {
        std::ofstream instructionListFile;
        std::string filename = std::filesystem::path(F);
        filename += std::string(".instr");
        instructionListFile.open(filename);

        for (auto I : instructions) {
            instructionListFile << (int) I << "\n";
        }
    }

    void DumpLabelsMap() {
        for (auto E : labels) {
            std::cout << "L " << E.first << " " << E.second << std::endl;
        }
    }

    void DumpJumpsMap() {
        for (auto E : jumps) {
            std::cout << "J " << E.first << " " << E.second << std::endl;
        }
    }

    void DumpDataMap() {
        for (auto E : data) {
            std::cout << "D " << E.first << " " << E.second << std::endl;
        }
    }


    std::string assemblyStr;
    int assemblyPos = 0;
    unsigned int currentLine = 0;
    std::vector<int> instructions;

    std::vector<std::string> identifiers;

    std::map<std::string, int> labels;
    std::map<int, std::string> jumps;
    std::map<std::string, int> data;
};

#endif //MORRIS_ASSEMBLER_H
