function showCards() {
    const playerCardsDiv = document.getElementById("playerCards");
    const dealerCardsDiv = document.getElementById("dealerCards");

    // Clear previous cards
    playerCardsDiv.innerHTML = "";
    dealerCardsDiv.innerHTML = "";

    fetch('http://localhost:8100/game_state')
        .then((resp) => resp.json())
        .then(function (data) {
            if (data.players.length === 0) {
                playerCardsDiv.innerHTML = "EMPTY HAND";
                dealerCardsDiv.innerHTML = "EMPTY HAND";
            } else {
                const player1 = data.players[0];
                const dealer = data.players[1];

                // Display dealer's cards
                if (dealer.hand.length === 0) {
                    dealerCardsDiv.innerHTML = "EMPTY HAND";
                } else {
                    dealer.hand.forEach(card => {
                        const cardImg = document.createElement('img');
                        cardImg.src = readCardImage(card);
                        cardImg.alt = `${card.rank} of ${card.suit}`;
                        cardImg.className = 'card-image';
                        dealerCardsDiv.appendChild(cardImg);
                    });
                }

                // Display player's cards
                if (player1.hand.length === 0) {
                    playerCardsDiv.innerHTML = "EMPTY HAND";
                } else {
                    player1.hand.forEach(card => {
                        const cardImg = document.createElement('img');
                        cardImg.src = readCardImage(card);
                        cardImg.alt = `${card.rank} of ${card.suit}`;
                        cardImg.className = 'card-image';
                        playerCardsDiv.appendChild(cardImg);
                    });
                }
            }
        })
        .catch(function (error) {
            console.log(error);
        });
}

function stand() {
    fetch('http://localhost:8100/stand')
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
            return response.json();
        })
        .then(data => {
            console.log("check");
            document.getElementById("actionMessage").innerHTML = data.message;

        })
        .catch(error => {
            console.error('Error standing:', error);
            document.getElementById("actionMessage").innerHTML = "Error standing: " + error.message;
        });

    dealer();
    showCards();
    getWinners();
}

function readCardImage(card) {

    let rank = card.rank.toLowerCase();
    if (rank === 'jack') rank = 'jack';
    else if (rank === 'queen') rank = 'queen';
    else if (rank === 'king') rank = 'king';
    else if (rank === 'ace') rank = 'ace';
    else if (rank === '10') rank = '10';
    else rank = rank.charAt(0);

    const suit = card.suit.toLowerCase();

    return `cards/${rank}_of_${suit}.png`;
}

function hit() {
    fetch('http://localhost:8100/hit')
        .then(response => {
            if (!response.ok) {
                throw new Error('You went over 21 and Busted!');
            }
            return response.json();
        })
        .then(data => {
            showCards();
            document.getElementById("actionMessage").innerHTML = data.message;
        })
        .catch(error => {
            console.error('Error standing:', error);
            document.getElementById("actionMessage").innerHTML = "Error standing: " + error.message;
        });
}

function startGame() {
    fetch('http://localhost:8100/start')
        .then(response => response.text())
        .then(data => {
            console.log("Server response:", data);
            showCards();
        })
        .catch(error => {
            console.error('Error starting game:', error);
            document.getElementById("actionMessage").innerHTML = "Error starting game: " + error.message;
        });

        document.getElementById("WinHeader").innerHTML = "";
        document.getElementById("winnerScore").innerHTML = "";
        document.getElementById("winnerName").innerHTML = "";
}

function getWinners() {
    const WinHeader = "Winner"
    var winnerName = "No winner"
    var winnerScore = 0;    //I'm assuming it can work with ints

    fetch('http://localhost:8100/getWinners')
    .then((resp) => resp.json())
    // .then(function(data){
        .then(data => {
        if (data.winners.length == 0) {
            winnerScore = 0;
        } else {
            let winnerList = data.winners;
            var winner1 = winnerList[0];
            var winner2;
            winnerScore = winner1.score;
            if (data.winners.length == 2) {
                winnerName = "Tie"
                winner2 = winnerList[1];
            } else {winnerName = winner1.name}
        }
        document.getElementById("WinHeader").innerHTML = WinHeader;
        document.getElementById("winnerScore").innerHTML = winnerScore;
        document.getElementById("winnerName").innerHTML = winnerName;
    })
    .catch(error =>{
        console.log(error);
    });
}

function dealer() {
    fetch('http://localhost:8100/dealer')
    .then((resp) => console.log(resp))
    .catch(function(error){
        console.log(error);
    });
}
