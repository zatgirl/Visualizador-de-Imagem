/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Versao 2.0
//
//  Instru��es:
//	  Para alterar a animacao, digite numeros entre 1 e 3
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

#include "Interface.h"
#include "Botao.h"
#include "Bmp.h"
#include "Draw.h"
#include "Histograma.h"
#include "Vector2.h"

//#define DEFAULT_START_IMG_X 290
//#define DEFAULT_START_IMG_Y 20

Botao *orig = NULL; Botao *cr = NULL; Botao *cg = NULL; Botao *cb = NULL; Botao *gray = NULL; Botao *hist = NULL; Botao *rot = NULL; Botao *roll = NULL;
Histograma *histograma[3];
Bmp *bmp[3];
Img img[3];

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 800, screenHeight = 500; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY; //variaveis globais do mouse para poder exibir dentro da render().
bool click=false;
int op = 0, select = 5, clicou = 0;
int DEFAULT_START_IMG_X = 290, DEFAULT_START_IMG_Y = 20, SCALE = 1;
bool ROT = 0;

void moveImg();

void render()
{
    /*if(click == true){
        clicou = 1;
    }
    if ((img[op].ColidiuImg(mouseX,mouseY == true))&&(clicou == 1)){
            DEFAULT_START_IMG_Y = mouseY-200, DEFAULT_START_IMG_Y = mouseY-200;
            if(click == false){
                clicou = 0;
            }
    }*/
    //img[0].View(DEFAULT_START_IMG_X,DEFAULT_START_IMG_Y);
    interface();

    //moveImg();
}

void moveImg(){
    if ((click == 1)&&(img[op].ColidiuImg(mouseX,mouseY==true))){
        DEFAULT_START_IMG_Y = mouseY-200, DEFAULT_START_IMG_Y = mouseY-200;
    }
}

void interface(){
    //Painel de fundo
    CV::color(0,0,0);
    CV::rectFill(0,0,screenWidth,screenHeight);
    //Cria��o dos bot�es
    cr = new Botao(1*(screenWidth/6)-100,7*(screenHeight/8),120,45,"RED",1,0,0);
    cr->Draw();
    cg = new Botao(2*(screenWidth/6)-100,7*(screenHeight/8),120,45,"GREEN",0,1,0);
    cg->Draw();
    cb = new Botao(3*(screenWidth/6)-100,7*(screenHeight/8),120,45,"BLUE",0,0,1);
    cb->Draw();
    gray = new Botao(4*(screenWidth/6)-100,7*(screenHeight/8),120,45,"GRAY",0.5,0.5,0.5);
    gray->Draw();
    roll = new Botao(5*(screenWidth/6)-100,7*(screenHeight/8),120,45,"TROCAR",1,0,1);
    roll->Draw();
    rot = new Botao(1*(screenWidth/6)-100,6*(screenHeight/8),120,45,"GIRAR",1,0.5,0);
    rot->Draw();
    orig = new Botao(1*(screenWidth/6)-100,5*(screenHeight/8),120,45,"ORIGINAL",0.5,0.5,0);
    orig->Draw();
    //Testa se algum bot�o foi acionado
    Botao *botoes[] = {cr,cg,cb,gray,orig,rot};
    if(click == true){
        for(int i = 0; i<6; i++){
            if(botoes[i]->Colidiu(mouseX, mouseY)){
                select = i+1;
            }
        }
        if(roll->Colidiu(mouseX, mouseY)==true){
            if (op != 3){
                op ++; click = false;
            }
            if (op == 3){
                op = 0; click = false;
            }
        }click = false;
    }
    /*if ((click == true)&&(img[op].ColidiuImg(mouseX,mouseY==true))){
        DEFAULT_START_IMG_Y = mouseY-200, DEFAULT_START_IMG_Y = mouseY-200;
        printf("foi");
    }*/
    //Desenha a banda selecionada e o histograma
    histograma[op] = new Histograma(5,20,280,260,bmp[op]->getImage());
    switch(select){
        case 1: img[op].RedChoice(true);    histograma[op]->RedChoice(true);     break;
        case 2: img[op].GreenChoice(true);  histograma[op]->GreenChoice(true);   break;
        case 3: img[op].BlueChoice(true);   histograma[op]->BlueChoice(true);    break;
        case 4: img[op].GrayChoice(true);   histograma[op]->GrayChoice(true);    break;
        case 5: img[op].RGBChoice(true);    histograma[op]->RGBChoice(true);     break;
        //case 6: img[op].ViewRot();                                             break;
    }
    img[op].ViewImg(DEFAULT_START_IMG_X, DEFAULT_START_IMG_Y, SCALE, ROT);
    histograma[op]->ViewHistograma();

}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d" , key);
   if( key == 95 )
   {
      click == true;
   }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;

   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

   if( state == 0 ) //clicou
   {
       click = true;
        //do{
            //if ((img[op].ColidiuImg(mouseX,mouseY == true))&&(state = -2)){
            //    DEFAULT_START_IMG_Y = mouseY-200, DEFAULT_START_IMG_Y = mouseY-200;
           // }
        //}while (state == 1);

   }
   if ((img[op].ColidiuImg(mouseX,mouseY == true))&&(state = -2)){
                DEFAULT_START_IMG_Y = mouseY-200, DEFAULT_START_IMG_Y = mouseY-200;
   }
}

int main(void)
{
   //Carregamento das Imagens
   unsigned char *data[3];

   bmp[0] = new Bmp(".\\trab_1_mauren\\resources\\Ex1.bmp");
   bmp[1] = new Bmp(".\\trab_1_mauren\\resources\\Ex2.bmp");
   bmp[2] = new Bmp(".\\trab_1_mauren\\resources\\Ex3.bmp");
   for(int i = 0; i < 3; i++){
        bmp[i]->convertBGRtoRGB();
        data[i] = bmp[i]->getImage();
        img[i] = Img(bmp[i]->getHeight(), bmp[i]->getWidth(), DEFAULT_START_IMG_X, DEFAULT_START_IMG_Y, data[i]);
   }

   CV::init(&screenWidth, &screenHeight, "Visualizador de Imagem");
   CV::run();
   return 0;
}
