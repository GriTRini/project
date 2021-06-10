//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//2019.12.03 (v2.0)점수 추가, 충돌처리 추가.
//2021.06.10 (v3.0)더블점프 추가, 선인장 장애물 추가
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define DINO_BOTTOM_Y 30
#define TREE_BOTTOM_Y 38
#define TREE_BOTTOM_X 100
#define CACTUS_BOTTOM_Y 38
#define CACTUS_BOTTOM_X 60

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
    system("mode con:cols=200 lines=50");
    system("title Google Dinosaurs. By BlockDMask.");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

//공룡을 그리는 함수
void DrawDino(int dinoY)
{
    GotoXY(0, dinoY);
    static bool legFlag = true;
    printf("        $$$$$$$ \n");
    printf("       $$ $$$$$$\n");
    printf("       $$$$$$$$$\n");
    printf("$      $$$      \n");
    printf("$$     $$$$$$$  \n");
    printf("$$$   $$$$$     \n");
    printf(" $$  $$$$$$$$$$ \n");
    printf(" $$$$$$$$$$$    \n");
    printf("  $$$$$$$$$$    \n");
    printf("    $$$$$$$$    \n");
    printf("     $$$$$$     \n");
    if (legFlag)
    {
        printf("     $    $$$    \n");
        printf("     $$          ");
        legFlag = false;
    }
    else
    {
        printf("     $$$  $     \n");
        printf("          $$    ");
        legFlag = true;
    }
}

//나무를 그리는 함수
void DrawTree(int treeX)
{
    GotoXY(treeX, TREE_BOTTOM_Y);
    printf("$$$$");
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    printf(" $$ ");
}

// 선인장을 그리는 함수
void DrawCactus(int cactusX)
{
    GotoXY(cactusX, CACTUS_BOTTOM_Y);
    printf("     $$     ");
    GotoXY(cactusX, CACTUS_BOTTOM_Y + 1);
    printf(" $$  $$  $$ ");
    GotoXY(cactusX, CACTUS_BOTTOM_Y + 2);
    printf(" $$$$$$$$$$ ");
    GotoXY(cactusX, CACTUS_BOTTOM_Y + 3);
    printf("     $$     ");
    GotoXY(cactusX, CACTUS_BOTTOM_Y + 4);
    printf("     $$     ");
}

//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score)
{
    system("cls");
    int x = 39;
    int y = 16;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("======G A M E O V E R======");
    GotoXY(x, y + 2);
    printf("===========================");
    GotoXY(x, y + 5);
    printf("SCORE : %d", score);

    printf("\n\n\n\n\n\n\n\n\n");
    system("pause");
}

//(v2.0) 충돌했으면 true, 아니면 false
bool isCollision_xt(const int treeX, const int dinoY)
{
    //트리의 X가 공룡의 몸체쪽에 있을때,
    //공룡의 높이가 충분하지 않다면 충돌로 처리
    GotoXY(0, 0);
    printf("treeX : %d, dinoY : %d", treeX, dinoY); //이런식으로 적절한 X, Y를 찾습니다.
    if (treeX <=  10 && treeX >= 6 && dinoY > 23)
    {
        return true;
    }
    return false;
}

bool isCollision_yt(const int treeY, const int dinoY)
{
    //트리의 Y 높이보다 공룡의 Y 높이가 낮다면 충돌
    GotoXY(0, 0);
    printf("treeX : %d, dinoY : %d", treeY, dinoY); //이런식으로 적절한 X, Y를 찾습니다.
    if (treeY > 23 && dinoY > 24)
    {
        return true;
    }
    return false;
}

bool isCollision_xc(const int cactusX, const int dinoY)
{
    //선인장의 X가 공룡의 몸체쪽에 있을때,
    //공룡의 높이가 충분하지 않다면 충돌로 처리
    GotoXY(0, 0);
    printf("cactusX : %d, dinoY : %d", cactusX, dinoY); //이런식으로 적절한 X, Y를 찾습니다.
    if (cactusX <= 8 && cactusX >= 3 && dinoY > 23)
    {
        return true;
    }
    return false;
}

bool isCollision_yc(const int cactusY, const int dinoY)
{
    //선인장의 Y 보다 공룡의 Y 가 더 낮다면 충돌
    GotoXY(0, 0);
    printf("cactusX : %d, dinoY : %d", cactusY, dinoY); //이런식으로 적절한 X, Y를 찾습니다.
    if (cactusY > 23 && dinoY > 24)
    {
        return true;
    }
    return false;
}

bool isJumping(const int dinoY)
{

}

int main()
{
    SetConsoleView();

    while (true)		//(v2.0) 게임 루프
    {
        //게임 시작시 초기화
        bool isJumping = false;
        bool doubleJumping = false;
        bool canDoubleJumping = true;
        bool isBottom = true;
        const int gravity = 3;

        int dinoY = DINO_BOTTOM_Y;
        int treeX = TREE_BOTTOM_X;
        int treeY = TREE_BOTTOM_Y;
        int cactusX = CACTUS_BOTTOM_X;
        int cactusY = CACTUS_BOTTOM_Y;
        int count = 1;

        int score = 0;
        clock_t start, curr;	//점수 변수 초기화
        start = clock();		//시작시간 초기화

        while (true)	//한 판에 대한 루프
        {
            //(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
            if(isCollision_xt(treeX, dinoY) && isCollision_yt(treeY, dinoY)) {
                break;
            } else if (isCollision_xc(cactusX, dinoY) && isCollision_yc(cactusY, dinoY)) {
                break;
            }

            //z키가 눌렸고
            if (GetKeyDown() == 'z') {
                // 바닥이면 점프
                if (isBottom) {
                    isJumping = true;
                    isBottom = false;
                    canDoubleJumping = true;
                // 점프중일때 한번 더 점프
                } else if (canDoubleJumping) {
                    doubleJumping = true;
                }
            }



            //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
            if (isJumping != 0 || doubleJumping != 0 )
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }

            //Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
            if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
                canDoubleJumping = false;
            }

            //나무가 왼쪽으로 (x음수) 가도록하고
            //나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
            treeX -= 1.03 * count;
            if (treeX <= 0)
            {
                treeX = TREE_BOTTOM_X;
                count += 0.01;
            }

            //선인장이 왼쪽으로 (x음수) 가도록 하고
            //선인장의 위치가 왼쪽 끝으로 가면 다시 오른쪽 끝으로 소환환
           cactusX -= count;
            if (cactusX <= 0) {
                cactusX = CACTUS_BOTTOM_X;
                count += 0.1;
            }



            //점프의 맨위를 찍으면 점프가 끝난 상황.
            if (dinoY <= 19 && !doubleJumping)
            {
                isJumping = false;
            } else if (dinoY <= 11 && doubleJumping) {
                doubleJumping = false;
            }

            DrawDino(dinoY);		//draw dino
            DrawTree(treeX);		//draw Tree
            DrawCactus(cactusX);    //draw cactus

            //(v2.0)
            curr = clock();			//현재시간 받아오기
            if (((curr - start) / CLOCKS_PER_SEC) >= 1)	// 1초가 넘었을떄
            {
                score++;	//스코어 UP
                start = clock();	//시작시간 초기화
            }
            Sleep(60);
            system("cls");	//clear

            //(v2.0) 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
            GotoXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
            printf("Score : %d isBottom : %d canDoubleJumping : %d doubleJumping : %d", score, isBottom, canDoubleJumping, doubleJumping);	//점수 출력해줌.
        }

        //(v2.0) 게임 오버 메뉴
        DrawGameOver(score);
    }
    return 0;
}