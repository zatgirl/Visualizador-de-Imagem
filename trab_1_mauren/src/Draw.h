#ifndef __DRAW_H__
#define __DRAW_H__

#include "gl_canvas2d.h"

class Img{
    int altura, largura;
    int x, y;
    unsigned char* pixel;
    int imagem[200][200];
public:
    Img(){
    }

    Img(int _altura, int _largura, int _iniciox, int _inicioy, unsigned char* _pixel){
        altura = _altura;
        largura = _largura;
        x = 290;
        y = 20;
        pixel = _pixel;
    }

    //Plota a imagem na tela
    void View(){
        int idx = 0; //Var para pegar os valores r,g,b a de cada pixel a cada 3 pos.
        for(int linha = 0; linha < largura; linha++){
            y = 290;
            for(int coluna = 0; coluna < altura; coluna++){
                CV::color((float)(pixel[idx])/255.0, (float)(pixel[idx+1])/255.0, (float)(pixel[idx+2])/255.0);
                idx += 3;
                CV::rectFill(coluna+y, linha+x, coluna+y+2, linha+x+2);
                y ++;
               // imagem[linha][coluna] =
            }  x ++;
        } x = 20;
    }

    //Plota o canal red da imagem na tela
    void ViewRed(){
        int idx = 0; //Var para pegar os valores r,g,b a de cada pixel a cada 3 pos.
        for(int linha = 0; linha < largura; linha++){
            y = 290;
            for(int coluna = 0; coluna < altura; coluna++){
                CV::color((float)(pixel[idx])/255.0, 0, 0);
                idx += 3;
                CV::rectFill(coluna+y, linha+x, coluna+y+2, linha+x+2);
                y ++;
            }  x ++;
        } x = 20;
    }

    //Plota o canal green da imagem na tela
    void ViewGreen(){
        int idx = 1; //Var para pegar os valores r,g,b a de cada pixel a cada 3 pos.
        for(int linha = 0; linha < largura; linha++){
            y = 290;
            for(int coluna = 0; coluna < altura; coluna++){
                CV::color(0, (float)(pixel[idx])/255.0, 0);
                idx += 3;
                CV::rectFill(coluna+y, linha+x, coluna+y+2, linha+x+2);
                y ++;
            }  x ++;
        } x = 20;
    }
    //Plota o canal blue da imagem na tela
    void ViewBlue(){
        int idx = 2; //Var para pegar os valores r,g,b a de cada pixel a cada 3 pos.
        for(int linha = 0; linha < largura; linha++){
            y = 290;
            for(int coluna = 0; coluna < altura; coluna++){
                CV::color(0, 0, (float)(pixel[idx])/255.0);
                idx += 3;
                CV::rectFill(coluna+y, linha+x, coluna+y+2, linha+x+2);
                y ++;
            }  x ++;
        } x = 20;
    }
    //Plota o canal gray da imagem na tela
    void ViewGray(){
        int idx = 0; //Var para pegar os valores r,g,b a de cada pixel a cada 3 pos.
        float ConvGray;
        for(int linha = 0; linha < largura; linha++){
            y = 290;
            for(int coluna = 0; coluna < altura; coluna++){
                ConvGray =(0.3*((float)(pixel[idx])/255.0)) + (0.59*((float)(pixel[idx+1])/255.0))+ (0.11*((float)(pixel[idx+2])/255.));
                CV::color(ConvGray, ConvGray, ConvGray);
                idx += 3;
                CV::rectFill(coluna+y, linha+x, coluna+y+2, linha+x+2);
                y ++;
            }  x ++;
        } x = 20;
    }

    void ViewRot(){
        int idx = 0; //Var para pegar os valores r,g,b a de cada pixel a cada 3 pos.
        for(int linha = 0; linha < largura; linha++){
            y = 290;
            for(int coluna = 0; coluna < altura; coluna++){
                CV::color((float)(pixel[idx])/255.0, (float)(pixel[idx+1])/255.0, (float)(pixel[idx+2])/255.0);
                idx += 3;
                CV::rectFill(coluna+y, linha+x, coluna+y+2, linha+x+2);
                y ++;
            }  x ++;
        } x = 20;
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
