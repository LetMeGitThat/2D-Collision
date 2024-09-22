#include <raylib.h>
#include <iostream>

class Object {
    private:
    Vector2 position;
    Vector2 size;
    Color color;

    public:
    Vector2 velocity;
    Vector2 GetPosition() { return position; }

    void Draw() { DrawRectangle(position.x, position.y, size.x, size.y, color); }

    void Update() {
        position.x += velocity.x;
        position.y += velocity.y;
    }

    Object(Vector2 pos, Vector2 Size, Color clr) : position(pos), size(Size), color(clr) {}
};

const short int WIDTH = 900;
const short int HEIGHT = 600;
const char* TITLE = "Collision Test";
const short int FPS = 60;

void Input() {

}

int main() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(FPS);

    Object player({100, 100}, {100, 100}, RED);
    Object wall({300, 300}, {100, 200}, BLUE);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        player.Update();

        if (IsKeyPressed(KEY_W)) {
            player.velocity.y += -1;
        }
        if (IsKeyPressed(KEY_A)) {
            player.velocity.x += -1;
        }
        if (IsKeyPressed(KEY_S)) {
            player.velocity.y += 1;
        }
        if (IsKeyPressed(KEY_D)) {
            player.velocity.x += 1;
        }

        if (IsKeyReleased(KEY_W)) {
            player.velocity.y += 1;
        }
        if (IsKeyReleased(KEY_A)) {
            player.velocity.x += 1;
        }
        if (IsKeyReleased(KEY_S)) {
            player.velocity.y += -1;
        }
        if (IsKeyReleased(KEY_D)) {
            player.velocity.x += -1;
        }

        player.Draw();
        wall.Draw();
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
}