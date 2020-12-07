#ifndef FileReader_h
#define FileReader_h

#include<fstream>
#include<iostream>
class FileReader
{
private:
    std::string input_file;                     //input file path
    std::string output_file;                    //output file path
public:
    virtual bool inputFile(std::ifstream& fin)=0;   //pure virtual input function to be overridden
    virtual bool outputFile(std::ofstream& fout)=0; //pure virtual output function to be overridden
    std::string getInputFileName();                 //getter for input_file
    std::string getOutputFileName();                //getter for output_file
    void setInputFileName(std::string s);           //setter for input_file
    void setOutputFileName(std::string s);          //setter for output_file
    virtual ~FileReader();                          //virtual destructor
};

#endif