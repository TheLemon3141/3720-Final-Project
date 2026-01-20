# CardREST
This is an example of a Web service that performs black jack functions using the rest endpoint logic.

# Group Responsiblities
- Nathan: wrote the basics of our HTML and JS so we could start and then worked specifically on the creation of the showcards function which would display the cards as texts which then was altered later by solomon who called them as images, worked on the dealer function whcih would call on the dealer endpoint after a player has stood and then allow the dealer to go and then would call on the display winners showing the score of both and who won.

- Ryan: Worked on the hit function which would call on the hit endpoint wrote by him and then allow a player to continously press the button up until they where above 21 in which they would bust and it would throw an error message and stop the player from being able to hit again and end the game since the player lost.  

- Solomon: worked on the stand button which when pressed would end the players turn and go onto the dealers turn and their actions, the startgame button which would call on the start endpoint to intialized and create the game and be able to be pressed multiple times to restart a game, the design aspect using css which displays the cards as images and background colours with coloured themes for buttons. 

- Erik: Worked on the winners function which would display the score of both player and dealer and who won after either the player bust which is automatic loss or if the dealer got his turn then who ever had the higher score would win. 

# How the Team worked together
At each stage of the milestones (1, 2) all group members would meet up to discuss the project. In each meeting all members would discuss the overall plan/ideas for that milestone. This included what classes, endpoints, and test were needed to complete the project. After this phase, members would create corresponding issues on gitlab to track and manage tasks accordingly. Following this, members would divide task evenly, by choosing what issues they wanted to do and verifying with the group if that was okay. 

In phase 3 the team followed this same process, creating issues and choosing tasks they would want to complete. Each member would update a group chat, letting others know issues or problems that had come up. Indiviudals who finished quicker than others decided to work on the design aspect of the webpage. 

The week following this meeting, another meeting was held to follow up, what task were left, if any issues had arose, or individuals have fallen behind. This ensured everyone was on the same page, leaving no one struggling behind.

Day before the demo, all members met up and verifed that all issues had been closed and task completed. Any issues that arose were quickly handled as group members would collaborate to finish quickly. 

All individuals then created merge request and had other members verify/review these changes into the main. 

## ------
Endpoint Links:

To start the game we need to create the game first and the objects so press the below link to start a new game.
* START: [http://localhost:8080/start]

Reveals the state of the game by showing both player 1's card and dealers cards and can be pressed after both go or at any point during the game to see what the updated version of the game looks like and to restart all you have to do is go back and press the start link.
* GAME_STATE: [http://localhost:8080/game_state]

Reveals what the dealer has done and goes over his turn by continuing to hit until his score is over 17 then he will stand and to see his updated hand all we have to do is go back to game_state link. 
* DEALER: [http://localhost:8080/dealer]

Allows player 1 to hit which adds card to player 1's hand and increases his score but could lead to busting if done too many times.
* PLAYER 1 HIT: [http://localhost:8080/hit]

Allows player 1 to end his turn by not hitting anymore(picking up anymore cards).
* PLAYER 1 STAND: [http://localhost:8080/stand]

After running the game and going over each of the above steps to determine the winner after both dealer and player 1 go this tells us the winner. 
* WINNERS: [http://localhost:8080/getWinners]


