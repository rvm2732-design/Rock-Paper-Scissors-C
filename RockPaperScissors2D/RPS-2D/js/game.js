/* =========================================
   ROCK PAPER SCISSORS
   GAME LOGIC
========================================= */


/*
    Available choices
*/

const choices = [
    "rock",
    "paper",
    "scissors"
];


/*
    Score variables
*/

let playerScore = 0;

let computerScore = 0;

let drawScore = 0;


/*
    Generate a random computer move
*/

function getComputerChoice() {

    const randomIndex =
        Math.floor(
            Math.random() * choices.length
        );

    return choices[randomIndex];

}


/*
    Determine who won the round
*/

function determineWinner(
    player,
    computer
) {

    /*
        Same choice = Draw
    */

    if (player === computer) {

        return "draw";

    }


    /*
        Player winning combinations
    */

    if (

        (player === "rock" &&
            computer === "scissors")

        ||

        (player === "paper" &&
            computer === "rock")

        ||

        (player === "scissors" &&
            computer === "paper")

    ) {

        return "player";

    }


    /*
        If player didn't win
        and it wasn't a draw,
        computer wins.
    */

    return "computer";

}


/*
    Play one complete round
*/

function playRound(playerMove) {


    /*
        Computer selects a move
    */

    const computerMove =
        getComputerChoice();


    /*
        Determine winner
    */

    const winner =
        determineWinner(
            playerMove,
            computerMove
        );


    /*
        Update score
    */

    if (winner === "player") {

        playerScore++;

    }

    else if (winner === "computer") {

        computerScore++;

    }

    else {

        drawScore++;

    }


    /*
        Return round information
        to the UI
    */

    return {

        player: playerMove,

        computer: computerMove,

        winner: winner,

        scores: {

            player: playerScore,

            computer: computerScore,

            draw: drawScore

        }

    };

}


/*
    Reset the entire game
*/

function resetGame() {

    playerScore = 0;

    computerScore = 0;

    drawScore = 0;

}


/*
    Expose game functions
    to ui.js
*/

window.game = {

    playRound,

    resetGame

};