/*Uva 1589
*/

#include <iostream>
#include <array>
#include <algorithm>

const int kRows = 11;
const int kColumns = 10;

std::array<std::array<char, kColumns>, kRows> board;

bool fly_general(int r, int c){
    while(++r<kRows){
        if(board[r][c] == '_') continue;
        if(board[r][c] == 'G') return true;
        return false;
    }
    return false;
}

bool captured_by_chariot(int r, int c){
    int tc = c;
    while(++tc < kColumns){
        if(board[r][tc] == 'R') return true;
        if(board[r][tc] != '_') break;
    }
    int tr = r;
    while(--tr > 0){
        if(board[tr][c] == 'R') return true;
        if(board[tr][c] != '_') break;
    }
    tc = c;
    while(--tc > 0){
        if(board[r][tc] == 'R') return true;
        if(board[r][tc] != '_') break;
    }
    tr = r;
    while(++tr < kRows){
        if(board[tr][c] == 'R') return true;
        if(board[tr][c] != '_') break;
    }
    return false;
}

bool captured_by_cannon(int r, int c){
    int tc = c;
    bool can_jump = false;
    while(++tc < kColumns){
        if(!can_jump && board[r][tc] != '_'){
            can_jump = true;
            continue;
        }
        if(can_jump){
            if(board[r][tc] == 'C') return true;
            if(board[r][tc] != '_') break;
        }
    }

    int tr = r;
    can_jump = false;
    while(--tr > 0){
        if(!can_jump && board[tr][c] != '_'){
            can_jump = true;
            continue;
        }
        if(can_jump){
            if(board[tr][c] == 'C') return true;
            if(board[tr][c] != '_') break;
        }
    }

    tc = c;
    can_jump = false;
    while(--tc < 0){
        if(!can_jump && board[r][tc] != '_'){
            can_jump = true;
            continue;
        }
        if(can_jump){
            if(board[r][tc] == 'C') return true;
            if(board[r][tc] != '_') break;
        }
    }

    tr = r;
    can_jump = false;
    while(++tr < kRows){
        if(!can_jump && board[tr][c] != '_'){
            can_jump = true;
            continue;
        }
        if(can_jump){
            if(board[tr][c] == 'C') return true;
            if(board[tr][c] != '_') break;
        }
    }
    return false;
}

bool captured_by_horse(int r, int c){
    if(board[r+1][c-1] == '_' && (board[r+1][c-2] == 'H' || board[r+2][c-1] == 'H')) return true;
    if(board[r+1][c+1] == '_' && (board[r+1][c+2] == 'H' || board[r+2][c+1] == 'H')) return true;
    if(r > 1){
        if(board[r-1][c-1] == '_' && board[r-1][c-2] == 'H') return true;
        if(board[r-1][c+1] == '_' && board[r-1][c+2] == 'H') return true;
    }
    if(r > 2){
        if(board[r-1][c-1] == '_' && board[r-2][c-1] == 'H') return true;
        if(board[r-1][c+1] == '_' && board[r-2][c+1] == 'H') return true;
    }
    return false;
}

bool is_safe(int r, int c){
    if(fly_general(r, c)) return false;
    if(captured_by_chariot(r, c)) return false;
    if(captured_by_cannon(r, c)) return false;
    if(captured_by_horse(r, c)) return false;
    return true;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("Xiangqi_input.txt", "r", stdin);
    freopen("Xiangqi_output.txt", "w", stdout);
#endif
    int N, RB, CB;
    while(std::cin>>N>>RB>>CB){
        if(N < 2) break;
        std::for_each(board.begin(), board.end(), [](std::array<char, kColumns>& ar){ar.fill('_');});
        while(N--){
            char pie;
            int r, c;
            std::cin>>pie>>r>>c;
            board[r][c] = pie;
        }
        if(fly_general(RB, CB)){
            std::cout<<"NO"<<std::endl;
            continue;
        }
        if(CB < 6 && is_safe(RB, CB+1)){
            std::cout<<"NO"<<std::endl;
            continue;
        }
        if(RB > 1 && is_safe(RB-1, CB)){
            std::cout<<"NO"<<std::endl;
            continue;
        }
        if(CB > 4 && is_safe(RB, CB-1)){
            std::cout<<"NO"<<std::endl;
            continue;
        }
        if(RB < 3 && is_safe(RB+1, CB)){
            std::cout<<"NO"<<std::endl;
            continue;
        }
        std::cout<<"YES"<<std::endl;
    }
    return 0;
}
