#include <stdio.h>
#include <math.h>

#define GRID_WIDTH 10  // Width of the grid
#define GRID_HEIGHT 10 // Height of the grid

char grid[GRID_WIDTH][GRID_HEIGHT] = {
    "1111111111",
    "1000000001",
    "1000000001",
    "1001111001",
    "1000000001",
    "1000000001",
    "1001111001",
    "1000000001",
    "1000000001",
    "1111111111"
};

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double x;
    double y;
    double angle;
} Ray;

void castRays(Point player, int numRays) {
    double fov = M_PI / 3.0; // Field of view (60 degrees)
    double rayAngleIncrement = fov / numRays;
    double rayAngle = player.angle - (fov / 2.0);

    for (int i = 0; i < numRays; i++) {
        // Initialize the ray
        Ray ray;
        ray.x = player.x;
        ray.y = player.y;
        ray.angle = rayAngle;

        double rayXStep = cos(ray.angle);
        double rayYStep = sin(ray.angle);

        while (grid[(int)ray.x][(int)ray.y] != '1') {
            // Move the ray along its angle until it hits a wall
            ray.x += rayXStep;
            ray.y += rayYStep;
        }

        printf("Ray %d: Hit wall at (%.2f, %.2f)\n", i + 1, ray.x, ray.y);

        rayAngle += rayAngleIncrement;
    }
}

int main() {
    Point player;
    player.x = 1.5;
    player.y = 1.5;
    player.angle = 0.0;

    int numRays = 60; // Number of rays to cast

    castRays(player, numRays);

    return 0;
}