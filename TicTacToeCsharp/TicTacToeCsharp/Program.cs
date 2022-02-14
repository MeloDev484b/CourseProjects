class Program
{
    const int GAME_BOARD_CONSTANT = 3;
    static bool victory = false;
    static string winner = "";
    static string[,] gameBoard = new string[GAME_BOARD_CONSTANT, GAME_BOARD_CONSTANT];
    static string mark = "[ X ]", player = "Player 1";
    static int turnNumber = 0;
    static int invalidSelections = 0;
    static void Main(string[] args)
    {
        generateGameBoard();
        while (!victory)
        {
            drawGameBoard();
            checkTurn();
            checkForWinner();
        }
        
        Console.ReadKey();
    }
    static void generateGameBoard()
    {
        int counter = 1;
        for (int i = 0; i < GAME_BOARD_CONSTANT; i++)
        {
            for (int j = 0; j < GAME_BOARD_CONSTANT; j++)
            {
                gameBoard[i, j] = "[ "+counter+" ]";
                counter++;
            }
        }
    }
    static void catGameBoard()
    {
        for (int i = 0; i < GAME_BOARD_CONSTANT; i++)
        {
            for (int j = 0; j < GAME_BOARD_CONSTANT; j++)
            {
                gameBoard[i, j] = "[ C ]";
            }
        }
    }
    static void drawGameBoard()
    {
        for (int i = 0; i < GAME_BOARD_CONSTANT; i++)
        {
            for (int j = 0; j < GAME_BOARD_CONSTANT; j++)
            {
                if(j==2)
                {
                    Console.Write(gameBoard[i, j]+"\n");
                }
                else
                {
                    Console.Write(gameBoard[i, j]);
                }
            }
        }
    }
    static void checkTurn()
    {
        if (turnNumber >= 9 && victory == false)
        {
            player = "The Cat";
            mark = "[ C ]";
            catGameBoard();
            Console.WriteLine("\nThe cat smacks the board with its paw, sending your marks flying.\n");
            drawGameBoard();
            Console.WriteLine("\n     Meow!");
            victory = true;
        }
        else if (turnNumber % 2 == 0)
        {
            player = "Player 1";
            mark = "[ X ]";
            Console.WriteLine("{0}, mark a box with {1}!", player, mark);
            getInput();
        }
        else
        {
            player = "Player 2";
            mark = "[ O ]";
            Console.WriteLine("{0}, mark a box with {1}!", player, mark);
            getInput();
        }
    }
    static void applyInput(string playerInput)
    {
        int boxToChange;
        bool success = int.TryParse(playerInput, out boxToChange);
        if (success && boxToChange <= 9)
        {
            switch (boxToChange)
            {
                case 1:
                    markBoard(0, 0);
                    break;
                case 2:
                    markBoard(0, 1);
                    break;
                case 3:
                    markBoard(0, 2);
                    break;
                case 4:
                    markBoard(1, 0);
                    break;
                case 5:
                    markBoard(1, 1);
                    break;
                case 6:
                    markBoard(1, 2);
                    break;
                case 7:
                    markBoard(2, 0);
                    break;
                case 8:
                    markBoard(2, 1);
                    break;
                case 9:
                    markBoard(2, 2);
                    break;
            }
        }
        else
        {
            Console.WriteLine("Please enter a valid number for your selection!");
            getInput();
        }
    }
    static void markBoard(int coordinate1, int coordinate2)
    {
        if (gameBoard[coordinate1, coordinate2] != "[ X ]" && gameBoard[coordinate1, coordinate2] != "[ O ]")
        {
            gameBoard[coordinate1, coordinate2] = mark;
            invalidSelections = 0;
            turnNumber++;
        }
        else
        {
            invalidSelections++;
            Console.WriteLine("{0}, please select a valid and unoccupied square.", player);
            if (invalidSelections > 2)
            {
                Console.WriteLine("{0}, you are trying my patience.", player);
            }
            getInput();
        }
    }
    static void getInput()
    {
        string input;
        input = Console.ReadLine();
        applyInput(input);
    }
    static void checkForWinner()
    {
        if (gameBoard[0, 0] == gameBoard[0, 1] && gameBoard[0,0] == gameBoard[0, 2])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[1, 0] == gameBoard[1, 1] && gameBoard[1, 0] == gameBoard[1, 2])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[2, 0] == gameBoard[2, 1] && gameBoard[2, 0] == gameBoard[2, 2])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[0, 0] == gameBoard[1, 0] && gameBoard[0, 0] == gameBoard[2, 0])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[0, 1] == gameBoard[1, 1] && gameBoard[0, 1] == gameBoard[2, 1])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[0, 2] == gameBoard[1, 2] && gameBoard[0, 2] == gameBoard[2, 2])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[0, 0] == gameBoard[1, 1] && gameBoard[0, 0] == gameBoard[2, 2])
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
        else if (gameBoard[0, 2] == gameBoard[1, 1] && gameBoard[0, 2] == gameBoard[2, 0])//
        {
            winner = player;
            victory = true;
            Console.WriteLine("\n<<[[The winner is {0}!]]>>\n", player);
            playOrQuit();
        }
    }
    static void playOrQuit()
    {
        string playerInput;
        Console.WriteLine("Press Enter to play again, or type \"q\" to quit the application.");
        playerInput = Console.ReadLine();
        if (playerInput == "q")
        {
            Console.WriteLine("Thanks for playing!");
        }
        else
        {
            generateGameBoard();
            victory = false;
            turnNumber = 0;
            winner = "";
            player = "Player 1";
            mark = "[ X ]";
        }

    }
}
//----NOTES----\\
/*
 * -Players choose a field
 * -Value changes to the player's mark
 * -error handling for incorrect inputs
 * -check for victory
 * -press any key to reset the game
 * 
 * --Functions needed--
 * -generate board/
 * -keep track of turn/
 * -player selects coordinates with a number/
 * -draw the game board/
 * -update thegame board/
 * -check for a win/
 * -handle a draw
 * -ask player if they want to continue or quit
 */