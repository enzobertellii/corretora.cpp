#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
struct dadosPontos
{
    int valor;
    char mes[13];
    int porcentagem;
};

void botao(int x1, int y1, int x2, int y2, char rotulo[], int estado, int corbotao, int cortexto)
{
    setcolor(corbotao);
    rectangle(x1, y1, x2, y2);

    setfillstyle(SOLID_FILL, corbotao);
    floodfill((x1 + x2) / 2, (y1 + y2) / 2, corbotao);

    setcolor(cortexto);
    setbkcolor(corbotao);

    int text_width = textwidth(rotulo);
    int text_height = textheight(rotulo);
    int text_x = (x1 + x2) / 2 - text_width / 2;
    int text_y = (y1 + y2) / 2 - text_height / 2;
    outtextxy(text_x, text_y, rotulo);
}

void escrevertexto(int x, int y, char texto[], int tamanho)
{
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, tamanho); // Alterando a fonte para SANS_SERIF_FONT
    setcolor(WHITE); // Definindo a cor do texto para branco
    setbkcolor(BLACK);
    int text_width = textwidth(texto);
    outtextxy(x - text_width / 2, y, texto);
}

void telainicial()
{
    initwindow(800, 600, "CORRETORA EPV", 300, 100);
    readimagefile("abc4.jpg", 0, 0, 800, 600);

    escrevertexto(400, 50, "CORRETORA EPV", 3);
   
    botao(280, 360, 360, 400, "Ação", 0, BLUE, WHITE);
    botao(370, 360, 450, 400, "FII", 0, GREEN, WHITE);
    botao(460, 360, 540, 400, "Cripto", 0, RED, WHITE);
}

void botaografico (int x1, int y1, int x2, int y2, char rotulo[], int estado, int corbotao, int cortexto, int tamanho)
{

    setcolor(corbotao);
    rectangle(x1, y1, x2, y2);

    setfillstyle(SOLID_FILL, corbotao);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, tamanho);
    floodfill((x1 + x2) / 2, (y1 + y2) / 2, corbotao);

    setcolor(cortexto);
    setbkcolor(corbotao);

   
    int text_width = textwidth(rotulo);
    int text_height = textheight(rotulo);
    int text_x = (x1 + x2) / 2 - text_width / 2;
    int text_y = (y1 + y2) / 2 - text_height / 2;
    outtextxy(text_x, text_y, rotulo);
}

void limparArea(int x, int y, int largura, int altura) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + largura, y + altura);
}

