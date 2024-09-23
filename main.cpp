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
    Vector2 GetSize() { return size; }

    void Draw() { DrawRectangle(position.x, position.y, size.x, size.y, color); }

    void Update(Object obj) {
        float newPosX = position.x + velocity.x;
        float newPosY = position.y + velocity.y;

        if (!CheckCollisionRecs({ newPosX, newPosY, size.x, size.y }, { obj.GetPosition().x, obj.GetPosition().y, obj.GetSize().x, obj.GetSize().y })) {
            position.x = newPosX;
            position.y = newPosY;
        }
    }

    Object(Vector2 pos, Vector2 Size, Color clr) : position(pos), size(Size), color(clr) {}
};

void Input(Object& player) {
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
}

const short int WIDTH = 900;
const short int HEIGHT = 600;
const char* TITLE = "Collision Test";
const short int FPS = 60;

Object player({100, 100}, {100, 100}, RED);
Object wall({500, 150}, {100, 200}, BLUE);

void Update() {
    player.Update(wall);
}

void Draw() {
    player.Draw();
    wall.Draw();

    DrawFPS(10, 10);
}

int main() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(FPS);

    while (WindowShouldClose() == false) {
        BeginDrawing();

        Update();
        Input(player);

        Draw();

        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
}