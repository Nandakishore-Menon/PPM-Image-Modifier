#ifndef pixel_h
#define pixel_h
#include <bits/stdc++.h> 
#include <fstream>

class Pixel
{                                                                  
    public:                                                                       
        int red;                    //stores red value                                                              
        int green;                  //stores green value                              
        int blue;                   //stores blue value    
        Pixel(int r, int g, int b); //Parameterized constructor                                                               
        Pixel();                    //default constructor
        Pixel(const Pixel &p);      //copy constructor

/*-----------setter functions for the colors in a pixel------------------------*/
        void setRed(int val);
        void setGreen(int val);
        void setBlue(int val);
        
/*----------friend functions to read and write from/into string/output stream respectively-----------------------------*/

        friend std::stringstream& operator>> (std::stringstream& fin, Pixel& p);
        friend std::ofstream& operator<< (std::ofstream& fout, Pixel& p); // while outputting,
        //it swaps values such that RGB becomes BRG
                                                 
};



#endif