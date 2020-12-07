#include "../include/FileReader.h"
/*------------------getter for input_file---------------------------*/
std::string FileReader::getInputFileName()
{
    return this->input_file;
}

/*------------------getter for output_file---------------------------*/

std::string FileReader::getOutputFileName()
{
    return this->output_file;
}

/*------------------setter for input_file---------------------------*/

void FileReader::setInputFileName(std::string s)
{
    this->input_file=s;
}

/*------------------setter for output_file---------------------------*/

void FileReader::setOutputFileName(std::string s)
{
    this->output_file = s;
}

/*------------------Destructor---------------------------*/

FileReader::~FileReader()
{
    
}