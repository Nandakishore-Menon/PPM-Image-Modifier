#include "../include/Pixel.h"

/*------------------Parameterized constructor---------------------------*/

Pixel::Pixel(int r, int g, int b): red(r), green(g), blue(b)
{

}       

/*------------------Default Constructor---------------------------*/

Pixel::Pixel(): Pixel(0, 0, 0)
{

}

/*------------------Copy Constructor---------------------------*/

Pixel::Pixel(const Pixel &p):red(p.red), green(p.green), blue(p.blue)
{

}

/*------------------friend functions---------------------------*/

std::stringstream& operator>> (std::stringstream& fin, Pixel& p)
{
    fin >> p.red;
    fin >> p.green;
    fin >> p.blue;
    return fin;
}

std::ofstream& operator<< (std::ofstream& fout, Pixel& p)
{                            
    fout << p.blue << " ";                                                      
    fout << p.red  << " ";                                                    
    fout << p.green;                                                            
    return fout;                                                                  
}

/*-----------setter functions for the colors in a pixel------------------------*/

void Pixel::setRed(int val)
{
    this->red = val;
}
void Pixel::setGreen(int val)
{
    this->green = val;
}
void Pixel::setBlue(int val)
{
    this->blue = val;
}