#include <SDL.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PLAYER_SPEED 5
#define BULLET_SPEED 10
#define ENEMY_SPEED 2
#define MAX_BULLETS 50
#define MAX_ENEMIES 20

typedef struct {
    float x, y;
    float vx, vy;
    bool active;
} Bullet;

typedef struct {
    float x, y;
    float vx, vy;
    bool active;
} Enemy;

SDL_Rect create_rect(float x, float y, int w, int h) {
    SDL_Rect r = { (int)x, (int)y, w, h };
    return r;
}

void spawn_enemy(Enemy enemies[]) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (!enemies[i].active) {
            int side = rand() % 4;
            float x, y;
            switch (side) {
                case 0: x = rand() % SCREEN_WIDTH; y = -20; break; // top
                case 1: x = SCREEN_WIDTH + 20; y = rand() % SCREEN_HEIGHT; break; // right
                case 2: x = rand() % SCREEN_WIDTH; y = SCREEN_HEIGHT + 20; break; // bottom
                case 3: x = -20; y = rand() % SCREEN_HEIGHT; break; // left
            }
            enemies[i].x = x;
            enemies[i].y = y;
            float dx = SCREEN_WIDTH / 2 - x;
            float dy = SCREEN_HEIGHT / 2 - y;
            float mag = sqrt(dx * dx + dy * dy);
            enemies[i].vx = (dx / mag) * ENEMY_SPEED;
            enemies[i].vy = (dy / mag) * ENEMY_SPEED;
            enemies[i].active = true;
            break;
        }
    }
}

int SDL_main(int argc, char* argv[]) {
    srand((unsigned int)time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("NEON BLASTER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    float playerX = SCREEN_WIDTH / 2;
    float playerY = SCREEN_HEIGHT / 2;

    Bullet bullets[MAX_BULLETS] = { 0 };
    Enemy enemies[MAX_ENEMIES] = { 0 };

    int score = 0;
    bool running = true;
    SDL_Event e;

    Uint32 lastEnemySpawn = 0;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
        }

        const Uint8* keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_W]) playerY -= PLAYER_SPEED;
        if (keys[SDL_SCANCODE_S]) playerY += PLAYER_SPEED;
        if (keys[SDL_SCANCODE_A]) playerX -= PLAYER_SPEED;
        if (keys[SDL_SCANCODE_D]) playerX += PLAYER_SPEED;

        int shootX = 0, shootY = 0;
        if (keys[SDL_SCANCODE_UP]) shootY = -1;
        if (keys[SDL_SCANCODE_DOWN]) shootY = 1;
        if (keys[SDL_SCANCODE_LEFT]) shootX = -1;
        if (keys[SDL_SCANCODE_RIGHT]) shootX = 1;

        if ((shootX != 0 || shootY != 0)) {
            for (int i = 0; i < MAX_BULLETS; i++) {
                if (!bullets[i].active) {
                    float mag = sqrt(shootX * shootX + shootY * shootY);
                    bullets[i].x = playerX + 12;
                    bullets[i].y = playerY + 12;
                    bullets[i].vx = (shootX / mag) * BULLET_SPEED;
                    bullets[i].vy = (shootY / mag) * BULLET_SPEED;
                    bullets[i].active = true;
                    break;
                }
            }
        }

        for (int i = 0; i < MAX_BULLETS; i++) {
            if (bullets[i].active) {
                bullets[i].x += bullets[i].vx;
                bullets[i].y += bullets[i].vy;
                if (bullets[i].x < 0 || bullets[i].x > SCREEN_WIDTH || bullets[i].y < 0 || bullets[i].y > SCREEN_HEIGHT)
                    bullets[i].active = false;
            }
        }

        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].active) {
                enemies[i].x += enemies[i].vx;
                enemies[i].y += enemies[i].vy;
                if (sqrt(pow(playerX - enemies[i].x, 2) + pow(playerY - enemies[i].y, 2)) < 20) {
                    running = false;
                }
            }
        }

        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].active) continue;
            for (int j = 0; j < MAX_ENEMIES; j++) {
                if (!enemies[j].active) continue;
                if (fabs(bullets[i].x - enemies[j].x) < 20 && fabs(bullets[i].y - enemies[j].y) < 20) {
                    bullets[i].active = false;
                    enemies[j].active = false;
                    score++;
                    break;
                }
            }
        }

        Uint32 now = SDL_GetTicks();
        if (now - lastEnemySpawn > 800) {
            spawn_enemy(enemies);
            lastEnemySpawn = now;
        }

        SDL_SetRenderDrawColor(renderer, 10, 10, 30, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_Rect playerRect = create_rect(playerX, playerY, 24, 24);
        SDL_RenderFillRect(renderer, &playerRect);

        SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (bullets[i].active) {
                SDL_Rect b = create_rect(bullets[i].x, bullets[i].y, 6, 6);
                SDL_RenderFillRect(renderer, &b);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].active) {
                SDL_Rect en = create_rect(enemies[i].x, enemies[i].y, 20, 20);
                SDL_RenderFillRect(renderer, &en);
            }
        }

        char title[64];
        snprintf(title, sizeof(title), "NEON BLASTER | Score: %d", score);
        SDL_SetWindowTitle(window, title);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
