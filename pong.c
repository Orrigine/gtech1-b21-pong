#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>








// Dimensions fenêtre = dims "renderer" = dims du "playground":
  #define WINDOW_WIDTH  640
  #define WINDOW_HEIGHT 480

// Extrémités du playground:
  #define PLAYGROUND_LIM_XMIN 0
  #define PLAYGROUND_LIM_XMAX WINDOW_WIDTH - BALL_WIDTH - 1
  #define PLAYGROUND_LIM_BOTTOM 0
  #define PLAYGROUND_LIM_TOP WINDOW_HEIGHT - BALL_HEIGHT - 1

// Paramètres du filet:
#define NET_DASH_Y_FIRST 80 // premier rectangle
#define NET_DASH_Y_LAST 560 // dernier rectangle
#define NET_DASH_WIDTH    4 // largeur rectangle
#define NET_DASH_HEIGTH   8 // hauteur rectangle
#define NET_DASH_PERIOD  16 // périodicité des rectangles

// Paramètres des raquettes:
#define RACKET_WIDTH    8  // largeur raquette
#define RACKET_HEIGHT  60  // hauteur raquette (le jeu originel utilise 30!)
#define RACKET_INIT_X_P1   120 // position initiale en x raquette joueur 1
#define RACKET_INIT_X_P2   WINDOW_WIDTH - RACKET_INIT_X_P1 - RACKET_WIDTH - 1 // pour la raquette du joueur 2
#define RACKET_INIT_Y      WINDOW_HEIGHT/2 - RACKET_HEIGHT/2 - 1 // position initiale en y des deux raquettes
#define RACKET_DY      12  // vitesse de déplacement (en y) des raquettes (en pixel/frame ou pixel/touche)

// Paramètres de la balle:
#define BALL_WIDTH      10 // largeur balle
#define BALL_HEIGHT     10 // hauteur balle
#define BALL_INIT_X WINDOW_WIDTH/2 - BALL_WIDTH/2 - 1   // position initiale en x balle
#define BALL_INIT_Y WINDOW_HEIGHT/2 - BALL_HEIGHT/2 - 1 // position initiale en y balle
#define BALL_INIT_VX   10 // Vitesse initiale en x (en pixel/frame)
#define BALL_INIT_VY    5 // Vitesse initiale en y (en pixel/frame)

// Paramètres d'affichage du score:
#define SCORE_WINNER   11 // Score qui fait qu'un joueur a gagné
#define SCORE_X_P1    217 // x0 pour l'affichage du premier digit du joueur 1
#define SCORE_X_P2    621 // x0 pour l'affichage du premier digit du joueur 2
#define SCORE_Y       112 // y0 pour l'affichage des digits des deux joueurs

// Couleurs:
#define SCORE_COLOR {255, 255, 255, 255} // Couleur des scores
#define BALL_COLOR {255, 255, 0, 255}    // Couleur de la balle
#define P1_COLOR {127, 127, 255, 255}    // Couleur de la raquette du joueur 1
#define P2_COLOR {127, 127, 255, 255}    // Couleur de la raquette du joueur 2


//Key press surfaces constants
enum KeyPressSurfaces
  {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL,
    KEY_PRESS_SURFACE_ECHAP,
  };

bool Initialisation(void);
void Update(void);
void Shutdown();

int main(int argc, char* args[]) {

  SDL_Window* fenetre;
  SDL_Renderer* renderer; //Déclaration du renderer

  if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
    {
      printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
      return EXIT_FAILURE;
    }

  // Création de la fenêtre :
  fenetre = SDL_CreateWindow("LET'S PONG !" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 600 , 600 , SDL_WINDOW_RESIZABLE);
  if(fenetre == NULL) // Gestion des erreurs
    {
      printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
      return EXIT_FAILURE;
    }

  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/); // Création du renderer
  //While application is running




  // GAME LOOP
  bool quit = false;
  //Event handler

  SDL_Event e;
  while( !quit ) {
    //Handle events on queue

    SDL_SetRenderDrawColor(renderer, 80, 147, 200, 255); // Color of the background
    SDL_RenderClear(renderer);






    //Color ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Color of the background

    //Init Ball values
    SDL_Rect ballRect = {
      WINDOW_WIDTH/2 - BALL_WIDTH/2,
      WINDOW_HEIGHT/2 - BALL_HEIGHT/2,
      BALL_HEIGHT,
      BALL_WIDTH,
    };

    SDL_RenderDrawRect(renderer, &ballRect);
    SDL_RenderFillRect(renderer, &ballRect);

    SDL_RenderPresent(renderer);

    while( SDL_PollEvent( &e ) != 0 )
      {
	//User requests quit






	if( e.type == SDL_QUIT )
	  {
	    quit = true;
	    // Destruction du renderer et de la fenêtre :
	    SDL_DestroyRenderer(renderer);
	    SDL_DestroyWindow(fenetre);
	    // On quitte la SDL
	    SDL_Quit();
	    break;
	  }
      }

  }
  //Init NET Values


  if(renderer == NULL)//gestion des erreurs
    {
      printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
      return EXIT_FAILURE;
    }
  // SDL_Delay(3000);//pause de 3 secondes
  //  SDL_Event event;
  // while (SDL_WaitEvent(&event)) {
  //     if(event.type == SDL_QUIT) {
  //         break;
  //     }
  // }

  // bool quit = false;
  // SDL_Event event;
  // while (!quit) {
  //     while (SDL_PollEvent(&event)) {
  //         if(event.type == SDL_QUIT) {
  //             quit = true;
  //         }
  //     }
  // }








}
