#include <iostream>
using namespace std;

char mat[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char token = 'x';
string p1 = "", p2 = "";
bool  draw;

void display_board(){
    cout << "   |   |   \n";
    cout << " "<<mat[0][0]<<" | "<<mat[0][1]<<" | "<<mat[0][2]<<" \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " "<<mat[1][0]<<" | "<<mat[1][1]<<" | "<<mat[1][2]<<" \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " "<<mat[2][0]<<" | "<<mat[2][1]<<" | "<<mat[2][2]<<" \n";
    cout << "   |   |   \n";
}

void fun(){ // In what place to keep the token 
    int place;
    if(token == 'x'){
        cout << p1 << ", Please enter the place in which you want to put your token" << endl;
        cin >> place;
    }
    if(token == '0'){
        cout << p2 << ", Please enter the place in which you want to put your token" << endl;
        cin >> place;
    }
    //indexing
    if(place == 1){
        row = 0; col = 0;
    }
    else if(place == 2){
        row = 0; col = 1;
    }
    else if(place == 3){
        row = 0; col = 2;
    }
    else if(place == 4){
        row = 1; col = 0;
    }
    else if(place == 5){
        row = 1; col = 1;
    }
    else if(place == 6){
        row = 1; col = 2;
    }
    else if(place == 7){
        row = 2; col = 0;
    }
    else if(place == 8){
        row = 2; col = 1;
    }
    else if(place == 9){
        row = 2; col = 2;
    }
    else{
        cout << "Invalid!" << endl;
        fun(); // the entered place is invalid, so ask again to enter a valid place.
    }

    if(token == 'x' && mat[row][col] != 'x' && mat[row][col]!= '0'){ //the chosen place is empty
        mat[row][col] = 'x';
        token = '0';
    }
    else if(token == '0' && mat[row][col] != 'x' && mat[row][col]!= '0'){ //the chosen place is empty
        mat[row][col] = '0';
        token = 'x';
    }
}

bool is_game_over(){
    for(int i=0;i<3;i++){
        if(mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2]){
            return true; //game over
        }
        if(mat[0][i] == mat[1][i] && mat[0][i] == mat[2][i]){
            return true; //game over
        }
    }
    if((mat[0][0]== mat[1][1] && mat[0][0] == mat[2][2]) || (mat[0][2] == mat[1][1] && mat[0][2]==mat[2][0])){ //checking diagonals
        return true; //game over
    }

    // still if some places are empty, then the game is not over
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j] != 'x' && mat[i][j] != '0'){
                //found an empty place.
                return false;
            }
        }
    }
    //other than above there is only one possibility that is DRAW.
     draw = true;
    return true;
}



int main(){
    cout << "Enter the name of Player 1" << endl;
    cin >> p1;
    cout << "Enter the name of Player 2" << endl;
    cin >> p2;
    cout << " "<<p1<<" vs "<<p2<<" \n";
    // p1's token is X.
    display_board();

    while(!is_game_over()){
        fun();
        display_board();
    }

    if(token == 'x' &&  draw == false){
        cout << p2 << " is the winner." << endl;
    }
    else if(token == '0' &&  draw == false){
        cout << p1 << " is the winner." << endl;
    }
    else{
       cout <<  "It's a DRAW." << endl;
    }
}