void mostrarInfoPonto(int x, int y, struct dadosPontos ponto) {
    
    limparArea(600, 700, 489, 40); 

   
    char info[100];
    sprintf(info, "Mês:%s ,Preço:%d ,Variação:%d", ponto.mes, ponto.valor, ponto.porcentagem);
    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(x, y, info);
}
[18:55, 02/07/2024] Pedro: void desenhargrafico()
{
    struct dadosPontos vetor[12];
    int meses[12];
    int comecox=200;
    int fimx=1430;
    int i;
    int j;
    int soma=comecox;
    meses[0]= comecox;
    int comecoy =150;
    int fimy = 580;
    int valores[12];
    int y;
    int soma2;
    char nomemeses[13][4]= {"JAN","FEV","MAR","ABR","MAI","JUN","JUL","AUG","SET","OUT","NOV","DEC"};
    char preco[11][4] = {"0","10","20","30","40","50","60","70","80","90","100"};
    int faixa[11];
    char Nmeses[12][13]= {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};

    bar(100,150,1430,580);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, 6);
    rectangle(97,147,1433,583);


    for(i=1; i<12; i++)
    {
        meses[i]=soma+((fimx-comecox)/12);
        soma= soma+(fimx-comecox)/12;

    }

    for(i=0; i<12; i++)
    {
        escrevertexto(meses[i], fimy +10, nomemeses[i], 1);
    }

    faixa[0]=575;
    soma2=575;
    escrevertexto(77, faixa[0], preco[0], 1);
    for(i=1; i<11; i++)
    {
        faixa[i]=soma2-((575-145)/10);
        soma2= soma2-(575-145)/10;
        escrevertexto(77, faixa[i], preco[i], 1);

    }

    escrevertexto(77, 110,"R$", 2);

   
    setlinestyle(SOLID_LINE, 0, 2);
    for(i=0; i<12; i++)
    {
       
    }
    setcolor(RED);
    srand(time(NULL));
    for(i=0; i<12; i++)
    {
        y=rand()%(fimy-comecoy) + comecoy;
        int thickness = 3;
        for (int t = 0; t < thickness; t++)
        {
            circle(meses[i], y, 3 + t);
        }
        valores[i] = y;
    }
    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 2);
    for(i=0; i<11; i++)
    {
        line(meses[i],valores[i],meses[i+1],valores[i+1]);
    }



    botaografico(1300,700,1430,800,"VOLTAR",0, RED,WHITE, 3 );
    botaografico(1090,700,1250,800,"RECOMENDAR",0, BLUE,WHITE, 3 );

    for(i=0; i<12; i++)
    {
        vetor[i].valor=valores[i]/4.3;
        strcpy(vetor[i].mes, Nmeses[i]);

    }
    vetor[0].porcentagem=0;
    for(j=1; j<12; j++)
    {
        vetor[j].porcentagem=valores[j]-valores[j-1];
    }


    while (!kbhit())
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (mousex() >= 1300 && mousex() <= 1430 && mousey() >= 700 && mousey() <= 800)
            {
                closegraph();
                telainicial();
                break; 
            }
            if (mousex() >= 1090 && mousex() <= 1250 && mousey() >= 700 && mousey() <= 800)
            {
                
                setcolor(WHITE);
                settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); // Tamanho menor para a recomendação
                if(valores[0]>valores[11])
                {
                    escrevertexto(300, 670,"O gráfico está em uma crescente, portanto", 2);
                    escrevertexto(305, 700,"nossa corretora recomenda comprar tal ativo.", 2);
                }
                if(valores[0]<valores[11])
                {
                    escrevertexto(300, 670,"O gráfico está em uma decrescente, portanto", 2);
                    escrevertexto(305, 700,"nossa corretora recomenda vender tal ativo.", 2);
                }
                if(valores[0]==valores[11])
                {
                    escrevertexto(300, 670,"O gráfico está lateralizado, portanto nossa", 2);
                    escrevertexto(305, 700,"corretora não recomenda operar em tal ativo.", 2);
                }

                clearmouseclick(WM_LBUTTONDOWN);
            }
            
           for (i = 0; i < 12; i++) {
    int raio = 6; // Raio do ponto vermelho
    if (mousex() >= meses[i] - raio && mousex() <= meses[i] + raio &&
        mousey() >= valores[i] - raio && mousey() <= valores[i] + raio) {
        mostrarInfoPonto(600, 700, vetor[i]);
        clearmouseclick(WM_LBUTTONDOWN);
        break; 
    }
}

        }
    }
}



void cliquemouse(int a)
{
   
    closegraph();
    initwindow(getmaxwidth(),getmaxheight(), "grafico", 0, 0);
    
    if(a==1)
    {
        escrevertexto(750,90, "BANCO BRADESCO (BBDC4)",6);
    }
    if(a==2)
    {
        escrevertexto(750,90, "CAPITANIA SECURITIES II (CPTS11)",6);
    }
    if(a==3)
    {
        escrevertexto(750,90, "BITCOIN (BTC)",6);
    }
    desenhargrafico();
}


main()
{
    telainicial();
    while (!kbhit())
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (mousex() >= 280 && mousex() <= 360 &&
                    mousey() >= 360 && mousey() <= 400)
            {
                botao(280, 360, 360, 400, "Ação", 1, BLUE, WHITE);

                cliquemouse(1);
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if (mousex() >= 370 && mousex() <= 450 &&
                    mousey() >= 360 && mousey() <= 400)
            {
                botao(370, 360, 450, 400, "Fii", 1, GREEN, WHITE);

                cliquemouse(2);
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if (mousex() >= 460 && mousex() <= 540 &&
                    mousey() >= 360 && mousey() <= 400)
            {
                botao(460, 360, 540, 400, "Cripto",1, RED, WHITE);
                cliquemouse(3);
                clearmouseclick(WM_LBUTTONDOWN);
            }
        }
    }
    closegraph();
}
