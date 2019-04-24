#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define HEIGHT 700
#define WIDTH 900
#define TITLE "BREAKDOWN"
//Structure "JEU"
typedef struct game{


     SDL_Window *window;
     SDL_Renderer *renderer;
     SDL_Texture *texture;
     SDL_Surface *surface;
     int nDialog;


}game;
void ShowText(TTF_Font*,char*,game*,int,int,SDL_Color,int);
int init(char*,int, int,game*, TTF_Font*);
void mainloop(const Uint8*,game*,TTF_Font*,SDL_Color);
void destroyTexture(game*);
void destroyFont(TTF_Font*);
void showimage(game*,char*);
void updatedialog(game*,TTF_Font*,SDL_Color,int*);

#endif // HEADER_H_INCLUDED
