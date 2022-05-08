#ifndef __HISTOGRAMA_H__
#define __HISTOGRAMA_H__

#include "gl_canvas2d.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

class Histograma{
    int x, y, altura, largura, valMax;
    unsigned char* data;
    int r[255], g[255], b[255];

public:
    Histograma(int _x, int _y, float _larg, float _alt, unsigned char*_data)
    {
     altura  = _alt;    x = _x+10;
     largura = _larg;   y = _y;
     data = _data;
    }

    void HistogramaRGB(){
        int idx = 0, temp;
        temp = x;
        for(int linha = 0; linha < largura; linha++){
            for(int coluna = 0; coluna < altura; coluna++){
                if (idx < 256){
                    r[idx]   = (int)data[idx];
                }
                if (idx+1 < 255){
                    g[idx+1] = (int)data[idx+1];
                }
                if (idx+2 < 255){
                    b[idx+2] = (int)data[idx+2];
                }
                idx += 3;
            } x ++;
        } x = temp;
    }

    void ViewHistogramaRGB(){
        int temp;
        temp = x;
        CV::color(1,1,1);
        CV::rectFill(x,y,largura,altura);
        for(int i = 0; i < 256; i++){
            CV::color(1,0,0);
            CV::line(x,y,x,y+r[i]);
            CV::color(0,1,0);
            CV::line(x,y,x,y+g[i]);
            CV::color(0,0,1);
            CV::line(x,y,x,y+b[i]);
            x ++;
        }x = temp;
    }

    void ViewHistogramaR(){
        int temp;
        temp = x;
        CV::color(1,1,1);
        CV::rectFill(x,y,largura,altura);
        for(int i = 0; i < 256; i++){
            CV::color(1,0,0);
            CV::line(x,y,x,y+r[i]);
            x ++;
        }x = temp;
    }

    void ViewHistogramaG(){
        int temp;
        temp = x;
        CV::color(1,1,1);
        CV::rectFill(x,y,largura,altura);
        for(int i = 0; i < 256; i++){
            CV::color(0,1,0);
            CV::line(x,y,x,y+g[i]);
            x ++;
        }x = temp;
    }

    void ViewHistogramaB(){
        int temp;
        temp = x;
        CV::color(1,1,1);
        CV::rectFill(x,y,largura,altura);
        for(int i = 0; i < 256; i++){
            if (valMax < b[i]) {
                valMax = b[i];
            }
            CV::color(0,0,1);
            CV::line(x,y,x,y+b[i]);
            x ++;
        }x = temp;
    }

    void ViewHistogramaGray(){
        int xini, convgray[254];
        xini = x;
        CV::color(1,1,1);
        CV::rectFill(x,y,largura,altura);
        for(int i = 0; i < 256; i++){
            convgray[i] = (0.3*r[i] + 0.59*g[i] + 0.11*b[i])/3;
            if (valMaxY < convgray[i]){
                valMaxY = convgray[i];
            }
            CV::color(0.5,0.5,0.5);
            CV::line(x,y,x,y+convgray[i]);
            x ++;
        }x = xini;
    }

};

#endif
