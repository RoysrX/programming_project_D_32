#include <stdio.h>
#include <stdbool.h>

void print_board(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

bool check_for_win(char board[], char player) {
    // Check rows
    for(int i = 0; i < 9; i += 3) {
        if(board[i] == player && board[i+1] == player && board[i+2] == player)
            return true;
    }
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[i] == player && board[i+3] == player && board[i+6] == player)
            return true;
    }
    // Check diagonals
    if(board[0] == player && board[4] == player && board[8] == player)
        return true;
    if(board[2] == player && board[4] == player && board[6] == player)
        return true;
    return false;
}

bool check_for_tie(char board[]) {
    for(int i = 0; i < 9; i++) {
        if(board[i] == ' ')
            return false;
    }
    return true;
}

int get_player_move(char board[], char player) {
    int move;
    do {
        printf("%c's turn. Enter a number (1-9): ", player);
        scanf("%d", &move);
        move--; // Convert to 0-based index
    } while(move < 0 || move > 8 || board[move] != ' ');
    return move;
}

int main() {
    char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    int move;
    bool game_over = false;
    
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 is X and Player 2 is O.\n\n");
    print_board(board);

    while(!game_over) {
        // Get player move
        move = get_player_move(board, player);
        board[move] = player;

        // Check for win or tie
        if(check_for_win(board, player)) {
            printf("%c wins!\n", player);
            game_over = true;
        } else if(check_for_tie(board)) {
            printf("It's a tie!\n");
            game_over = true;
        }

        // Switch players
        if(player == 'X')
            player = 'O';
        else
            player = 'X';

        print_board(board);
    }
    
    return 0;
}