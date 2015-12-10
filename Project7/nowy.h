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

int dlugosc = 800, szerokosc = 600;

int main() {
	ALLEGRO_DISPLAY *display;
	const float FPS = 60.0;
	const float frameFPS = 15.0;
	if (!al_init()) return-1;
	display = al_create_display(dlugosc, szerokosc);
	if (!display) return-1;
	al_set_window_position(display, 200, 200);

	bool done = false, active = false;
	bool draw = true;
	int x = 0, y = 0, movespeed = 5;
	al_init_primitives_addon();
	al_install_keyboard;
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font1 = al_load_font("Minecrafter_3.ttf", 15, 0);
	ALLEGRO_FONT *mcfont = al_load_font("Minecrafter_3.ttf", 30, 0);

	al_draw_text(mcfont, al_map_rgb(100, 50, 250), 170, 100, 0, "Enter by zaczac gre");
	al_draw_text(mcfont, al_map_rgb(100, 50, 250), 205, 200, 0, "Esc by skonczyc gre");
	al_draw_textf(mcfont, al_map_rgb(250, 0, 250), 120, 350, 0, "Zloto: %i");
	al_draw_textf(mcfont, al_map_rgb(250, 0, 250), 470, 350, 0, "Czas: %i sec");



	al_destroy_display(display);
	return 0;
}







}