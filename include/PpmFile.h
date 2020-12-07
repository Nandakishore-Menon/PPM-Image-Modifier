#ifndef PpmFile_h
#define PpmFile_h
#include "FileReader.h"
#include "Pixel.h"
#include<fstream>
#include<iostream>
#include <vector>
#include <string>

class PpmFile: public FileReader
{
    private:                                                                      
        std::vector<std::vector<Pixel> > data;      //Stores the input data as pixels                                  
        std::string magicNumber;    //Stores the magicnumber in the header of .ppm files. eg "P3"                                       
        int width;                  // stores width in pixels                                                                  
        int height;                 // stores height in pixels                       
        int maxVal;                 // stores maximum intensity of a color in a pixel                   
    public:   
        PpmFile();                  // default constructor
        PpmFile(const PpmFile &pp); // Copy constructor                                           
        bool inputFile(std::ifstream& fin); //function to read data from the input ppm file                                
        bool outputFile(std::ofstream& fout);// function that changes RGB to BRG and writes into output file
        ~PpmFile(){};                                          
        
};

#endif