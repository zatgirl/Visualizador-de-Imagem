#ifndef __DRAW_H__
#define __DRAW_H__

#include "gl_canvas2d.h"
#include "Histograma.h"


class Img{
    int altura, largura, scale = 1;
    int x, y, outroX, outroY;
    unsigned char* pixel;
    int imagem[200][200];
    float grayScale;
    bool red = false, green = false, blue = false, gray = false, rgb = false;
    //Histograma *histograma;

public:
    Img(){
    }

    Img(int _altura, int _largura, int _iniciox, int _inicioy, unsigned char* _pixel){
        altura = _altura;
        largura = _largura;
        outroX = _iniciox;
        outroY = _inicioy;
        pixel = _pixel;
        //histograma = new Histograma(5,20,280,260,pixel);
    }

    int getStartX (int _StartX){
        return outroX = _StartX;
    }

    int getStartY (int _StartY){
        return outroY = _StartY;
    }

    void ViewImg(int _x, int _y, int _scale){
        int idx = 0;
            y = 20;
            for(int linha = 0; linha < largura; linha++){
                x = 290;
                for(int coluna = 0; coluna < altura; coluna++){
                    if(rgb == true){
                        CV::color((float)(pixel[idx])/255.0, (float)(pixel[idx+1])/255.0, (float)(pixel[idx+2])/255.0);
                    }
                    if(red == true){
                        CV::color((float)(pixel[idx])/255.0, 0, 0);
                    }
                    if(green == true){
                        CV::color(0, (float)(pixel[idx+1])/255.0, 0);
                    }
                    if(blue == true){
                        CV::color(0, 0, (float)(pixel[idx+2])/255.0);
                    }
                    if(gray == true){
                        grayScale = (0.3*((float)(pixel[idx])/255.0)) + (0.59*((float)(pixel[idx+1])/255.0))+ (0.11*((float)(pixel[idx+2])/255.));
                        CV::color(grayScale, grayScale, grayScale);
                    }
                    CV::rectFill(coluna+x, linha+y, coluna+x+2, linha+y+2);
                    idx +=3; x +=scale;
                }   y += scale;
            }   idx = 0;
    }

    void RedChoice(bool _red){
        red = true;
        green = false;
        blue = false;
        gray = false;
        rgb = false;
        //histograma->ViewHistograma(true,false,false,false,false);
    }

    void GreenChoice(bool _green){
        red = false;
        green = true;
        blue = false;
        gray = false;
        rgb = false;
        //histograma->ViewHistograma(false,true,false,false,false);
    }

    void BlueChoice(bool _blue){
        red = false;
        green = false;
        blue = true;
        gray = false;
        rgb = false;
        //histograma->ViewHistograma(false,false,true,false,false);
    }

    void GrayChoice(bool _gray){
        red = false;
        green = false;
        blue = false;
        gray = true;
        rgb = false;
        //histograma->ViewHistograma(false,false,false,true,false);
    }

    void RGBChoice(bool _rgb){
        red = false;
        green = false;
        blue = false;
        gray = false;
        rgb = true;
        //histograma->ViewHistograma(false,false,false,false,true);
    }

    bool ColidiuImg(int mx, int my)
    {
        if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) )
        {
            return true;
        }
            return false;
    }
};
#endif
