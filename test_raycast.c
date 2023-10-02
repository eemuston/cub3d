#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TILE_SIZE 64
#define VIEW_DISTANCE 5.0

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct {
    float x, y;        // Player's position
    float direction;   // Player's direction in radians
} Player;

Player player = {5.5, 5.5, 1.5708};  // Middle of the map, facing upwards

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
} MLX;

MLX g_mlx;

void draw_line(int x, int start, int end, int color) {
    for (int y = start; y < end; y++) {
        mlx_pixel_put(g_mlx.mlx_ptr, g_mlx.win_ptr, x, y, color);
    }
}

void raycast(Player player) {
    for(int x = 0; x < SCREEN_WIDTH; x++) {
        float rayDir = player.direction - (M_PI / 6.0f) + ((x / (float)SCREEN_WIDTH) * (M_PI / 3.0f));
        float stepX = cos(rayDir);
        float stepY = sin(rayDir);

        float rayX = player.x;
        float rayY = player.y;
        int hit = 0;

        while(!hit && rayX >= 0 && rayX < MAP_WIDTH && rayY >= 0 && rayY < MAP_HEIGHT) {
            rayX += stepX;
            rayY += stepY;

            if(map[(int)rayY][(int)rayX] == 1) {
                hit = 1;
                float distance = sqrt(pow(player.x - rayX, 2) + pow(player.y - rayY, 2));
                int lineHeight = (int)(SCREEN_HEIGHT / distance);

                draw_line(x, (SCREEN_HEIGHT - lineHeight) / 2, (SCREEN_HEIGHT + lineHeight) / 2, 0xFFA500);  // Drawing in white color
            }
        }
    }
}

int main() {
    g_mlx.mlx_ptr = mlx_init();
    g_mlx.win_ptr = mlx_new_window(g_mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Raycasting with MLX");

    raycast(player);

    mlx_loop(g_mlx.mlx_ptr);

    return 0;
}

