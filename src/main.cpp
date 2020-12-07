/*-------------include all necessary headers----------------------------*/
#include<iostream>
#include "../include/PpmFile.h"
// #include "../include/dlFile.h"
// #include "../include/GraphsFile.h"
// #include "../include/FileReader.h"
// #include "../include/DocStats.h"
// #include "../include/Input_output.h"
#include <bits/stdc++.h>
#include<string>

int main(int argc, char *argv[])
{
    /*------------------------check if number of arguments is valid----------------------------*/
    if(argc<2 || argc>3)      // only take 1 or 2 arguments
    {
        std::cout<<"Invalid command format\n";
        return -1;
    }
    std::string inputpath(argv[1]);     // stores input path
    std::string outputpath;             //stores output path
    if(argc == 2)
        outputpath = "./";              // by default, make output file in current directory
    else
        outputpath = argv[2];           // else in user specified directory
    FileReader* b;
    std::string delimiter=".";
    std::string token = inputpath.substr(inputpath.find_last_of(delimiter), std::string::npos);

    /*------------------------check file extension and create appropriate objects----------------------------*/
    /*----------------Make the base class pointer point to the appropriate derived class---------------------*/ 

    if(token.std::string::compare(".ppm")==0)
    {
        b = new PpmFile();              
    }
    // else if(token.std::string::compare(".dl") == 0)
    // {
    //     b = new dlFile();
    // }
    // else if(token.std::string::compare(".gdf") == 0)
    // {
    //     b = new GraphsFile();
    //     token=".csv";// ouput file is a csv file
    // }
    // else if(token.std::string::compare(".txt") == 0)
    // {
    //     b = new DocStats();
    // }
    // else if(token.std::string::compare(".ply") == 0)
    // {
    //     b = new Input_output();
    // }
    else
    {
        std::cout<<"Invalid file type\n";
        return -1;
    }

    /*------------------------create input file stream and open the input file----------------------------*/

    std::ifstream fin;
    fin.open(inputpath);
    /*------------------------call input function on the input file  ----------------------------*/

    if(!b->inputFile(fin))
    {
        std::cout<<"File could not be read\n";
    }
    fin.close();
    /*------------------------create output file stream and create the output file----------------------------*/

    std::ofstream fout;
    if(outputpath[outputpath.size()-1]=='.')
    {
        outputpath+="/";// default path for the outputfile
    }
    fout.open(outputpath+"output"+token);
    if(!b->outputFile(fout))
    {
        std::cout<<"Output path not valid\n";
    }
    fout.close();
    delete b;
    return 0;
}