
 CNG242 Programming Language Concepts
 Assignment 3
 Heroes of the Board: Legendary two-player board game

 Team Members:
- İrem Çiloğlu 2385292 7
- Turgut Canberk Diner 2453157


In project, we decide which player will play with mod of 2 starting with a random number.
Then, the game asks the player which character s/he wants to play with. After we 
take the input, we check if entered char is a correct input. If it is not, player enters again.

If the character is Mage, one life is added to all pieces in the player's board except 
the Mage added.
If the character is Knight, one damage hit is added to all pieces in the player's board 
except Knight added.

After character selection, game continues with coordinate selection and we check if the 
coordinate is between the correct range. If it is correct, we determine that if it is 
empty or not. When the coordinate is empty, we continue with hit functionality.

In our project, hit functionality works like this: 
	- We scan the enemy's board and player's board.
	- We check if a position in enemy's board is empty or not.
	- If not empty, the player's pieces shoot the one in the same row.
	- If there is more than one piece in enemy's board, and damage hit is bigger than the 
	first piece's life, the remaining damage hit applies to the next piece.
	- If all positions in the row is empty, then the piece shoots the enemy player.

Then, we continue with the other player until one of the player's life is zero.

