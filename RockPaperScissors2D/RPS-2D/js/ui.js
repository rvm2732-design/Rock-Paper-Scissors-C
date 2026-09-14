/* =========================================
   ROCK PAPER SCISSORS
   USER INTERFACE
========================================= */


document.addEventListener(
    "DOMContentLoaded",
    () => {


        /*
            ================================
            GET HTML ELEMENTS
            ================================
        */


        const choiceButtons =
            document.querySelectorAll(
                ".choice-btn"
            );


        const playerHand =
            document.getElementById(
                "player-hand"
            );


        const computerHand =
            document.getElementById(
                "computer-hand"
            );


        const playerChoiceText =
            document.getElementById(
                "player-choice"
            );


        const computerChoiceText =
            document.getElementById(
                "computer-choice"
            );


        const resultText =
            document.getElementById(
                "result"
            );


        const playerScore =
            document.getElementById(
                "player-score"
            );


        const computerScore =
            document.getElementById(
                "computer-score"
            );


        const drawScore =
            document.getElementById(
                "draw-score"
            );


        const resetButton =
            document.getElementById(
                "reset-btn"
            );


        const handIcons = {

            rock: "✊",

            paper: "✋",

            scissors: "✌️"

        };


        /*
            ================================
            DISPLAY NAMES
            ================================
        */

        const displayNames = {

            rock: "Rock",

            paper: "Paper",

            scissors: "Scissors"

        };


        /*
            ================================
            PLAYER CHOICE BUTTONS
            ================================
        */


        choiceButtons.forEach(
            (button) => {


                button.addEventListener(
                    "click",
                    () => {


                        /*
                            Get selected choice
                        */

                        const selectedChoice =
                            button.dataset.choice;


                        /*
                            Send choice
                            to game.js
                        */

                        const round =
                            window.game.playRound(
                                selectedChoice
                            );

                        updateHands(round);

                        updateResult(round);

                        updateScore(round);

                    }
                );

            }
        );


        /*
            ================================
            UPDATE HAND IMAGES
            ================================
        */

        function updateHands(round) {


            /*
                Remove previous animation
            */

            playerHand.classList.remove(
                "reveal"
            );

            computerHand.classList.remove(
                "reveal"
            );


            /*
                Force browser to restart
                the animation
            */

            void playerHand.offsetWidth;

            void computerHand.offsetWidth;


            playerHand.textContent =
                handIcons[round.player];


            computerHand.textContent =
                handIcons[round.computer];


            /*
                Update choice labels
            */

            playerChoiceText.textContent =
                displayNames[round.player];


            computerChoiceText.textContent =
                displayNames[round.computer];


            /*
                Start animation
            */

            playerHand.classList.add(
                "reveal"
            );

            computerHand.classList.add(
                "reveal"
            );

        }


        /*
            ================================
            UPDATE RESULT
            ================================
        */

        function updateResult(round) {


            if (round.winner === "player") {

                resultText.textContent =
                    "🎉 You Win!";

            }


            else if (
                round.winner === "computer"
            ) {

                resultText.textContent =
                    "💻 Computer Wins!";

            }


            else {

                resultText.textContent =
                    "🤝 It's a Draw!";

            }

        }


        /*
            ================================
            UPDATE SCORE
            ================================
        */

        function updateScore(round) {


            playerScore.textContent =
                round.scores.player;


            computerScore.textContent =
                round.scores.computer;


            drawScore.textContent =
                round.scores.draw;

        }


        /*
            ================================
            RESET GAME
            ================================
        */

        resetButton.addEventListener(
            "click",
            () => {


                /*
                    Reset JavaScript state
                */

                window.game.resetGame();


                playerHand.textContent =
                    handIcons.rock;

                computerHand.textContent =
                    handIcons.rock;


                /*
                    Reset labels
                */

                playerChoiceText.textContent =
                    "Waiting...";

                computerChoiceText.textContent =
                    "Waiting...";


                /*
                    Reset result
                */

                resultText.textContent =
                    "Make your move!";


                /*
                    Reset scoreboard
                */

                playerScore.textContent = "0";

                computerScore.textContent = "0";

                drawScore.textContent = "0";

            }
        );


    }
);