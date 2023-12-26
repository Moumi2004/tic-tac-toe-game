# tic-tac-toe-game

As we all know this game is often played in classrooms on the last page of the notebook 😀.
Two players mark the position in which they want to keep their token alternatively in a 3 ✖️ 3 grid.
Here, player 1 is given the token ❌ and player 2 is given token ⭕️.
The positions are marked as below.

                                                      |   |   
                                                    1 | 2 | 3 
                                                   ___|___|___
                                                      |   |   
                                                    4 | 5 | 6 
                                                   ___|___|___
                                                      |   |   
                                                    7 | 8 | 9 
                                                      |   |   
                                                      
The players need to choose any number from 1 to 9. 
The function display_board() will display the board.
The function fun() will tell in what place of the board the token should be kept and modifies the matrix and also changes the token for the next player's turn.
The corresponding positions will be marked with the corresponding tokens.
The function is_game_over() will return true if the game is over and false when the game needs to be continued and also checks if the game is DRAW.
Game will end if any row or column or diagonal of the same token is found and prints out the winner.
If the game is a draw, the outcome is "It's a DRAW".
