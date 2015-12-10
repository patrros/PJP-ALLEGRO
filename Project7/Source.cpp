#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_audio.h>
#include<allegro5\allegro_color.h>
#include<allegro5\allegro_ttf.h>
#include<allegro5\allegro_image.h>
#include<allegro5\timer.h>
#include<iostream>

using namespace std;

int dlugosc = 1200, szerokosc = 600;


int main() {
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *logo=NULL;
	/*const float FPS = 60.0;
	const float frameFPS = 15.0;*/
	if (!al_init()) return-1;
	display = al_create_display(dlugosc, szerokosc);
	if (!display) return-1;
	al_set_window_position(display, 200, 200);

	bool done = false, active = false;
	bool draw = true;
	//int x = 0, y = 0, movespeed = 5;
	al_init_primitives_addon();
	al_install_keyboard;
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font1 = al_load_font("Minecrafter_3.ttf", 15, 0);
	ALLEGRO_FONT *mcfont = al_load_font("Minecrafter_3.ttf", 30, 0);
	ALLEGRO_FONT *mcfont_1 = al_load_font("Minecrafter_3.ttf", 20, 0);
	while (!done){
		logo = al_load_bitmap("wezyk.png");

		al_draw_bitmap(logo, 200, 30, 0);

		al_draw_text(mcfont, al_map_rgb(100, 50, 250), 170, 100, 0, "Enter by zaczac gre");
		al_draw_text(mcfont, al_map_rgb(100, 50, 250), 205, 200, 0, "Esc by skonczyc gre");
		al_draw_text(mcfont, al_map_rgb(100, 50, 250), 300, 250, 0, "Instrukcje:");
		al_draw_text(mcfont_1, al_map_rgb(255, 255, 255), 300, 300, 0, "Sterowanie za pomoca strzalek,gora, dol, lewo, prawo.");
		al_draw_text(mcfont_1, al_map_rgb(255, 255, 255), 300, 330, 0, "Zakaz dotykania scian i ciala weza.");
		al_draw_textf(mcfont, al_map_rgb(250, 0, 250), 120, 370, 0, "Zloto : coin");
		al_draw_textf(mcfont, al_map_rgb(250, 0, 250), 470, 370, 0, "Czas : sec");
		al_flip_display();
		
	}
	al_clear_to_color(al_map_rgb(0, 0, 0 ));
al_destroy_display(display);
al_destroy_bitmap(logo);
		return 0;
	
	
}