#include "../include/PpmFile.h"

/*------------------Default Constructor---------------------------*/

PpmFile::PpmFile()
{

}

/*------------------Copy Constructor---------------------------*/

PpmFile::PpmFile(const PpmFile &pp)
{
    width=pp.width;                                                                  
    height=pp.height;                                                                 
    maxVal=pp.maxVal;
}

/*------------------Input function---------------------------*/

bool PpmFile::inputFile(std::ifstream& fin)
{
    if (fin.fail())         //if file is not opened, return false
    {
        return false;
    };
    std::string line;
    std::string delimiter = "#";
    int a[3]; int i=1;
    fin >> magicNumber;     //input magic number
    if (magicNumber != "P3")    //if its not ASCII values, then it is invalid for this tool
    {
        return false;
    }
    while(std::getline(fin, line))
    {
        std::string token = line.substr(0, line.find(delimiter));  
        std::stringstream s(token);
        while(s>>a[i-1])
        {
            
            if(i==3)
            {
                i=0;
                break;
            }
            i++;
            
        }
        if(i==0)
            break;
    }
    i=1;
    width=a[0];height=a[1]; // input height and width of iput image
    maxVal= a[2];          //input maximum intensity
    
    
    
    
    while ( std::getline(fin, line) )
    {
        /*Filter out comments starting with # if any*/
        std::string token = line.substr(0, line.find(delimiter));  
        std::stringstream s(token);
        std::vector<Pixel> temp;    // stores a row of pixels as outputted in the output file
        Pixel p; 
        while(s>>a[i-1])        // input individual colors
        {
            if(i%3==0)          // after getting 3 colors, make it a pixel and add to data
            {
                p.setRed(a[0]);
                p.setGreen(a[1]);
                p.setBlue(a[2]);
                temp.push_back(p);
                i=0;
            }
            i++;
        }
        data.push_back(temp);
        
    }
    
    return true;        // returns true if input was successful
}                                         

/*------------------Output function---------------------------*/

bool PpmFile::outputFile(std::ofstream& fout)   // outputs the data in BRG format
{
    fout << magicNumber << "\n";
    fout << width << " " << height << "\n";
    fout << maxVal<<"\n";
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data.at(i).size();j++)
        {
            fout<<data.at(i).at(j)<<"  ";
        }
        fout<<"\n";
    }
    return true;
}