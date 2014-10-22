#include "pacman.h"

Pacman::Pacman()
{
	x = 8;
	y = 8;
	direction = 0;
	load_sprites();
	timer.start();
}


void Pacman::render()
{
	if (direction == 0)
	render_sprite(x - 4, y - 4, &sprite_clips[timer.ticks() / 75 % 4]);
	else
	if (direction == 1)
	render_sprite(x - 4, y - 4, &sprite_clips[(timer.ticks() / 75 % 4) + 4]);
	else
	if (direction == 2)
	render_sprite(x - 4, y - 4, &sprite_clips[(timer.ticks() / 75 % 4) + 8]);
	else
	if (direction == 3)
	render_sprite(x - 4, y - 4, &sprite_clips[(timer.ticks() / 75 % 4) + 12]);

}
void Pacman::set_coords(int x_axis, int y_axis, int direction_num)
{
	x = x_axis;
	y = y_axis;
	direction = direction_num;
}


void Pacman::load_sprites()
{
	int y = 0;
	sprite_sheet = load_image(ren, "res\\img\\pacman.bmp", 255, 0, 255);

	for (int i = 0; i < 3; i++)
	{
		sprite_clips[i].x = i * 16;
		sprite_clips[i].y = y;
		sprite_clips[i].w = 16;
		sprite_clips[i].h = 16;
	}
	sprite_clips[3] = sprite_clips[1];
	y += 16;
	for (int i = 4; i < 7; i++)
	{
		sprite_clips[i].x = (i-4) * 16;
		sprite_clips[i].y = y;
		sprite_clips[i].w = 16;
		sprite_clips[i].h = 16;
	}
	sprite_clips[7] = sprite_clips[5];
	y += 16;
	for (int i = 8; i < 11; i++)
	{
		sprite_clips[i].x = (i - 8) * 16;
		sprite_clips[i].y = y;
		sprite_clips[i].w = 16;
		sprite_clips[i].h = 16;
	}
	sprite_clips[11] = sprite_clips[9];
	y += 16;
	for (int i = 12; i < 15; i++)
	{
		sprite_clips[i].x = (i - 12) * 16;
		sprite_clips[i].y = y;
		sprite_clips[i].w = 16;
		sprite_clips[i].h = 16;
	}
	sprite_clips[15] = sprite_clips[13];

}
void Pacman::render_sprite(int x, int y, SDL_Rect* clip)
{
	SDL_Rect tile_rect = { x, y, 16, 16 };
	SDL_RenderCopy(ren, sprite_sheet, clip, &tile_rect);
}


Pacman::~Pacman()
{
	SDL_DestroyTexture(sprite_sheet);
	timer.stop();
}