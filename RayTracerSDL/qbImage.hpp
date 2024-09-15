#ifndef QBIMAGE_H
#define QBIMAGE_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>


class qbImage
{
  public:
    // The constructor
    qbImage();
    // The distrcutor
    ~qbImage();
  
    //Function to Initialize SDL2 entities
    void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);

    //Function to set the color of a pixel
  
    void SetPixel(const int x, const int y, const double red, const double green, const double blue);
    //Function to return the qbImage
    void Display();
  private:
    Uint32 ConvertColor(const double red, const double green, const double blue);
    void InitTexture();
    // Rays 
    std::vector<std::vector<double>> m_rChannel;
    std::vector<std::vector<double>> m_gChannel;
    std::vector<std::vector<double>> m_bChannel;
    // Image attributes
    int m_xSize, m_ySize; //image dims
    //SDL2 stuff
    SDL_Renderer *m_pRenderer;
    SDL_Texture  *m_pTexture;

};
#endif // !QBIMAGE_H
