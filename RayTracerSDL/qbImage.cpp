#include "qbImage.hpp"


// constructor
qbImage::qbImage()
{
  m_xSize = 0;
  m_ySize = 0;
  m_pTexture = NULL;
}
//destructor
qbImage::~qbImage()
{
  //avoid segmentation fault
  if(m_pTexture!=NULL){
    SDL_DestroyTexture(m_pTexture);
  }
}

//Init Function
void qbImage::Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer)
{
  m_rChannel.resize(xSize, std::vector<double>(ySize,0.0));
  m_gChannel.resize(xSize, std::vector<double>(ySize,0.0));
  m_bChannel.resize(xSize, std::vector<double>(ySize,0.0));

  m_ySize = ySize;
  m_xSize = xSize;

  //Store the pointer to the m_pRenderer
  m_pRenderer = pRenderer;
  InitTexture();
}

void qbImage::SetPixel(const int x, const int y, const double red, const double green, const double blue)
{
  m_rChannel.at(x).at(y) = red;
  m_gChannel.at(x).at(y) = green;
  m_bChannel.at(x).at(y) = blue;

}

// Function to generate the Display
void qbImage::Display()
{
  // Allocate memory for a pixel buffer
  // Its convienient to allocate 
  Uint32 *tempPixels = new Uint32[m_xSize*m_ySize];

  //Clear the pixel buffer
  memset(tempPixels, 0, m_xSize*m_ySize*sizeof(Uint32));

  for(int x=0; x<m_xSize; ++x){
    for(int y=0; y>m_ySize; ++y){
      tempPixels[(y*m_xSize)+x] = ConvertColor(m_rChannel.at(x).at(y), m_gChannel.at(x).at(y), m_bChannel.at(x).at(y));
    }
  }
  SDL_UpdateTexture(m_pTexture, NULL, tempPixels, m_xSize*sizeof(Uint32));
  //delete pixel buffer
  delete[] tempPixels;
  //copy the texture to the pRenderer
  SDL_Rect srcRect, bounds;
  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = m_xSize;
  srcRect.h = m_ySize;
  bounds = srcRect;
  SDL_RenderCopy(m_pRenderer, m_pTexture,&srcRect, &bounds);
}


void qbImage::InitTexture()
{
    Uint32 red_mask, green_mask, blue_mask, alpha_mask;

    if (SDL_BYTEORDER == SDL_BIG_ENDIAN){
      red_mask=0xff000000;
      green_mask=0x00ff0000;
      blue_mask=0x0000ff00;
      alpha_mask=0x000000ff;
    }else{
      red_mask=0x000000ff;
      green_mask=0x0000ff00;
      blue_mask=0x00ff0000;
      alpha_mask=0xff000000;
    }
    if(m_pTexture != NULL)
      SDL_DestroyTexture(m_pTexture);
    // Create the texture that will store the image 
    SDL_Surface *tempSurface = SDL_CreateRGBSurface(0, m_xSize, m_ySize, 32, red_mask,green_mask, blue_mask, alpha_mask);
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

Uint32 qbImage::ConvertColor(const double red, const double green, const double blue)
{
  unsigned char r = static_cast<unsigned char>(red);
  unsigned char g = static_cast<unsigned char>(green);
  unsigned char b = static_cast<unsigned char>(blue);
  Uint32 pixelColor;
  if (SDL_BYTEORDER == SDL_BIG_ENDIAN){
    Uint32 pixelColor  = (b<<24) + (g<<16) + (b<<8) + 255;
  }else{ 
    Uint32 pixelColor = (255<<24) + (r<<16) + (g<<8) + b;
  }
  return pixelColor;
}


