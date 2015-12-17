#include<allegro5\allegro_acodec.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
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
	//LEGRO_SAMPLE *MUZ = NULL;
	const float FPS = 60.0;
	const float frameFPS = 15.0;
	if (!al_init()) return -1;
	display = al_create_display(dlugosc, szerokosc);
	if (!display) return -1;
	al_set_window_position(display, 400, 400);
	if (!al_install_audio())
	{
		fprintf(stderr, "blad!\n");
		return -1;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "blad!\n");
		return -1;
	}
	if (!al_reserve_samples(1))
	{
		fprintf(stderr, "blad!\n");
		return -1;
	}
	bool done = false, active = false;
	bool draw = true;
	int x = 0, y = 0, moveSpeed = 5;
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();


	//Z = al_load_sample("coin1.wav");
	/*(!MUZ)
	{
	printf("Audio clip nie laduje sie\n");
	return -1;
	}*/
	ALLEGRO_BITMAP *glowa = al_load_bitmap("glowa.png");
	ALLEGRO_BITMAP *cialo = al_load_bitmap("cialo.png");
	ALLEGRO_FONT *font1 = al_load_font("Minecrafter_3.ttf", 15, 0);
	ALLEGRO_FONT *mcfont = al_load_font("Minecrafter_3.ttf", 30, 0);
	ALLEGRO_FONT *mcfont_1 = al_load_font("Minecrafter_3.ttf", 20, 0);
	ALLEGRO_BITMAP *coin1 = al_load_bitmap("coin.png");
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 10);
	ALLEGRO_TIMER *frameTimer = al_create_timer(1.0 / frameFPS);
	ALLEGRO_TIMER *VREME = al_create_timer(1);
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(frameTimer));
	al_register_event_source(event_queue, al_get_timer_event_source(VREME));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);
	al_start_timer(frameTimer);
	al_start_timer(VREME);
	srand(time(NULL));

	const int maxF = 8;
	int curF = 0;
	int frameC = 0;
	int frameD = 2;
	int frameW = 40;
	int frameH = 40;
	int timeS = 0;
	int timeF = 0;

	enum Direction { DOWN, LEFT, RIGHT, UP };

	int dir = DOWN;
	int score = 1;
	int lastX;
	int lastY;
	int coinX = 40 * (rand() % 20);
	int coinY = 40 * (rand() % 15);
	int snakeRevolution[50];
	for (int i = 0; i <= 50; i++){
		snakeRevolution[i] = 0;
	}
	int snakeRevolutionX[50], snakeRevolutionY[50];
	bool menu = true;
	bool dead = false;
	while (1)
	{
		lastX = x;
		lastY = y;

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_ENTER:
				if (menu) menu = false, score = 1, timeS = 0, x = 0, y = 0;
			}
		}


		if (event.type == ALLEGRO_EVENT_TIMER){
			if (event.timer.source == VREME) timeS++;
			if (event.timer.source == timer){
				al_get_keyboard_state(&keyState);


				if (x == coinX && y == coinY)
				{
					score++;
					coinX = 40 * (rand() % 20);
					coinY = 40 * (rand() % 15);
					snakeRevolution[score] = 5;
				}

				draw = true;
			}
		}
		if (++frameC >= frameD){
			if (++curF >= maxF)
				curF = 0;
			frameC = 0;
		}

		if (draw == true){
			draw = false;
			if (menu){
				x = 0, y = 0;
				for (int i = 0; i <= 50; i++){
					snakeRevolutionX[i] = 0;
				}
				al_draw_text(mcfont, al_map_rgb(100, 50, 250), 170, 100, 0, "Enter by zaczac gre");
				al_draw_text(mcfont, al_map_rgb(100, 50, 250), 205, 200, 0, "Esc by skonczyc gre");
				al_draw_text(mcfont, al_map_rgb(100, 50, 250), 300, 250, 0, "Instrukcje:");
				al_draw_text(mcfont_1, al_map_rgb(255, 255, 255), 300, 300, 0, "Sterowanie za pomoca strzalek,gora, dol, lewo, prawo.");
				al_draw_text(mcfont_1, al_map_rgb(255, 255, 255), 300, 330, 0, "Zakaz dotykania scian i ciala weza.");
				al_draw_text(mcfont_1, al_map_rgb(255, 255, 255), 300, 360, 0, "Zbierz jak najwiecej zlota.");

				al_draw_textf(mcfont, al_map_rgb(250, 0, 250), 120, 385, 0, "Zloto:");
				al_draw_textf(mcfont, al_map_rgb(250, 0, 250), 470, 385, 0, "Czas: sec");
			}
			else{
				al_draw_bitmap_region(coin1, curF * frameW, 0, frameW, frameH, coinX, coinY, 0);

			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;

}
