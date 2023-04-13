// 2023.4.5,1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

/*
    1 ~ 12 의 숫자카드
    1. 카드 2장이 랜덤하게 선택 되고 플레이어에게 보여진다.
       카드 1장은 선택이 되고 경기 종료까지 오픈되지 않는다.
    2. 기본 베팅 200원
    3. 게임 포기 : 100원 회수, 스탑 : 승부, 추가 베팅 : 두배로 - 카드 추가 오픈
       승부 : 숨겨진 카드가 위에 오픈된 두 숫자 사이의 카드라면 승리
       추가 베팅 : 선택 되지 않은 카드 중에 한장이 오픈 된다.
*/

int main()
{
    // 플레이어의 총 금액, 베팅 금액, 카드 12장 (배열), 베팅 횟수, 게임 지속여부, 
    // 배열의 0, 1 : 오픈카드, 2 : 승부 카드, 3, 4, 5 : 추가 베팅시 오픈 카드
    
    srand(time(NULL));
    rand();

    int nMoney = 400;
    int nBet;
    int nAddBet;
    int nCards[12];
    bool isPlaying = true;
    
    while (isPlaying)
    {
        for (int i = 1; i <= 12; i++)
            nCards[i - 1] = i;

        for (int i = 0; i < 100; i++)
        {
            int nSrc = rand() % 12;
            int nDest = rand() % 12;

            int nTemp = nCards[nSrc];
            nCards[nSrc] = nCards[nDest];
            nCards[nDest] = nTemp;
        }

        nBet = 100;
        nAddBet = 1;

        if (nCards[0] > nCards[1])
        {
            int nTemp = nCards[0];
            nCards[0] = nCards[1];
            nCards[1] = nTemp;
        }

        while (true) //for (int i = 0; i < 4; i++) -- 1 ~ 3이 아닌 숫자를 고를때도 카운트 되서 while로 변경 // 한판당 최대 선택 가능 횟수가 4번
        {
            system("cls");

            cout << "현재 보유 금액 : " << nMoney << endl;
            cout << "==========================" << endl;
            cout << "현재 베팅 금액 : " << nBet * nAddBet << endl;
            cout << "오픈 카드 : " << nCards[0] << " ~ " << nCards[1] << endl;
            cout << "승부 카드 : ? " << endl;

            cout << "추가 오픈 :\t";

            int nIndex = 0;
            for (int i = 2; i <= nAddBet; i *= 2)
            {
                cout << nCards[3 + (nIndex++)] << "\t";
            }

            for (int i = nAddBet; i < 8; i *= 2)
                cout << "?\t";

            cout << endl;

            int nSelect;
            cout << "1. 포기, 2. 승부, 3.추가 베팅 : ";
            cin >> nSelect;

            if (nSelect == 1)
            {
                cout << "게임 포기!!" << endl;
                cout << "승부 카드 : " << nCards[2] << endl;

                nMoney -= nBet * nAddBet / 2;
                break;
            }
            else if (nSelect == 2)
            {
                cout << "승부!!" << endl;
                cout << "승부 카드 : " << nCards[2] << endl;

                if (nCards[2] > nCards[0] && nCards[2] < nCards[1])
                {
                    cout << "플레이어 승리!!" << endl;
                    nMoney += nBet * nAddBet;
                }
                else
                {
                    cout << "플레이어 패배!!" << endl;
                    nMoney -= nBet * nAddBet;
                }
                break;
            }
            else if (nSelect == 3)
            {
                if (nMoney < nBet * nAddBet * 2)
                    cout << "보유 금액이 부족합니다." << endl;
                else 
                    nAddBet *= 2;
            }
            else
            {
                cout << "선택 범위 안에서 숫자를 고르세요." << endl;
            }
        }

        if (nMoney < 200)
        {
            cout << "더 이상 플레이할 금액이 없습니다." << endl
                << "게임을 종료합니다." << endl;

            isPlaying = false;
        }
        else
        {
            char chYN;
            cout << "다음 게임 (y,n)";
            cin >> chYN;

            if (chYN == 'n')
                isPlaying = false;
        }
    }

    system("pause");

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
